// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "F_SGameModeBase.generated.h"

class UAObject;
template <typename T>
class TFilterContainer;

/**
 * 
 */
UCLASS()
class F_S_API AF_SGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AF_SGameModeBase();
	virtual ~AF_SGameModeBase() override;
	AF_SGameModeBase(FVTableHelper& Helper);
	
private:
	virtual void BeginPlay() override;

private:
	TArray<UAObject*> MakeObjects();

private:
	TUniquePtr<TFilterContainer<UAObject>> FilterContainer;  
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> FilterSortHUDClass;
};
