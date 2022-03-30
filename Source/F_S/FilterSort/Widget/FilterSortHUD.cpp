// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/FilterSortHUD.h"

#include "AObjectWidget.h"
#include "FilterContainer.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "UMGEditor/Public/WidgetBlueprint.h"

void UFilterSortHUD::Init(const TArray<UAObject*>& Objects, TFilterContainer<UAObject>* FilterContainerArgs)
{
	Origin = Objects;
	FilterContainer = FilterContainerArgs;
	FilterContainer->GetUpdateFilter().AddUObject(this, &UFilterSortHUD::OnUpdateFilter);
	SetAObjectWidget();	
}

void UFilterSortHUD::SetAObjectWidget() const
{
	static FSoftObjectPath WidgetBlueprintPath { TEXT("WidgetBlueprint'/Game/Maps/Widget/AObjectWidget.AObjectWidget'") };
	const UWidgetBlueprint* WidgetClass = Cast<UWidgetBlueprint>(WidgetBlueprintPath.TryLoad());
	TArray<UAObject*> CopyObjects = Origin;

	FilterContainer->ApplyFilter(CopyObjects);

	ScrollBox->ClearChildren();
	for (UAObject* AObject : CopyObjects)
	{
		if (UAObjectWidget* AObjectWidget = Cast<UAObjectWidget>(CreateWidget(GetWorld(), *WidgetClass->GeneratedClass)))
		{
			AObjectWidget->SetAObject(AObject);
			ScrollBox->AddChild(AObjectWidget);
		}
	}
	TextBlock->SetText(FText::FromString(FString::Printf(TEXT("Object Num: %d"), ScrollBox->GetChildrenCount())));
}

void UFilterSortHUD::OnUpdateFilter() const
{
	SetAObjectWidget();
}
