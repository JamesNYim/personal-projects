#include <iostream>
#include <string>
#include <stdexcept>
#include "List.h"
#include "BigInteger.h"

using namespace std;

int main()
{

	cout << "\n" << "----------= Testing BigInteger =----------" <<"\n" << endl;
	
	// Testing Constructors
	cout << "---= Constructors Test =---" << endl;
	
	// Printing zero state Big Int
	BigInteger A = BigInteger();
	cout << "Zero state big int: " << A << endl;

	// Printing string Positive Big Int
	BigInteger B = BigInteger("123456789");
	cout << "Positive Big Int: " << B << endl;

	// Printing string Negative Big Int
	BigInteger C = BigInteger("-123456789");
	cout << "Negative Big Int: " << C << endl;

	// Printing copy of a positive Big Int
	BigInteger D = B;
	cout << "Positive copy Big Int: " << D << endl;

	// Printing copy of a negative Big Int
	BigInteger E = C;
	cout << "Negative copy Big Int: " << E << endl;

	// Testing Access Functions
	cout << "---= Accessor Functions Test =---" << endl;

	//sign()
	if (A.sign() == 0) //Tests 0 Sign
	{
		cout << "case 0: TRUE" << endl;
	}
	else
	{
		cout << "case 0: FALSE" << endl;
	}

	if (B.sign() == 1) //Tests 1 sign
	{
		cout << "case 1: TRUE" << endl;
	}
	else
	{
		cout << "case 1: FALSE:" << endl;
	}

	if (C.sign() == -1) //Tests -1 sign
	{
		cout << "case 2: TRUE" << endl;
	}
	else
	{
		cout << "case 2: FALSE" << endl;
	}


	cout << "\n" << "----------= End Test =----------" << "\n" << endl;




	return 0;
}



