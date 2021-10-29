typedef struct noeud noeud;
struct noeud
{
    
};

typedef struct pile pile;
struct pile
{
    int donnee; 
    pile *suivant;
    noeud *noeud;
};

/*
   pile_vide
   description : construit une pile vide
   parametres : aucun
   valeur de retour : une pile vide
   effets de bord : aucun
*/
pile pile_vide();

/*
   detruire_pile
   description : detruit une pile
   parametres : une pile a detruire
   valeur de retour : aucune
   effets de bord : la pile passee en parametre n'est plus utilisable
*/
void detruire_pile(pile p);

/*
   empiler
   description : ajoute une donnee au sommet de la pile
   parametres : donnee a ajouter, pile sur laquelle on ajoute
   valeur de retour : la pile avec la donnee en plus
   effets de bord : la pile passee en parametre n'est plus utilisable
                    (sinon perte de coherence du chainage)
*/
pile empiler(int donnee, pile p);

/*
   sommet
   description : retourne la valeur de l'element au sommet de la pile ou 0 si
                 la pile est vide
   parametres : pile
   valeur de retour : valeur du sommet de la pile
   effets de bord : aucun
*/
int sommet(pile p);

/*
   depiler
   description : supprime le sommet de la pile
   parametres : pile dans laquelle on souhaite depiler
   valeur de retour : la pile avec son sommet en moins
   effets de bord : la pile passee en parametre n'est plus utilisable
*/
pile depiler(pile p);

/*
   est_pile_vide
   description : retourne 1 si la pile passee en parametre est vide
   parametres : pile
   valeur de retour : 1 si la pile passee en parametre est vide, 0 sinon
   effets de bord : aucun
*/
int est_pile_vide(pile p);

