#include "vecteur_dynamique.h"
#include "utils_vecteur.h"
#include "utils_tests.h"
#include <stdio.h>

void teste_vecteur(vecteur v) {
    int i;
    int limite, extra = 100;

    limite = taille_vecteur(v);
    printf("Taille vecteur \n");
    for (i = -extra; i < limite + extra; i++){
        if (acces_vecteur(v, i) != NULL){
            *acces_vecteur(v, i) = i % 10;
            printf("Accès vecteur %d", i);
        }            
    }
        
    for (i = -extra; i < limite + extra; i++)
        if (acces_vecteur(v, i) != NULL)
            affiche_test("%g", *acces_vecteur(v, i));
    affiche_test("\n");
}

int main(int argc, char *argv[]) {
    vecteur v1, v2;
    printf("debut\n");
    init(argv[1]);
    printf("début\n");
    v1 = lit_vecteur("vecteur1.txt");
    printf("lit vecteur 1\n");
    teste_vecteur(v1);
    printf("test vecteur 1\n");
    liberer_vecteur(v1);
    printf("libere vecteur 1\n");
    v2 = lit_vecteur("vecteur2.txt");
    printf("lit vecteur 1\n");
    teste_vecteur(v2);
    printf("teste vecteur 1\n");
    liberer_vecteur(v2);
    printf("libere vecteur 1\n");

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
