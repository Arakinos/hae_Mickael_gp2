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
		printf("Detruire %s\n",name.c_str());
	}
	void Ensure(int size);
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
	void fillWithRandom(int nbElem); // Test PushGit
	void trier();
};