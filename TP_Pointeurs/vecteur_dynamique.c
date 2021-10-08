#include "vecteur_dynamique.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = malloc(sizeof(struct donnees_vecteur));
    if(taille > 0){
        v->taille = taille;
        v->donnees = malloc(taille*sizeof(double));
    } else {
        v->taille = -1;
        v->donnees = NULL;
    }
    return v;
}

void liberer_vecteur(vecteur v) {
    free(v->donnees);
    free(v);
}

int est_vecteur_invalide(vecteur v) {
    int resultat = 0;
    if(v->taille == -1 || v->donnees == NULL){
        resultat = 1;
    }
    return resultat;
}

double *acces_vecteur(vecteur v, int i) {
    if(i < 0){
        return NULL;
    } else {
        if(i >= v->taille){
            v->taille = i+1;
            v->donnees = realloc(v->donnees,(i+1)*sizeof(double));
        }
        double *resultat = &v->donnees[i];
        return resultat;
        }
}


int taille_vecteur(vecteur v) {
    return v->taille;
}
