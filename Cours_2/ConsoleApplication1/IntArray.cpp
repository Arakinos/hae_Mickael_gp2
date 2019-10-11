#include "pch.h"
#include "IntArray.hpp"

int IntArray :: TEST = 66;

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
