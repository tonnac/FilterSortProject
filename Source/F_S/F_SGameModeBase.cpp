// Copyright Epic Games, Inc. All Rights Reserved.


#include "F_SGameModeBase.h"

#include "StatFilterElementContainer.h"

void AF_SGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	const auto StatFilters = NewObject<UStatFilterElementContainer>();
	StatFilters->Initialize();

	TArray<UAObject*> Objects;

	for (int32 i = 0; i < 32; ++i)
	{
		auto AObject = NewObject<UAObject>();
		AObject->Initialize();
		Objects.Emplace(AObject);
	}

	Objects.RemoveAll([StatFilters](const UAObject* Object)
	{
		return StatFilters->Is_Satisfied(Object);
	});

	int32 mn = 53;
}
