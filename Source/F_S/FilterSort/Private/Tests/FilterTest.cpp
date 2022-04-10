#include "AObject.h"
#include "AObjectFilter.h"
#include "Filter/FilterContainer.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectLevelFilter, "FilterSort.Private.AObjectLevelFilter",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

TArray<UAObject*> MakeObjects()
{
	TArray<UAObject*> Objects;
	
	{
		auto AObject = NewObject<UAObject>();
		AObject->Initialize(1, 2, 3, false);
		AObject->Option = true;
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(2, 2, 2, false);
		AObject->Option = true;
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(3, 3, 3, false);
		AObject->Option = true;
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(4, 4, 4, false);
		AObject->Option = true;
		Objects.Emplace(AObject);
	
		AObject = NewObject<UAObject>();
		AObject->Initialize(5, 5, 5, true);
		AObject->Option = true;
		Objects.Emplace(AObject);

		AObject = NewObject<UAObject>();
		AObject->Initialize(1, 1, 1, true);
		AObject->Option = true;
		Objects.Emplace(AObject);
		
		AObject = NewObject<UAObject>();
		AObject->Initialize(1, 2, 2, true);
		AObject->Option = false;
		Objects.Emplace(AObject);
		
		AObject = NewObject<UAObject>();
		AObject->Initialize(4, 2, 3, true);
		AObject->Option = false;
		Objects.Emplace(AObject);

		AObject = NewObject<UAObject>();
		AObject->Initialize(2, 2, 3, true);
		AObject->Option = false;
		Objects.Emplace(AObject);
	}

	return Objects;
}

class FTestFilter
{
public:
	FTestFilter(UFilter* Filter, UFilterElement* FilterElement, TArray<UAObject*>& Objects,
		TFilterContainer<UAObject>* FilterContainer)
		: Filter(Filter),
		  FilterElement(FilterElement),
		  Objects(Objects),
		  OriginObjects(Objects),
	      FilterContainer(FilterContainer)
	{
	}

	void ApplyFilter()
	{
		Objects = OriginObjects;
		Filter->UpdateFilter(FilterElement);
		FilterContainer->ApplyFilter(Objects);
	}

private:
	UFilter* Filter = nullptr;
	UFilterElement* FilterElement = nullptr;
	TArray<UAObject*>& Objects;
	TArray<UAObject*> OriginObjects;
	TFilterContainer<UAObject>* FilterContainer;
};

void TestFilter(UFilter* Filter, UFilterElement* FilterElement, TArray<UAObject*>& Objects)
{
	Filter->UpdateFilter(FilterElement);
	
}

bool AObjectLevelFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();

	auto Filters = FilterContainer->GetFilters();
	UFilter* LevelFilter = Cast<UFilter>(Filters[2]);
	UFilterElement* Lv2Filter = Cast<ULevelFilter>(LevelFilter)->GetFilterElements()[2];
	
	FTestFilter TestFilter { LevelFilter, Lv2Filter, Objects, FilterContainer.Get() };
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), 5);
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), Objects.Num());
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

	FTestFilter TestFilter { StatFilter, Stat2Filter, Objects, FilterContainer.Get() };
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), 2);
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), Objects.Num());
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

	FTestFilter TestFilter { UsingFilter, UsingFilterElem, Objects, FilterContainer.Get() };
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), 5);
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), Objects.Num());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(AObjectOptionFilter, "FilterSort.Private.AObjectOptionFilter",
								 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool AObjectOptionFilter::RunTest(const FString& Parameters)
{
	const TUniquePtr<TFilterContainer<UAObject>> FilterContainer = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());
	TArray<UAObject*> Objects = MakeObjects();
	TArray<UAObject*> ObjectCopy = Objects;

	auto Filters = FilterContainer->GetOptionFilters();
	UFilter* OptionFilter = Cast<UFilter>(Filters[0]);
	UFilterElement* OptionFilterElem = Cast<UAObjectOptionFilter>(OptionFilter)->GetFilterElements()[0];

	FTestFilter TestFilter { OptionFilter, OptionFilterElem, Objects, FilterContainer.Get() };
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), 6);
	TestFilter.ApplyFilter();
	TestEqual(TEXT("Filter Result"), Objects.Num(), Objects.Num());
	return true;
}