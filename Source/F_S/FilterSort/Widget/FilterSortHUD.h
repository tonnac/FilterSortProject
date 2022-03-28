// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FilterSortHUD.generated.h"


class UTextBlock;
class UScrollBox;
class UFilterListWidget;
class UAObject;
template <typename T>
struct TFilterContainer;

/**
 * 
 */
UCLASS()
class F_S_API UFilterSortHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFilterListWidget* GetFilterList() const { return FilterList; }
	void Init(const TArray<UAObject*>& Objects, TFilterContainer<UAObject>* FilterContainerArgs);

private:
	void SetAObjectWidget() const;
	void OnUpdateFilter() const;
	
private:
	UPROPERTY()
	TArray<UAObject*> Origin;
	
	TFilterContainer<UAObject>* FilterContainer = nullptr;

	UPROPERTY(EditAnywhere)
	FSoftClassPath ClassPath;
	
	UPROPERTY(meta=(BindWidget))
	UFilterListWidget* FilterList = nullptr;

	UPROPERTY(meta=(BindWidget))
	UScrollBox* ScrollBox = nullptr;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* TextBlock = nullptr;
};
