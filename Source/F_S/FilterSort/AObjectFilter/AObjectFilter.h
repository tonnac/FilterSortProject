#pragma once
#include "CoreMinimal.h"
#include "AObject.h"
#include "Filter.h"
#include "AObjectFilter.generated.h"

UCLASS()
class F_S_API UStatFilter : public UFilter
{
	GENERATED_BODY()
	IMPLEMENT_COMMON_PROPERTY(UAObject, 1)
	
public:
	virtual FText GetFilterName() override { return FText::FromString(TEXT("Stat")); }
	virtual void Initialize() override;
};

UCLASS()
class F_S_API ULevelFilter : public UFilter 
{
	GENERATED_BODY()
	IMPLEMENT_COMMON_PROPERTY(UAObject, 2)

public:
	virtual FText GetFilterName() override { return FText::FromString(TEXT("Level")); };
	virtual void Initialize() override;
};

UCLASS()
class F_S_API UAObjectUsingFilter : public UFilter
{
	GENERATED_BODY()
	IMPLEMENT_COMMON_PROPERTY(UAObject, 3)
	
public:
	virtual void Initialize() override;
	virtual FText GetFilterName() override { return FText::FromString(TEXT("UsingFilter")); }
};

UCLASS()
class F_S_API UAObjectOptionFilter : public UOptionFilter
{
	GENERATED_BODY()
	IMPLEMENT_COMMON_PROPERTY(UAObject, 0)
	
public:
	virtual void Initialize() override;
	virtual FText GetFilterName() override { return FText::FromString(TEXT("Option")); }
};