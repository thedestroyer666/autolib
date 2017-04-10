#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


struct station tabstation[TAILLE_TABS];
struct utilisateur tabutil[TAILLE_TABS];
int nombre_utilisateurs_deja_enregistres = 0;
struct gestionnaire tabgest[TAILLE_TABS];
int nbregest = 0;
int main()
{
    int cpt=10 ;
    FILE *fichier;
    char nomFichier[30]="dossier_utilisateur.txt";
    fichier=fopen(nomFichier, "w");//pour ouvrir le fichier en mode écriture
    fprintf(fichier, "%d\n", cpt);

    fclose(fichier);//pour fermer le fichier


    int tab[TAILLE_TABS][TAILLE_TABS];

    int numdossier;
    struct voiture automobile;
    struct gestionnaire gest;
    char nom_temp[taille];

    char mdp_temp[taille];
    char choixUtil;
    char junk;


    automobile.voiture=16;


    init_utils_et_stations();
    do   //pour tout recommencer
    {
        //Demander la nature de la personne (gestionnaire, utilisateur)
        do
        {
            printf("ETES VOUS GESTIONNAIRE OU UTILISATEUR ?\n Tapez 1: utilisateur\n tapez 2: gestionnaire\n tapez 3: quitter\n ");
            scanf("%d",&cpt);

            if (cpt<=0 || cpt>3)
            {
                printf("erreur, tapez un chiffre entre 1 et 3 ");
            }

        }
        while (cpt<=0 || cpt>3);

        if (cpt==1)
        {
            int utilindex;
            //menu utilisateur
            //if(new dossier)
            numdossier=0;
            printf("Quel est votre nom ?\n");
            scanf("%s",&(nom_temp));
            utilindex = utilisateur_deja_enregistre(nom_temp);
            if(utilindex!=777)
            {
                printf("tapez votre mot de passe?\n");
                scanf("%s",&(mdp_temp));
                if(strcmp(tabutil[utilindex].mdp,mdp_temp)==0)
                {
                    printf("  :) C'est bien toi!\n");
                    my_printInt(tabutil[utilindex].numdossier);
                }
                else
                {
                    printf("  :( C'est pas toi!\n");
                }
            }
            else
            {
                printf("Nouvel utilisateur!\n");

                printf("choisissez votre mot de passe?\n");
                scanf("%s",&(mdp_temp));
                printf("votre numero de dossier est %d",numdossier);

                strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].nom,nom_temp);
                strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].mdp,mdp_temp);
                tabutil[nombre_utilisateurs_deja_enregistres].numdossier = 100+nombre_utilisateurs_deja_enregistres;
                nombre_utilisateurs_deja_enregistres++;
                printUtil();
                utilindex = nombre_utilisateurs_deja_enregistres;
            }


            scanf("%c",&junk); // purge le buffer de scanf
            printf("Que voulez vous faire ?\n a) Louer un vehicule\n b) rendre un vehicule\n c) consulter mon statut\n d) je sors\n");
            scanf("%c",&choixUtil);

            if (choixUtil=='a')

            {
               printf("entrez le numero de la station\n");//demander la station
               scanf("%d",&tabutil[utilindex].station);

                if (tabstation[utilindex].nbrevoitures!=0){//verifier si il y a une voiture de disponible dans la station

                    tabstation[utilindex].nbrevoitures=tabstation[utilindex].nbrevoitures-1;
                    //l'attribuer a l'utilisateur
                    printf("une voiture vous a ete attribue\n");
                }

                else{
                    if(tabstation[utilindex+1].nbrevoitures!=0)
                    printf("vous devez aller a la station %d\n",tabstation[utilindex+1].station);
                }

            }
            else if (choixUtil=='b')
            {
                //demander le temps du trajet
                //demander la station
                //verifier qu'il y a de la place
                //sinon chercher la place la plus proche
                //afficher le prix et le deduire du compte


            }
            else if (choixUtil=='c')
            {

                //afficher les informations de l'utilisateurs
                print1Util(utilindex);
            }
            else if (choixUtil=='d')
            {
                printf("%c Je sors\n",choixUtil);
                return 0;

            }
            else
            {
                printf("%c recommencer\n",choixUtil);
            }






        }
        else if (cpt==2)
        {
            //menu gestionnaire
            printf("numero ?\n");
            scanf("%d",&(gest.service));

        }
        /* else if (cpt==3)
         {//cas annulé

         }*/


    }
    while ( cpt!=3);

    //si utilisateur demander inscrit ou non inscrit
    //si inscrit demander identifiant avec verif

    //si non inscrit création d'un compte avec verif

//restitution, location de véhicule, modifications informations, consultation historique
    // verification de la solde/abonnement
    // si restitutiuon demander le nombre de place
    //si plus de place chercher la station la plus proche avec une place libre
    //si une place est libre attribuer la place a la voiture de l'utilisateur et arreter le comteur de temps
    //si location demander le nombre de voitures
    //si pas de voitures demander la station la plus proche avec une voiture libre
    //si une voiture est libre attribuer la voiture a l'utilisateur  et demarrer un compteur de temps(compter 30mn)
    //si modifications informations ou historique ou abonnement : acceder et modifier le compte


//si gestonnaire
    // consulter et modifier comptes utilisateurs
    //consulter et modifier nbre vehicules
    //statistiques
}
