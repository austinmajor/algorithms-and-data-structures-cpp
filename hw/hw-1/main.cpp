// Author: Austin Major
// Title: Quadratic Primes
// Date: 9/2/19

#include <iostream>

using namespace std;

// n^2+n+41
int formulaOne(int n)
{
    return n * n + n + 41;
}

// n^2-79n+1601
int formulaTwo(int n)
{
    return n * n - 79 * n + 1601;
}

// n^2+(a*n)+b
int formulaThree(int n, int a, int b)
{
    return n * n + a * n + b;
}

// O(n/2) = O(n)
// sqrt n + 1 is best
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n/2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void generateFormulaOne()
{
    for (int i = 0; i < 40; i++)
    {
        int f = formulaOne(i);
        if (isPrime(f))
        {
            cout << f << " ";
        }
    }
    cout << endl << endl;
}

void generateFormulaTwo()
{
    for (int i = 0; i < 80; i++)
    {
        int f = formulaTwo(i);
        if (isPrime(f))
        {
            cout << f << " ";
        }
    }
    cout << endl << endl;
}

void generateFormulaThree()
{
    int a, b, f, maxa = 0, maxb = 0, maxn = 0;
    int aMin = -999, aMax = 999, bMin = -1000, bMax = 1000;

    for (a = aMin; a < aMax; a++)
    {
        for (b = bMin; b <= bMax; b++)
        {
            if(!isPrime(b)) continue;

            int n = 0;
            do
            {
                f = formulaThree(n, a, b);
                n++;
            } while (isPrime(f));

            if (n > maxn)
            {
                maxa = a;
                maxb = b;
                maxn = n;
            }
        }
    }
    cout << "a = " << maxa << endl;
    cout << "b = " << maxb << endl;
    cout << "Max prime #'s = " << maxn - 1 << endl << endl;
}

int main()
{
    cout << "Formula One: " << endl;
    generateFormulaOne();

    cout << "Formula Two: " << endl;
    generateFormulaTwo();

    cout << "Formula Three: " << endl;
    generateFormulaThree();

    return 0;
}