// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelFilterElementContainer.h"

#include "AObjectFilter.h"

void ULevelFilterElementContainer::Initialize()
{
	Super::Initialize();
	for (int32 i = 0; i < 5; ++i)
	{
		LevelFilters.Emplace(MakePimpl<FLevelFilter>(i));
	}

	CurrentFilters.Emplace(LevelFilters[2].Get());
	CurrentFilters.Emplace(LevelFilters[3].Get());
}

bool ULevelFilterElementContainer::IsEmpty()
{
	return CurrentFilters.Num() == 0;
}

bool ULevelFilterElementContainer::Is_Satisfied(const UAObject* Data)
{
	return Is_Satisfied_Internal(this, Data);
}
