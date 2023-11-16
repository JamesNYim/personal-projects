#pragma once

#include <iostream>
#include <string>
#include "BigInteger.h"


using namespace std;

class Rsa
{
	// Private Variables
	private:
		BigInteger p;
		BigInteger q;
		BigInteger n;
		BigInteger phi;
		BigInteger e;
		BigInteger d;

		
		// find n
		void make_n(BigInteger p, BigInteger q);

		// make_e
		void make_e(BigInteger phi);

		// make_phi
		void make_phi(BigInteger p, BigInteger q);

		// make_d
		void make_d(long int e, BigInteger phi);

	public:

		//Empty Constructor
		Rsa();
	
		//KeyGen()
		int keyGen(string pubKeyFileName);

		//Encrypt
		BigInteger encrypt(BigInteger plainText, BigInteger e, BigInteger n); // returns cipher text

		//Decrypt
		BigInteger decrypt(BigInteger cipherText, BigInteger d, BigInteger n); // returns plain text
		
		//Signing
		//rsaSign()?

		//Verifying
		//rsaVerify()?
};
