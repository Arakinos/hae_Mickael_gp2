// Cours1App.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>

static void TestRec();

 /*int Memcpy(char * dest, char * src, int size)
{
	int i = 0;
	for (i; i != size; i++)
	{
		dest[i] = src[i];
	}
	dest[i + 1] = 0;
	return 0;
}
 int Memcpy2(char * dest, char * src, int size)
 {
	 int i = 0;
	 while (i != size)
	 {
		 dest[i] = src[i];
		 i++;
	 }
	 dest[i] = 0;
	 return 0;
 }
 int StrChr(char * grg, char Chat)
 {
	 for (int i = 0; i < strlen(grg); i++)
	 {
		 if (grg[i] == Chat)
		 {
			 return(i);
		 }
	 }
	 return(-1);
 }
 int StrChr2(char * grg, char Chat)
 {
	 char * oldGrange = grg;
	 while (*grg)
	 {
		 if (*grg == Chat)
		 {
			 return ((int)(grg-oldGrange));
		 }
		 grg++;
	 }
	 return(-1);
 }
 int StrChr3(char * grg, char Chat)
 {
	 int counter = 0;
	 while (grg[counter] != 0)
	 {
		 if (grg[counter] == Chat)
		 {
			 return counter;
		 }
		 counter++;
	 }
	 return-1;
 }
 char * strstr2(char * MeuleDeFoin, char* Aiguille)
 {
	 for (int i = 0; i < strlen(MeuleDeFoin); i++)
	 {
		 if (MeuleDeFoin[i] == Aiguille[0])
		 {
			 for (int y = 0; y < strlen(Aiguille); y++)
			 {
				 int test = strlen(Aiguille);
				 if (MeuleDeFoin[i + y] == Aiguille[y])
				 {
					 continue;
				 }
				 if (y == test - 1)
				 {
					 return 0 ;
				 }
			 }
		 }
	 }
	 return NULL;
 }
 char * StrStr2(char*MeuleDeFoin, char*aiguille)
 {
	 int lenMeul = strlen(MeuleDeFoin);
	 int lenAiguille = strlen(aiguille);

	 for (int i = 0; i < lenMeul; i++)
	 {
		 bool found = true;
		 for (int j = 0; j < lenAiguille; ++j)
		 {
			 if (MeuleDeFoin[j] != aiguille[j])
			 {
				 found = false;
				 break;
			 }
		 }
		 if (found)
		 {
			 return MeuleDeFoin;
		 }
		 MeuleDeFoin++;
	 }
	 return nullptr;
 }
 int Max(int a, int b)
 {
	 return(a < b ? a : b);
 }
 int Min(int a, int b)
 {
	 return (a < b ? b : a);
 }
 int Strcmp(char * meule, char * Aiguille)
 {
	 int LenMeul = strlen(meule);
	 int AigLeng = strlen(Aiguille);

	 int MaxLen = Max(LenMeul, AigLeng);
	 int Minlen = Min(LenMeul, AigLeng);

	 for (int i = 0; i < Minlen; i++)
	 {
		 if(meule[i]<Aiguille[i])
			 {
				 return-1;
			 }
		 else if (meule[i] > Aiguille[i])
		 {
			 return 1;
		 }
	 }
	 if (Minlen == MaxLen)
	 {
		 return 0;
	 }
	 if (MaxLen == LenMeul)
	 {
		 return 1;
	 }
	 return -1;
 }*/



int main()
{
    /*std::cout << "Hello World!\n";
	char Licorne[32] = "Licorne";
	char Vomi[32] = "Vomi";
	char Chat = 'C';
	char Grange[32] = "Vive le Chat est très mignon";
	//Memcpy(Licorne, Vomi, strlen(Licorne+1));
	Memcpy2(Licorne, Vomi, strlen(Licorne+1));
	printf("Licorne = %s\n ", Licorne);
	printf("position Chat = %d\n", StrChr2(Grange, Chat));
	char Alpha[32] = "Licorne";
	char beta[32] = "Lico";
	printf("case 1 = %d\n", Strcmp(Alpha,beta));
	char Alpha1[32] = "Licorne";
	char beta1[32] = "Licorne noire";
	printf("case 1 = %d\n", Strcmp(Alpha1, beta1));
	char Alpha2[32] = "Licorne";
	char beta2[32] = "Licorne";
	printf("case 1 = %d\n", Strcmp(Alpha2, beta2));
	char text[32] = "Lorem ipsum dolor sit amet";
	char token[1024] = "dolor";
	char * tokeninText = StrStr2(text, token);
	int pos = (int)(tokeninText - text);
	printf("lorem = %s\n", tokeninText);
	printf("Le token est en position %d\n", pos);*/
	TestRec();
}
int Add(int a, int b)
{
	int i = 0;
	for (i = 0; i < a + b; ++i)
	{
		return i;
	}
}
int Add_1(int a, int b)
{
	int val = a;
	for (int i = 0; i < b; ++i)
	{
		val++;
	}
	return val;
}
int Add_2(int a, int b)
{
	printf("A = %d\n B = %d\n", a, b);
	if (a == 0)
	{
		return b;
	}
	else
	{	
		return Add_2(a - 1, b + 1);
	}
}
int Add_3(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;
	}
	else
	{
		printf("A = %d\n", a);
		printf("B = %d\n", b);
		return 1 + Add_3(a - 1, b);
	}
}
int Sub(int a, int b)
{
	printf("A:%i B:%i\n", a, b);
	if (b == 0)
	{
		return a;
	}
	else if (b>0)
	{
		return(Sub(a - 1, b - 1));
	}
	else if (b < 0)
	{
		return(Sub(a + 1, b + 1));
	}
}
int Mul(int a, int b)
{
	if (a == 0)
	{
		return 0;
	}
	if (b == 0)
	{
		return 0;
	}
	if (a == 1)
	{
		return b;
	}
	if (b == 1)
		return a;
	if (b > 0)
	{
		return a + Mul(a, b - 1);
	}
	if (b < 0)
	{
		return -Mul(a, -b);
	}
}
int Divid(int a, int b)
{
	printf("A= %i B = %i\n", a, b);
	if(a == 0)
	{
		return 0;
	}
	if (a<b)
	{
		return 0;
	}
	if (b < 0)
	{
		return -Divid(a, -b);
	}
	else if (b>0)
	{
		return 1 + Divid(a - b, b);
	}
	else if (a < 0)
	{
		return -Divid(-a, b);
	}
}
int Modulo(int a, int b)
{
	return a - Mul(b, Divid(a, b));
}
void TestRec()
{
	int i = 0;
	printf("5+6 = %d\n",Add_2(5,6));
	int a = 12;
	int b = 5;
	printf("(%i) - (%i) = %d\n",a,b,Sub(a,b));
	printf("(%i) x (%i) = %d\n",a,b,Mul(a,b));
	printf("(%i) / (%i) = %d\n",a,b,Divid(a,b));
	printf("(%i) / (%i) = %d.%d\n",a,b,Divid(a,b),Modulo(a,b));
}
