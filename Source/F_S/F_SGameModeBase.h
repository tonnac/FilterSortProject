// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "F_SGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class F_S_API AF_SGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


	virtual void BeginPlay() override;
};
