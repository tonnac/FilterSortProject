// Fill out your copyright notice in the Description page of Project Settings.


#include "StatFilter.h"
#include "AObjectFilter.h"

void UStatFilter::Initialize()
{
	for (int32 i = 0; i < 5; ++i)
	{
		if (UAObjectStatFilterElement* NewFilterElement = NewObject<UAObjectStatFilterElement>(this))
		{
			int32 Stat = i + 1;
			NewFilterElement->Initialize(&Stat);
			Filters.Emplace(NewFilterElement);
		}
	}

	// CurrentFilters.Emplace(StatFilters[2].Get());
}
