// Fill out your copyright notice in the Description page of Project Settings.


#include "StatFilter.h"
#include "AObjectFilter.h"

void UStatFilter::Initialize()
{
	for (int32 i = 0; i < 5; ++i)
	{
		StatFilters.Emplace(MakePimpl<FStatFilter>(GetIndex(), i + 1));
	}

	// CurrentFilters.Emplace(StatFilters[2].Get());
}