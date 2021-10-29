#include "fap.h"
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_BUFFER 128

void aide_pile(int i)
{
  fprintf(stderr, "Choix de la priorité de la pile %d :\n", i);
  fprintf(stderr, "Saisir l'une des commandes suivantes\n");
  fprintf(stderr, "\n");
  fprintf(stderr, "c : croissante\n");
  fprintf(stderr, "d : décroissante\n");
  fprintf(stderr, "1 : 1\n");
  fprintf(stderr, "0 : 0\n");
  fprintf(stderr, "a : aléatoire\n");
}

void choix_pile(int i, fap* f)
{
  char buffer[TAILLE_BUFFER];
  aide_pile(i);
  char commande = getchar();
  switch (commande)
  {
  case 'c':
    *f = creer_fap_vide(cmp_d);
    break;
  case 'd':
    *f = creer_fap_vide(cmp_d);
    break;
  case '0':
    *f = creer_fap_vide(cmp_0);
    break;
  case '1':
    *f = creer_fap_vide(cmp_1);
    break;
  case 'a':
    *f = creer_fap_vide(cmp_a);
    break;
  default:
    fprintf(stderr, "Commande inconnue !\n");
    fgets(buffer, TAILLE_BUFFER, stdin);
    choix_pile(i,f);
  }
  fgets(buffer, TAILLE_BUFFER, stdin);
}

void aide()
{
  fprintf(stderr, "Aide :\n");
  fprintf(stderr, "Saisir l'une des commandes suivantes\n");
  fprintf(stderr, "\n");
  fprintf(stderr, "i nombre priorite  :   inserer un nombre avec sa priorite\n");
  fprintf(stderr, "e                  :   extraire le nombre de priorite maximale\n");
  fprintf(stderr, "v                  :   teste si la fap est vide\n");
  fprintf(stderr, "h                  :   afficher cette aide\n");
  fprintf(stderr, "q                  :   quitter ce programme\n");
}

int main()
{
  char buffer[TAILLE_BUFFER];
  char commande;
  int nombre1, priorite1, nombre2, priorite2;
  fap f1, f2;

  choix_pile(1,&f1);
  choix_pile(2,&f2);

  aide();
  while (1)
  {
    commande = getchar();
    switch (commande)
    {
    case 'i':
      scanf("%d", &nombre1);
      scanf("%d", &priorite1);
      f1 = inserer(f1, nombre1, priorite1);
      f2 = inserer(f2, nombre1, priorite1);
      nombre2 = nombre1;
      priorite2 = priorite1;
      printf("(%d,%d) a ete insere\n", nombre1, priorite1);
      break;
    case 'e':
      if (!est_fap_vide(f1) && !est_fap_vide(f2))
      {
        f1 = extraire(f1, &nombre1, &priorite1);
        printf("(%d,%d) a ete extrait\n", nombre1, priorite1);
        f2 = extraire(f2, &nombre2, &priorite2);
        printf("(%d,%d) a ete extrait\n", nombre2, priorite2);
      }
      else
        printf("Les faps sont vide !\n");
      break;
    case 'v':
      printf("Est_fap_vide a retourne %d\n", est_fap_vide(f1));
      break;
    case 'h':
      aide();
      break;
    case 'q':
      detruire_fap(f1);
      detruire_fap(f2);
      exit(0);
    default:
      fprintf(stderr, "Commande inconnue !\n");
    }
    /* vide ce qu'il reste de la ligne dans le buffer d'entree */
    fgets(buffer, TAILLE_BUFFER, stdin);
  }
  detruire_fap(f1);
  detruire_fap(f2);
  return 0;
}
