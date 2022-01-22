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
	
public:
	mutable int32 ID = 0;
	mutable int32 Level = 0;
	mutable int32 Stat = 0;
};