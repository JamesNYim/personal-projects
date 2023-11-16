#include <exception>
#include <iostream>
#include <fstream>
#include "BigInteger.h"
//#include "MakePrime.h"

#include "rsa.h"
using namespace std;

	// -= Constructors =-

	// Initializing rsa values	rsa()
	Rsa::Rsa()
	{
		p = BigInteger();
		q = BigInteger();
		n = BigInteger();
		phi = BigInteger();
		long int e;
		d = BigInteger();
	}

	// make_n() p * q = n
	void Rsa::make_n(BigInteger p, BigInteger q)
	{
		n = p * q;
	}

	void Rsa::make_phi(BigInteger p, BigInteger q)
	{
		BigInteger p1 = p - 1;
		BigInteger q1 = q - 1;
		phi = p1 * q1;;
	}

	void Rsa::make_e(BigInteger phi)
	{
		//phi = phi;
		e = 65537;
	}

	void Rsa::make_d(long int e, BigInteger phi)
	{
		BigInteger t = BigInteger(0);
		BigInteger t1 = BigInteger(1);
		long int r1 = e;
		BigInteger r = phi;
		BigInteger temp = BigInteger();
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
			throw std::exception("no inverse");
		}

		if (t < 0)
		{
			t = t + phi;
		}

		d = t;
	}

	int Rsa::keyGen(string pubKeyFileName)
	{
		ofstream pubKeyFile;
		pubKeyFile.open(pubKeyFileName);
		if (!pubKeyFile)
		{
			throw exception("Unable to open to write pub file");
		}
		p = BigInteger(733);
		q = BigInteger(811);

		make_phi(p, q);
		make_e(phi);
		make_d(e, phi);

		pubKeyFile << "p: " << p << endl;
		pubKeyFile << "q: " << q << endl;
		pubKeyFile << "n: " << n << endl;
		pubKeyFile << "phi: " << phi << endl;
		pubKeyFile << "e: " << e << endl;
		pubKeyFile << "d: " << d << endl;

		pubKeyFile.close();
		return 0;
	}


