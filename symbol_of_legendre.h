#ifndef SYMBOL_OF_LEGENDRE
#define SYMBOL_OF_LEGENDRE

/*
 * Fonction qui vérifie si un nombre est résidu quadratique modulo un autre nombre.
 * Arguments : les deux nombres a et p.
 * Retour    : True si a est résidu quadratique modulo p , 0 sinon.
*/
_Bool is_quadratic_residu(mpz_t a, mpz_t p);
/*
 * Fonction qui calcule le symbole de legendre de deux nombres
 * Arguments : les deux nombres a et p.
 * Retour    : ne retourne rien.
*/
void symbol_of_legendre(mpz_t a, mpz_t p);

#endif
