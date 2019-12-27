#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "solovay_strassen.h"
#include "symbol_of_jacobi.h"
#include "symbol_of_legendre.h"
#include "square_and_multiply.h"
#include "arithmetic.h"

/*
 * Fonction qui réalise la teste de primalité de solovay strassen selon le symbole de jacobi en 
 * utilisant la méthode de l'exponentiation modulaire pour accélerer le calcul de grandes puissances.
 * Arguments : a un entier , n le nombre à tester
 * Retour    : True s'il est probablement premier et false s'il est composé.
*/
_Bool solovay_strassen(mpz_t n, unsigned long long int k)
{
	if(!mpz_cmp_ui(n,0))
	{
		puts("\n\nError n must be different than 0");

		exit(0);
	}
	mpz_t a;
	mpz_t result;
	mpz_t temp;
	int symbol = 0;
    gmp_randstate_t state;
    mpz_init(a);
    mpz_init(result);
    mpz_init(temp);
    gmp_randinit_default (state);
    
	for(unsigned long long int i = 0 ; i <= k ; i++)
	{
		mpz_urandomm (a, state, n);
		if(mpz_cmp_ui(a,2) < 0)
			continue;
			
		symbol = symbol_of_jacobi(a,n);
		//printf("%d\n",symbol);
		//(n-1) / 2
		mpz_sub_ui(temp,n,1);
		mpz_fdiv_q_ui(temp,temp,2);
		sq_and_mul(result,a,temp,n);
		
		mpz_fdiv_q(temp,result,n);
		
		if((symbol == 0) || (!mpz_cmp_ui(temp,symbol)))
		{
			mpz_clear(a);
			mpz_clear(result);
			mpz_clear(temp);
			printf("\n\n");
			printf ("\033[34;01mPrimality : \033[00m");
			printf ("\033[39;01mComposed \033[00m");
			printf("\n\n");
			

			return false;
		}
	}
	
	mpz_clear(a);
	mpz_clear(result);
	mpz_clear(temp);
	printf("\n\n");
	printf ("\033[32;01mPrimality : \033[00m");
	printf ("\033[31;01mPropably prime \033[00m");
	printf("\n\n");

	return true;
}
