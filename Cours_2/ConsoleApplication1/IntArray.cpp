#include "pch.h"
#include "IntArray.hpp"

int IntArray :: TEST = 66;

IntArray::IntArray(int size, const char * name)
{
	this->name = name;
	Data = new int[16];
	for (int i = 0; i < size; i++)
	{
		Data[i] = NULL;
	}
	maxSize = size;
	printf("Construire %s\n", this->name.c_str());
}

void IntArray::Ensure(int size)
{
	if (size <= maxSize)
	{
		return;
	}
	else
	{
		int* Data2 = new int[size];

		for (int i = 0; i < size; i++)
		{
			if (i < maxSize)
			{
				Data2[i] = Data[i];
			}
			else
			{
				Data2[i] = 0;
			}
		}
		delete(Data);
		Data = Data2;
		maxSize = size;
	}
}

void IntArray::Push_Front(int Elem)
{
	Ensure(curSize + 1);
	for (int i = curSize; i != 0; i--)
	{
		Data[i] = Data[i - 1];
	}
	Data[0] = Elem;
	curSize++;
}

void IntArray::insert(int Pos, int Elem)
{
	if (Pos >= curSize)
	{
		Ensure(Pos + 1);
	}
	else
	{
		Ensure(curSize + 1);
	}
	//ensure((pos>=curSize)?(pos+1):(curSize+1));
	for (int i = curSize; i != Pos; i--)
	{
		Data[i] = Data[i - 1];
	}
	Data[Pos] = Elem;
	if (Pos >= curSize)
	{
		curSize = Pos + 1;
	}
	else
	{
		curSize++;
	}
}

int IntArray::SearchPosition(int Element)
{
	int Alpha = 0;
	for (int i = 0; i <getLenght(); i++)
	{
		if (Element <= Data[i])
		{
			return i;
		}
	}
	return getLenght();
}

void IntArray::RemoveNonTrier(int valeur)
{
	if (valeur < 0) return;
	int pos = -1;
	for (int i = 0; i < getLenght(); i++)
	{
		if (this->Data[i] == valeur)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		return;
	}
	for (int i = pos; i < getLenght(); i++)
	{
		this->Data[i] = this->Data[i + 1];
	}
	curSize--;
}

void IntArray::fillWithRandom(int nbElem) {
	Ensure(nbElem);
	for (int i = 0; i < nbElem; ++i) {
		int val = std::rand()%100;
		SetSafe(i, val);
	}
}

void IntArray::trier()
{
	IntArray Data2(1, "Data2");
	for (int i = 0; i < getLenght(); i++)
	{
		int val = get(i);
		printf("val: %d\n", val);

		int pos = Data2.SearchPosition(val);
		printf("future pos: %d\n", pos);
		Data2.insert(Data2.SearchPosition(val), val);

		printf("[");
		for (int j = 0; j < Data2.getLenght(); j++)
		{
			printf("%d ", Data2[j]);
		}
		printf("]\n");
	}
	/*for (int i = 0; i <= curSize; i++)
	{
		if (i == 0)
		{
			SetSafe(0, Data2[0]);
		}
		else
		{
			SetSafe(SearchPosition(Data2[i]), Data2[i]);
		}
	}*/
	for (int i = 0; i < getLenght(); i++) 
	{
		SetSafe(i, Data2.get(i));
	}
}
