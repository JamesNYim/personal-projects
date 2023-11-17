#include <exception>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "BigInteger.h"
//#include "MakePrime.h"

#include "rsa.h"
using namespace std;

	// -= Helper Functions =-
	long int powMod(long int a, long int d, long int n)
	{
		long int v = 1;
		long int p = a;
		while (d > 0)
		{
			if (d % 2 != 0)
			{
				v = (v * p) % n;
			}
			p = (p * p) % n;
			d = d / 2;
		}
		return v;
	}
	// -= Constructors =-

	// Initializing rsa values	rsa()
	Rsa::Rsa()
	{

	}

	// make_n() p * q = n
	void Rsa::make_n(long int p, long int q)
	{
		n = p * q;
	}

	void Rsa::make_phi(long int p, long int q)
	{
		phi = (p - 1) * (q - 1);
	}

	void Rsa::make_e(long int phi)
	{
		//phi = phi;
		e = 65537;
	}

	void Rsa::make_d(long int e, long int phi)
	{
		long int t = 0;
		long int t1 = 1;
		long int r1 = e;
		long int r = phi;
		while (r1 != 0)
		{
			long int q = r / r1;
			
		    long int rTemp = r - (q *r1);
			long int tTemp = t - (q * t1);

			r = r1;
			r1 = rTemp;
			t = t1;
			t1 = tTemp;
		}

		// If there is no inverse
		if (r > 1)
		{
			cout << "No Inverse" << endl;
			return;
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
			cout << "Unable to open file for writing" << endl;
			return -1;
		}
		p = 733;
		q = 811;

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

	long int Rsa::encrypt(long int plainText, long int e, long int n)
	{
		return powMod(plainText, e, n);
	}

	long int Rsa::decrypt(long int cipherText, long int d, long int n)
	{
		return powMod(cipherText, d, n);
	}
