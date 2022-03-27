﻿#include "AObject.h"
#include "AObjectFilter.h"
#include "FilterContainer.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectLevelFilter, "FilterSort.Private.AObjectLevelFilter",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

TArray<UAObject*> MakeObjects()
{
	TArray<UAObject*> Objects;
	
	{
		auto AObject = NewObject<UAObject>();
		AObject->Initialize(1, 2, 3, false);
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(2, 2, 2, false);
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(3, 3, 3, false);
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(4, 4, 4, false);
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(5, 5, 5, true);
		Objects.Emplace(AObject);

		AObject = NewObject<UAObject>();
		AObject->Initialize(1, 1, 1, true);
		Objects.Emplace(AObject);
		
		AObject = NewObject<UAObject>();
		AObject->Initialize(1, 2, 2, true);
		Objects.Emplace(AObject);
		
		AObject = NewObject<UAObject>();
		AObject->Initialize(4, 2, 3, true);
		Objects.Emplace(AObject);

		AObject = NewObject<UAObject>();
		AObject->Initialize(2, 2, 3, true);
		Objects.Emplace(AObject);
	}

	return Objects;
}

bool AObjectLevelFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();
	TArray<UAObject*> ObjectCopy = Objects;

	auto Filters = FilterContainer->GetFilters();
	UFilter* LevelFilter = Cast<UFilter>(Filters[2]);
	UFilterElement* Lv2Filter = Cast<ULevelFilter>(LevelFilter)->GetFilterElements()[2];
	LevelFilter->UpdateFilter(Lv2Filter);

	FilterContainer->ApplyFilter(ObjectCopy);

	TestEqual(TEXT("Filter Result"), ObjectCopy.Num(), 5);

	ObjectCopy = Objects;
	LevelFilter->UpdateFilter(Lv2Filter);
	FilterContainer->ApplyFilter(ObjectCopy);

	TestEqual(TEXT("Filter Result"), ObjectCopy.Num(), Objects.Num());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectStatFilter, "FilterSort.Private.AObjectStatFilter",
								 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool AObjectStatFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();
	TArray<UAObject*> ObjectCopy = Objects;

	auto Filters = FilterContainer->GetFilters();
	UFilter* StatFilter = Cast<UFilter>(Filters[1]);
	UFilterElement* Stat2Filter = Cast<UStatFilter>(StatFilter)->GetFilterElements()[2];
	StatFilter->UpdateFilter(Stat2Filter);

	FilterContainer->ApplyFilter(ObjectCopy);

	TestEqual(TEXT("Filter Result"), ObjectCopy.Num(), 2);

	ObjectCopy = Objects;
	StatFilter->UpdateFilter(Stat2Filter);
	FilterContainer->ApplyFilter(ObjectCopy);

	TestEqual(TEXT("Filter Result"), ObjectCopy.Num(), Objects.Num());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectUsingFilter, "FilterSort.Private.AObjectUsingFilter",
								 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool AObjectUsingFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();
	TArray<UAObject*> ObjectCopy = Objects;

	auto Filters = FilterContainer->GetFilters();
	UFilter* UsingFilter = Cast<UFilter>(Filters[3]);
	UFilterElement* UsingFilterElem = Cast<UAObjectUsingFilter>(UsingFilter)->GetFilterElements()[0];
	UsingFilter->UpdateFilter(UsingFilterElem);

	FilterContainer->ApplyFilter(ObjectCopy);

	TestEqual(TEXT("Filter Result"), ObjectCopy.Num(), 5);

	UsingFilter->UpdateFilter(UsingFilterElem);
	ObjectCopy = Objects;
	FilterContainer->ApplyFilter(ObjectCopy);

	TestEqual(TEXT("Filter Result"), ObjectCopy.Num(), Objects.Num());
	return true;
}

