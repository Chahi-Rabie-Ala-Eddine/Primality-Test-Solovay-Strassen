#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "arithmetic.h"
#include "symbol_of_jacobi.h"
#include "symbol_of_legendre.h"

/*
 * Fonction qui réalise la propriété 1 du symbole de jacobi 
 * Arguments : a un entier , n le nombre qu'on cherche à savoir s'il est premier ou pas.
 * Retour    : 1 si on peut réduire a modolu n et 0 sinon.
*/
int first_proprety(mpz_t temp, mpz_t a, mpz_t n)
{	
	mpz_mod(temp,a,n);

	if(mpz_cmp_ui(temp,0) != 0)
	{	
		return 1;
	}
	
	return 0;
}
/*
 * Fonction qui réalise la propriété 2 du symbole de jacobi 
 * Arguments : a un entier , n le nombre qu'on cherche à savoir s'il est premier ou pas.
 * Retour    : 0 si n divise a et la valeur du symbole_de jacobi sinon.
*/
int second_proprety(mpz_t a, mpz_t n)
{
	if(!check_coprimes(a,n))
		return 0;
	else
		return symbol_of_jacobi(a,n);
}
/*
 * Fonction qui réalise la propriété 3 du symbole de jacobi 
 * Arguments : a un entier à décomposer si possible en facteur
 * Retour    : 1 si a est un multiple de deux 0 sinon.
*/
int third_proprety(mpz_t a, mpz_t value, mpz_t pow)
{	
	mpz_t temp;
	mpz_t memory;
	mpz_init(temp);
	mpz_init(memory);
	mpz_set(memory,a);
	
	mpz_mod_ui(value,memory,2);
	if(!mpz_cmp_ui(value,0))
	{
		while(!mpz_cmp_ui(value,0))
		{
			mpz_set(temp,memory);
			mpz_mod_ui(value,memory,2);
			mpz_fdiv_q_ui(memory,memory,2);
			if(mpz_cmp_ui(value,0))
			{
				mpz_set(memory,temp);
				break;
			}
			mpz_add_ui(pow,pow,1);
		}
		mpz_set(value,memory);
		//gmp_printf("= 2 ^ %Zd * %Zd\n",pow,memory);
		
		mpz_clear(memory);
		mpz_clear(temp);
		
		return 1;
	}
	else
	{
		mpz_clear(memory);
		mpz_clear(temp);
		
		return 0;
	}
	
	mpz_clear(memory);
	mpz_clear(temp);
		
	return 1;
}
/*
 * Fonction qui réalise la propriété 4 du symbole de jacobi 
 * Arguments : a un entier.
 * Retour    : 1 si a = 1 et donc jacobi(a,n) = 1 et 0 sinon.
*/
int fourth_proprety(mpz_t a)
{
	if(!mpz_cmp_ui(a,1))
	{
		return 1;
	}
	
	return 0;
}
/*
 * Fonction qui réalise la propriété 5 du symbole de jacobi 
 * Arguments : n le nombre qu'on cherche à savoir s'il est premier ou pas.
 * Retour    : 1 si n = 1 mod 8 ou n = 7 mod 8, -1 si n = 3 mod 8 ou n = 5 mod 8 et 0 sinon.
*/
int fifth_proprety(mpz_t n)
{
	if(is_congruent(n,8,1) || is_congruent(n,8,7))
		return 1;
	
	if(is_congruent(n,8,3) || is_congruent(n,8,5))
		return -1;
	
	return 0;
}
/*
 * Fonction qui réalise la propriété 6 du symbole de jacobi ( Loi de réciprocité quadratique )
 * Arguments : n le nombre qu'on cherche à savoir s'il est premier ou pas, m un entier.
 * Retour    : 1 si m et n sont premier et que n ou m = 1 mod 4, et -1 si n et m = 3 mod 4 ou n = 5 mod 8 et 0 sinon.
*/
int sixth_proprety(mpz_t m, mpz_t n)
{
	if(check_coprimes(m,n))
	{
		if(is_congruent(n,4,1) || is_congruent(m,4,1))
		{
			return 1;
		}
		
		if(is_congruent(n,4,3) && is_congruent(m,4,3))
		{
			return -1;
		}
	}
	
	return 0;
}
/*
 * Fonction qui calcule le symbol de jacobi selon l'algorithme de notre Professeur.
 * Arguments : a un entier , n un nombre entier dont on souhaite tester la primalité il ne doit être ni égal à 0 ni pair
 * Retour    : 1 si a = 1 et donc jacobi(a,n) = 1 et 0 sinon.
*/
int symbol_of_jacobi(mpz_t a, mpz_t n)
{	
	mpz_t temp;
	mpz_t value;
	mpz_init(temp);
	mpz_init(value);
	
	//Vérifions que n est différent de 0
	if(!mpz_cmp_ui(n,0))
	{
		puts("\n\n\nError n must be different than 0");
		mpz_clear(value);
		mpz_clear(temp);
		
		exit(0);
	}
	
	//Vérifions si n est impair 
	if(is_even_or_odd(n))
	{
		puts("\n\n\nBottom must be odd\n");
		mpz_clear(value);
		mpz_clear(temp);
		
		exit(0);
	}
	 	
	//Vérifions que n ne divise pas a
	mpz_mod(temp,a,n);
	
	if(!mpz_cmp_ui(temp,0))
	{
		mpz_clear(value);
		mpz_clear(temp);
		
		return 0;
	}
	
	//étape 1

	//propriété 1
	
	mpz_mod(temp,a,n);
	
	if(mpz_cmp(temp,a) != 0)
	{	
		return symbol_of_jacobi(temp,n);
	}
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	
	//étapae 2
	//printf("==> STEP 2\n");
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	//propriété 3
	third_proprety(a,temp,value);
	//gmp_printf("(2 / %Zd) ^ %Zd * (%Zd / %Zd)\n",n,value,temp,n);
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	
	//propriété 5
	if(mpz_cmp_ui(value,0) != 0)
	{
		if(mpz_cmp_ui(temp,1) != 0)
		{
			if(fifth_proprety(n) == 1) //si n = 1 mod 8 ou n = 7 mod 8
			{
				mpz_set(a,temp);
			}
			if(fifth_proprety(n) == -1) //si n = 3 mod 8 ou n = 5 mod 8
			{
				//gmp_printf("je suis dans le else if temp vaut = %Zd\n",temp);
				mpz_mod_ui(value,value,2);
				
				if(!mpz_cmp_ui(value,0)) //si la puissance est pair
					return symbol_of_jacobi(temp,n);
					
				if(mpz_cmp_ui(value,0) != 0) // si la puissance est impair
					return -symbol_of_jacobi(temp,n);
			}		
		}
		//gmp_printf("avant le if temp vaut = %Zd\n",temp);
		if(!mpz_cmp_ui(temp,1))
		{ 	
			//gmp_printf("je suis dans le if n = %Zd\n",n);
			if(fifth_proprety(n) == 1) //si n = 1 mod 8 ou n = 7 mod 8
			{
				//gmp_printf("je suis dans le if temp vaut = %Zd\n",temp);
				//printf("RETURN 1\n");
				mpz_clear(value);
				mpz_clear(temp);
				
				return 1;
			}
			if(fifth_proprety(n) == -1) //si n = 3 mod 8 ou n = 5 mod 8
			{
				//gmp_printf("je suis dans le else if temp vaut = %Zd\n",temp);
				mpz_mod_ui(value,value,2);
				
				if(!mpz_cmp_ui(value,0)) //si la puissance est pair
				{
					//printf("RETURN 2\n");
					mpz_clear(value);
					mpz_clear(temp);
					
					return 1;
				}
					
				if(mpz_cmp_ui(value,0) != 0) // si la puissance est impair
				{
					mpz_clear(value);
					mpz_clear(temp);
					//printf("RETURN 3\n");
					return -1;
				}
			}	
		}
	}
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	
	//étape 3
	//gmp_printf("==> STEP 3\n",a);
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	if(!mpz_cmp_ui(a,1))
	{
		//printf("RETURN 4\n");
		return fourth_proprety(a);
	}
		
	else if(!check_coprimes(a,n))
	{
		mpz_clear(value);
		mpz_clear(temp);
		//printf("RETURN 5\n");
		return 0;
	}
	
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	
	//étape 4
	//printf("==> STEP 4\n");
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	
	if(sixth_proprety(a,n) == 1)
		{
			//printf("jacobi +\n");
			return symbol_of_jacobi(n,a);
		}
	
	if(sixth_proprety(a,n) == -1)
	{
		//printf("jacobi -\n");
		return (-symbol_of_jacobi(n,a));
	}
	
	//gmp_printf("(%Zd / %Zd)\n",a,n);
	
	//printf("RETURN 6\n");
	mpz_clear(value);
	mpz_clear(temp);
	
	return 0;
}

