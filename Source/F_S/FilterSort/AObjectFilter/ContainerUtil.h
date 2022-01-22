#pragma once
#include "FilterElementContainer.h"
#include "FilterInterface.h"

class UFilterElementContainer;

// template <typename T>
// class TContainerHasArray
// {
// public:
// 	bool operator()(UFilterElementContainer* FilterElementContainer,  const TSet<TFilterInterface<T>*>& Filters, const T* Data)
// 	{
// 		
// 		if (FilterElementContainer->IsEmpty())
// 		{
// 			return false;
// 		}
//
// 		for (const auto& Filter : Filters)
// 		{
// 			if (Filter->Is_Satisfied(Data))
// 			{
// 				return true;
// 			}
// 		}
//
// 		return false;
// 	}
// };