#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

using namespace std;

template<typename T>
class TLinkedList
{
private:
	struct Node
	{
		T data;
		Node* pNext = nullptr;
	};

	size_t length;
	Node* pFirst, * pLast;

	Node* get_node(int index) const
	{
		Node* node = pFirst;
		for (int i = 0; i < index; i++)
			node = node->pNext;
		return node;
	};

public:
	TLinkedList() : length(0), pFirst(nullptr), pLast(nullptr) {};
	TLinkedList(const TLinkedList& src) : length(src.length), pFirst(nullptr), pLast(nullptr)
	{
		if (!src.pFirst)
		{
			return;
		}

		Node* pNew = pFirst = new Node{ *src.pFirst };
		for (; pNew->pNext != nullptr; pNew = pNew->pNext)
		{
			pNew->pNext = new Node{ *pNew->pNext };
		}
		pLast = pNew;
	};
	~TLinkedList()
	{
		Node* currentNode = pFirst, * tmp;
		while (currentNode)
		{
			tmp = currentNode;
			currentNode = tmp->pNext;
			delete tmp;
		}
	}

	size_t size() const noexcept { return length; };
	bool is_empty() const noexcept { return length == 0; };

	void push_back(const T& element)
	{
		Node* node = new Node{ element };

		if (pFirst == nullptr)
		{
			pFirst = pLast = node;
		}
		else
		{
			pLast->pNext = node;
			pLast = node;
		}

		length++;
	};
	void remove(int index)
	{
		Node* node;
		if (index == 0)
		{
			node = pFirst;
			pFirst = node->pNext;
		}
		else
		{
			Node* prev = get_node(index - 1);
			node = prev->pNext;
			prev->pNext = prev->pNext->pNext;
		}
		delete node;

		length--;
	};

	T& operator[](int index) { return get_node(index)->data; };
	const T& operator[](int index) const { return get_node(index)->data; };

	bool operator==(const TLinkedList& other) const noexcept
	{
		if (this == &other)
			return true;

		if (length != other.length)
			return false;

		Node* lhsNode = pFirst, * rhsNode = other.pFirst;
		while (lhsNode->pNext)
		{
			if (lhsNode->data != rhsNode->data)
				return false;

			lhsNode = lhsNode->pNext;
			rhsNode = rhsNode->pNext;
		}

		return true;
	};
	bool operator!=(const TLinkedList& other) const noexcept { return !(*this == other); };

	TLinkedList& operator=(const TLinkedList& other)
	{
		if (*this != other)
		{
			TLinkedList<T> tmp(other);
			swap(*this, tmp);
		}

		return *this;
	};

	friend void swap(TLinkedList<T>& lhs, TLinkedList<T>& rhs)
	{
		swap(lhs.length, rhs.length);
		swap(lhs.pFirst, rhs.pFirst);
		swap(lhs.pLast, rhs.pLast);
	}

	class Iterator
	{
	private:
		Node* pCurrent;

	public:
		Iterator(Node* node) : pCurrent(node) {}

		Iterator& operator++()
		{
			pCurrent = pCurrent->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		bool operator==(const Iterator& other) const
		{
			return pCurrent == other.pCurrent;
		}

		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}

		T& operator*()
		{
			return pCurrent->data;
		}
	};

	Iterator begin() const
	{
		return Iterator(pFirst);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}
};

#endif
