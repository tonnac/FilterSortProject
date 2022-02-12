// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "Filter.h"
#include "Templates/PimplPtr.h"
#include "LevelFilter.generated.h"

class UFilterElement;
class FLevelFilter;
/**
 * 
 */
UCLASS()
class F_S_API ULevelFilter : public UFilter 
{
	GENERATED_BODY()
	IMPLEMENT_HASCONTAINER_FILTER(UAObject, ULevelFilter, 1)
	
public:
	virtual FText GetFilterName() override { return FText::FromString(TEXT("Level")); };
	virtual void Initialize() override;
};
