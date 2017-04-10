#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

extern struct station tabstation[];
extern struct utilisateur tabutil[];
extern int nombre_utilisateurs_deja_enregistres;
extern

void printUtil()
{
    int i;
    printf("\n%s-%d printUtil\n",__FILE__,__LINE__);
    printf("nombre_utilisateurs_deja_enregistres =%d",nombre_utilisateurs_deja_enregistres);
    for(i=0; i<nombre_utilisateurs_deja_enregistres; i++)
    {
        printf("\ntabutil[%d]\n", i);
       printf("tabutil[i].nom=%s\n",tabutil[i].nom);
        printf("tabutil[i].numdossier=%d\n",tabutil[i].numdossier);
        printf("tabutil[i].mdp=%s\n",tabutil[i].mdp);
    }
}

int utilisateur_deja_enregistre(char *nom_test)
{
    int i;
    printf("nom_test=%s",nom_test);
    for(i=0; i<nombre_utilisateurs_deja_enregistres; i++)
    {
        printf("tabutil[%d].nom\t= %s\n", i, tabutil[i].nom);
        if(strcmp(tabutil[i].nom,nom_test)==0)
        {
            printf("\n:) Trouve![%d]\n", i);
            return i;
        }
    }
    printf("\n:( Pas trouve!\n");
    return 777;

}

void init_utils_et_stations()
{
    tabstation[0].station=1;
    tabstation[0].places=16;
    tabstation[0].nbrevoitures=16;

    tabstation[1].station=2;
    tabstation[1].places=16;
    tabstation[1].nbrevoitures=16;

    tabstation[2].station=3;
    tabstation[2].places=16;
    tabstation[2].nbrevoitures=16;

    tabstation[3].station=4;
    tabstation[3].places=16;
    tabstation[3].nbrevoitures=16;

    tabstation[4].station=5;
    tabstation[4].places=16;
    tabstation[4].nbrevoitures=16;

    nombre_utilisateurs_deja_enregistres = 0;
    strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].nom,"toto");
    tabutil[nombre_utilisateurs_deja_enregistres].numdossier = 65;
    strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].mdp,"cool");
    nombre_utilisateurs_deja_enregistres++;
    strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].nom,"stella");
    strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].mdp,"cool");
    tabutil[nombre_utilisateurs_deja_enregistres].numdossier = 99;
    nombre_utilisateurs_deja_enregistres++;
    strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].nom,"ulysse");
    strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].mdp,"pascool");
    tabutil[nombre_utilisateurs_deja_enregistres].numdossier = 97;
    nombre_utilisateurs_deja_enregistres++;
    printUtil();

}
