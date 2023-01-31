// --------------------
// Victor Nguyen, vnguy138
// 2022 Spring CSE101 PA6
// BigInteger.cpp
// BigInteger ADT
// --------------------

#include <iostream>
#include <string>
#include "BigInteger.h"
#include "List.h"

// helper function to compute base
// got help from gecko
ListElement pow10(int exp) {
    return exp == 0 ? 1 : 10 * pow10(exp - 1);
}

// power is within 1 <= power <= 9
const int power = 9;
const ListElement base = pow10(power);

// Class Constructors & Destructors ----------------------------------------

// BigInteger()
// Constructor that creates a new BigInteger in the zero state:
// signum=0, digits=()
BigInteger::BigInteger() {
    signum = 0;
}

// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s) {
    // empty string
    if (s.length() == 0) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }

    std::string::size_type i = 0, slen = s.length(), oslen = s.length() , odd_iter = 0;
    bool odd, nonzero = false;
    std::string buffer = "";
    ListElement convert;
    signum = 1;
    int pair = 0;

    // check for optional positive/negative sign
    if (s[i] == '+') {
        i++;
        slen--;
    } else if (s[i] == '-') {
        i++;
        slen--;
        signum = -1;
    }

    // check for additional valid/invalid inputs
    std::size_t found = s.find_first_not_of("1234567890", i);
    if (found != std::string::npos) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    found = s.find_first_of("1234567890", i);
    if (found == std::string::npos) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }

    // get rid of additional leading zeros
    while (s[i] == '0') {
        i++;
        slen--;
    }

    // insert into list accordingly
    odd = (slen % power != 0) ? true : false;
    buffer = "";
    for (; i < oslen; i++) {
        nonzero = true;
        buffer += s[i];

        // insert non modular part of the string into list
        if (odd) {
            odd_iter++;
            if (odd_iter == (slen % power)) {
                convert = stol(buffer);
                digits.insertBefore(convert);
                odd = false;
                buffer = "";
            }
            continue;
        }

        // insert into list when pair matches node size (determined by power)
        pair++;
        if (pair == power) {
            convert = stol(buffer);
            digits.insertBefore(convert);
            buffer = "";
            pair = 0;
        }
    }

    if (!nonzero) {
        signum = 1;
    }

    return;
}

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& n) {
    this->digits = n.digits;
    this->signum = n.signum;
    return;
}

// Optional Destuctor
// ~BigInteger()
// ~BigInteger();


// Access functions --------------------------------------------------------

// sign()
// Returns -1, 1 or 0 according to whether this BigInteger is positive,
// negative or 0, respectively.
int BigInteger::sign() const {
    return signum;
}

// compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& n) const {
    if (this->signum > n.signum) {
        return 1;
    } else if (this->signum < n.signum) {
        return -1;
    }

    List a = this->digits, b = n.digits;

    a.moveFront();
    while (a.position() != a.length() && a.peekNext() == 0) {
        a.eraseAfter();
    }

    b.moveFront();
    while (b.position() != b.length() && b.peekNext() == 0) {
        b.eraseAfter();
    }

    if (this->digits.length() > n.digits.length() && n.signum == 1) {
        return 1;
    } else if (this->digits.length() < n.digits.length() && n.signum == 1) {
        return -1;
    } else if (this->digits.length() > n.digits.length() && n.signum == -1) {
        return -1;
    } else if (this->digits.length() < n.digits.length() && n.signum == -1) {
        return 1;
    }

    //List a = this->digits, b = n.digits;
    ListElement x, y;
    a.moveFront();
    b.moveFront();
    while (a.position() != a.length()) {
        x = a.moveNext();
        y = b.moveNext();
        if (x > y && n.signum == 1) {
            return 1;
        } else if (x < y && n.signum == 1) {
            return -1;
        } else if (x > y && n.signum == -1) {
            return -1;
        } else if (x < y && n.signum == -1) {
            return 1;
        }
    }

    return 0;
}


// Manipulation procedures -------------------------------------------------

// makeZero()
// Re-sets this BigInteger to the zero state.
void BigInteger::makeZero() {
    digits.clear();
    signum = 0;
    return;
}

// negate()
// If this BigInteger is zero, does nothing, otherwise reverses the sign of 
// this BigInteger positive <--> negative.
void BigInteger::negate() {
    if (digits.length() == 0) {
        return;
    }
    signum = (signum == 1) ? -1 : 1;
    return;
}


// BigInteger Arithmetic operations ----------------------------------------

// helper function that normalizes add and sub functions
void normalizeList(List& l) {
    int carry = 0;
    ListElement x;
    l.moveBack();
    while (l.position() > 0) {
        x = l.movePrev();
        // if carry is -1 or 1
        if (carry != 0) {
            x += carry;
            carry = 0;
        }

        if (x >= base) {
            carry = 1;
            x -= base;
            l.setAfter(x);
        } else if (x < 0) {
            carry = -1;
            x += base;
            l.setAfter(x);
        } else {
            l.setAfter(x);
        }
    }

    if (carry == 1) {
        l.moveFront();
        l.insertBefore(1);
    }

    return;
}

// helper function that normalize mult function
void normalizeMult(List& l) {
    long carry = 0;
    ListElement x;
    l.moveBack();
    while (l.position() > 0) {
        x = l.movePrev();
        if (carry != 0) {
            x += carry;
            carry = 0;
        }

        if (x >= base) {
            carry = x / base;
            x %= base;
            l.setAfter(x);
        } else {
            l.setAfter(x);
        }
    }

    if (carry != 0) {
        l.moveFront();
        l.insertBefore(carry);
    }

    return;
}

// helper sumList that deals with conditions lengths of BigIntegers are unequal
void sumList_helper(List& s, List& a, List& b, int sign) {
    ListElement x;
    if (a.position() <= 0) {
        x = b.movePrev();
        x = x < 0 ? -x : x;
        s.insertAfter(x);
    } else {
        x = a.movePrev();
        s.insertAfter(x);
    }
    return;
}

// helper function that adds/subtracts two BigIntegers
void sumList(List& s, List a, List b, int sign) {
    ListElement x, y, sum;

    a.moveBack();
    b.moveBack();
    while (a.position() > 0 || b.position() > 0) {
        if (a.position() <= 0 || b.position() <= 0) {
            sumList_helper(s, a, b, sign);
            continue;
        }

        x = a.movePrev();
        y = b.movePrev();
        if (sign == -1) {
            sum = x - y;
        } else {
            sum = x + y;
        }
        s.insertAfter(sum);
    }
    return;
}

// helper function that shifts a list a certain number of times
void shiftList(List &l, int p) {
    l.moveBack();
    for (int i = 0; i < p; i++) {
        l.insertAfter(0);
    }
    return;
}

// helper function that computes the scalar multiple of a list given a number
void scalarMultList(List &l, ListElement m) {
    ListElement x;
    l.moveFront();
    while (l.position() != l.length()) {
        x = l.moveNext();
        x *= m;
        l.setBefore(x);
    }
    return;
}

// add()
// Returns a BigInteger representing the sum of this and N.
BigInteger BigInteger::add(const BigInteger& n) const {
    BigInteger a = *this, b = n, c;
    int select = 0;
    bool swetch = 0;

    if (a.signum < b.signum && a.signum != 0 && b.signum != 0) {
        swetch = 1;
    } else if (a.signum > b.signum && a.signum != 0 && b.signum != 0) {
        swetch = 0;
    }

    // if signs arent equal
    if (a.signum != b.signum) {
        (swetch == 1) ? a.negate() : b.negate();
        if (a > b) {
            // +a -b
            select = 1;
            sumList(c.digits, a.digits, b.digits, -1);
        } else if (a < b) {
            // -a +b
            select = -1;
            sumList(c.digits, b.digits, a.digits, -1);
        } else {
            // else = +a -a so do nothing
            (swetch == 1) ? a.negate() : b.negate();
            c.signum = 0;
            return c;
        }
        (swetch == 1) ? a.negate() : b.negate();
    } else {
        // +a +b || -a -b
        sumList(c.digits, a.digits, b.digits, 1);
    }

    c.signum = (select == 1) ? a.signum : b.signum;
    normalizeList(c.digits);
    return c;
}

// sub()
// Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& n) const {
    BigInteger a = *this, b = n, c;
    int s = a.signum;

    if (a.signum == b.signum) {
        if (a > b) {
            c.signum = 1;
            (s == 1) ? sumList(c.digits, a.digits, b.digits, -1) : sumList(c.digits, b.digits, a.digits, -1);
        } else if (a < b) {
            c.signum = -1;
            (s == 1) ? sumList(c.digits, b.digits, a.digits, -1) : sumList(c.digits, a.digits, b.digits, -1);
        } else {
            c.signum = 0;
            return c;
        }
    } else {
        sumList(c.digits, a.digits, b.digits, 1);
        c.signum = a.signum;
    }

    normalizeList(c.digits);
    return c;
}

// mult()
// Returns a BigInteger representing the product of this and N. 
BigInteger BigInteger::mult(const BigInteger& n) const {
    BigInteger a = *this, b = n, c;
    ListElement x;
    int shift = 0;
    List temp;
    b.digits.moveBack();
    while (b.digits.position() > 0) {
        List temp2 = a.digits, temp3;
        x = b.digits.movePrev();
        scalarMultList(temp2, x);
        shiftList(temp2, shift);
        sumList(temp3, temp, temp2, 1);
        normalizeMult(temp3);
        if (b.digits.position() == 0) {
            c.digits = temp3;
        }
        temp = temp3;
        shift++;
    }

    if (c.digits.length() == 0) {
        c.signum = 0;
        return c;
    }

    c.signum = (a.signum == b.signum) ? 1 : -1;
    return c;
}


//// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this BigInteger consisting of its
// base 10 digits. If this BigInteger is negative, the returned string 
// will begin with a negative sign '-'. If this BigInteger is zero, the
// returned string will consist of the character '0' only.
std::string BigInteger::to_string() {
    std::string s = "", ze, ze2;
    std::string::size_type t;
    int x;

    // add negative sign to string if number is negative
    if (sign() == -1) {
        s += "-";
    }

    // remove leading zeros
    digits.moveFront();
    while (digits.position() != digits.length()) {
        if (digits.peekNext() != 0) {
            break;
        }
        digits.moveNext();
    }

    // print out zero if the number is zero
    if (digits.position() == digits.length()) {
        s = "0";
        return s;
    }

    // reload zeros
    for (int i = 0; i < power; i++) {
        ze += "0";
    }

    // format output
    while (digits.position() != digits.length()) {
        x = digits.moveNext();
        if (x == 0 && digits.position() != 1) {
            s += ze;
        } else if (x < base && digits.position() != 1) {
            t = (std::to_string(x)).length();
            while (t < power) {
                ze2 += "0";
                t++;
            }
            s += ze2 + std::to_string(x);
            ze2 = "";
        } else {
            s += std::to_string(x);
        }
    }
    return s;
}


// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator << (std::ostream& stream, BigInteger n) {
    return stream << n.BigInteger::to_string();
}

// operator==()
// Returns true if and only if A equals B.
bool operator == (const BigInteger& a, const BigInteger& b) {
    int cmp = a.BigInteger::compare(b);
    return (cmp == 0) ? true : false;
}

// operator<()
// Returns true if and only if A is less than B.
bool operator < (const BigInteger& a, const BigInteger& b) {
    int cmp = a.BigInteger::compare(b);
    return (cmp == -1) ? true : false;
}

// operator<=()
// Returns true if and only if A is less than or equal to B.
bool operator <= (const BigInteger& a, const BigInteger& b) {
    int cmp = a.BigInteger::compare(b);
    return (cmp <= 0) ? true : false;
}

// operator>()
// Returns true if and only if A is greater than B.
bool operator > (const BigInteger& a, const BigInteger& b) {
    int cmp = a.BigInteger::compare(b);
    //std::cout << cmp << std::endl;
    return (cmp == 1) ? true : false;
}

// operator>=()
// Returns true if and only if A is greater than or equal to B.
bool operator >= (const BigInteger& a, const BigInteger& b) {
    int cmp = a.BigInteger::compare(b);
    return (cmp >= 0) ? true : false;
}

// operator+()
// Returns the sum A+B.
BigInteger operator + (const BigInteger& a, const BigInteger& b) {
    return a.BigInteger::add(b);
}

// operator+=()
// Overwrites A with the sum A+B.
BigInteger operator += (BigInteger& a, const BigInteger& b) {
    a = a.BigInteger::add(b);
    return a;
}

// operator-()
// Returns the difference A-B.
BigInteger operator - (const BigInteger& a, const BigInteger& b) {
    return a.BigInteger::sub(b);
}

// operator-=()
// Overwrites A with the difference A-B.
BigInteger operator -= (BigInteger& a, const BigInteger& b) {
    a = a.BigInteger::sub(b);
    return a;
}

// operator*()
// Returns the product A*B.
BigInteger operator * (const BigInteger& a, const BigInteger& b) {
    return a.BigInteger::mult(b);
}

// operator*=()
// Overwrites A with the product A*B.
BigInteger operator *= (BigInteger& a, const BigInteger& b) {
    a = a.BigInteger::mult(b);
    return a;
}
