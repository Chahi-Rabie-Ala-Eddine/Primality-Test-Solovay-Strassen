#ifndef SQUARE_AND_MULTIPLY
#define SQUARE_AND_MULTIPLY

/*
 * Fonction d’exponentiation modulaire rapide (SQUARE AND MULTIPLY)
 * On converti L'exposant en binaire  ( en faisant des divisions successives du nombre sur 2)
 * On le stocke sous forme de chaine de caractères en commençant par le bit de poids fort ( Binary[0]== le bit de poids faible)
 * Ensuite on lit cette dernière Caractère par caractère en commançant par Binary[0] et on s'arrete a l'avant dernier Bit 
 * (selon l'algorithme de Square and multiply) 
 * si le bit == 0 on fait un SQUARE sinon (bit == 1) on fait un SQUARE and MULTIPLY
 * on prend le reste de la division de la BASE sur  le MODULO 
 * Arguments : La base x ,l'exposant a, Le modulo p
 * Retour    : Le resultat de l'expenentiation modulaire  de type mpz_t
*/
void sq_and_mul(mpz_t result,mpz_t x,mpz_t a,mpz_t p);

#endif
