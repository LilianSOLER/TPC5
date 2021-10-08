#include "vecteur.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v;
    if(taille < 0){
        v.taille = -1;
        v.donnees = NULL;
    } else {
        v.taille = taille;
        v.donnees = malloc(taille*sizeof(double));
    }
    return v;
}

void liberer_vecteur(vecteur v) {
    free(v.donnees);
}

int est_vecteur_invalide(vecteur v) {
    int res = 0;
    if(v.taille == -1){
        res = 1;
    }
    return res;
}

double *acces_vecteur(vecteur v, int i) {
    double *res = &v.donnees[i];
    return res;
}

int taille_vecteur(vecteur v) {
    return v.taille;
}

