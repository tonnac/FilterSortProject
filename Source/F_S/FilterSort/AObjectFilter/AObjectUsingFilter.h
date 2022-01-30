// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "Filter.h"
#include "Templates/PimplPtr.h"
#include "AObjectUsingFilter.generated.h"

class FUsingFilter;
/**
 * 
 */
UCLASS()
class F_S_API UAObjectUsingFilter : public UFilter
{
	GENERATED_BODY()
	IMPLEMENT_HASNOTCONTAINER_FILTER(UAObject, UAObjectUsingFilter)

public:
	virtual void Initialize() override;
private:
	TPimplPtr<FUsingFilter> UsingFilter;
};
