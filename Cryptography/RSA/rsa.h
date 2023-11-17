#pragma once

#include <iostream>
#include <string>
#include "BigInteger.h"


using namespace std;

class Rsa
{
	// Private Variables
	private:
		long int p;
		long int q;
		long int n;
		long int phi;
		long int e;
		long int d;

		//powMod()
	//	long int powMod(long int a, long int d, long int n);
		// find n
		void make_n(long int p, long int q);

		// make_e
		void make_e(long int phi);

		// make_phi
		void make_phi(long int p, long int q);

		// make_d
		void make_d(long int e, long int phi);

	public:

		//Empty Constructor
		Rsa();
	
		//KeyGen()
		int keyGen(string pubKeyFileName);

		//Encrypt
		long int encrypt(long int plainText, long int e, long int n); // returns cipher text

		//Decrypt
		long int decrypt(long int cipherText, long int d, long int n); // returns plain text
		
		//Signing
		//rsaSign()?

		//Verifying
		//rsaVerify()?
};
