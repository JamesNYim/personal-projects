//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
// James Yim
// Cruz ID: jnyim
// #1798845
// CSE 101-01 Tantalo
// Programming Assignment 6
// Arithmetic.cpp
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdexcept>
#include "List.h"
#include "BigInteger.h"

using namespace std;

int main()
{
	BigInteger a = BigInteger(24);
	BigInteger b = BigInteger(18);

	cout << a.div(6) << endl;
	return 0;
}
