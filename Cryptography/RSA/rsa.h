#include <iostream>
#include "BigInteger.h"

using namespace std;

class rsa
{
	// Private Variables
	private:
		BigInteger p;
		BigInteger q;
		BigInteger n;
		BigInteger phi;
		BigInteger e;
		BigInteger d;


	public:

		//Empty Constructor
		rsa();

		//Encrypt
		encrypt(plainText, e, n) // returns cipher text

		//Decrypt
		decrypt(cipherText, d, n) // returns plain text
		
		//Signing
		//rsaSign()?

		//Verifying
		//rsaVerify()?

