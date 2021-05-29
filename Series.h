#ifndef SERIES_H
#define SERIES_H

#include <iostream>

using namespace std;

class Series
{
    private:
        double firstElement, delta;

    public:
        Series();
        Series(double);
        Series(double, double);
        ~Series();
        double getFirstElement();
        double getDelta();
        void setDelta(double);
        void setFirstElement(double);
        void printArithmetic(int);
        void printGeometric(int);
        void printConvergent(double);
        void printHarmonic_fraction(int);
        void printHarmonic_decimal(int);
        void printFib(int);
        void printHarmonic_primeDecimal(int);
        void printHarmonic_primeFraction(int);
        void printSumOfSquares(int);
        double geometric(int);
        double arithmetic(int);
        double geometricSum(double, int);
        double arithmeticSum(double, int);
        double convergentSum(double);
        double harmonicSum(int n);
        double harmonicSum_prime(int n);
        double sumOfSquares(int n);
        double printHarmonic_prime(int);
        double fibSum(int);
        int fib(int);
        int isPrime(int, int);
        int primeSeries(int, int);
};

#endif // SERIES_H
