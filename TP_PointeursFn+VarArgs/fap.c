#include "fap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


fap creer_fap_vide(int (*pointeur_fap)(int, int))
{
  fap resultat;
  resultat.cmp = pointeur_fap;
  resultat.tete = NULL;
  return resultat;
}

fap inserer(fap f, int element, int priorite)
{
  struct maillon *nouveau, *courant, *precedent;

  nouveau = (struct maillon *) malloc(sizeof(struct maillon));
  nouveau->element = element;
  nouveau->priorite = priorite;
  if ((f.tete == NULL) || f.cmp(priorite,f.tete->priorite))
    {
      nouveau->prochain = f.tete;
      f.tete = nouveau;
    }
  else
    {
      precedent = f.tete;
      courant = precedent->prochain;
      while ((courant != NULL) && !f.cmp(priorite,courant->priorite))
        {
          precedent = courant;
          courant = courant->prochain;
        }
      precedent->prochain = nouveau;
      nouveau->prochain = courant;
    }
  return f;
}
  
fap extraire(fap f, int *element, int *priorite)
{
  struct maillon *courant;

  if (f.tete != NULL)
    {
      courant = f.tete;
      *element = courant->element;
      *priorite = courant->priorite;
      f.tete = courant->prochain;
      free(courant);
    }
  return f;
}

int est_fap_vide(fap f)
{
  return f.tete == NULL;
}

void detruire_fap(fap f)
{
  int element, priorite;

  while (!est_fap_vide(f))
      f = extraire(f,&element,&priorite);
}
int cmp_c(int a, int b)
{
  return (a > b);
}

int cmp_d(int a, int b)
{
  return (a < b);
}

int cmp_0(int a, int b)
{
  return 0;
}

int cmp_1(int a, int b)
{
  return 1;
}

int cmp_a(int a, int b)
{
  return rand() % 2;
}

