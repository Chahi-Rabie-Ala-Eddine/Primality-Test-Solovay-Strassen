#ifndef ARITHMETIC
#define ARITHMETIC

/*
 * Fonction qui teste si un nombre est pair ou impair
 * Arguments : le nombre à évalué 
 * Retour    : True s'il est pair et False sinon
*/
_Bool is_even_or_odd(mpz_t x);
/*
 * Fonction qui teste si un nombre est pair ou impair
 * Arguments : le nombre à évalué 
 * Retour    : True s'il est pair et False sinon
*/
_Bool is_congruent(mpz_t n, unsigned long int mod, unsigned long int val);
/*
 * Fonction qui calcule le pgcd de deux nombre à l'aide de la méthode : ALGORITHME D'EUCLIDE 
 * On soustrait un nombre de l'autre autant de fois qu'on peut et on regarde ce qui reste.
 * Cela revient à faire une division euclidienne.
 * Arguments : les deux nombres x et y.
 * Retour    : 1 si les deux nombres sont premiers entre eux et 0 sinon.
*/
_Bool check_coprimes(mpz_t x, mpz_t y);

#endif
