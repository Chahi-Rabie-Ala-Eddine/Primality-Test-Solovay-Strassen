#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "square_and_multiply.h"
#include "symbol_of_jacobi.h"
#include "arithmetic.h"

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
void sq_and_mul(mpz_t result,mpz_t x,mpz_t a,mpz_t p)
{
	mpz_t  q,r,b;

	mpz_init(r);
	mpz_init(q);
	mpz_init(result);
	mpz_init(b);
	mpz_set_ui(result,1);

	//Conversion en binaire
	int size=0;
	char *Binary = malloc(sizeof(char)*99999999); 
	mpz_set(q,a); //q=a;

		do
		{		

			mpz_fdiv_r_ui(r,q,2); //r= q mod 2
			mpz_fdiv_q_ui(q,q,2);	//q = q / 2
			char c = mpz_get_ui(r) + 48; // c = '0' ou c = '1'
			Binary[size] = c;	//concaténer c avec le reste de Binary
			size++;


		}while(mpz_cmp_ui(q,1) >= 0); // Tant que q >= 1

	//s contient le nombre en binaire.reverse

		if(mpz_cmp_ui(a,1) >= 0) mpz_set(result,x); 
		
		for (int i = 0 ; i < strlen(Binary)-1 ; i++)
		{
			mpz_mul(b,result,result); //square
			mpz_set(result,b);
			if (Binary[i] == '1')
			{	
				mpz_mul(result,result,x); //y= y .x -> MUL	
			}
			mpz_mod(result,result,p);	// x^a mod p
		}	

		


	mpz_clear(r);
	mpz_clear(q);
	mpz_clear(b);
	free(Binary);

}
