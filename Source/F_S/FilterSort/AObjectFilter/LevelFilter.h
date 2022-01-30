// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "Filter.h"
#include "Templates/PimplPtr.h"
#include "LevelFilter.generated.h"

class FLevelFilter;
/**
 * 
 */
UCLASS()
class F_S_API ULevelFilter : public UFilter 
{
	GENERATED_BODY()
	IMPLEMENT_HASCONTAINER_FILTER(UAObject, ULevelFilter)
	
public:
	virtual void Initialize() override;
private:
	TArray<TPimplPtr<FLevelFilter>> LevelFilters;
};
