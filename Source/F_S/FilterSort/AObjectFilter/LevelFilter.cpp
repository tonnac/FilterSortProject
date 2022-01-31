// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelFilter.h"
#include "AObjectFilter.h"

void ULevelFilter::Initialize()
{
	for (int32 i = 0; i < 5; ++i)
	{
		LevelFilters.Emplace(MakePimpl<FLevelFilter>(GetIndex(), i + 1));
	}

	// CurrentFilters.Emplace(LevelFilters[2].Get());
	// CurrentFilters.Emplace(LevelFilters[3].Get());
}