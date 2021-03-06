/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud, Matt�o Arzel
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
//
// 25/01/2021 : - Ajout de la librairie <ctime> (Matt�o Arzel)
//              - Fonction InitJoueur complet�e (Matt�o Arzel)
//              - Fonction TirerNombreMystere complet�e (Matt�o Arzel)
//
// 07/02/2021 : - Fonction JouerPartie complet�e (Matt�o Arzel)
//              - Fonction MajResultatsJoueur complet�e (Matt�o Arzel)
//              - Fonction ResultatsJoueur complet�e (Matt�o Arzel)
//
//
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"
#include <ctime>

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : un_nom
// Param�tres de sortie : joueurAcreer
// Param�tres d'entr�e/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
        joueurAcreer.nbTentatives = 0;
        joueurAcreer.nbPartiesGagnees = 0;
        joueurAcreer.nbPartiesJouees = 0;
        joueurAcreer.nom = un_nom;

}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
        srand((unsigned int) time(0));
        int nombreADeviner=(rand()%10) + 0;
        return nombreADeviner;
}

// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void MajResultatsJoueur(TJoueur& joueur, int nbEssais, bool gagne)
{
    joueur.nbTentatives = joueur.nbTentatives + nbEssais;
    if (gagne == true) {
        joueur.nbPartiesGagnees++;
    }
    joueur.nbPartiesJouees++;
}

// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: nombreADeviner
// Param�tres de sortie:
// Param�tres d'entr�e/sortie : un_joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
        int i = 0;
        int valeur = 0;
        bool win = true;
        bool loose = false;

        cout << "Trouve le nombre mystere !" << endl;
        while(valeur != nombreADeviner && i!= 4) {
            cout << "Valeur : ";
            cin >> valeur;
            i++;
            if(valeur < nombreADeviner) {
                cout << "C'est plus !" << endl;
            }
            else if(valeur > nombreADeviner) {
                cout << "C'est moins !" << endl;
            }
            else if(valeur == nombreADeviner) {
                MajResultatsJoueur(un_joueur, i, win);
                cout << endl << "Vous avez trouver le juste prix !" << endl;
                cout << "Nombre d'essais : " << i << endl;
            }
        }

        if(i == 4 && valeur != nombreADeviner) {
                MajResultatsJoueur(un_joueur, 4, loose);
                cout << endl << "Vous n'avez pas reussi a trouve le juste prix..." << endl;
                cout << "Le nombre mystere a trouver etait : " << nombreADeviner << endl;
        }
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

