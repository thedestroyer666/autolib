#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

extern struct station tabstation[];
extern struct utilisateur tabutil[];
extern int nombre_utilisateurs_deja_enregistres;
extern struct gestionnaire tabgest[];
extern int nbregest;
void printUtil()
{
    int i;
    printf("\n%s-%d printUtil\n",__FILE__,__LINE__);
    printf("nombre_utilisateurs_deja_enregistres =%d",nombre_utilisateurs_deja_enregistres);
    for(i=0; i<nombre_utilisateurs_deja_enregistres; i++)
    {
        printf("\ntabutil[%d]\n", i);
        printf("\t.nom=%s\n",tabutil[i].nom);
        printf("\t.numdossier=%d\n",tabutil[i].numdossier);
        printf("\t.mdp=%s\n",tabutil[i].mdp);
        printf("\t.voiture=%s\n",tabutil[i].voiture);
        printf("\t.station=%s\n",tabutil[i].station);
    }
}

void printGest()
{
    int i;
    printf("\n%s-%d printGest\n",__FILE__,__LINE__);
    printf("nombre de gestionnaire =%d",nbregest);
    for(i=0; i<nbregest; i++)
    {
        printf("\ntabgest[%d]\n", i);
        printf("tabgest[i].nomgest=%s\n",tabgest[i].nomgest);
        printf("tabgest[i].service=%d\n",tabgest[i].service);
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
    tabstation[0].places=17;
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
    tabutil[nombre_utilisateurs_deja_enregistres].station=0;
    tabutil[nombre_utilisateurs_deja_enregistres].voiture=0;
    nombre_utilisateurs_deja_enregistres++;
    printUtil();

    nbregest=0;
    strcpy(&tabgest[nbregest].nomgest,"stella");
    tabgest[nbregest].service = 665;
    nbregest++;
    strcpy(&tabgest[nbregest].nomgest,"ulysse");
    tabgest[nbregest].service = 666;
    nbregest++;
    printGest();
}
