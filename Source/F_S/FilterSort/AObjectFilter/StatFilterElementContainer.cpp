// Fill out your copyright notice in the Description page of Project Settings.


#include "StatFilterElementContainer.h"
#include "ContainerUtil.h"
#include "AObjectFilter.h"

UStatFilterElementContainer::UStatFilterElementContainer() = default;
UStatFilterElementContainer::~UStatFilterElementContainer() = default;

UStatFilterElementContainer::UStatFilterElementContainer(FVTableHelper& Helper)
	: Super(Helper)
{
}

void UStatFilterElementContainer::Initialize()
{
	Super::Initialize();

	for (int32 i = 0; i < 5; ++i)
	{
		StatFilters.Emplace(MakeUnique<FStatFilter>(i));
	}

	CurrentFilters.Emplace(StatFilters[2].Get());
}

bool UStatFilterElementContainer::IsEmpty()
{
	return CurrentFilters.Num() == 0;
}

bool UStatFilterElementContainer::Is_Satisfied(const UAObject* Data)
{
	return Is_Satisfied_Internal(this, Data);
}
