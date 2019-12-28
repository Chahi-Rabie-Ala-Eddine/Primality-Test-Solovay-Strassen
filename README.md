# The Primality Test of Solovay-Strassen

**Version 1.0.0**

This project is carried out as part of a DM of the cryptography module, with the aim to implement in C a primality test which is: the Solovay-Strassen test. This test uses this called the Jacobi symbol to test whether a number is prime or not. To do this test we needed to calculate the jacobi symbol using all the properties of the latter as well as The Square and Multiply algorithm, Parity test, modulo congruence… etc

The project contains 6 files:

1. aritmethic.c and its .h: contain the parity test, the modulo congruence test and the if test two numbers are prime between them.
2.square_and_multiply.c and its .h: contain the modular openentiation algorithm.
3.symbol_of_jacobi.c and its .h: contain all the properties of the jacobi symbol and
the algorithm that calculates this symbol using all of these properties.
4.solovay_strassen.c and its .h: contain the algorithm of the “SolovayStrassen primality test”.
5.symbol_of_legendre.c and its .h: contain The quadratic residue test and the calculation of the symbol to caption.
6.main.c

## Algorithms

1._Bool is_even_or_odd (mpz_t x):
This function is responsible for testing the parity of the number passed as a parameter, by testing whether the rest of the division of the number is equal to 1 (odd) or 0 (even) and returns True if it is even and False if not.

2._Bool is_congruent (mpz_t n, unsigned long int mod, unsigned long int val):
This function tests the congruence of two modulo mod numbers and returns true if they are congruent False otherwise.

3._Bool check_coprimes (mpz_t x, mpz_t y):
This function tests if two numbers are prime between them by first calculating the pgcd of the two numbers x and t using the EUCLIDE ALGORITHM. It is like making a Euclidean division by treating all cases. This function returns TRUE if the pgcd is 1 and therefore the two numbers are prime between them otherwise FALSE.

4.void sq_and_mul (mpz_t result, mpz_t x, mpz_t a, mpz_t p):
This function takes care of the rapid modular exponentiation (SQUARE AND MULTIPLY) First, we convert the exponent to binary (by making successive divisions of the number out of 2). Then, we read the result of the conversion Character by character and we stop at the penultimate bit (according to the algorithm of Square and multiply we do not read the last bit of the weight strong). And we test each time if the bit == 0 we do a SQUARE otherwise (bit == 1) we do a SQUARE and MULTIPLY. We take at each iteration the rest of the division of the result on the Modulo p Finally we store the final result in the variable result.

5.int first_proprety (mpz_t temp, mpz_t a, mpz_t n):
this Function realizes property 1 of the jacobi symbol of (a n). Takes in Arguments: a an integer, n the number we are trying to find out whether it is prime or not. Returns 1 if we can reduce a modolu n, 0 otherwise.

6.int second_proprety (mpz_t a, mpz_t n):
This function realizes property 2 of the jacobi symbol (a, n) takes as an integer a, and n the number we are trying to find out if it is prime or not Return 0 if n divides a and the value of the jacobi_symbol otherwise. 

7.int third_proprety (mpz_t a, mpz_t value, mpz_t pow):
A function that realizes property 3 of the jacobi symbol Take as Input, an integer to decompose if possible into factors and stock the factors in value and pow. Returns 1 if a is a multiple of two 0 otherwise.

8.int fourth_proprety (mpz_t a):
A function which realizes property 4 of the jacobi symbol, takes an integer a like argument and returns 1 if a = 1 and therefore jacobi (a, n) = 1 and 0 otherwise.

9.int fifth_proprety (mpz_t n):
A function which realizes property 5 of the jacobi symbol, it has n as Argument (the number we are trying to find out if it is prime or not). And returns 1 if n = 1 mod 8 or n = 7 mod 8, -1 if n = 3 mod 8 or n = 5 mod 8 and 0 otherwise.

10.int sixth_proprety (mpz_t m, mpz_t n):
A function which realizes property 6 of the jacobi symbol (Law of reciprocity quadratic) its Arguments are: n the number that one seeks to know if it is prime or not, m un whole. This function returns 1 if m and n are prime and n or m = 1 mod 4, and -1 if n and m = 3 mod 4 or n = 5 mod 8 and 0 otherwise.
All these properties will be used to calculate the jacobi symbol (a n).

11.int symbol_of_jacobi (mpz_t a, mpz_t n)
This is the function that calculates the symbol of jacobi according to the algorithm of our Professor. Making recursive calls between the properties presented previously, respecting the order of 4 algorithm steps.
It takes as argument an integer, n an integer whose primality we wish to test must not be equal to 0 or even. This function returns 1 if a = 1 and therefore jacobi (a, n) = 1 and 0 otherwise.

12._Bool solovay_strassen (mpz_t n, unsigned long long int k):
This function performs the primality test of solovay strassen starting from the symbol of jacobi and using the modular exponentiation method to speed up the calculation of large powers. Its Arguments are: has an integer, n the number to be tested and it returns TRUE if it is
probably first and FALSE if it is composed.

13._Bool is_quadratic_residu (mpz_t a, mpz_t p):
A boolean function which checks if one number n is a quadratic residue modulo another number p.

14.void symbol_of_legendre (mpz_t a, mpz_t p):
this function calculates the legend symbol using the Solovaystrassen primality test and the modular openentiation algorithm according to the Eulere criterion.

## Compilation and Execution

A makefile was created with several targets, gmp and uvsqgraphics targets install the two libraries.
In order to compile the program you will have to type make in the terminal. Then there are 4 possibilities of execution:

1- ./solovay_strassen primality_test n: in order to carry out the solovay strassen test.
2- ./solovay_strassen symbol_of_jacobi a n: in order to calculate the jacobi symbol (a / n)
3- ./solovay_strassen symbol_of_legendre a n: in order to calculate the symbol of Legendre (a / n)
4- ./solovay_strassen coprimes a n: in order to test if the two numbers are prime between them.

## License & copyright

© **Chahi Rabie Ala Eddine**, **Keskes Yasmine** ***Versailles Saint Quentin en Yvelines college***.

