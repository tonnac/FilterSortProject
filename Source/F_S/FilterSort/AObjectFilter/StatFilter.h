// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "Filter.h"
#include "Templates/PimplPtr.h"
#include "StatFilter.generated.h"

class FStatFilter;
/**
 * 
 */
UCLASS()
class F_S_API UStatFilter : public UFilter
{
	GENERATED_BODY()
	IMPLEMENT_HASCONTAINER_FILTER(UAObject, UStatFilter)

public:
	virtual void Initialize() override;
private:
	TArray<TPimplPtr<FStatFilter>> StatFilters;
};
