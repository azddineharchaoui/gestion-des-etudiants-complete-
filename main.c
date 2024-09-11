#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define MAX_ETUDIANT 200

typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

typedef enum {INFORMATIQUE, MATHEMATIQUES, PHYSIQUE, CHIMIE}Departement;

typedef struct {
    int id;
    char nom[MAX];
    char prenom[MAX];
    Date date_naissance;
    Departement departement;
    float note;
}Etudiant;

int count =0;
Etudiant classe[MAX_ETUDIANT];

void ajouterEtudiant(){
    if(count >= MAX_ETUDIANT){ printf("Il n'y a pas de places vides\n");}
    else{
        classe[count].id = count+1;
        printf("Entrer le nom de l'etudiant\n");
        scanf(" %[^\n]s", &classe[count].nom);
        printf("Entrer le prenom de l'etudiant\n");
        scanf(" %[^\n]s", &classe[count].prenom);
        printf("Entrer la date de naissance (jour mois annee)\n");
        scanf("%d %d %d", &classe[count].date_naissance.jour, &classe[count].date_naissance.mois, &classe[count].date_naissance.annee );
        printf("Entrer la departement : \n0-INFORMATIQUE.\n1-MATHEMATIQUES.\n2-PHYSIQUE.\n3-CHIMIE\n");
        scanf("%d", &classe[count].departement);
        printf("Entrer la note generale de l'etudiant\n");
        scanf("%f", &classe[count].note);
        count++;
    }
}

void modifierEtudiant(){
    int id;
    printf("Entrez l'id de l'etudiant que vous voulez modifier\n");
    scanf("%d", &id);
    for(int i=0; i<count ; i++){
        if(classe[i].id == id){
            printf("Entrer le nouveau nom de l'etudiant\n");
            scanf(" %[^\n]s", &classe[i].nom);
            printf("Entrer le nouveau prenom de l'etudiant\n");
            scanf(" %[^\n]s", &classe[i].prenom);
            printf("Entrer la nouvelle date de naissance (jour mois annee)");
            scanf("%d %d %d", &classe[i].date_naissance.jour, &classe[i].date_naissance.mois, &classe[i].date_naissance.annee );
            printf("Entrer la nouvelle departement : \n0-INFORMATIQUE.\n1-MATHEMATIQUES.\n2-PHYSIQUE.\n3-CHIMIE\n");
            scanf("%d", &classe[i].departement);
            printf("Entrer la nouvelle note generale de l'etudiant\n");
            scanf("%f", &classe[i].note);
            printf("Les infos de l'etudiant ont ete modifie avec succes\n");
            return ;
        }
    }
    printf("Il n'y a pas d'etudiant avec cet id \n");
}

void supprimerEtudiant(){
    int id;
    printf("Entrer l'id de l'etudiant que vous voulez supprimer\n");
    scanf("%d",&id);
    if(id>count){
        printf("Il n'y a pas d'etudiant avec cet id \n");
        return ;
    }else {
        for(int i = id; i< count -1; i++){
            classe[i]=classe[i+1];
        }
        count--;
        printf("l'etudiant a ete supprime avec succes\n");
    }
}
char *departement(Departement d ){
    char * str = malloc(20*sizeof(char));
    switch(d){
    case 0 :
        strcpy(str, "Informatique");
        break;
    case 1:
        strcpy(str, "Mathematiques");
        break;
    case 2:
        strcpy(str, "Physique");
        break;
    case 3:
        strcpy(str, "Chimie");
        break;
    default:
        break;
    }
    return str;
}
void afficherEtudiants() {
    if (count == 0) {
        printf("La liste des etudiants est vide\n");
    } else {
        printf("%-3s | %-12s | %-12s | %-12s | %-12s | %s\n",
               "ID", "Nom", "Prenom", "Date de Naissance", "Departement", "Note Generale");
        printf("-----+-------------+-------------+--------------+-------------+------------\n");

        for (int i = 0; i < count; i++) {
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
        }
    }
}

void rechercherEtudiant(){
    char  str[30];
    printf("entrer le nom de l'etudiant que vous recherchez\n");
    scanf("%s", &str);
    for(int i=0; i<count ; i++){
        if(!strcmp(str, classe[i].nom)){
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
                   return ;
        }
    }
    printf("Il n'y a pas d'etudiant correspondant au nom que vous avez entre\n");
}

void afficherDepartement(){
    int dep;
    if(count ==0){
        printf("La liste des etudiants est vide \n");
    }else{
        printf("Entrer la departement que vous voulez afficher \n");
        printf("(0)-INFORMATIQUE.\n(1)-MATHEMATIQUES.\n(2)-PHYSIQUE.\n(3)-CHIMIE\n");
        scanf("%d", &dep);
        if(dep>3){
            printf("Cette departement n'existe pas \n");
            return ;
        }else{
        printf("id | nom | prenom | date de naissance | Departement | note generale\n");
        for(int i=0; i<count; i++){
            if(dep==classe[i].departement){
                printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
                }
            }
        }
    }
}

void claculMoyenne(){
    int choice;
    int dep;
    float sum = 0;
    float avg;
    int dep_count = 0;
    printf("1- Afficher la moyenne generale de l'universite entiere\n");
    printf("2- Afficher la moyenne generale d'une departement \n");
    scanf("%d", &choice);
    switch(choice){
case 1:
    if(count ==0){ printf("La liste des etudiants est vide \n");}else{
    for(int i=0; i<count; i++ ){
        sum+=classe[i].note;
    }
    avg = sum / count;
    printf("la moyenne generale de l'universite est : %.2f", avg);
    }
    break;
case 2:
    if(count == 0){ printf("La liste des etudiants est vide \n");}else{
        printf("Entrer la departement \n");
        printf("(0)-INFORMATIQUE.\n(1)-MATHEMATIQUES.\n(2)-PHYSIQUE.\n(3)-CHIMIE\n");
        scanf("%d",&dep);
        for(int i = 0; i< count ; i++){
            if(classe[i].departement == dep){
                sum+=classe[i].note;
                dep_count++;
            }
        }
        avg = sum / dep_count;
        printf("La moyenne generale du departement %s est %.2f", departement(dep), avg);
    }
    break ;
default:
    printf("Choix invalide \n");
    break ;
    }
}



void depCount(){
    int dep0 = 0 ;
    int dep1 = 0 ;
    int dep2 = 0 ;
    int dep3 = 0 ;
    if(count == 0){ printf("La liste des etudiants est vide \n");}else{
        for(int i = 0 ; i<count ; i++){
            switch(classe[i].departement){
                case 0 : dep0++;
                    break ;
                case 1 : dep1++;
                    break ;
                case 2 : dep2++;
                    break ;
                case 3 : dep3++;
                    break ;
            }
        }
        printf("(0) Informatique %d etudiants \n", dep0);
        printf("(1) Mathematiques %d etudiants \n", dep1);
        printf("(2) Physique %d etudiants \n", dep2);
        printf("(3) Chimie %d etudiants \n", dep3);
    }
}

int maxIndex(float t[], int n ){
    int max = 0;
    for (int i = 0 ; i< n ; i++){
        if(t[i]>t[max]){
            max = i;
        }
    }
    t[max]=0;
    return max;
}

void depCountSucces(){
    int succes0 = 0 ;
    int succes1 = 0 ;
    int succes2 = 0 ;
    int succes3 = 0 ;
    if(count == 0){ printf("La liste des etudiants est vide \n");}else{
        for(int i = 0 ; i<count ; i++){
            switch(classe[i].departement){
                case 0 :
                    if(classe[i].note > 10){ succes0++; }
                    break ;
                case 1 :
                    if(classe[i].note > 10){ succes1++; }
                    break ;
                case 2 :
                    if(classe[i].note > 10){ succes2++; }
                    break ;
                case 3 :
                    if(classe[i].note > 10){ succes3++; }
                    break ;
            }
        }
        printf("(0) Le nombre de reussite en departement Informatique est : %d \n", succes0);
        printf("(1) Le nombre de reussite en departement Mathematiques %d \n", succes1);
        printf("(2) Le nombre de reussite en departement Physique %d \n", succes2);
        printf("(3) Le nombre de reussite en departement Chimie %d \n", succes3);
    }

}

void afficherStats(){
    int choice ;
    int seuil ;
    float t[count];
    int max3[3];
    printf("1- Afficher le nbr total d'etudiants inscrits \n");
    printf("2- Afficher le nbr d'etudiants dans chaque departement\n");
    printf("3- Afficher les etudiants ayant une moyenne generale > seuil\n");
    printf("4- Afficher les 3 etudiants ayant les meilleures notes \n");
    printf("5- Afficher le nbr d'etudiants ayant reussi dans chaque departement\n");
    printf("6- Retourner au menu \n");
    scanf("%d", &choice);
    switch(choice){
case 1:
    printf("Le nombre total d'etudiants inscrits est %d\n", count);
    break ;
case 2:
    depCount();
    break ;
case 3:
    printf("entrer un seuil\n");
    scanf("%d", &seuil);
    printf("%-3s | %-12s | %-12s | %-12s | %-12s | %s\n",
               "ID", "Nom", "Prenom", "Date de Naissance", "Departement", "Note Generale");
    printf("-----+-------------+-------------+--------------+-------------+------------\n");

    for (int i = 0; i < count; i++) {
        if(classe[i].note> seuil ){
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
            }
        }
    break ;
case 4:
    for(int i = 0 ; i< count ; i++){
        t[i] = classe[i].note;
    }
    max3[0] = maxIndex(t, count);
    max3[1] = maxIndex(t, count);
    max3[2] = maxIndex(t, count);
    for (int i = 0; i < 3; i++) {
        printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                classe[max3[i]].id, classe[max3[i]].nom, classe[max3[i]].prenom,
                classe[max3[i]].date_naissance.jour, classe[max3[i]].date_naissance.mois,
                classe[max3[i]].date_naissance.annee, departement(classe[max3[i]].departement),
                classe[max3[i]].note);

        }
    break ;
case 5:
    depCountSucces();
    break ;
case 6:
    return ;
default :
    printf("Choix invalide\n");
    break ;
    }

}



void trierEtudiant(){
    int choice ;
    printf("1- Trier les etudiants alphabetiquement selon leur nom de A a Z \n");
    printf("2- Trier les etudiants alphabetiquement selon leur nom de Z a A\n");
    printf("3- Trier les etudiants par moyenne generale par ordre croissant \n");
    printf("4- Trier les etudiants par moyenne generale par ordre decroissant \n");
    printf("5- Trier les etudiants selon leur statut de reussite  \n");
    printf("6- Retourner au menu \n");
    scanf("%d", &choice);
    switch (choice){
    case 1:
        for( int i =0 ; i< count -1; i++){
            for(int j=0; j<count-i-1; j++){
                if(strcmp(classe[j].nom, classe[j+1].nom)>0){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 2:
        for( int i =0 ; i< count -1; i++){
            for(int j=0; j<count-i-1; j++){
                if(strcmp(classe[j].nom, classe[j+1].nom)<0){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 3:
        for(int i =0 ; i< count -1; i++){
            for(int j = 0 ; j< count -i -1 ; j++){
                if(classe[j].note>classe[j+1].note){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 4:
         for(int i =0 ; i< count -1; i++){
            for(int j = 0 ; j< count -i -1 ; j++){
                if(classe[j].note<classe[j+1].note){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 5:
        for(int i =0 ; i< count -1; i++){
            for(int j = 0 ; j< count -i -1 ; j++){
                if(classe[j].note<classe[j+1].note){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        for(int i =0 ; i< count ; i++){
            if(classe[i].note>10){
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
            }

        }
        break ;
    case 6:
        return ;
    default :
        printf("Choix invalide \n");
        break ;

    }
}

int main(){
    int choix ;
    do{
        printf("---Menu---\n\n");
        printf("1- Ajouter un etudiant a l'universite\n");
        printf("2- Modifier un etudiant\n");
        printf("3- Supprimer un etudiant\n");
        printf("4- Afficher tous les etudiants\n");
        printf("5- Rechercher un etudiant\n");
        printf("6- Afficher les etudiants d'une departement\n");
        printf("7- Calculer la moyenne generale\n");
        printf("8- Afficher les statistiques\n");
        printf("9- Trier les etudiants \n");
        printf("0- Quitter \n");
        printf("\n Votre choix \n\n");
        scanf("%d", &choix);
        switch(choix){
            case 1: ajouterEtudiant();
                break;
            case 2: modifierEtudiant();
                break;
            case 3: supprimerEtudiant();
                break ;
            case 4: afficherEtudiants();
                break ;
            case 5: rechercherEtudiant();
                break;
            case 6: afficherDepartement();
                break;
            case 7: claculMoyenne();
                break;
            case 8: afficherStats();
                break;
            case 9: trierEtudiant();
                break;
            default:
                break ;
        }
    }while(choix!=0);
    return 0;
}
