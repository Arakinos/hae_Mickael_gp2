#pragma once


template<typename Type>
class List {
public:
	Type  elem;
	List<Type>* next = nullptr;

	List(const Type & elem)
	{
		this->elem = elem;
	};
	int Length()
	{
		if (next == nullptr) return 1;
		return 1+next->Length();
	}
	List<Type>* Append(const Type & elem)
	{
		if (next == nullptr) next = new List(elem);
		else
		{
			return next->Append(elem);
		}
	}

	List<Type>* ConCat(const Type & elem)
	{
		auto toto = new List(elem);
		toto->next = this;
		return toto;
	}
	List<Type>* Remove(const Type & removeme)
	{
		if (this->elem == removeme)
		{
			auto suitedeliste = next;
			this->next = nullptr;
			delete this;
			if (suitedeliste != nullptr)
			{
				return suitedeliste->Remove(removeme);
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			if (next)
			{
				next = next->Remove(removeme);
			}
			return this;
		}
	}
	bool Contains(const Type & elemAtrouver)
	{
		if (next == nullptr) return false;
		if (elem == elemAtrouver) return true;
		else return next->Contains(elemAtrouver);
	}
};

typedef List<int> IntList;