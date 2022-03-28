// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AObjectWidget.generated.h"

class UAObject;
/**
 * 
 */
UCLASS()
class F_S_API UAObjectWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetAObject(UAObject* AObject);
	
};
