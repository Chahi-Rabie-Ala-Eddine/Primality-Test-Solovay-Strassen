#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "symbol_of_legendre.h"
#include "symbol_of_jacobi.h"
#include "square_and_multiply.h"
#include "solovay_strassen.h"
#include "arithmetic.h"

/*
 * Fonction qui vérifie si un nombre est résidu quadratique modulo un autre nombre.
 * Arguments : les deux nombres a et p.
 * Retour    : True si a est résidu quadratique modulo p , 0 sinon.
*/
_Bool is_quadratic_residu(mpz_t a, mpz_t p)
{
	mpz_t x,y,var,temp,val;
	mpz_init_set_str(x, "0", 10); // x <- 0
	mpz_init_set_str(y, "1", 10); // y <- 1
	mpz_init_set_str(var, "2", 10);// var <- 2
	mpz_init_set_str(temp, "0", 10);// temp <- 0
	mpz_init_set_str(val, "0", 10);// val <- 0
	mpz_set(val,p); 
	mpz_add(p,p,y); // p <- p + y
	mpz_fdiv_q(p,p,var); // p <- p / var
	mpz_add(p,p,y); //p <- p + y 
	do
	{	
		mpz_add(x,x,y); // x <- x + y
		mpz_mul(temp,x,x); // temp <- x^2
		mpz_fdiv_r(temp,temp,val); //temp <- temp % val
		//gmp_printf("==>x = %Zd temp = %Zd \n",x,temp);
		if(mpz_cmp(temp,a) == 0) // si temp = a 
		{
			gmp_printf("%Zd est résidu quadratique modulo %Zd\n\n",a,val);
			return true;
		}
		
		gmp_printf("x = %Zd a = %Zd p = %Zd\n",x,a,p);
	}while(mpz_cmp (p, x)); // tant que x < p
	
	gmp_printf("%Zd n'est pas résidu quadratique modulo %Zd\n",a,val);
	
	return false;
}
/*
 * Fonction qui calcule le symbole de legendre de deux nombres
 * Arguments : les deux nombres a et p.
 * Retour    : ne retourne rien.
*/
void symbol_of_legendre(mpz_t a, mpz_t p)
{
	mpz_t temp;
	mpz_init(temp);
	
	//Vérifions que n ne divise pas a
	mpz_mod(temp,a,p);
	
	if(!mpz_cmp_ui(temp,0))
	{
		mpz_clear(temp);		
		printf("Symbol de legendre = 0\n");
		
		exit(0);
	}
	
	mpz_sub_ui(temp,p,1);
	mpz_fdiv_q_ui(temp,temp,2);
	sq_and_mul(a,a,temp,p);
	
	gmp_printf("Symbol de legendre = %Zd\n",a);
	
	mpz_clear(temp);
	
}
