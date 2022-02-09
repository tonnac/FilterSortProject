// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "Filter.h"
#include "Templates/PimplPtr.h"
#include "StatFilter.generated.h"

class UFilterElement;
class FStatFilter;
/**
 * 
 */
UCLASS()
class F_S_API UStatFilter : public UFilter
{
	GENERATED_BODY()
	IMPLEMENT_HASCONTAINER_FILTER(UAObject, UStatFilter, 0)
	
public:
	virtual FText GetFilterName() override { return FText::FromString(TEXT("Stat")); }
	virtual void Initialize(const FOnUpdateFilter& _Delegate) override;
public:
	UPROPERTY()
	TArray<UFilterElement*> Filters;
};
