/*
 * In The Name Of God
 * ========================================
 * [] File Name : TMath.h
 *
 * [] Creation Date : 22-02-2015
 *
 * [] Last Modified : Sun 22 Feb 2015 10:57:29 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef TMATH_H
#define TMATH_H

long long llpow(long long n, long long m);
int sgn(double number);
double bisection(double a, double b, int M, double delta,
		double epsilon, double (*f)(double));
#endif
