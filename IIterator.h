#pragma once

template <typename T>
class IIterator
{
public:
	virtual IIterator* First() = 0;
	virtual IIterator* Last() = 0;
	virtual IIterator* Next() = 0;
	virtual IIterator* Current() = 0;
	virtual T CurrentData() = 0;
	virtual bool IsEnd() = 0;
};