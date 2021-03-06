// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AObject.generated.h"

/**
 * 
 */
UCLASS()
class F_S_API UAObject : public UObject
{
	GENERATED_BODY()

public:
	void Initialize();
	void Initialize(int32 InID, int32 InLevel, int32 InStat, bool InIsUsing);
	
public:
	UPROPERTY(BlueprintReadOnly)
	mutable int32 ID = 0;

	UPROPERTY(BlueprintReadOnly)
	mutable int32 Level = 0;
	
	UPROPERTY(BlueprintReadOnly)
	mutable int32 Stat = 0;

	UPROPERTY(BlueprintReadOnly)
	mutable bool IsUsing = false;

	UPROPERTY(BlueprintReadOnly)
	mutable bool Option = false;
};