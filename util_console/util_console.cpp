// util_console.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "ConsoleTextStyle.hpp"
#include "ConsoleCursorControler.hpp"
#include "ConsoleUtility.hpp"

#include "drop.h"

using namespace std;

void cout_clear() {
	cout << "\r                                       ";
	cout.flush();
}

void color(int p) {
	if (p < 33) {
		CTS::setColor(CTS::Red);
	}
	else if (p < 67) {
		CTS::setColor(CTS::Yellow);
	}
	else if (p < 100) {
		CTS::setColor(CTS::Green);
	}
	else {
		CTS::setColor(CTS::Cyan);
	}
}

void bar(int p) {
	string a, b;

	color(p);

	int am = max(min(p, 50), 0);

	a = string(am / 5, '-') + string(10 - am / 5, ' ');

	int bm = max(min(p, 100), 50);
	b = string(bm / 5 - 10, '-') + string(10 - (bm / 5 - 10), ' ');

	printf("\r[%s %3d%% %s]", a.c_str(), p, b.c_str());
	fflush(stdout);
}

int main()
{
	CCC::hideCursor();
	cout << "____";
	cout.flush();
	//sleep(1);
	this_thread::sleep_for(chrono::milliseconds(1000));

	for (int i = 0; i <= 100; ++i) {
		bar(i);
		this_thread::sleep_for(chrono::milliseconds(10));
	}
	CTS::reset();

	CU::clear_console();
	drop::INITIALIZE();
	static const int size_drop = 100;
	drop ds[size_drop];

	CTS::setColor(CTS::Green);
	std::string mes;
	while (true) {
		//CU::clear_console();
		drop::INITIALIZE();

		for (int i = 0; i < size_drop; ++i)
			ds[i].print();

		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(30));
	}


	return 0;
}




// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
