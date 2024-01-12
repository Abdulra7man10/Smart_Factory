#pragma once

template <typename T>
class List
{
public:
	virtual void push_front() {};
	virtual void push_back()  {};
	virtual void push_at(size_t i) {};
	virtual bool pop_front()  { return true; };
	virtual bool pop_back()   { return true; };
	virtual bool pop_at(size_t i) { return true; };
	virtual bool IsEmpty()    { return true; };
	virtual size_t getSize()  { return 0; };
};
