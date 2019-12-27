#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "arithmetic.h"
#include "symbol_of_jacobi.h"
#include "symbol_of_legendre.h"
#include "square_and_multiply.h"
#include "solovay_strassen.h"

int main(int argc, char** argv)
{	
	mpz_t n;
	mpz_init(n);
	
	printf("\n\n\n\n\n\n\n");
	printf("\n\n\n\n                      BONJOUR ET BIENVENUE SUR NOTRE APPLICATION\n");
	printf("                    VOUS POUVEZ ENCORE TESTER PLUS DE CHOSE COMME \n");
	printf("\n");
	printf ("\033[36;01m                            CALCULER LE SYMBOLE DE JACOBI \033[00m");
	printf("\n");
	printf ("\033[31;01m                            CALCULER LE SYMBOLE DE LEGENDRE \033[00m");
	printf("\n");
	printf ("\033[37;01m                   TESTER SI DEUX NOMBRES SONT PREMIERS ENTRE EUX \033[00m");
	printf("\n\n");
	printf ("\033[33;01m                      POUR PLUS D'INFORMATION LISEZ LE READ-ME \033[00m");
	printf("\n\n");
	printf ("\033[39;01m               DÉVELOPPEURS : CHAHI RABIE ALA EDDINE & KESKES YASMINE \033[00m");
	
	//TEST 1 TESTE DE PRIMALITÉ DE SOLOVAY STRASSEN 
	if(!strcmp(argv[1],"primality_test"))
	{
		mpz_init_set_str(n,argv[2],10);
		solovay_strassen(n,10);	
	}
	
	//TEST 2 CALCUL DU SYMBOLE DE JACOBI
	if(!strcmp(argv[1],"symbol_of_jacobi"))
	{
		mpz_t a;
		mpz_init(a);
		mpz_init_set_str(n,argv[3],10);
		mpz_init_set_str(a,argv[2],10);
		printf("\n\n");
		printf ("\033[36;01mSymbol de jacobi \033[00m");
		gmp_printf("(%Zd / %Zd)",a,n);
		printf(" = %d\n",symbol_of_jacobi(a,n));
		mpz_clear(a);	
	}
	
	//TEST 3 CALCUL DU SYMBOLE DE LEGENDRE
	if(!strcmp(argv[1],"symbol_of_legendre"))
	{
		mpz_t a;
		mpz_init(a);
		mpz_init_set_str(n,argv[3],10);
		mpz_init_set_str(a,argv[2],10);
		if(!solovay_strassen(n,10))
		{
			puts("P must be prime\n");
			mpz_clear(a);	
			
			exit(0);
		}
		symbol_of_legendre(a,n);
		mpz_clear(a);	
	}
	
	//TEST 4 TESTE SI DEUX NOMBRES SONT PREMIERS ENTRE EUX
	if(!strcmp(argv[1],"coprimes"))
	{
		mpz_t a;
		mpz_init(a);
		mpz_init_set_str(n,argv[3],10);
		mpz_init_set_str(a,argv[2],10);
		if(check_coprimes(a,n))
			printf("They are coprimes\n");
		else
			printf("They are not coprimes\n");
		mpz_clear(a);	
	}
	
	printf("\n\n\n");
	
	mpz_clear(n);
	
	return 0;
}
