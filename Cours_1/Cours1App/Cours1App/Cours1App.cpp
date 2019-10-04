// Cours1App.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>


 int Memcpy(char * dest, char * src, int size)
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


int main()
{
    std::cout << "Hello World!\n";
	char Licorne[32] = "Licorne";
	char Vomi[32] = "Vomi";
	char Chat = 'C';
	char Grange[32] = "Vive le Chat est très mignon";
	//Memcpy(Licorne, Vomi, strlen(Licorne+1));
	Memcpy2(Licorne, Vomi, strlen(Licorne+1));
	printf("Licorne = %s\n ", Licorne);
	printf("position Chat = %d\n", StrChr2(Grange, Chat));
}
