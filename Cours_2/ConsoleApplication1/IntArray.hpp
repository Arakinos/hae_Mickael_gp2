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
};