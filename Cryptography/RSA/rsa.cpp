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
	e = BigInteger();
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
	e = BigInteger("65537");
}

