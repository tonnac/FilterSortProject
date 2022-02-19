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
		}
	}
}
