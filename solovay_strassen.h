#ifndef SOLOVAY_STRASSEN
#define SOLOVAY_STRASSEN

/*
 * Fonction qui réalise la teste de primalité de solovay strassen selon le symbole de jacobi en 
 * utilisant la méthode de l'exponentiation modulaire pour accélerer le calcul de grandes puissances.
 * Arguments : a un entier , n le nombre à tester
 * Retour    : True s'il est probablement premier et false s'il est composé.
*/
_Bool solovay_strassen(mpz_t n, unsigned long long int k);

#endif

