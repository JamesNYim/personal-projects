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
	cout << endl;

	if (A.sign() == 0) //Tests 0 Sign
	{
		cout << "sign() case 0: TRUE" << endl;
	}
	else
	{
		cout << "sign() case 0: FALSE" << endl;
	}

	if (B.sign() == 1) //Tests 1 sign
	{
		cout << "sign() case 1: TRUE" << endl;
	}
	else
	{
		cout << "sign() case 1: FALSE:" << endl;
	}

	if (C.sign() == -1) //Tests -1 sign
	{
		cout << "sign() case 2: TRUE" << endl;
	}
	else
	{
		cout << "sign() case 2: FALSE" << endl;
	}

	// compare()
	cout << endl;

	BigInteger bigNum = BigInteger("2320394802394803294820394823094820394874109238");
	BigInteger smallNum = BigInteger("500");
	BigInteger smallNum2 = BigInteger("500");
	BigInteger negNum = BigInteger("-2394873298479329847239847923478");
	BigInteger negNum2 = BigInteger("-69420");
	
	cout << "bigNum.compare(smallNum) (1) = " << bigNum.compare(smallNum) << endl;
	cout << "smallNum.BigInteger(bigNum) (-1) = " << smallNum.compare(bigNum) << endl;
	cout << "smallNum.BigInteger(smallNum2) (0) = " << smallNum.compare(smallNum2) << endl;
	cout << "negNum.compare(smallNum) (-1) = " << negNum.compare(smallNum) << endl;
	cout << "negNum2.compare(negNum) (1) = " << negNum2.compare(negNum) << endl;
	
	// Testing Manipulation procedures
	cout << "---= Manipulation Functions =---" << endl;
	
	//makeZero()
	cout << endl;
	BigInteger makeZero = BigInteger("230914891023840912384910238491023841902348192348");
	cout << "makeZero b4: " << makeZero << endl;
	makeZero.makeZero();
	cout << "makeZero aftr: " << makeZero << endl;

	//negate()
	cout << endl;
	BigInteger negateNum = BigInteger("320948239048923048923048230948230948230948239084342890");
	cout << "negateNum before: " << negateNum << endl;
	negateNum.negate();
	cout << "negateNum after 1st: " << negateNum << endl;
	negateNum.negate();
	cout << " negateNum after 2nd: " << negateNum << endl;

	// Arithemtic Function Tests
	cout << "---= Arithmetic Functions =---" << endl;

	BigInteger equaA = BigInteger("98823984274294329487252983742394823752935723492847298472");
	BigInteger equaB = BigInteger("98823984274294329487252983742394823752935723492847298472");
	BigInteger bigNumA = BigInteger("1234123412341231232131331313131313131441455551312432");
	BigInteger bigNumB = BigInteger("1234123412341231232131331313131313131441455551312432");
	BigInteger smolNumA = BigInteger("981239232984392423842");
	BigInteger smolNumB = BigInteger("981239232984392423842");


	if (equaA == equaB)
	{
		cout << "equals good" << endl;
	}
	if (bigNumA > smolNumA)
	{
		cout << "greater than good" << endl;
	}
	if (bigNumA >= bigNumB)
	{
		cout << "greater equals good" << endl;
	}
	if (smolNumA < bigNumA)
	{
		cout << "less than good" << endl;
	}
	if (smolNumA <= smolNumB)
	{
		cout << "less equal good" << endl;
	}

	BigInteger numA = BigInteger("999999999992340923482304982340928420934823049820942804928402984209482309482049285092865209482");
	BigInteger numB = BigInteger("23094823045923852305872362938672349823742");
	BigInteger sum = BigInteger("999999999992340923482304982340928420934823049820942828023226030133334615354412223765215033224");
	BigInteger difference = BigInteger("999999999992340923482304982340928420934823049820942781833579938285630003609686346420515385740");
	
	BigInteger num1 = BigInteger("3");
	BigInteger num2 = BigInteger("1");
	
	if (numA + numB == sum)
	{
		cout << "positive add is good" << endl;
	}
	if (numA - numB == difference)
	{
		cout << "positive sub is good" << endl;
	}

	cout << "num1(3) - num2(1) = " << num1 - num2 << endl;
	cout << "\n" << "----------= End Test =----------" << "\n" << endl;




	return 0;
}



