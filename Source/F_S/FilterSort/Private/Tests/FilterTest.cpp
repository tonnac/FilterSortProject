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

	UFilter* LevelFilter = FilterContainer.Get()->Filters[1];
	UFilterElement* Lv2Filter = Cast<ULevelFilter>(FilterContainer.Get()->Filters[1])->Filters[1];
	LevelFilter->UpdateFilter(Lv2Filter);

	const int32 OriginNum = Objects.Num();
	FilterContainer->ApplyFilter(Objects);

	TestEqual(TEXT("Filter Result"), Objects.Num(), 4);

	LevelFilter->UpdateFilter(Lv2Filter);
	FilterContainer->ApplyFilter(Objects);

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

	UFilter* StatFilter = FilterContainer.Get()->Filters[0];
	UFilterElement* Stat2Filter = Cast<UStatFilter>(FilterContainer.Get()->Filters[0])->Filters[1];
	StatFilter->UpdateFilter(Stat2Filter);

	const int32 OriginNum = Objects.Num();
	FilterContainer->ApplyFilter(Objects);

	TestEqual(TEXT("Filter Result"), Objects.Num(), 7);

	StatFilter->UpdateFilter(Stat2Filter);
	FilterContainer->ApplyFilter(Objects);

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

	UFilter* UsingFilter = FilterContainer.Get()->Filters[2];
	UFilterElement* UsingFilterElem = Cast<UAObjectUsingFilter>(FilterContainer.Get()->Filters[2])->Filter;
	UsingFilter->UpdateFilter(UsingFilterElem);

	const int32 OriginNum = Objects.Num();
	FilterContainer->ApplyFilter(Objects);

	TestEqual(TEXT("Filter Result"), Objects.Num(), 4);

	UsingFilter->UpdateFilter(UsingFilterElem);
	FilterContainer->ApplyFilter(Objects);

	TestEqual(TEXT("Filter Result"), Copy.Num(), OriginNum);
	return true;
}

