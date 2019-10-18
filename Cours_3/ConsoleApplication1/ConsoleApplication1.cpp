// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"
#include "Util.hpp"
#include "List.hpp"
#include "Tree.hpp"

void assert(bool boubou)
{
	if (!boubou)
	{
		throw std::exception();
	}
}

void TestIntTree() {
	IntTree * tree = new IntTree();
	Node<int> * leaf = new IntNode(8);
	leaf->insert(4);
	//assert(leaf->left->elem == 4);

	leaf->insert(9);
	//assert(leaf->right->elem == 9);

	leaf->insert(16);
	leaf->insert(3);
	leaf->insert(5);
	assert(leaf->getLength() == 6);


	assert(leaf->Contains(16) == true);
	leaf->remove(16);
	assert(leaf->Contains(16) == false);
	assert(leaf->Contains(4) == true);
	leaf->remove(4);
	assert(leaf->Contains(4) == false);
	leaf->insert(0);
	assert(leaf->Contains(0) == true);
	leaf->remove(0);
	assert(leaf->Contains(0) == false);
	leaf->dfsPrint();
	printf("\n");
	leaf->dfsPrintInverse();
	int k = 0;
}


void TestList2()
{
	IntList* MONNOM = new IntList(8);
	int toto = 8;
	MONNOM->Append(6);
	printf("Taile = %i \n", MONNOM->Length());
	MONNOM =MONNOM->ConCat(12);
	printf("Taile = %i \n", MONNOM->Length());
	printf("Elem = %i \n", MONNOM->elem);
	bool Alpha = MONNOM->Contains(60);
	assert(Alpha == false);
	bool Beta = MONNOM->Contains(12);
	assert(Beta == true);
	int  i = 0;
}
int main()
{
	TestList2();
	TestIntTree();

	/*double Alpha;
	double Omega;
	auto NameTab0 = "Tab0";
	auto NameTab1 = "Tab1";
	{
		IntArray Tab0 = IntArray(16, NameTab0);
	}
	{
		IntArray * Tab1 = new IntArray(16, NameTab1);

		int i = 0;
	}
	{
		IntArray t(1024*1024);
		{
			for (int i = 1; i <=(1024*1024) ; i++)
			{
				t[i-1] = i*i;
			}
		}
		double t0 = Util::GetTimeStamp();
		printf("Inserer la clef a cet endroit %i \n", t.BinarySearch2(15000));
		double t1 = Util::GetTimeStamp();
		printf("Temps de calcul du premier tableau : %llf for recur \n", (t1 - t0));

		double t2 = Util::GetTimeStamp();
		printf("Inserer la clef a cet endroit %i \n", t.SearchPosition(15000));
		double t3 = Util::GetTimeStamp();
		printf("Temps de calcul du premier tableau : %llf for Normal \n", (t3 - t2));
		int i = 0;
	}*/
	/*{
		double t0 = Util::GetTimeStamp();
		IntArray t(128);
		{
			t.fillWithRandom(1024);
		}
		t.InsertSort();
		int i = 0;
		double t1 = Util::GetTimeStamp();
		Alpha = (t1-t0);
		printf("Temps de calcul du premier tableau : %llf for %d \n", (t1 - t0), t.getLenght());
	}*/
	/*{
		double t0 = Util::GetTimeStamp();
		IntArray Beta(1024);
		{
			Beta.fillWithRandom(Beta.maxSize);
		}
		Beta.InsertSort();
	double t1 = Util::GetTimeStamp();
	Omega = (t1-t0);
	printf("Temps de calcul du second tableau : %llf for %d \n", (t1 - t0), Beta.getLenght());
	
	}*/
	/*{
		printf("Rapport : %llf \n", (Omega/Alpha));
	}*/
	int i = 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
