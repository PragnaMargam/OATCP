#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int greatestCommonDivisor(int a, int b)
{
    return b == 0 ? a : greatestCommonDivisor(b, a % b);
}
 
int leastCommonMultiple(int a, int b)
{
    return a * b / greatestCommonDivisor(a, b);
}
 
int fastExponentiation(int x, int n, int mod)
{
    int res = 1;
    x = x % mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
 
    return res;
}

string findMinimumAfterRemoval(string inputString, int numToRemove)
{
    int size = inputString.size();
    stack<char> digitStack;
    for (char digit : inputString) {
        while (!digitStack.empty() && numToRemove > 0
               && digitStack.top() > digit) {
            digitStack.pop();
            numToRemove -= 1;
        }
 
        if (!digitStack.empty() || digit != '0')
            digitStack.push(digit);
    }

    while (!digitStack.empty() && numToRemove--)
    {
        digitStack.pop();
    }
    if (digitStack.empty())
    {
        return "0";
    }

    while (!digitStack.empty()) {
        inputString[size - 1] = digitStack.top();
        digitStack.pop();
        size -= 1;
    }
    return inputString.substr(size);
}
 
int main()
{ 
    
   string numberString;
   cin >> numberString;
   int digitsToRemove;
   cin >> digitsToRemove;
   string result = findMinimumAfterRemoval(numberString, digitsToRemove);
   cout << result << endl;


}
