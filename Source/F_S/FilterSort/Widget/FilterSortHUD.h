// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FilterSortHUD.generated.h"


class USortListWidget;
class UTextBlock;
class UScrollBox;
class UFilterListWidget;
class UAObject;
template <typename T>
class TFilterContainer;
template <typename T>
class TSortContainer;

/**
 * 
 */
UCLASS()
class F_S_API UFilterSortHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init(const TArray<UAObject*>& Objects, TFilterContainer<UAObject>* FilterContainerArgs, TSortContainer<UAObject>* InSortContainer);

private:
	void SetAObjectWidget() const;
	void OnUpdateFilter() const;
	
private:
	UPROPERTY()
	TArray<UAObject*> Origin;
	
	TFilterContainer<UAObject>* FilterContainer = nullptr;
	TSortContainer<UAObject>* SortContainer = nullptr;
	
	UPROPERTY(meta=(BindWidget))
	UFilterListWidget* FilterList = nullptr;

	UPROPERTY(meta=(BindWidget))
	USortListWidget* SortList = nullptr;
	
	UPROPERTY(meta=(BindWidget))
	UScrollBox* ScrollBox = nullptr;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* TextBlock = nullptr;
};
