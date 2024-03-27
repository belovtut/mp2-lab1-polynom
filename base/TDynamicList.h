#ifndef __TDYNAMICLIST_H__
#define __TDYNAMICLIST_H__

template<class T>
class TDynamicList
{
private:
	size_t length;
	size_t memSize;
	T* pMem;

public:
	TDynamicList(size_t capacity = 5) : memSize(capacity > 0 ? capacity : throw invalid_argument("List capacity must be positive")), length(0), pMem(new T[capacity]) { }
	~TDynamicList() { delete[] pMem; }

	size_t size() const { return length; }
	bool is_empty() const { return length == 0; }

	void add(const T& value)
	{
		if (length == memSize)
		{
			memSize *= 2;
			T* tmpMem = new T[memSize];
			std::copy(pMem, pMem + length, tmpMem);
			delete[] pMem;
			pMem = tmpMem;
		}
		pMem[length++] = value;
	}

	void remove(size_t index)
	{
		copy(pMem + index + 1, pMem + length, pMem + index);
		length--;
	}

	T& operator[](const size_t index)
	{
		return pMem[index];
	}
	const T& operator[](const size_t index) const
	{
		return pMem[index];
	}

	TDynamicList& operator=(const TDynamicList& other)
	{
		if (this == &other)
			return *this;

		TDynamicList<T> tmp(other);
		swap(*this, tmp);
		return *this;
	}

	TDynamicList& operator=(TDynamicList&& other) noexcept
	{
		swap(*this, other);
		return *this;
	}

	friend void swap(TDynamicList& lhs, TDynamicList& rhs) noexcept
	{
		swap(lhs.pMem, rhs.pMem);
		swap(lhs.capacity, rhs.capacity);
		swap(lhs.length, rhs.length);
	}
};

#endif