#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "arithmetic.h"

/*
 * Fonction qui teste si un nombre est pair ou impair
 * Arguments : le nombre à évalué 
 * Retour    : True s'il est pair et False sinon
*/
_Bool is_even_or_odd(mpz_t x)
{
	mpz_t value;
	mpz_init(value);
	mpz_mod_ui(value,x,2);
	if(!mpz_cmp_ui(value,0))
	{
		/* 
		* Mettre ce code en clair pour avoir le pgcd
		* gmp_printf("%Zd is even\n",x);
		*/
		mpz_clear(value);
		
		return true;
	}
	else
	{
		/* 
		* Mettre ce code en clair pour avoir le pgcd
		* gmp_printf("%Zd is odd\n",x);
		*/
		mpz_clear(value);
		
		return false;
	}
}
/*
 * Fonction qui teste si un nombre est pair ou impair
 * Arguments : le nombre à évalué 
 * Retour    : True s'il est pair et False sinon
*/
_Bool is_congruent(mpz_t n, unsigned long int mod, unsigned long int val)
{
	mpz_t temp;
	mpz_init(temp);
	mpz_set(temp,n);
	mpz_sub_ui(n,n,val);
	mpz_mod_ui(n,n,mod);

	if(mpz_cmp_ui(n,0) == -1)
	{
		puts("Error on the rest !\n");
		exit(0);
	}
	if(!mpz_cmp_ui(n,0))
	{
		//gmp_printf("Yes : %Zd = %lu mod %lu\n",temp,val,mod);
		mpz_set(n,temp);
		mpz_clear(temp);
		
		return true;
	}
	else
	{
		mpz_set(n,temp);
		//gmp_printf("No : %Zd =/= %lu mod %lu\n",temp,val,mod);
		mpz_clear(temp);
		
		return false;
	}
		
	return true;
}
/*
 * Fonction qui calcule le pgcd de deux nombre à l'aide de la méthode : ALGORITHME D'EUCLIDE 
 * On soustrait un nombre de l'autre autant de fois qu'on peut et on regarde ce qui reste.
 * Cela revient à faire une division euclidienne.
 * Arguments : les deux nombres x et y.
 * Retour    : 1 si les deux nombres sont premiers entre eux et 0 sinon.
*/
_Bool check_coprimes(mpz_t x, mpz_t y)
{
	mpz_t temp_one;
	mpz_t temp_two;
	mpz_init(temp_one);
	mpz_init(temp_two);
	mpz_set(temp_one,x);
	mpz_set(temp_two,y);

	//si x et y sont égaux alors le pgcd = x = y et x et y ne sont pas premiers entre eux
	if(!mpz_cmp(x,y))
	{
		mpz_clear(temp_one);
		mpz_clear(temp_two);
		
		return 0;
	}
	//si x est supérieurs à y on inverse x et y 
	else if(mpz_cmp(x,y) == -1)
	{
		mpz_t value;
		mpz_init(value);
		mpz_set(value,x);
		mpz_set(x,y);
		mpz_set(y,value);
		mpz_clear(value);
	}
	//on utilise l'algorithme d'Euclide pour calculer le pgcd
	mpz_t rest;
	mpz_t temp;
	mpz_init(rest);
	mpz_init(temp);
	//Boucle dans laquelle le PGCD est calculé
	do
	{
		mpz_set(temp,y);
		mpz_mod(rest,x,y);
		mpz_set(x,y);
		mpz_set(y,rest);
	}
	//Tant que le reste est différent de 0
	while(mpz_cmp_ui(rest,0));
	
	/* 
	 * Mettre ce code en clair pour avoir le pgcd
	 * gmp_printf("GCD = %Zd\n",temp);
	*/
	
	//si le pgcd est négatif
	if(mpz_cmp_ui(temp,1) < 0)
	{
		puts("Errors, impossible value of GCD ! \n");
		exit(0);
	}
	//si le pgcd est 1 et donc si x et y sont premier entre eux
	else if(!mpz_cmp_ui(temp,1))
	{
		mpz_set(x,temp_one);
		mpz_set(y,temp_two);
		mpz_clear(temp);
		mpz_clear(rest);
		mpz_clear(temp_one);
		mpz_clear(temp_two);
		//printf("They are coprimes\n");
		return true;
	}
	//si le pgcg est supérieur à 1 et donc que x et y ne sont pas premiers entre eux
	else
	{
		mpz_set(x,temp_one);
		mpz_set(y,temp_two);
		mpz_clear(temp);
		mpz_clear(rest);
		mpz_clear(temp_one);
		mpz_clear(temp_two);
		//printf("They aren't coprimes\n");
		return false;
	}
		
	//on libère la mémoire des variables usuelles
	mpz_clear(temp_one);
	mpz_clear(temp_two);
	mpz_clear(temp);
	mpz_clear(rest);
	
	return false;
}
