#include "AObject.h"
#include "FilterContainer.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FilterTest, "FilterSort.Private.FilterTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FilterTest::RunTest(const FString& Parameters)
{
	
	TUniquePtr<TFilterContainer<UAObject>> ff = MakeUnique<TFilterContainer<UAObject>>(GetTransientPackage());

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

	TestEqual(TEXT("Array Num"), Objects.Num(), 9);

	Objects.RemoveAll([Filter = ff.Get()](const UAObject* Object)
	{
		return Filter->Is_Satisfied(Object);
	});
	
	int32 mn = 53;
	// Make the test pass by returning true, or fail by returning false.
	return true;
}
