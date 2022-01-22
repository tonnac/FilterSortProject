// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "FilterElementContainer.h"
#include "FilterInterface.h"
#include "Templates/PimplPtr.h"
#include "UObject/Object.h"
#include "LevelFilterElementContainer.generated.h"

class FLevelFilter;
/**
 * 
 */
UCLASS()
class F_S_API ULevelFilterElementContainer : public UFilterElementContainer, public TFilterInterface<UAObject> 
{
	GENERATED_BODY()

public:
	virtual void Initialize() override;
	virtual bool IsEmpty() override;
	virtual bool Is_Satisfied(const UAObject* Data) override;

public:
	TSet<TFilterInterface<UAObject>*> CurrentFilters;

private:
	TArray<TPimplPtr<FLevelFilter>> LevelFilters;
};
