#pragma once
#include "AObject.h"
#include "FilterInterface.h"

class FLevelFilter final : public TFilterInterface<UAObject>
{
public:
	explicit FLevelFilter(int32 Index, int32 Level)
		: TFilterInterface<UAObject>(Index) ,Level(Level)
	{}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	int32 Level = 0;
};


class FIDFilter final : public TFilterInterface<UAObject>
{
public:
	explicit FIDFilter(int32 Index, int32 ID)
		: TFilterInterface<UAObject>(Index), ID(ID)
	{}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	int32 ID = 0;
};

class FStatFilter final : public TFilterInterface<UAObject>
{
public:
	explicit FStatFilter(int32 Index, int32 Stat)
		: TFilterInterface<UAObject>(Index), Stat(Stat)
	{}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	int32 Stat = 0;
};

class FUsingFilter final : public TFilterInterface<UAObject>
{
public:
	explicit FUsingFilter(int32 Index, bool IsUsing)
		: TFilterInterface<UAObject>(Index), IsUsing(IsUsing)
	{}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	bool IsUsing = false;
};