// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Misc/Guid.h"
#include "PartsBase.h"
#include <unordered_map>
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include <fstream>
#include "CircuitSubsystem.generated.h"


#ifndef RELEASE
#define RELEASE(x) \
	if ((x) != nullptr) \
	{ \
		delete (x); \
		(x) = nullptr; \
	} \
	((void)0)
#endif

#if !defined(ASSERT)
#define ASSERT(expr) \
	if (!(expr)) \
	{ \
		UE_LOG(LogTemp, Warning, TEXT("%s, %s(%d)\n"), *FString(#expr), *FString(__FILE__), __LINE__); \
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false); \
	} \
	((void)0)
#endif

#if !defined(MASSERT)
#define MASSERT(expr, msg) \
	if (!(expr)) \
	{ \
		UE_LOG(LogTemp, Warning, TEXT("%s, %s, %s(%d)\n"), (msg), *FString(#expr), *FString(__FILE__), __LINE__); \
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false); \
	} \
	((void)0)
#endif


USTRUCT(BlueprintType)
struct FResultStruct
{
	GENERATED_USTRUCT_BODY()
public:
	FResultStruct();
	~FResultStruct();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int fromx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int fromy;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int tox;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int toy;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int value;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool switchValue;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	PartsType type;
};


/**
 * 
 */
UCLASS(Blueprintable)
class EHPROJECT_API UCircuitSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
private:
	struct Line;

	struct VoltageSource
	{
		const AActor* LeftPoint;
		const AActor* RightPoint;

		std::vector<Line*> ConnectedLines; // 최대 두 개를 가진다.
		int V;
		FGuid UniqueID;
	};

	struct Resistor
	{
		const AActor* LeftPoint;
		const AActor* RightPoint;
		std::vector<Line*> ConnectedLines; // 최대 두 개를 가진다.
		int R;
		FGuid UniqueID;
	};

	struct Switch
	{
		const AActor* LeftPoint;
		const AActor* RightPoint;
		std::vector<Line*> ConnectedLines; // 최대 두 개를 가진다.
		bool On;
	};

	struct Line
	{
		const AActor* From;
		const AActor* To;

		std::vector<Line*> ConnectedLines;
		std::vector<Resistor*> ConnectedResistors; // 최대 두 개를 가진다.
		std::vector<Switch*> ConnectedSwitchs; // 최대 두 개를 가진다.
		VoltageSource* ConnectedVoltageSource;
		FGuid UniqueID;
	};

	struct PointOverlapElements
	{
		std::vector<Line*> Lines;
		std::vector<Resistor*> Resistors;
		std::vector<Switch*> Switchs;
		VoltageSource* VoltageSource;
		int OverlapCountSum;
	};

	struct Node
	{
		const AActor* Point;
		std::vector<Node*> Neighbors;
		bool Visited;
	};

	struct ElementSidePoint
	{
		const AActor* Left;
		const AActor* Right;
	};

	struct ParallelResistance
	{
		int ResistanceCount;
		float ReversedValue;
	};

public:
	struct POINT
	{
		LONG x;
		LONG y;
	};


private:

	VoltageSource* mVoltageSource = nullptr;
	std::vector<Line*> mLines = {};
	std::vector<Resistor*> mResistors = {};
	std::vector<Switch*> mSwitchs = {};

	// 언리얼에서만 사용됨.
	std::vector<const AActor*> mPoints = {};

private:
	void simplifyLines(std::vector<Line*>* lines
		, std::vector<Resistor*>* resistors
		, std::vector<Switch*>* switchs
		, VoltageSource* voltageSource) const;

	bool areTwoPointSame(const AActor* a, const AActor* b) const;
	void simplifyResistors(std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const;
	void mergeSeriesResistance(Resistor* a, Resistor* b, std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const;
	ElementSidePoint getElementSidePoint(const Resistor* elementCellPoint) const;
	ElementSidePoint getElementSidePoint(const VoltageSource* elementCellPoint) const;
	ElementSidePoint getElementSidePoint(const Switch* elementCellPoint) const;

	void removeResistor(Resistor* resistor, std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const;
	void disconnectResistor(Line* line, Resistor* resistor) const;
	void disconnectVoltageSource(Line* line, VoltageSource* voltageSource) const;

	void addLine(Line* line, std::vector<Line*>* lines
		, std::vector<Resistor*>* resistorsOrNull
		, std::vector<Switch*>* switchsOrNull
		, VoltageSource* voltageSourceOrNull) const;
	void addResistor(Resistor* r, std::vector<Resistor*>* resistors, std::vector<Line*>* lines) const;

	bool AreLinesOverlapped(const Line& a, const Line& b) const;
	bool IsLineOverlappedWithElement(const Line& line, const Resistor* elementCellPoint) const;
	bool IsLineOverlappedWithElement(const Line& line, const VoltageSource* elementCellPoint) const;
	bool IsLineOverlappedWithElement(const Line& line, const Switch* elementCellPoint) const;

	void connectResistorAndLine(Resistor* r, Line* line) const;
	void connectVoltageAndLine(VoltageSource* voltageSource, Line* line) const;
	Line* mergeLines(Line* a
		, Line* b
		, std::vector<Line*>* lines
		, std::vector<Resistor*>* resistors
		, std::vector<Switch*>* switchs
		, VoltageSource* voltageSourceOrNull) const;  // 이어진 두 라인을 하나의 라인으로 병합합니다.
	void removeLine(Line* line, std::vector<Line*>* lines) const;
	bool IsPointOverlappedWithElementSide(const AActor* point, const Resistor* elementCellPoint) const;
	void connectVoltageSourceToLines(VoltageSource* voltageSource, std::vector<Line*>* lines) const;

	using NodeSet = std::unordered_map<const AActor*, Node*>;

	NodeSet createTree(const std::vector<Line*>& lines
		, const std::vector<Resistor*>& resistors
		, const std::vector<Switch*>& switchs
		, const VoltageSource* voltageSource
		, Node** outRootNode) const;

	void traceTree(Node* node
		, const std::vector<Resistor*>& resistors
		, const VoltageSource& voltageSource
		, const NodeSet& nodes
		, std::vector<ParallelResistance>* parallelResistances) const;

	void Reset();
	void MakeLine(APartsBase* Part);
	void MakeResistors(APartsBase* Part);
	void MakeVoltageSource(APartsBase* Part);
	void MakeSwitch(APartsBase* Part);
	const AActor* findNearestPoint(const AActor& p);

	void connectSwitchAndLine(Switch* s, Line* line) const;

	void addSwitch(Switch* s, std::vector<Switch*>* switchs, std::vector<Line*>* lines) const;
	void removeSwitch(Switch* s, std::vector<Switch*>* switchs, std::vector<Line*>* lines) const;
	void simplifySwitch(std::vector<Switch*>* switchs, std::vector<Line*>* lines) const;
	void disconnectSwitch(Line* line, Switch* s) const;

	PointOverlapElements GetPointOverlapElements(const AActor* point
		, std::vector<Line*>* lines
		, std::vector<Resistor*>* resistors
		, std::vector<Switch*>* switchs
		, VoltageSource* voltageSource) const;


	FString OpenFileDialog();

	template <typename T>
	void ReadValue(std::ifstream* file, T* outValues, const size_t count = 1)
	{
		ASSERT(file != nullptr and outValues != nullptr);
		file->read(reinterpret_cast<char*>(outValues), static_cast<std::streamsize>(sizeof(T)) * count);
	}

public:
	UFUNCTION(BlueprintCallable)
	TArray<float> RunCircuit();
	UFUNCTION(BlueprintCallable)
	void UpdateCircuit(TArray<APartsBase*> Parts);




	//---------------------------파일 입력-----------------------------

	UFUNCTION(BlueprintCallable)
	TArray<FResultStruct> ImportCircuit();

	UFUNCTION(BlueprintCallable)
	TArray<FResultStruct> ImportCircuitInFile(FString filename);
};

