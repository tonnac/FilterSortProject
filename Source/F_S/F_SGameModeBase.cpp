// Copyright Epic Games, Inc. All Rights Reserved.


#include "F_SGameModeBase.h"

#include "FilterContainer.h"
#include "AObject.h"
#include "Blueprint/UserWidget.h"
#include "Widget/FilterListWidget.h"
#include "Widget/FilterSortHUD.h"

AF_SGameModeBase::AF_SGameModeBase() = default;
AF_SGameModeBase::~AF_SGameModeBase() = default;

AF_SGameModeBase::AF_SGameModeBase(FVTableHelper& Helper)
{
}

void AF_SGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetGameInstance());

	if (FilterContainer)
	{
		if (UFilterSortHUD* FilterSortHUD = Cast<UFilterSortHUD>(CreateWidget(GetGameInstance(), FilterSortHUDClass, TEXT("HUD"))))
		{
			FilterSortHUD->AddToViewport(0);
			FilterSortHUD->GetFilterList()->SetFilter(FilterContainer.Get());
			const TArray<UAObject*> Objects = MakeObjects();
			FilterSortHUD->Init(Objects, FilterContainer.Get());
		}
	}
}

TArray<UAObject*> AF_SGameModeBase::MakeObjects()
{
	TArray<UAObject*> Objects;

	for (int32 i = 0; i < 50; ++i)
	{
		if (UAObject* AObject = NewObject<UAObject>(this))
		{
			AObject->Initialize();
			Objects.Emplace(AObject);
		}
	}

	return Objects;
}
