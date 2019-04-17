#pragma once

class Fib
{
    //the Fibonacci sequence of classes
private:
    int f, g; //f = fib(k - 1), g = fib(k). Both of them are of type int and will overflow quickly
public:
    Fib(int n) // is initialized to the smallest Fibonacci term of no less than n
    {
        f = 1;
        g = 0;
        while (g < n)
            next();
    }                       //fib(-1), fib(0), O(log_phi(n)) time
    int get() { return g; } // gets the current Fibonacci term, O(1) time
    int next()
    {
        g += f;
        f = g - f;
        return g;
    } // to the next Fibonacci term, O(1) time
    int prev()
    {
        f = g - f;
        g -= f;
        return g;
    } // go to the previous Fibonacci term, O(1) time
};