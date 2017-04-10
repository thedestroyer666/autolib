#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define STRINGIFY2( x) #x
#define STRINGIFY(x) STRINGIFY2(x)
#define valueInt( myvar) STRINGIFY(myvar##_), myvar
#define my_printInt( myvar) printf("%s\t= %d\n",valueInt( myvar))
#define valueStr( myvar) STRINGIFY(myvar##_), myvar
#define my_printStr( myvar) printf("%s\t= %s\n",valueInt( myvar))

#define taille 30
#define TAILLE_TABS 7

extern void init_utils_et_stations();
extern void printUtil();
int utilisateur_deja_enregistre(char *nom_test);

struct utilisateur
{

int numdossier;
char nom[taille];
int abonnement;
char mdp[taille];
};

struct voiture
{
    int voiture;
    int etat;
    int station;
};
struct station
{
    int station;
    int nbrevoitures;
    int places;
};
struct gestionnaire
{

    int service;
};



#endif // FONCTIONS_H_INCLUDED
