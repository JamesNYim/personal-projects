#include <iostream>
#include "BigInteger.h"
//#include "MakePrime.h"

#include "rsa.h"
using namespace std;
using namespace rsa;

// -= Constructors =-

// Initializing rsa values
rsa()
{
	p = BigInteger();
	q = BigInteger();
	n = BigInteger();
	phi = BigInteger()
	long int e;
	d = BigInteger();
}

// make_n() p * q = n
make_n(p, q)
{
	n = p * q;
}

make_phi(p, q)
{
	phi = (p - 1)(q - 1);
}

make_e(phi)
{
	e = 65537;
}

make_d(e, phi)
{
	BigInteger t = BigInteger(0);
	BigInteger t1 = BigInteger(1);
	long int r1 = e;
	BigInteger r = phi;

	while (r1 != 0)
	{
		BigInteger q = r.div(r1);
		
		BigInteger rTemp = r - (q *r1);
		BigInteger tTemp = t - (q * t1);

		r = r1;
		r1 = temp;
		t = t1;
		t1 = tTemp;
	}

	// If there is no inverse
	if (r > 1)
	{
		return nullptr;
	}

	if (t < 0)
	{
		t = t + phi;
	}

	return t;
}

