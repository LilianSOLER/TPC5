#include "matrice.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    matrice m = {-1, -1, NULL};
    if(l != 0 || c != 0){
        m.l = l;
        m.c = c;
        m.donnees = malloc(l*sizeof(double*));

        for(int i = 0; i < l ; i++){
            m.donnees[i] = malloc(c*sizeof(double));
        }
    }
    return m;
}

void liberer_matrice(matrice m) {
    for(int i = 0; i < m.l ; i++){
            free(m.donnees[i]);
        }
    free(m.donnees);
}

int est_matrice_invalide(matrice m) {
    int resultat = 0;
    if(m.l == 0 || m.c == 0 || m.donnees == NULL ){
        resultat = 1;
    }
    return resultat;
}

double *acces_matrice(matrice m, int i, int j) {
    double *resultat = m.donnees[i];
    return &resultat[j];
}

int nb_lignes_matrice(matrice m) {
    return m.l;
}

int nb_colonnes_matrice(matrice m) {
    return m.c;
}
