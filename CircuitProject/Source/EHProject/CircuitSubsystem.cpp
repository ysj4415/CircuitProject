// Fill out your copyright notice in the Description page of Project Settings.


#include "CircuitSubsystem.h"
#include <queue>
#include <unordered_set>
#include <map>
#include "DesktopPlatform/Public/IDesktopPlatform.h"
#include "DesktopPlatform/Public/DesktopPlatformModule.h"

void UCircuitSubsystem::simplifyLines(std::vector<Line*>* lines, std::vector<Resistor*>* resistors, std::vector<Switch*>* switchs, VoltageSource* voltageSource) const
{
	ASSERT(lines != nullptr
		and resistors != nullptr
		and switchs != nullptr
		and voltageSource != nullptr);

	bool bSimplified = false;

	// ��� ������ ����ȭ�� ������ ���ε��� �����մϴ�.
	do
	{
		bSimplified = false;

		for (Line* line : *lines)
		{
			// from point�� ��ġ�� ���� Ȥ�� ������ ������ �����ϰ� �ش� ������ �����ϰ�, Ȥ�� ��ġ�� ������ ���� �ϳ��� ������ ��Ĩ�ϴ�.
			PointOverlapElements fromOverlapElements = GetPointOverlapElements(line->From, &line->ConnectedLines, resistors, switchs, voltageSource);
			if (fromOverlapElements.OverlapCountSum == 0)
			{
				removeLine(line, lines);
				bSimplified = true;
				break;
			}
			else if (fromOverlapElements.Lines.size() == 1)
			{
				mergeLines(line, fromOverlapElements.Lines.front(), lines, resistors, switchs, voltageSource);
				bSimplified = true;
				break;
			}

			// to point�� ��ġ�� ���� Ȥ�� ������ ������ �����ϰ� �ش� ������ �����ϰ�, Ȥ�� ��ġ�� ������ ���� �ϳ��� ������ ��Ĩ�ϴ�.
			PointOverlapElements toOverlapElements = GetPointOverlapElements(line->To, &line->ConnectedLines, resistors, switchs, voltageSource);
			if (toOverlapElements.OverlapCountSum == 0)
			{
				removeLine(line, lines);
				bSimplified = true;
				break;
			}
			else if (toOverlapElements.Lines.size() == 1)
			{
				mergeLines(line, toOverlapElements.Lines.front(), lines, resistors, switchs, voltageSource);
				bSimplified = true;
				break;
			}
		}
	} while (bSimplified);
}

bool UCircuitSubsystem::areTwoPointSame(const AActor* a, const AActor* b) const
{
	FVector ALoc = a->GetActorLocation();
	FVector BLoc = b->GetActorLocation();

	return ALoc.Equals(BLoc, 0.1f);
}

void UCircuitSubsystem::simplifyResistors(std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const
{
	ASSERT(resistors != nullptr and lines != nullptr);

	bool bSimplified = false;

	do
	{
		bSimplified = false;

		for (Resistor* resistor : *resistors)
		{
			if (resistor->ConnectedLines.size() < 2)
			{
				// UE_LOG(LogTemp, Warning, TEXT("no line\n"));
				removeResistor(resistor, resistors, lines);
				bSimplified = true;
				break;
			}
		}

		for (Line* line : *lines)
		{
			std::vector<Resistor*> connectedResistors = line->ConnectedResistors;
			if (connectedResistors.size() >= 2)
			{
				// UE_LOG(LogTemp, Warning, TEXT("sum\n"));
				mergeSeriesResistance(connectedResistors[0], connectedResistors[1], resistors, lines);
				bSimplified = true;
				break;
			}
		}
	} while (bSimplified);
}

void UCircuitSubsystem::mergeSeriesResistance(Resistor* a, Resistor* b, std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const
{
	ASSERT(a != nullptr
		and b != nullptr
		and resistors != nullptr
		and lines != nullptr);

	a->R += b->R;

	ElementSidePoint bSidePoint = getElementSidePoint(b);
	auto newLine = new Line
	{
		.From = bSidePoint.Left,
		.To = bSidePoint.Right
	};

	removeResistor(b, resistors, lines);
	addLine(newLine, lines, resistors, nullptr, nullptr);
}

UCircuitSubsystem::ElementSidePoint UCircuitSubsystem::getElementSidePoint(const Resistor* elementCellPoint) const
{
	ElementSidePoint elementSidePoint =
	{
		elementCellPoint->LeftPoint,
		elementCellPoint->RightPoint
	};

	return elementSidePoint;
}

UCircuitSubsystem::ElementSidePoint UCircuitSubsystem::getElementSidePoint(const VoltageSource* elementCellPoint) const
{
	ElementSidePoint elementSidePoint =
	{
		elementCellPoint->LeftPoint,
		elementCellPoint->RightPoint
	};

	return elementSidePoint;
}

UCircuitSubsystem::ElementSidePoint UCircuitSubsystem::getElementSidePoint(const Switch* elementCellPoint) const
{
	ElementSidePoint elementSidePoint =
	{
		elementCellPoint->LeftPoint,
		elementCellPoint->RightPoint
	};

	return elementSidePoint;
}

void UCircuitSubsystem::removeResistor(Resistor* resistor, std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const
{
	ASSERT(resistor != nullptr
		and resistors != nullptr
		and lines != nullptr);
	// ����� ���ο��� ������ ������ �����ϴ�.
	while (resistor->ConnectedLines.size() > 0)
	{
		disconnectResistor(resistor->ConnectedLines.front(), resistor);
	}

	bool bRemoved = false;

	// �迭���� �ش� ������ �����մϴ�.
	for (size_t i = 0; i < resistors->size(); ++i)
	{
		if ((*resistors)[i] == resistor)
		{
			std::swap((*resistors)[i], (*resistors).back());
			RELEASE(resistors->back());
			(*resistors).pop_back();

			bRemoved = true;
			break;
		}
	}

	MASSERT(bRemoved, "�迭�� �����Ϸ��� ������ �����ϴ�.");
}

void UCircuitSubsystem::disconnectResistor(Line* line, Resistor* resistor) const
{
	ASSERT(line != nullptr and resistor != nullptr);

	bool bDisconnectedLine = false;

	for (size_t j = 0; j < resistor->ConnectedLines.size(); ++j)
	{
		if (resistor->ConnectedLines[j] == line)
		{
			std::swap(resistor->ConnectedLines[j], resistor->ConnectedLines.back());
			resistor->ConnectedLines.pop_back();

			bDisconnectedLine = true;
			break;
		}
	}

	MASSERT(bDisconnectedLine, "���׿� �ش� ������ ����Ǿ� ���� �ʽ��ϴ�.");
	bool bDisconnectedResistor = false;

	for (size_t i = 0; i < line->ConnectedResistors.size(); ++i)
	{
		if (line->ConnectedResistors[i] == resistor)
		{
			std::swap(line->ConnectedResistors[i], line->ConnectedResistors.back());
			line->ConnectedResistors.pop_back();

			bDisconnectedResistor = true;
			break;
		}
	}
	MASSERT(bDisconnectedResistor, "���ο� �ش� ������ ����Ǿ� ���� �ʽ��ϴ�.");

}

void UCircuitSubsystem::disconnectVoltageSource(Line* line, VoltageSource* voltageSource) const
{
	ASSERT(line != nullptr and voltageSource != nullptr);
	MASSERT(line->ConnectedVoltageSource == voltageSource, "���ο� ����� ���п��� ���޵� ���ڿ� ��ġ���� �ʽ��ϴ�.");
	bool bDisonncectedLine = false;

	// ���п����� ������ �����ϴ�.
	for (size_t i = 0; i < voltageSource->ConnectedLines.size(); ++i)
	{
		if (voltageSource->ConnectedLines[i] == line)
		{
			std::swap(voltageSource->ConnectedLines[i], voltageSource->ConnectedLines.back());
			voltageSource->ConnectedLines.pop_back();

			bDisonncectedLine = true;
			break;
		}
	}
	MASSERT(bDisonncectedLine, "���п��� �ش� ������ ����Ǿ� ���� �ʽ��ϴ�.");

	line->ConnectedVoltageSource = nullptr;
}

void UCircuitSubsystem::addLine(Line* line, std::vector<Line*>* lines
	, std::vector<Resistor*>* resistorsOrNull
	, std::vector<Switch*>* switchsOrNull
	, VoltageSource* voltageSourceOrNull) const
{
	ASSERT(line != nullptr and lines != nullptr);

	MASSERT(not areTwoPointSame(line->From, line->To), "������ �� �� ���� �����ϸ� �ȵ˴ϴ�.");
	MASSERT(line->ConnectedLines.empty(), "������ ���ο��� ����� ������ ����� �մϴ�.");
	MASSERT(resistorsOrNull == nullptr or line->ConnectedResistors.empty(), "������ ���ο��� ����� ������ ����� �մϴ�.");
	MASSERT(switchsOrNull == nullptr or line->ConnectedSwitchs.empty(), "������ ���ο��� ����� ����ġ�� ����� �մϴ�.");
	MASSERT(line->ConnectedVoltageSource == nullptr, "������ ���ο��� ����� ���п��� ����� �մϴ�.");

	for (Line* otherLine : *lines)
	{
		if (AreLinesOverlapped(*line, *otherLine))
		{
			otherLine->ConnectedLines.push_back(line);
			line->ConnectedLines.push_back(otherLine);
		}
	}

	if (resistorsOrNull != nullptr)
	{
		for (Resistor* r : *resistorsOrNull)
		{
			if (IsLineOverlappedWithElement(*line, r))
			{
				connectResistorAndLine(r, line);
			}
		}
	}

	if (switchsOrNull != nullptr)
	{
		for (Switch* s : *switchsOrNull)
		{
			if (IsLineOverlappedWithElement(*line, s))
			{
				connectSwitchAndLine(s, line);
			}
		}
	}

	if (voltageSourceOrNull != nullptr)
	{
		if (IsLineOverlappedWithElement(*line, voltageSourceOrNull))
		{
			connectVoltageAndLine(voltageSourceOrNull, line);
		}
	}

	lines->push_back(line);
}

void UCircuitSubsystem::addResistor(Resistor* r, std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const
{

	for (Line* line : *lines)
	{
		if (IsLineOverlappedWithElement(*line, r))
		{
			connectResistorAndLine(r, line);
		}
	}

	resistors->push_back(r);
}

bool UCircuitSubsystem::AreLinesOverlapped(const Line& a, const Line& b) const
{
	return areTwoPointSame(a.From, b.From)
		|| areTwoPointSame(a.From, b.To)
		|| areTwoPointSame(a.To, b.From)
		|| areTwoPointSame(a.To, b.To);
}

bool UCircuitSubsystem::IsLineOverlappedWithElement(const Line& line, const Resistor* elementCellPoint) const
{
	ElementSidePoint sidePoint = getElementSidePoint(elementCellPoint);

	return areTwoPointSame(line.From, sidePoint.Left)
		|| areTwoPointSame(line.From, sidePoint.Right)
		|| areTwoPointSame(line.To, sidePoint.Left)
		|| areTwoPointSame(line.To, sidePoint.Right);
}

bool UCircuitSubsystem::IsLineOverlappedWithElement(const Line& line, const VoltageSource* elementCellPoint) const
{
	ElementSidePoint sidePoint = getElementSidePoint(elementCellPoint);

	return areTwoPointSame(line.From, sidePoint.Left)
		|| areTwoPointSame(line.From, sidePoint.Right)
		|| areTwoPointSame(line.To, sidePoint.Left)
		|| areTwoPointSame(line.To, sidePoint.Right);
}

bool UCircuitSubsystem::IsLineOverlappedWithElement(const Line& line, const Switch* elementCellPoint) const
{
	ElementSidePoint sidePoint = getElementSidePoint(elementCellPoint);

	return areTwoPointSame(line.From, sidePoint.Left)
		|| areTwoPointSame(line.From, sidePoint.Right)
		|| areTwoPointSame(line.To, sidePoint.Left)
		|| areTwoPointSame(line.To, sidePoint.Right);
}

void UCircuitSubsystem::connectResistorAndLine(Resistor* r, Line* line) const
{
	ASSERT(r != nullptr and line != nullptr);
	MASSERT(r->ConnectedLines.size() < 2, "���׿� ������ �ִ� �� �� ������ �� �ֽ��ϴ�.");
	MASSERT(line->ConnectedResistors.size() < 2, "���ο� ������ �ִ� �� �� ������ �� �ֽ��ϴ�.");

	r->ConnectedLines.push_back(line);
	line->ConnectedResistors.push_back(r);
}

void UCircuitSubsystem::connectVoltageAndLine(VoltageSource* voltageSource, Line* line) const
{
	ASSERT(voltageSource != nullptr and line != nullptr);
	MASSERT(voltageSource->ConnectedLines.size() < 2, "���п��� ������ �ִ� �� �� ������ �� �ֽ��ϴ�.");
	MASSERT(line->ConnectedVoltageSource == nullptr, "���ο� ���п��� �̹� ����Ǿ� �ֽ��ϴ�.");

	voltageSource->ConnectedLines.push_back(line);
	line->ConnectedVoltageSource = voltageSource;
}

UCircuitSubsystem::Line* UCircuitSubsystem::mergeLines(Line* a
	, Line* b
	, std::vector<Line*>* lines
	, std::vector<Resistor*>* resistors
	, std::vector<Switch*>* switchs
	, VoltageSource* voltageSourceOrNull) const
{
	ASSERT(a != nullptr
		and b != nullptr
		and lines != nullptr
		and switchs != nullptr
		and resistors != nullptr);

	MASSERT(std::find(a->ConnectedLines.begin(), a->ConnectedLines.end(), b) != a->ConnectedLines.end()
		and std::find(b->ConnectedLines.begin(), b->ConnectedLines.end(), a) != b->ConnectedLines.end()
		, "�� ������ ���� ����Ǿ�� �մϴ�.");
	auto newLine = new Line{};
	if (areTwoPointSame(a->From, b->From))
	{
		newLine->From = a->To;
		newLine->To = b->To;
	}
	else if (areTwoPointSame(a->From, b->To))
	{
		newLine->From = a->To;
		newLine->To = b->From;
	}
	else if (areTwoPointSame(a->To, b->From))
	{
		newLine->From = a->From;
		newLine->To = b->To;
	}
	else if (areTwoPointSame(a->To, b->To))
	{
		newLine->From = a->From;
		newLine->To = b->From;
	}

	removeLine(a, lines);
	removeLine(b, lines);
	addLine(newLine, lines, resistors, switchs, voltageSourceOrNull);

	return newLine;
}

void UCircuitSubsystem::removeLine(Line* line, std::vector<Line*>* lines) const
{
	ASSERT(line != nullptr and lines != nullptr);

	if (line->ConnectedVoltageSource != nullptr)
	{
		disconnectVoltageSource(line, line->ConnectedVoltageSource);
	}

	while (line->ConnectedResistors.size() > 0)
	{
		disconnectResistor(line, line->ConnectedResistors.front());
	}

	while (line->ConnectedSwitchs.size() > 0)
	{
		disconnectSwitch(line, line->ConnectedSwitchs.front());
	}

	// ����� ���ο��� ������ ������ �����ϴ�.
	for (size_t i = 0; i < line->ConnectedLines.size(); ++i)
	{
		Line* connectedLine = line->ConnectedLines[i];

		for (size_t j = 0; j < connectedLine->ConnectedLines.size(); ++j)
		{
			if (connectedLine->ConnectedLines[j] == line)
			{
				std::swap(connectedLine->ConnectedLines[j], connectedLine->ConnectedLines.back());
				connectedLine->ConnectedLines.pop_back();

				break;
			}
		}
	}

	bool bRemoved = false;

	// �迭���� ������ ������ �����մϴ�.
	for (size_t i = 0; i < lines->size(); ++i)
	{
		if ((*lines)[i] != line)
		{
			continue;
		}

		std::swap((*lines)[i], (*lines).back());
		RELEASE(lines->back());
		lines->pop_back();

		bRemoved = true;
		break;
	}
	MASSERT(bRemoved, "�迭�� �����Ϸ��� ������ �����ϴ�.");

}

bool UCircuitSubsystem::IsPointOverlappedWithElementSide(const AActor* point, const Resistor* elementCellPoint) const
{
	ElementSidePoint sidePoint = getElementSidePoint(elementCellPoint);

	return areTwoPointSame(point, sidePoint.Left) or areTwoPointSame(point, sidePoint.Right);
}

void UCircuitSubsystem::connectVoltageSourceToLines(VoltageSource* voltageSource, std::vector<Line*>* lines) const
{
	ASSERT(voltageSource != nullptr and lines != nullptr);
	MASSERT(voltageSource->ConnectedLines.empty(), "����� ������ ����� �մϴ�.");

	for (Line* line : *lines)
	{
		if (IsLineOverlappedWithElement(*line, voltageSource))
		{
			connectVoltageAndLine(voltageSource, line);
		}
	}
}

UCircuitSubsystem::NodeSet UCircuitSubsystem::createTree(const std::vector<Line*>& lines
	, const std::vector<Resistor*>& resistors
	, const std::vector<Switch*>& switchs
	, const VoltageSource* voltageSource
	, Node** outRootNode) const
{
	ASSERT(outRootNode != nullptr);

	NodeSet nodes = {};
	nodes.reserve(lines.size() + 1);

	// ��� ������ �� �� ���� ���� ��ȯ�մϴ�.
	for (const Line* line : lines)
	{
		if (not nodes.contains(line->From))
		{
			nodes.insert({ line->From, new Node{.Point = line->From } });
		}

		if (not nodes.contains(line->To))
		{
			nodes.insert({ line->To, new Node{.Point = line->To } });
		}
	}

	// ��峢�� �����մϴ�.
	{
		for (const Line* line : lines)
		{
			ElementSidePoint voltageSidePoint = getElementSidePoint(voltageSource);

			// ������ ���п��� ���۰� ��ġ�� ��Ʈ ���� ����մϴ�.
			if (areTwoPointSame(line->From, voltageSidePoint.Left)
				or areTwoPointSame(line->To, voltageSidePoint.Left))
			{
				if (areTwoPointSame(line->From, voltageSidePoint.Left))
				{
					*outRootNode = nodes[line->To];
				}
				else
				{
					*outRootNode = nodes[line->From];
				}
			}
			// ��尡 ��ȯ���� �ʵ��� ������ ���п� �� ���� ��ġ�� ��峢�� �������� �ʽ��ϴ�.
			else if (areTwoPointSame(line->From, voltageSidePoint.Right)
				or areTwoPointSame(line->To, voltageSidePoint.Right))
			{
				continue;
			}

			Node* fromNode = nodes[line->From];
			Node* toNode = nodes[line->To];

			fromNode->Neighbors.push_back(toNode);
			toNode->Neighbors.push_back(fromNode);
		}

		for (const Resistor* resistor : resistors)
		{
			ElementSidePoint sidePoint = getElementSidePoint(resistor);
			Node* leftNode = nodes[sidePoint.Left];
			Node* rightNode = nodes[sidePoint.Right];

			if (leftNode == nullptr
				or rightNode == nullptr)
			{
				continue;
			}

			leftNode->Neighbors.push_back(rightNode);
			rightNode->Neighbors.push_back(leftNode);
		}

		for (const Switch* s : switchs)
		{
			ElementSidePoint sidePoint = getElementSidePoint(s);
			Node* leftNode = nodes[sidePoint.Left];
			Node* rightNode = nodes[sidePoint.Right];

			if (leftNode == nullptr
				or rightNode == nullptr)
			{
				continue;
			}

			leftNode->Neighbors.push_back(rightNode);
			rightNode->Neighbors.push_back(leftNode);
		}

		{
			ElementSidePoint sidePoint = getElementSidePoint(voltageSource);
			Node* leftNode = nodes[sidePoint.Left];
			Node* rightNode = nodes[sidePoint.Right];

			if (leftNode != nullptr
				and rightNode != nullptr)
			{
				leftNode->Neighbors.push_back(rightNode);
				rightNode->Neighbors.push_back(leftNode);
			}
		}
	}

	return nodes;
}

void UCircuitSubsystem::traceTree(Node* node
	, const std::vector<Resistor*>& resistors
	, const VoltageSource& voltageSource
	, const NodeSet& nodes
	, std::vector<ParallelResistance>* parallelResistances) const
{
	ASSERT(node != nullptr and parallelResistances != nullptr);
	ASSERT(parallelResistances->empty());

	std::queue<const Node*> bfs = {};
	std::unordered_set<Resistor*> visitedResistor = {};

	bfs.push(node);
	node->Visited = true;
	parallelResistances->push_back({ .ResistanceCount = 0, .ReversedValue = 0.0f });

	while (bfs.size() > 0)
	{
		const Node* node = bfs.front();
		bfs.pop();

		if (node->Neighbors.size() >= 3)
		{
			parallelResistances->emplace_back();
		}

		// �̿��� ���� ���� ������ �����մϴ�.
		// ������, ���İ� ������ �������� ������ �� �������� ���� ó���Ǿ�� �մϴ�.
		std::multimap<size_t, Node*> neighbors = {};
		for (Node* neighbor : node->Neighbors)
		{
			neighbors.insert({ neighbor->Neighbors.size(), neighbor });
		}

		for (auto& neighbor : neighbors)
		{
			Node* neighborNode = neighbor.second;
			if (neighborNode->Visited)
			{
				continue;
			}

			for (Resistor* resistor : resistors)
			{
				if (visitedResistor.contains(resistor)
					or not IsPointOverlappedWithElementSide(neighborNode->Point, resistor))
				{
					continue;
				}

				ParallelResistance& parallelResistance = parallelResistances->back();
				parallelResistance.ReversedValue += 1.0f / resistor->R;
				++parallelResistance.ResistanceCount;

				visitedResistor.insert(resistor);
			}

			bfs.push(neighborNode);
			neighborNode->Visited = true;
		}
	}
}

void UCircuitSubsystem::Reset()
{
	for (Resistor* r : mResistors)
	{
		RELEASE(r);
	}
	mLines.clear();
	for (Line* line : mLines)
	{
		RELEASE(line);
	}
	mResistors.clear();
	for (Switch* s : mSwitchs)
	{
		RELEASE(s);
	}
	mSwitchs.clear();
	RELEASE(mVoltageSource);
}

void UCircuitSubsystem::MakeLine(APartsBase* Part)
{
	auto newLine = new Line
	{
		.From = findNearestPoint(*Part->LeftPoint),
		.To = findNearestPoint(*Part->RightPoint)
	};
	UE_LOG(LogTemp, Log, TEXT("MakeLine: %p, %p, %p"), Part, Part->LeftPoint, Part->RightPoint);

	addLine(newLine, &mLines, &mResistors, &mSwitchs, mVoltageSource);
}

void UCircuitSubsystem::MakeResistors(APartsBase* Part)
{
	auto newResistor = new Resistor
	{
		.LeftPoint = findNearestPoint(*Part->LeftPoint),
		.RightPoint = findNearestPoint(*Part->RightPoint),
		.R = Part->Value
	};
	UE_LOG(LogTemp, Log, TEXT("MakeResistors: %p, %p, %p, %d"), Part, Part->LeftPoint, Part->RightPoint, Part->Value);
	addResistor(newResistor, &mResistors, &mLines);
}

void UCircuitSubsystem::MakeVoltageSource(APartsBase* Part)
{
	mVoltageSource = new VoltageSource
	{
		.LeftPoint = findNearestPoint(*Part->LeftPoint),
		.RightPoint = findNearestPoint(*Part->RightPoint),
		.V = Part->Value
	};
	UE_LOG(LogTemp, Log, TEXT("MakeVoltageSource: %p, %p, %p, %d"), Part, Part->LeftPoint, Part->RightPoint, Part->Value);

	connectVoltageSourceToLines(mVoltageSource, &mLines);
}

void UCircuitSubsystem::MakeSwitch(APartsBase* Part)
{
	auto newSwitch = new Switch
	{
		.LeftPoint = findNearestPoint(*Part->LeftPoint),
		.RightPoint = findNearestPoint(*Part->RightPoint),
		.On = Part->SwitchValue
	};
	addSwitch(newSwitch, &mSwitchs, &mLines);
}

const AActor* UCircuitSubsystem::findNearestPoint(const AActor& p)
{
	for (const AActor* point : mPoints)
	{
		if (areTwoPointSame(point, &p))
		{
			return point;
		}
	}

	mPoints.push_back(&p);
	return &p;
}

void UCircuitSubsystem::connectSwitchAndLine(Switch* s, Line* line) const
{
	ASSERT(s != nullptr and line != nullptr);
	MASSERT(s->ConnectedLines.size() < 2, "����ġ�� ������ �ִ� �� �� ������ �� �ֽ��ϴ�.");
	MASSERT(line->ConnectedResistors.size() < 2, "���ο� ����ġ�� �ִ� �� �� ������ �� �ֽ��ϴ�.");

	s->ConnectedLines.push_back(line);
	line->ConnectedSwitchs.push_back(s);
}

void UCircuitSubsystem::addSwitch(Switch* s, std::vector<Switch*>* switchs, std::vector<Line*>* lines) const
{
	ASSERT(s != nullptr
		and switchs != nullptr
		and lines != nullptr);

	MASSERT(s->ConnectedLines.empty(), "����� ������ ����� �մϴ�.");
	for (Line* line : *lines)
	{
		if (IsLineOverlappedWithElement(*line, s))
		{
			connectSwitchAndLine(s, line);
		}
	}

	switchs->push_back(s);
}

void UCircuitSubsystem::removeSwitch(Switch* s, std::vector<Switch*>* switchs, std::vector<Line*>* lines) const
{
	ASSERT(s != nullptr
		and switchs != nullptr
		and lines != nullptr);

	// ����� ���ο��� ������ ����ġ�� �����ϴ�.
	while (s->ConnectedLines.size() > 0)
	{
		disconnectSwitch(s->ConnectedLines.front(), s);
	}

	bool bRemoved = false;

	// �迭���� �ش� ����ġ�� �����մϴ�.
	for (size_t i = 0; i < switchs->size(); ++i)
	{
		if ((*switchs)[i] == s)
		{
			std::swap((*switchs)[i], (*switchs).back());
			RELEASE(switchs->back());
			(*switchs).pop_back();

			bRemoved = true;
			break;
		}
	}
}

void UCircuitSubsystem::simplifySwitch(std::vector<Switch*>* switchs, std::vector<Line*>* lines) const
{
	ASSERT(switchs != nullptr and lines != nullptr);

	bool bRemoved = false;

	do
	{
		bRemoved = false;

		for (Switch* s : *switchs)
		{
			if (not s->On)
			{
				removeSwitch(s, switchs, lines);
				bRemoved = true;
				break;
			}
		}
	} while (bRemoved);
}

void UCircuitSubsystem::disconnectSwitch(Line* line, Switch* s) const
{
	ASSERT(line != nullptr and s != nullptr);


	bool bDisconnectedLine = false;

	for (size_t j = 0; j < s->ConnectedLines.size(); ++j)
	{
		if (s->ConnectedLines[j] == line)
		{
			std::swap(s->ConnectedLines[j], s->ConnectedLines.back());
			s->ConnectedLines.pop_back();

			bDisconnectedLine = true;
			break;
		}
	}


	bool bDisconnectedSwitch = false;

	for (size_t i = 0; i < line->ConnectedSwitchs.size(); ++i)
	{
		if (line->ConnectedSwitchs[i] == s)
		{
			std::swap(line->ConnectedSwitchs[i], line->ConnectedSwitchs.back());
			line->ConnectedSwitchs.pop_back();

			bDisconnectedSwitch = true;
			break;
		}
	}
}

UCircuitSubsystem::PointOverlapElements UCircuitSubsystem::GetPointOverlapElements(const AActor* point, std::vector<Line*>* lines, std::vector<Resistor*>* resistors, std::vector<Switch*>* switchs, VoltageSource* voltageSource) const
{
	ASSERT(lines != nullptr
		and resistors != nullptr
		and switchs != nullptr
		and voltageSource != nullptr);

	const AActor* pointByAddr = point;
	PointOverlapElements pointOverlapElements = {};

	for (Line* line : *lines)
	{
		if (areTwoPointSame(pointByAddr, line->From)
			or areTwoPointSame(pointByAddr, line->To))
		{
			pointOverlapElements.Lines.push_back(line);
			++pointOverlapElements.OverlapCountSum;
		}
	}

	for (Resistor* resistor : *resistors)
	{
		ElementSidePoint sidePoint = getElementSidePoint(resistor);

		if (areTwoPointSame(pointByAddr, sidePoint.Left)
			or areTwoPointSame(pointByAddr, sidePoint.Right))
		{
			pointOverlapElements.Resistors.push_back(resistor);
			++pointOverlapElements.OverlapCountSum;
		}
	}

	for (Switch* s : *switchs)
	{
		ElementSidePoint sidePoint = getElementSidePoint(s);

		if (areTwoPointSame(pointByAddr, sidePoint.Left)
			or areTwoPointSame(pointByAddr, sidePoint.Right))
		{
			pointOverlapElements.Switchs.push_back(s);
			++pointOverlapElements.OverlapCountSum;
		}
	}

	{
		ElementSidePoint sidePoint = getElementSidePoint(voltageSource);

		if (areTwoPointSame(pointByAddr, sidePoint.Left)
			or areTwoPointSame(pointByAddr, sidePoint.Right))
		{
			pointOverlapElements.VoltageSource = voltageSource;
			++pointOverlapElements.OverlapCountSum;
		}
	}

	return pointOverlapElements;
}


TArray<float> UCircuitSubsystem::RunCircuit()
{
	{
		if (mVoltageSource == nullptr
			or mLines.empty())
		{
			UE_LOG(LogTemp, Warning, TEXT("�߸��� ȸ�� �����Դϴ�. �ٽ� Ȯ���� �ּ���.\n"));
		}
		TArray<float> result;

		std::vector<Line*> lines = {};
		lines.reserve(mLines.size());

		std::vector<Resistor*> resistors = {};
		lines.reserve(mResistors.size());

		std::vector<Switch*> switchs = {};
		switchs.reserve(mSwitchs.size());

		VoltageSource* voltageSource = nullptr;

		// ���� ����, ����, ���п� �迭�� �����ϰ� ����ȭ ��ŵ�ϴ�.
		{
			for (const Line* line : mLines)
			{
				auto newLine = new Line
				{
					.From = line->From,
					.To = line->To,
				};
				addLine(newLine, &lines, nullptr, nullptr, nullptr);
			}

			for (Resistor* r : mResistors)
			{
				auto newR = new Resistor
				{
					.LeftPoint = r->LeftPoint,
					.RightPoint = r->RightPoint,
					.R = r->R
				};
				addResistor(newR, &resistors, &lines);
			}

			for (Switch* s : mSwitchs)
			{
				auto newSwitch = new Switch
				{
					.LeftPoint = s->LeftPoint,
					.RightPoint = s->RightPoint,
					.On = s->On
				};
				addSwitch(newSwitch, &switchs, &lines);
			}

			voltageSource = new VoltageSource
			{
					.LeftPoint = mVoltageSource->LeftPoint,
					.RightPoint = mVoltageSource->RightPoint,
					.V = mVoltageSource->V
			};
			connectVoltageSourceToLines(voltageSource, &lines);
		}

		// ���� �˰����� �����մϴ�.
		{
			while (true)
			{
				size_t previousLineCount = lines.size();
				size_t previousResistorCount = resistors.size();
				size_t previousSwitchCount = switchs.size();

				simplifyLines(&lines, &resistors, &switchs, voltageSource);
				simplifySwitch(&switchs, &lines);
				simplifyLines(&lines, &resistors, &switchs, voltageSource);
				simplifyResistors(&resistors, &lines);

				if (lines.size() != previousLineCount
					or resistors.size() != previousResistorCount
					or switchs.size() != previousSwitchCount)
				{
					continue;
				}
				else
				{
					break;
				}
			}

			UE_LOG(LogTemp, Log, TEXT("l: %lld\n"), lines.size());
			UE_LOG(LogTemp, Log, TEXT("r: %lld\n"), resistors.size());

			Node* rootNode = nullptr;
			auto tree = createTree(lines, resistors, switchs, voltageSource, &rootNode);

			// �ռ������� ���մϴ�.
			float equivalentResistance = 0.0f;
			if (voltageSource->ConnectedLines.size() == 2)
			{
				std::vector<ParallelResistance> parallelResistances = {};
				traceTree(rootNode, resistors, *voltageSource, tree, &parallelResistances);

				for (int level = 0; ParallelResistance r : parallelResistances)
				{
					if (r.ReversedValue <= 0.0f)
					{
						continue;
					}

					UE_LOG(LogTemp, Log, TEXT("R per level(%d): %d %f\n"), level++, r.ResistanceCount, 1.0f / r.ReversedValue);
					//printf("R per level(%d): %d %f\n", level++, r.ResistanceCount, 1.0f / r.ReversedValue);
					equivalentResistance += 1.0f / r.ReversedValue;
				}
			}

			float I = equivalentResistance > 0.0f ? voltageSource->V / equivalentResistance : 0.0f;
			UE_LOG(LogTemp, Log, TEXT("I: %fA\n"), I);
			UE_LOG(LogTemp, Log, TEXT("R: %f��\n"), equivalentResistance);
			UE_LOG(LogTemp, Log, TEXT("V: %fV\n"), I * equivalentResistance);

			//printf("I: %fA\n", I);
			//printf("R: %f��\n", equivalentResistance);
			//printf("V: %fV\n", I * equivalentResistance);

			result.Add(I);
			result.Add(equivalentResistance);
			result.Add(I * equivalentResistance);


			for (auto& node : tree)
			{
				RELEASE(node.second);
			}

			return result;
		}

		// �Ҵ��� �޸𸮸� �����մϴ�.
		{
			for (Line* line : lines)
			{
				RELEASE(line);
			}

			for (Resistor* resistor : resistors)
			{
				RELEASE(resistor);
			}

			for (Switch* s : switchs)
			{
				RELEASE(s);
			}

			RELEASE(voltageSource);
		}
	}
}

void UCircuitSubsystem::UpdateCircuit(TArray<APartsBase*> Parts)
{
	UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));
	UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));
	UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));
	UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));
	UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));
	UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));

	Reset();
	mPoints.clear();

	//UE_LOG(LogTemp, Warning, TEXT("UpdateCircuit"));


	for (APartsBase* Part : Parts)
	{
		UE_LOG(LogTemp, Warning, TEXT("Parts In for"));

		switch (Part->Type)
		{
		case PartsType::Line:
			MakeLine(Part);
			break;
		case PartsType::Resistor:
			MakeResistors(Part);
			break;
		case PartsType::VoltageSource:
			MakeVoltageSource(Part);
			break;
		case PartsType::Switch:
			MakeSwitch(Part);
			break;
		}
	}
}

FString UCircuitSubsystem::OpenFileDialog()
{
	FString DefaultPath = FPaths::ProjectContentDir();
	FString FileTypes = TEXT("ȸ�� ���� (*.circuit)|*.circuit");

	TArray<FString> OutFilenames;
	FString SelectedFile;

	if (FDesktopPlatformModule::Get()->OpenFileDialog(
		nullptr,
		TEXT("Select Circuit"),
		DefaultPath,
		TEXT(""),
		FileTypes,
		EFileDialogFlags::None,
		OutFilenames))
	{
		SelectedFile = OutFilenames[0];
	}

	return SelectedFile;
}

TArray<FResultStruct> UCircuitSubsystem::ImportCircuit()
{
	TArray<FResultStruct> result;

	FString SelectedFile = OpenFileDialog();
	if (SelectedFile.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail to Get File"));
		return result;
	}

	std::string circuitFilename = TCHAR_TO_UTF8(*SelectedFile);
	if (circuitFilename.find(".circuit") == std::string::npos)
	{
		circuitFilename += ".circuit";
	}


	std::ifstream circuit(circuitFilename);
	if (not circuit.is_open())
	{
		UE_LOG(LogTemp, Warning, TEXT("not found circuit file."));
		//printf("������ ã�� �� �����ϴ�.\n");
		return result;
	}

	// ������ �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		size_t lineCount = 0;
		ReadValue(&circuit, &lineCount);
		mLines.reserve(lineCount);
		FResultStruct newR = {};

		for (size_t i = 0; i < lineCount; ++i)
		{

			POINT from = {};
			ReadValue(&circuit, &from.x);
			ReadValue(&circuit, &from.y);

			POINT to = {};
			ReadValue(&circuit, &to.x);
			ReadValue(&circuit, &to.y);

			newR.fromx = from.x;
			newR.fromy = from.y;

			newR.tox = to.x;
			newR.toy = to.y;
			newR.type = PartsType::Line;
			result.Push(newR);
		}
	}

	// ������ �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		size_t resistorCount = 0;
		ReadValue(&circuit, &resistorCount);
		mLines.reserve(resistorCount);
		FResultStruct newR = {};

		for (size_t i = 0; i < resistorCount; ++i)
		{
			POINT cellPoint = {};
			ReadValue(&circuit, &cellPoint.x);
			ReadValue(&circuit, &cellPoint.y);

			int r = 0;
			ReadValue(&circuit, &r);

			newR.fromx = cellPoint.x;
			newR.fromy = cellPoint.y;
			newR.type = PartsType::Resistor;
			newR.value = r;


			result.Push(newR);
		}
	}

	// ����ġ�� �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		size_t switchCount = 0;
		ReadValue(&circuit, &switchCount);
		mLines.reserve(switchCount);
		FResultStruct newR = {};

		for (size_t i = 0; i < switchCount; ++i)
		{
			POINT cellPoint = {};
			ReadValue(&circuit, &cellPoint.x);
			ReadValue(&circuit, &cellPoint.y);

			bool on = false;
			ReadValue(&circuit, &on);

			newR.fromx = cellPoint.x;
			newR.fromy = cellPoint.y;

			newR.type = PartsType::Switch;
			newR.switchValue = on;

			result.Push(newR);
		}
	}

	// ���п��� �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		bool bVoltageSourceExisted = false;
		ReadValue(&circuit, &bVoltageSourceExisted);
		FResultStruct newR = {};

		if (bVoltageSourceExisted)
		{
			POINT cellPoint = {};
			ReadValue(&circuit, &cellPoint.x);
			ReadValue(&circuit, &cellPoint.y);

			int v = 0;
			ReadValue(&circuit, &v);

			newR.fromx = cellPoint.x;
			newR.fromy = cellPoint.y;

			newR.type = PartsType::VoltageSource;
			newR.value = v;

			result.Push(newR);
		}
	}

	return result;
}

TArray<FResultStruct> UCircuitSubsystem::ImportCircuitInFile(FString filename)
{
	TArray<FResultStruct> result;

	FString SaveDir = FPaths::ProjectContentDir();
	SaveDir = FPaths::Combine(SaveDir, TEXT("Problem/"));
	FString FilePath = FPaths::Combine(SaveDir, filename);
	std::string circuitFilename = TCHAR_TO_UTF8(*FilePath);
	//std::string circuitFilename = "1_1.circuit";

	if (circuitFilename.find(".circuit") == std::string::npos)
	{
		circuitFilename += ".circuit";
	}


	std::ifstream circuit(circuitFilename);
	if (not circuit.is_open())
	{
		UE_LOG(LogTemp, Warning, TEXT("not found circuit file."));
		//printf("������ ã�� �� �����ϴ�.\n");
		return result;
	}

	// ������ �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		size_t lineCount = 0;
		ReadValue(&circuit, &lineCount);
		mLines.reserve(lineCount);
		FResultStruct newR = {};

		for (size_t i = 0; i < lineCount; ++i)
		{

			POINT from = {};
			ReadValue(&circuit, &from.x);
			ReadValue(&circuit, &from.y);

			POINT to = {};
			ReadValue(&circuit, &to.x);
			ReadValue(&circuit, &to.y);

			newR.fromx = from.x;
			newR.fromy = from.y;

			newR.tox = to.x;
			newR.toy = to.y;
			newR.type = PartsType::Line;
			result.Push(newR);
		}
	}

	// ������ �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		size_t resistorCount = 0;
		ReadValue(&circuit, &resistorCount);
		mLines.reserve(resistorCount);
		FResultStruct newR = {};

		for (size_t i = 0; i < resistorCount; ++i)
		{
			POINT cellPoint = {};
			ReadValue(&circuit, &cellPoint.x);
			ReadValue(&circuit, &cellPoint.y);

			int r = 0;
			ReadValue(&circuit, &r);

			newR.fromx = cellPoint.x;
			newR.fromy = cellPoint.y;
			newR.type = PartsType::Resistor;
			newR.value = r;


			result.Push(newR);
		}
	}
	 
	// ����ġ�� �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		size_t switchCount = 0;
		ReadValue(&circuit, &switchCount);
		mLines.reserve(switchCount);
		FResultStruct newR = {};

		for (size_t i = 0; i < switchCount; ++i)
		{
			POINT cellPoint = {};
			ReadValue(&circuit, &cellPoint.x);
			ReadValue(&circuit, &cellPoint.y);

			bool on = false;
			ReadValue(&circuit, &on);

			newR.fromx = cellPoint.x;
			newR.fromy = cellPoint.y;

			newR.type = PartsType::Switch;
			newR.switchValue = on;

			result.Push(newR);
		}
	}

	// ���п��� �ҷ� �ɴϴ�.
	{
		int32 offset = 0;
		bool bVoltageSourceExisted = false;
		ReadValue(&circuit, &bVoltageSourceExisted);
		FResultStruct newR = {};

		if (bVoltageSourceExisted)
		{
			POINT cellPoint = {};
			ReadValue(&circuit, &cellPoint.x);
			ReadValue(&circuit, &cellPoint.y);

			int v = 0;
			ReadValue(&circuit, &v);

			newR.fromx = cellPoint.x;
			newR.fromy = cellPoint.y;

			newR.type = PartsType::VoltageSource;
			newR.value = v;


			result.Push(newR);
		}
	}

	return result;
}

FResultStruct::FResultStruct()
{

}

FResultStruct::~FResultStruct()
{

}
