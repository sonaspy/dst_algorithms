// currency class using  a single data member
// (amount) represent an instance

#ifndef Currency_
#define Currency_

#include <iostream>
#include "myExceptions.h"

using namespace std;

enum signType
{
    plus,
    minus
};

class currency
{
  public:
    // constructor
    currency(signType theSign = plus,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);
    // destructor
    ~currency() {}
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const
    {
        if (amount < 0)
            return minus;
        else
            return plus;
    }
    unsigned long getDollars() const
    {
        if (amount < 0)
            return (-amount) / 100;
        else
            return amount / 100;
    }
    unsigned int getCents() const
    {
        if (amount < 0)
            return -amount - getDollars() * 100;
        else
            return amount - getDollars() * 100;
    }
    currency add(const currency &) const;
    currency &increment(const currency &x)
    {
        amount += x.amount;
        return *this;
    }
    void output() const;
    void input();
    currency subtract(const currency& x);
    currency percent(float x);
    currency multiply(float x);
    currency divide(float x);
    private : long amount;
};

currency::currency(signType theSign, unsigned long theDollars,
                   unsigned int theCents)
{ // Create a currency object.
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,
                        unsigned int theCents)
{ // Set currency value.
    if (theCents > 99)
        // too many cents
        throw illegalParameterValue("Cents should be < 100");

    amount = theDollars * 100 + theCents;
    if (theSign == minus)
        amount = -amount;
}

void currency::setValue(double theAmount)
{ // Set currency value.
    if (theAmount < 0)
        amount = (long)((theAmount - 0.001) * 100);
    else
        amount = (long)((theAmount + 0.001) * 100);
    // 2 decimal digits only
}

currency currency::add(const currency &x) const
{ // Add x and *this.
    currency y;
    y.amount = amount + x.amount;
    return y;
}

void currency::output() const
{ // Output currency value.
    long theAmount = amount;
    if (theAmount < 0)
    {
        cout << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100; // dollars
    cout << '$' << dollars << '.';
    int cents = theAmount - dollars * 100; // cents
    if (cents < 10)
        cout << '0';
    cout << cents;
}

void currency::input(){
    // input the amount as a double
    cout << "Enter the currency amount as a real number" << endl;
    double theValue;
    cin >> theValue;

    // set the value
    setValue(theValue);
}

currency currency::subtract(const currency &x)
{ // Return *this - x.
    currency result;
    result.amount = amount - x.amount;
    return result;
}
currency currency::percent(float x)
{ // Return x percent of *this.
    currency result;
    result.amount = (long)(amount * x / 100);
    return result;
}

currency currency::multiply(float x)
{ // Return this * x.
    currency result;
    result.amount = (long)(amount * x);
    return result;
}

currency currency::divide(float x)
{ // Return this / x.
    currency result;
    result.amount = (long)(amount / x);
    return result;
}

#endif
