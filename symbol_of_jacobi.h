#ifndef SYMBOL_OF_JACOBI
#define SYMBOL_OF_JACOBI

/*
 * Fonction qui réalise la propriété 1 du symbole de jacobi 
 * Arguments : a un entier , n le nombre qu'on cherche à savoir s'il est premier ou pas.
 * Retour    : 1 si on peut réduire a modolu n et 0 sinon.
*/
int first_proprety(mpz_t temp, mpz_t a, mpz_t n);
/*
 * Fonction qui réalise la propriété 2 du symbole de jacobi 
 * Arguments : a un entier , n le nombre qu'on cherche à savoir s'il est premier ou pas.
 * Retour    : 0 si n divise a et la valeur du symbole_de jacobi sinon.
*/
int second_proprety(mpz_t a, mpz_t n);
/*
 * Fonction qui réalise la propriété 3 du symbole de jacobi 
 * Arguments : a un entier à décomposer si possible en facteur
 * Retour    : 1 si a est un multiple de deux 0 sinon.
*/
int third_proprety(mpz_t a, mpz_t value, mpz_t pow);
/*
 * Fonction qui réalise la propriété 4 du symbole de jacobi 
 * Arguments : a un entier.
 * Retour    : 1 si a = 1 et donc jacobi(a,n) = 1 et 0 sinon.
*/
int fourth_proprety(mpz_t a);
/*
 * Fonction qui réalise la propriété 5 du symbole de jacobi 
 * Arguments : n le nombre qu'on cherche à savoir s'il est premier ou pas.
 * Retour    : 1 si n = 1 mod 8 ou n = 7 mod 8, -1 si n = 3 mod 8 ou n = 5 mod 8 et 0 sinon.
*/
int fifth_proprety(mpz_t n);
/*
 * Fonction qui réalise la propriété 6 du symbole de jacobi ( Loi de réciprocité quadratique )
 * Arguments : n le nombre qu'on cherche à savoir s'il est premier ou pas, m un entier.
 * Retour    : 1 si m et n sont premier et que n ou m = 1 mod 4, et -1 si n et m = 3 mod 4 ou n = 5 mod 8 et 0 sinon.
*/
int sixth_proprety(mpz_t m, mpz_t n);
/*
 * Fonction qui calcule le symbol de jacobi selon l'algorithme de notre Professeur.
 * Arguments : a un entier , n un nombre entier dont on souhaite tester la primalité il ne doit être ni égal à 0 ni pair
 * Retour    : 1 si a = 1 et donc jacobi(a,n) = 1 et 0 sinon.
*/
int symbol_of_jacobi(mpz_t a, mpz_t n);

#endif
