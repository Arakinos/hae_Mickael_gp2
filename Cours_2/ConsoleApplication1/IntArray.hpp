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
	IntArray(int size,const char * name = "")
	{
		this->name = name;
		Data = new int[16];
		for (int i = 0; i < size; i++)
		{
			Data[i] = 0;
		}
		maxSize = size;
		printf("Construire %s\n",this->name.c_str());
	}
	~IntArray()
	{
		printf("Detruire %s\n",name.c_str());
	}
	void Ensure(int size)
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
	void Push_Front(int Elem)
	{
		Ensure(curSize+1);
		for (int i = curSize; i != 0; i--)
		{
			Data[i] = Data[i-1];
		}
		Data[0] = Elem;
		curSize++;
	}
	void insert(int Pos, int Elem)
	{
		Ensure(curSize + 1);
		for (int i = curSize; i != Pos; i--)
		{
			Data[i] = Data[i - 1];
		}
		Data[Pos] = Elem;
		curSize++;
	}
};