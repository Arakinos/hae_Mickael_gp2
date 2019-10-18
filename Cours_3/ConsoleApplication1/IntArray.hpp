#pragma once
#include <cstdio>
#include <cstdlib>
#include <string>
class IntArray
{
public:
	std::string name;
	static int TEST;
	int* Data;
	int maxSize = 0;
	int curSize = 0;
	IntArray(int size, const char * name = "");
	~IntArray()
	{
		//printf("Detruire %s\n", name.c_str());
	}
	bool Ensure(int size)
	{
		if (size < maxSize) return false;

		int* newdata = new int[size];

		for (int i = 0; i < size; ++i) newdata[i] = 0;
		for (int i = 0; i < curSize; i++)
			newdata[i] = Data[i];

		delete(Data);
		Data = newdata;

		maxSize = size;
		//printf("on passe");
		return true;
	}
	void SetSafe(int Pos, int Element)
	{
		Ensure(Pos+1);
		Data[Pos] = Element;
		curSize = Pos+1;
	}
	void SetUnSafe(int pos, int Element)
	{
		this->Data[pos] = Element;
		curSize = pos + 1;
	}
	void Push_Back(int Elem)
	{
		Ensure(curSize+1);
		Data[curSize] = Elem;
		curSize++;
	}
	void Push_Front(int Elem);
	void insert(int Pos, int Elem);
	int getLenght()
	{
		return curSize;
	}
	int SearchPosition(int Element);
	void removeTrier(int valeur)
	{
		if (Data[SearchPosition(valeur)] == valeur)
		{
			int i = SearchPosition(valeur);
			for (i; i <= getLenght(); i++)
			{
				Data[i] = Data[i + 1];
			}
			curSize--;
		}
	}
	int & operator() (int pos) {
		Ensure(pos + 1);
		if (pos >= curSize) curSize = pos + 1;
		return Data[pos];
	}

	//attention je ne deplace pas le curseur de taille
	int & operator[] (int pos) {
		Ensure(pos + 1);
		if (pos >= curSize) curSize = pos + 1;
		return Data[pos];
	}
	int get(int pos) {
		return Data[pos];
	}
	void RemoveAll()
	{
		for (int i = 0; i < maxSize; i++)
		{
			Data[i] = NULL;
		}
		curSize = 0;
	}
	void RemoveNonTrier(int valeur);
	void fillWithRandom(int nbElem);
	void trier();
	void InsertSort()
	{
		for (int i = 1; i < curSize; i++)
		{
			int j = i;
			while (j > 0 && Data[j] < Data[j - 1])
			{
				swap(j, j-1);
				j--;
			}
		}
	}
	void swap(int pos1, int pos2)
	{
		int tempo1 = Data[pos1];
		Data[pos1] = Data[pos2];
		Data[pos2] = tempo1;
	}
	int BinarySearch(int key)
	{
		return _BinarySearch(key, 0, curSize);
	}
	int BinarySearch2(int key)
	{
		return _BinarySearch2(key, 0, curSize);
	}
	int _BinarySearch(int key, int start, int end)
	{

		if (end <= start)
		{
			return start;
		}
		int pivot = ((end + start) / 2);
		if (Data[pivot] == key)
		{
			return pivot;
		}
		if (Data[pivot - 1] < key && Data[pivot + 1] > key)
		{
			return pivot;
		}
		if (Data[pivot] < key)
		{
			return _BinarySearch(key, pivot, end);
		}
		if (Data[pivot] > key)
		{
			return _BinarySearch(key, start, pivot);
		}

	}
	int _BinarySearch2(int key, int start, int end)
	{

		if (end <= start)
		{
			return start;
		}
		if (end == start + 1)
		{
			if (key > Data[start]) return end;
			if (key < Data[end]) return start;
			return start;
		}
		int pivot = ((end + start) / 2);
		if (Data[pivot] == key)
		{
			return pivot;
		}
		if (Data[pivot] > key)
		{
			return _BinarySearch2(key, start, pivot);
		}
		else
			return _BinarySearch2(key, pivot, end);
	}
};