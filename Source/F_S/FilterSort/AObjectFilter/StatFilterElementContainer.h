// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "FilterElementContainer.h"
#include "FilterInterface.h"
#include "UObject/Object.h"
#include "StatFilterElementContainer.generated.h"

class FStatFilter;
/**
 * 
 */
UCLASS()
class F_S_API UStatFilterElementContainer : public UFilterElementContainer, public TFilterInterface<UAObject>
{
	GENERATED_BODY()

	UStatFilterElementContainer();
	~UStatFilterElementContainer();
	UStatFilterElementContainer(FVTableHelper& Helper);
	
public:
	virtual void Initialize() override;
	virtual bool IsEmpty() override;
	virtual bool Is_Satisfied(const UAObject* Data) override;

public:
	TSet<TFilterInterface<UAObject>*> CurrentFilters;
	
private:
	TArray<TUniquePtr<FStatFilter>> StatFilters;
};
