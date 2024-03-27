#ifndef __STACK_H__
#define __STACK_H__

#include "TDynamicList.h"

const int MAX_STACK_SIZE = 100;

using namespace std;

template<typename T>
class TStack
{
private:
	TDynamicList<T> list;

public:
	TStack(size_t capacity = 6) : list(capacity <= MAX_STACK_SIZE ? capacity : throw out_of_range("Stack size must not exceed the allowed value")) { }

	void push(const T& element)
	{
		if (size() == MAX_STACK_SIZE)
		{
			throw length_error("Stack overflow");
		}
		list.add(element);
	}

	T top()
	{
		if (list.size() == 0)
		{
			throw logic_error("Stack is empty");
		}
		return list[list.size() - 1];
	}

	T pop()
	{
		if (list.size() == 0)
		{
			throw logic_error("Stack is empty");
		}
		T tmp = list[list.size() - 1];

		list.remove(list.size() - 1);
		return tmp;
	}

	bool is_empty() const noexcept(noexcept(list.is_empty()))
	{
		return list.is_empty();
	}

	size_t size() const noexcept(noexcept(list.size()))
	{
		return list.size();
	}
};

#endif