/*
 * In The Name Of God
 * ========================================
 * [] File Name : pow.c
 *
 * [] Creation Date : 22-02-2015
 *
 * [] Last Modified : Sun 22 Feb 2015 10:04:07 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "TMath.h"

/*
 * calculate n^m in O(lg m)
*/
long long llpow(long long n, long long m)
{
	if (m == 0)
		return 1;

	if (m % 2 == 0) {
		long long result = llpow(n, m / 2);

		return result * result;
	} else {
		long long result = llpow(n, m - 1);

		return n * result;
	}
}
