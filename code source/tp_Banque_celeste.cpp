#include <iostream>
#include <sstream>
#include <time.h>
#include<iomanip>
#include<string>
using namespace std;

double solde[100];
string nom[100], prenom[100];   //les tableaux
int numero[100], numeroEffacer[1];

void afficherTousLesComptes();  //les fonctions			// CELESTE
void afficherComptePrecis();
void triage();

void menu(void);
void quit(int param);
double afficherSoldeMoyenDesSoldes();                    // CLAUTAIRE
double afficherValeurTotaleDesComptes();


void ajouterUnCompte();
void faireUnDepot();
void faireUnRetrait();			// AMADOU
void retirerUnCompte();
short validerNumerique();

int main() {

	short nombreDeCompte = 0;        //AMADOU

	for (int i = 0; i < 20; i++) {
		solde[i] = 500;              //on initialise de 1 a 20
		nom[i] = "GOUBA";
		prenom[i] = "Celeste";
		numero[i] = 10000 + i;
	}
	for (int i = 20; i < 50; i++) {
		solde[i] = 860;              //on initialise de 21 a 50
		nom[i] = "Miot";
		prenom[i] = "Lucy";
		numero[i] = 10000 + i;
	}
	for (int i = 50; i < 80; i++) {
		solde[i] = 7.8;          //on initialise de 51 a 80
		nom[i] = "Legault";
		prenom[i] = "Sarah";
		numero[i] = 10000 + i;
	}
	for (int i = 80; i < 100; i++) {
		solde[i] = 125;          //on initialise de 81 a 100
		nom[i] = "Pierre";
		prenom[i] = "Dubois";
		numero[i] = 10000 + i;
	}
	string alphabet[26];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = i + 65;
	}

	locale::global(locale(""));          // pour traiter les affichages avec les acsents

	menu();
	quit(0);

	system("pause");
	return 0;
}

// FONCTIONS CLAUTAIRE

void menu() {
	system("CLS");
	int choix;

	cout << "             MENU :" << endl;
	cout << endl;
	cout << "(" << 1 << ") Ajouter un compte " << endl;
	cout << endl;
	cout << "(" << 2 << ") Retirer compte " << endl;
	cout << endl;
	cout << "(" << 3 << ") Afficher compte client " << endl;
	cout << endl;
	cout << "(" << 4 << ") Effectuer un dépôt " << endl;
	cout << endl;
	cout << "(" << 5 << ")  Effectuer un retrait " << endl;
	cout << endl;
	cout << "(" << 6 << ") Afficher liste des clients " << endl;
	cout << endl;
	cout << "(" << 7 << ")  Afficher solde moyen des comptes " << endl;
	cout << endl;
	cout << "(" << 8 << ") Afficher valeur totale des comptes " << endl;
	cout << endl;
	cout << " Quitter (0)" << endl;
	cout << endl;
	cout << "CHOIX : ";
	cin >> choix;
	while (choix < 0) {
		cin.clear(); //
		cin.ignore(512, '\n');
		cout << "Attention - valeur numérique : ";
		cin >> choix;
	}
	while (choix > 8) {
		cout << "Attention - une valeur entre 0 et 8 : ";
		cin >> choix;
	}
	cin.ignore(512, '\n');

	switch (choix)
	{
	case 1:
		system("CLS");
		ajouterUnCompte();
		break;
	case 2:
		system("CLS");
		retirerUnCompte();
		break;
	case 3:
		system("CLS");
		afficherComptePrecis();
		break;
	case 4:
		system("CLS");
		faireUnDepot();
		break;
	case 5:
		system("CLS");
		faireUnRetrait();
		break;
	case 6:
		system("CLS");
		triage();
		break;
	case 7:
		system("CLS");
		afficherSoldeMoyenDesSoldes();
		break;
	case 8:
		system("CLS");
		afficherValeurTotaleDesComptes();
		break;
	case 9:
		cout << endl;
		quit(0);
		break;
	}
	quit(0);

}

void quit(int param) {

	string reponse;
	cout << endl;
	cerr << "\n" << "Voulez-vous quitter entierement le programme !? O/N :\n"; cin >> reponse;
	if (reponse == "o" || reponse == "O") {								//MODIFIER
		exit(0);
	}
	if (reponse == "n" || reponse == "N") {
		cout << endl;
		if (param == 0) {
			menu();
		}

	}
}

double afficherSoldeMoyenDesSoldes() {
	int nbComptes = 0;
	double sommeDesComptes, soldeMoyen;
	sommeDesComptes = 0;									//MODIFIER
	for (int i = 0; i < 100; i++) {
		if (numero[i] != 0) {
			sommeDesComptes += solde[i];
			nbComptes += 1;
		}
	}

	soldeMoyen = sommeDesComptes / nbComptes;
	cout << " SOLDE MOYEN : " << soldeMoyen << " $";

	return 0;
}

double afficherValeurTotaleDesComptes() {
	double sommeDesComptes, soldeMoyen;
	sommeDesComptes = 0;								//MODIFIER
	for (int i = 0; i < 100; i++) {
		if (numero[i] != 0) {
			sommeDesComptes += solde[i];
		}
	}
	cout << " TOTAL DES COMPTES : " << sommeDesComptes << " $";

	return 0;
}




// FONCTIONS CELESTE

void afficherTousLesComptes() {
	cout << "No      soldes  noms  prenoms" << endl;
	for (int i = 0; i < 100; i++) {
		if (numero[i] != 0) {
			cout << numero[i] << "    " << solde[i] << " $  " << nom[i] << "  " << prenom[i] << endl;
		}
	}
}

void afficherComptePrecis() {
	int k, ID;
	cout << "entrer le numero du compte : ";
	cin >> ID;
	while (ID < 0) {
		cin.clear(); //
		cin.ignore(512, '\n');
		cout << "Attention - valeur numérique : ";
		cin >> ID;
	}
	while (ID < 10000 || ID > 10099) {
		cout << "Attention - une valeur entre 10000 et 10099 : ";
		cin >> ID;
	}
	cin.ignore(512, '\n');
	for (int i = 0; i < 100; i++) {
		if (10000 + i == ID) {
			k = i;
		}
	}
	if (10000 + k == ID && numero[k] != 0) {
		cout << numero[k] << "    " << solde[k] << " $  " << nom[k] << " " << prenom[k] << endl;
	}
	else {
		cout << " DESOLER LE COMTE N'EXISTE PAS " << endl;
	}
}

void triage() {
	int choix, ordre, cpt = 99, temp;
	double tempSolde;
	string tempNom, tempPrenom, tempChaine, symbolAvant, symbolApres, alphabet[26];
	cout << "Pour afficher tous les comptes appuyez (0) :" << endl;
	cout << endl;
	cout << "                      OU " << endl;
	cout << endl;
	cout << "veuillez afficher la liste selon votre choix ((1)-nom / (2)-prenom / (3)-solde) : ";
	cin >> choix;
	while (choix < 0) {
		cin.clear(); //
		cin.ignore(512, '\n');
		cout << "Attention - valeur numérique : ";
		cin >> choix;
	}
	while (choix > 3) {
		cout << "Attention - une valeur entre 1 et 3 : ";
		cin >> choix;
	}
	cin.ignore(512, '\n');

	switch (choix) {
	case 0:
		afficherTousLesComptes();  // utilise la fonction juste en haut de quelques lignes.
		break;
	case 1:
		cout << "Par ordre croissant ou decroissant ? ((1)-croissant / (-1)-decroissant) : ";
		cin >> ordre;
		while (ordre != 1 && ordre != -1) {
			cout << "Attention - entrer un ordre correcte ((1)-croissant / (-1)-decroissant) : ";
			cin >> ordre;
		}
		cin.ignore(512, '\n');
		cout << endl;
		if (ordre == 1) {
			for (int i = 0; i < 26; i++) {
				alphabet[i] = 65 + i;
			}
			do {
				tempSolde = 0;
				for (int i = 0; i < cpt; i++) {
					symbolAvant = nom[i][0];
					symbolApres = nom[i + 1][0];
					if (symbolAvant > symbolApres) {

						tempSolde = solde[i + 1];
						solde[i + 1] = solde[i];
						solde[i] = tempSolde;

						tempNom = nom[i + 1];
						nom[i + 1] = nom[i];
						nom[i] = tempNom;

						tempPrenom = prenom[i + 1];
						prenom[i + 1] = prenom[i];
						prenom[i] = tempPrenom;

						temp = numero[i + 1];
						numero[i + 1] = numero[i];
						numero[i] = temp;

					}
				}
				cpt--;
			} while (cpt > 0);
			for (int i = 0; i < 100; i++) {
				cout << numero[i] << "    " << nom[i] << "  " << " " << prenom[i] << " " << solde[i] << " $  " << endl;
			}
		}
		else if (ordre == -1) {
			for (int i = 0; i < 26; i++) {
				alphabet[i] = 65 + i;
			}
			do {
				tempSolde = 0;
				for (int i = cpt; i > 0; i--) {
					symbolAvant = nom[i][0];
					symbolApres = nom[i - 1][0];
					if (symbolAvant > symbolApres) {

						tempSolde = solde[i];
						solde[i] = solde[i - 1];
						solde[i - 1] = tempSolde;

						tempNom = nom[i];
						nom[i] = nom[i - 1];
						nom[i - 1] = tempNom;

						tempPrenom = prenom[i];
						prenom[i] = prenom[i - 1];
						prenom[i - 1] = tempPrenom;

						temp = numero[i];
						numero[i] = numero[i - 1];
						numero[i - 1] = temp;

					}
				}
				cpt--;
			} while (cpt > 0);
			for (int i = 0; i < 100; i++) {
				cout << numero[i] << "    " << solde[i] << " $  " << nom[i] << " " << prenom[i] << endl;
			}
		}
		break;

	case 2:
		cout << "Par ordre croissant ou decroissant ? ((1)-croissant / (-1)-decroissant) : ";
		cin >> ordre;
		while (ordre != 1 && ordre != -1) {
			cout << "Attention - entrer un ordre correcte ((1)-croissant / (-1)-decroissant) : ";
			cin >> ordre;
		}
		cin.ignore(512, '\n');
		cout << endl;
		if (ordre == 1) {
			for (int i = 0; i < 26; i++) {
				alphabet[i] = 65 + i;
			}
			do {
				tempSolde = 0;
				for (int i = 0; i < cpt; i++) {
					symbolAvant = prenom[i][0];
					symbolApres = prenom[i + 1][0];
					if (symbolAvant > symbolApres) {

						tempSolde = solde[i + 1];
						solde[i + 1] = solde[i];
						solde[i] = tempSolde;

						tempNom = nom[i + 1];
						nom[i + 1] = nom[i];
						nom[i] = tempNom;

						tempPrenom = prenom[i + 1];
						prenom[i + 1] = prenom[i];
						prenom[i] = tempPrenom;

						temp = numero[i + 1];
						numero[i + 1] = numero[i];
						numero[i] = temp;

					}
				}
				cpt--;
			} while (cpt > 0);
			for (int i = 0; i < 100; i++) {
				cout << numero[i] << "    " << prenom[i] << "  " << " " << nom[i] << " " << solde[i] << " $  " << endl;
			}
		}
		else if (ordre == -1) {
			for (int i = 0; i < 26; i++) {
				alphabet[i] = 65 + i;
			}
			do {
				tempSolde = 0;
				for (int i = cpt; i > 0; i--) {
					symbolAvant = prenom[i][0];
					symbolApres = prenom[i - 1][0];
					if (symbolAvant > symbolApres) {

						tempSolde = solde[i];
						solde[i] = solde[i - 1];
						solde[i - 1] = tempSolde;

						tempNom = nom[i];
						nom[i] = nom[i - 1];
						nom[i - 1] = tempNom;

						tempPrenom = prenom[i];
						prenom[i] = prenom[i - 1];
						prenom[i - 1] = tempPrenom;

						temp = numero[i];
						numero[i] = numero[i - 1];
						numero[i - 1] = temp;

					}
				}
				cpt--;
			} while (cpt > 0);
			for (int i = 0; i < 100; i++) {
				cout << numero[i] << "    " << prenom[i] << "  " << " " << nom[i] << " " << solde[i] << " $  " << endl;
			}

		}
		break;

	case 3:
		cout << "Par ordre croissant ou decroissant ? ((1)-croissant / (-1)-decroissant) : ";
		cin >> ordre;
		while (ordre != 1 && ordre != -1) {
			cout << "Attention - entrer un ordre correcte ((1)-croissant / (-1)-decroissant) : ";
			cin >> ordre;
		}
		cin.ignore(512, '\n');
		cout << endl;
		if (ordre == 1) {
			do {
				tempSolde = 0;
				for (int i = 0; i < cpt; i++) {
					if (solde[i] > solde[i + 1]) {

						tempSolde = solde[i + 1];
						solde[i + 1] = solde[i];
						solde[i] = tempSolde;

						tempNom = nom[i + 1];
						nom[i + 1] = nom[i];
						nom[i] = tempNom;

						tempPrenom = prenom[i + 1];
						prenom[i + 1] = prenom[i];
						prenom[i] = tempPrenom;

						temp = numero[i + 1];
						numero[i + 1] = numero[i];
						numero[i] = temp;

					}
				}
				cpt--;
			} while (cpt > 0);
			for (int i = 0; i < 100; i++) {
				cout << numero[i] << "    " << solde[i] << " $  " << nom[i] << " " << prenom[i] << endl;
			}
		}
		else if (ordre == -1) {
			do {
				tempSolde = 0;
				for (int i = cpt; i > 0; i--) {
					if (solde[i] > solde[i - 1]) {

						tempSolde = solde[i];
						solde[i] = solde[i - 1];
						solde[i - 1] = tempSolde;

						tempNom = nom[i];
						nom[i] = nom[i - 1];
						nom[i - 1] = tempNom;

						tempPrenom = prenom[i];
						prenom[i] = prenom[i - 1];
						prenom[i - 1] = tempPrenom;

						temp = numero[i];
						numero[i] = numero[i - 1];
						numero[i - 1] = temp;

					}
				}
				cpt--;
			} while (cpt > 0);
			for (int i = 0; i < 100; i++) {
				cout << numero[i] << "    " << solde[i] << " $  " << nom[i] << " " << prenom[i] << endl;
			}
		}
		break;
	}
}




// FONCTIONS AMADOU 


void ajouterUnCompte() {
	int egaliter = 0, num, bon = 0, nbCompte = 0, compteLibre;
	for (int i = 0; i < 100; i++) {														//MODIFIER
		if (numero[i] == 0) {
			compteLibre = i;
		}
		else {
			nbCompte++;
		}
		if (nbCompte == 100) {
			cout << " !!!! DESOLER LE MAXIMUM DE COMPTE EST ATTEINT !!!! " << endl;
		}
	}
	if (nbCompte < 100) {

		cout << "Saisir votre Prenom : ";
		cin >> prenom[compteLibre];
		cout << "Saisir votre Nom : ";
		cin >> nom[compteLibre];
		for (int i = 0; i < 100; i++) {
			if (numero[i] == 0) {
				numero[i] = numeroEffacer[0];
			}
		}
		cout << "Saisir le montant que vous voulez deposer : ";
		cin >> solde[compteLibre];
		while (solde[compteLibre] <= 0) {
			cout << "Saisir un montant correct : ";
			cin >> solde[compteLibre];
		}
		cout << " !!!! AJOUT TERMINER !!!! ";
	}
}

void faireUnDepot() {
	double montantDuDepot;
	int numeroDeCompteDestinataire;											//MODIFIER

	cout << "Saisir numero du compte que vous voulez depot l'argent" << endl;
	cin >> numeroDeCompteDestinataire;


	for (int i = 0; i < 100; i++)
	{
		if (numeroDeCompteDestinataire == numero[i])
		{
			cout << "Saisir le montant de la transaction: ";
			cin >> montantDuDepot;

			solde[i] += montantDuDepot;
		}

	}
}

void faireUnRetrait() {
	double montantDuRetrait;
	int numeroDeComptePourRetrait;

	cout << "Saisir numero du compte pour faire le retrait " << endl;
	cin >> numeroDeComptePourRetrait;


	for (int i = 0; i < 100; i++)
	{
		if (numeroDeComptePourRetrait == numero[i])
		{
			cout << "Saisir le montantque vous voulez retirer : ";
			cin >> montantDuRetrait;


			if (montantDuRetrait > solde[i]) {
				cout << "Solde insuffisant pour retirer une telle somme !" << endl;
			}

			else {

				solde[i] -= montantDuRetrait;
				cout << " !!!! RETRAIT EFFECTUE !!!!!" << endl;
			}

		}

	}
}

short validerNumerique() {         // POUR LES FONCTIONS D'AMADOU
	short val;
	cin >> val;
	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Attention : valeur num rique seulement! : ";
		cin >> val;
	}
	cin.ignore(512, '\n');
	return val;
}

void retirerUnCompte() {

	short numeroDeCompteARetier;
	cout << "Saisir le numero du compte que vous voulez retirer" << endl;
	cin >> numeroDeCompteARetier;
	while (numeroDeCompteARetier < 0) {
		cin.clear(); //
		cin.ignore(512, '\n');
		cout << "Attention - valeur numérique : ";
		cin >> numeroDeCompteARetier;
	}
	while (numeroDeCompteARetier < 10000 || numeroDeCompteARetier > 10099) {
		cout << "Attention - une valeur entre 10000 et 10099 : ";
		cin >> numeroDeCompteARetier;
	}
	cin.ignore(512, '\n');
	for (int i = 0; i < 100; i++)
	{
		if (numeroDeCompteARetier == numero[i])
		{
			numeroEffacer[0] = numeroDeCompteARetier;
			numero[i] = 0;
			cout << " !!!! LE COMPTE EST BIEN RETIRER !!!! ";
		}

	}
}
