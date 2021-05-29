#ifndef SERIES_CPP
#define SERIES_CPP

#include <cmath>
#include <cstring>
#include "Series.h"

Series::Series(double fe, double rate)
{
    firstElement = fe;
    delta = rate;
}

Series::Series(double fe)
{
    firstElement = fe;
    delta = 0;
}

Series::~Series()
{
    firstElement = delta = 0;
}

Series::Series()
{
    firstElement = delta = 0;
}

double Series::getDelta()
{
    return delta;
}

double Series::getFirstElement()
{
    return firstElement;
}

void Series::setFirstElement(double fe)
{
    firstElement = fe;
}

void Series::setDelta(double change)
{
    delta = change;
}

//Fast Exponentiation
double fastExponent(double base, int exponent, int accumulator)
{
    if(exponent == 0)
        return accumulator;
    else if(exponent % 2 == 0)
        return fastExponent(base * base, exponent/2, accumulator);

    return fastExponent(base, exponent-1, base * accumulator);
}

//Conversion from int to string
string tocar(int num)
{
    string str = "";
    while(num != 0)
    {
        str += ( (num%10) + 48 );
        num /= 10;
    }
    for(int count = 0; count < str.length() / 2; count++)
        swap(str[count], str[str.length() - count - 1]);

    return str;
}

//E_arithmetic = a + n*r;                       COMPLETE
double Series::arithmetic(int n)
{
    if(n==0)
        return firstElement;

    return delta + arithmetic(n-1);
}

//Print Arithmetic series
void Series::printArithmetic(int n)
{
    if(n==0)
    {
        cout << firstElement;
        return;
    }
    printArithmetic(n-1);
    cout << "+" << (firstElement + n*delta);
}

//Arithmetic sum of n elements
double Series::arithmeticSum(double e, int n)
{
    if(n==0)
        return n;

    return e + arithmeticSum(e+delta, n-1);
}

//E_geometric = a * r^n                         COMPLETE
double Series::geometric(int n)
{
    if(n==0)
        return firstElement;

    return delta * geometric(n-1);
}

//Sum of geometric progression
double Series::geometricSum(double e,  int n)
{
    if(n==0)
        return 0;

    return e + geometricSum(e*delta, n-1);
}

//Print Geometric series
void Series::printGeometric(int n)
{
    if(n==0)
    {
        cout << firstElement;
        return;
    }
    printGeometric(n-1);
    cout << "+" << firstElement * fastExponent(delta, n, 1);
}

//Print sum of convergent series
double Series::convergentSum(double num)
{
    if(num < 0.0001)
        return num * delta;

    return num + convergentSum(num * delta);
}

//Print convergent series
void Series::printConvergent(double num)
{
    if(num < 0.0001)
    {
        //cout << num / delta << endl;
        return;
    }
    cout << num << " + " << endl;
    printConvergent(num * delta);
}

//Sum of harmonic series up to nth element
double Series::harmonicSum(int n)
{
    if(n==firstElement)
        return 1.0/(double)n;

    return 1.0/(double)n + harmonicSum(n-1);
}

//Print Harmonic series in fraction format
void Series::printHarmonic_fraction(int n)
{
    if(n==firstElement)
    {
        cout << "(" << ( (firstElement == 1) ? "" : "1/") << firstElement << ")";
        return;
    }
    printHarmonic_fraction(n-1);
    cout << "+(1/" << n << ")";
}

//Print Harmonic series in decimal format
void Series::printHarmonic_decimal(int n)
{
    if(n==firstElement)
    {
        cout << "(" << (firstElement == 1 ? 1: (floor((1.0/(double)firstElement * 1000) + 0.5) ) / 1000 ) << ")";
        return;
    }
    printHarmonic_decimal(n-1);
    cout << "+(" << (floor((1.0/(double)n * 1000) + 0.5) ) / 1000 << ")";
}

//f_n = f_(n-1) + f_(n-2)                       COMPLETE
int Series::fib(int n)
{
    if(n==0 || n==1)
        return n;

    return fib(n-1) + fib(n-2);
}

//Print Fibonacci
void Series::printFib(int n)
{
    if(n == (firstElement-1))
    {
        cout << fib(n);
        return;
    }

    printFib(n-1);

    cout << "+" << fib(n);
}

//f_sum = f_(n-1) + f_(n-2) + 1                 COMPLETE
double Series::fibSum(int n)
{
    if(n==firstElement)
        return n;
    else if(n==(firstElement-1) )
        return n+1;

    return fibSum(n-1) + fibSum(n-2) + 1;
}

double Series::harmonicSum_prime(int n)
{
    if(n == firstElement)
        return 1.0 / (double)n;

    return 1.0 / (double)n + harmonicSum_prime(n-1);
}

double Series::sumOfSquares(int n)
{
    if(n==firstElement)
        return fastExponent(n, 2, 1);

    return fastExponent(n,2,1) + sumOfSquares(n-1);
}

void Series::printSumOfSquares(int n)
{
    if(n==firstElement)
    {
        cout << fastExponent(n, 2, 1);
        return;
    }

    printSumOfSquares(n-1);
    cout << "+" << fastExponent(n, 2, 1);
}

int Series::isPrime(int num, int i)
{
    if( num <= 2 || num < fastExponent(i,2,1) )       //2nd condition passes divisibility check
        return num;
    else if(num % i == 0)
        return 0;

    return isPrime(num, i+1);
}

int Series::primeSeries(int x, int y)
{
    if(x==y)
    {
        if(isPrime(x,2))
            cout << tocar( isPrime(x,2) );

        return isPrime(x,2);
    }
    if( isPrime(x,2) )
        cout << tocar( isPrime(x,2) )+" + ";

    return isPrime(x, 2) + primeSeries(x+1, y);
}

void Series::printHarmonic_primeDecimal(int n)
{
    if(n == firstElement)
    {
        if(isPrime(n,2))
            cout << floor((1.0/(double)isPrime(n,2) * 1000) + 0.5) / 1000;

        return;
    }
    printHarmonic_primeDecimal(n-1);
    if(isPrime(n,2))
        cout << " + " << floor((1.0/(double)isPrime(n,2) * 1000) + 0.5) / 1000;
}

void Series::printHarmonic_primeFraction(int n)
{
    if(n == firstElement)
    {
        cout << (isPrime(n,2) == 0 ? "": "1/"+(tocar(isPrime(n,2)) ) );
        return;
    }
    printHarmonic_primeFraction(n-1);
    cout << (isPrime(n,2) == 0 ? "": " + 1/"+(tocar(isPrime(n,2)) ) );
}

#endif // SERIES_CPP
