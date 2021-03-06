// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"

void assert(bool boubou)
{
	if (!boubou)
	{
		throw new std::string("nope");
	}
}
int main()
{
	auto NameTab0 = "Tab0";
	auto NameTab1 = "Tab1";
	{
		IntArray Tab0 = IntArray(16,NameTab0);		
	}
	{
		IntArray * Tab1 = new IntArray(16,NameTab1);

		int i = 0;
	}
	{
		IntArray t(16);
		for (int i = 0; i < 16; i++)
		{
			t.fillWithRandom(t.maxSize);
		}
		t.trier();
	}
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
