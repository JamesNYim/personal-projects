#include <iostream>
#include <string>

#include "BigInteger.h"
#include "rsa.h"

using namespace std;

int main(int argc, char* argv[])
{
	Rsa a = Rsa();
	a.keyGen(argv[1]);
	long int plainText = 3;
	long int e = 65537;
	long int n = 4296719428;
	cout << "Plaintext: " << plainText << endl;
	long int cipherText = a.encrypt(plainText, e, n);
	cout << "CipherText: " << cipherText << endl;
	return 0;
}
