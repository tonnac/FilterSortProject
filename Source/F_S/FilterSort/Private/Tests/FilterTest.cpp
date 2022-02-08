#include "AObject.h"
#include "AObjectFilter.h"
#include "AObjectUsingFilter.h"
#include "FilterContainer.h"
#include "LevelFilter.h"
#include "StatFilter.h"
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
	TArray<UAObject*> Copy = Objects;

	UFilterElement* Lv2Filter = Cast<ULevelFilter>(FilterContainer.Get()->arrr[1])->Filters[1];
	FilterContainer->UpdateFilter(Lv2Filter);

	const int32 OriginNum = Objects.Num();
	
	Objects.RemoveAll([Filter = FilterContainer.Get()](const UAObject* Object)
	{
		return Filter->operator()(Object);
	});

	TestEqual(TEXT("Filter Result"), Objects.Num(), 4);

	FilterContainer->UpdateFilter(Lv2Filter);

	Copy.RemoveAll([Filter = FilterContainer.Get()](const UAObject* Object)
	{
		return Filter->operator()(Object);
	});

	TestEqual(TEXT("Filter Result"), Copy.Num(), OriginNum);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectStatFilter, "FilterSort.Private.AObjectStatFilter",
								 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool AObjectStatFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();
	TArray<UAObject*> Copy = Objects;

	auto Stat2Filter = Cast<UStatFilter>(FilterContainer.Get()->arrr[0])->Filters[1];
	FilterContainer->UpdateFilter(Stat2Filter);

	const int32 OriginNum = Objects.Num();
	
	Objects.RemoveAll([Filter = FilterContainer.Get()](const UAObject* Object)
	{
		return Filter->operator()(Object);
	});

	TestEqual(TEXT("Filter Result"), Objects.Num(), 7);

	FilterContainer->UpdateFilter(Stat2Filter);

	Copy.RemoveAll([Filter = FilterContainer.Get()](const UAObject* Object)
	{
		return Filter->operator()(Object);
	});

	TestEqual(TEXT("Filter Result"), Copy.Num(), OriginNum);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectUsingFilter, "FilterSort.Private.AObjectUsingFilter",
								 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool AObjectUsingFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();
	TArray<UAObject*> Copy = Objects;

	auto UsingFilter = Cast<UAObjectUsingFilter>(FilterContainer.Get()->arrr[2])->UsingFilter;
	FilterContainer->UpdateFilter(UsingFilter);

	const int32 OriginNum = Objects.Num();
	
	Objects.RemoveAll([Filter = FilterContainer.Get()](const UAObject* Object)
	{
		return Filter->operator()(Object);
	});

	TestEqual(TEXT("Filter Result"), Objects.Num(), 4);

	FilterContainer->UpdateFilter(UsingFilter);

	Copy.RemoveAll([Filter = FilterContainer.Get()](const UAObject* Object)
	{
		return Filter->operator()(Object);
	});

	TestEqual(TEXT("Filter Result"), Copy.Num(), OriginNum);
	return true;
}

