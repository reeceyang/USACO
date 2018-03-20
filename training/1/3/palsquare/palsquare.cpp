/*
ID: reeceya1
LANG: C++11
TASK: palsquare
*/
#include <bits/stdc++.h>

using namespace std;

// converts 10 to A, 11 to B, etc
string numToLetter(int n) {
    switch (n) {
        case 10:
            return "A";
            break;
        case 11:
            return "B";
            break;
        case 12:
            return "C";
            break;
        case 13:
            return "D";
            break;
        case 14:
            return "E";
            break;
        case 15:
            return "F";
            break;
        case 16:
            return "G";
            break;
        case 17:
            return "H";
            break;
        case 18:
            return "I";
            break;
        case 19:
            return "J";
            break;
        case 20:
            return "K";
            break;
    }
    return to_string(n);
}

// exponent function
int power(int base, int exponent) {
    int product = 1;
    for (int i = 0; i < exponent; i++) {
        product *= base;
    }
    return product;
}

// convert base 10 number to base b
string base(int number, int b) {
    string newNumber = "";
    int largestPower = -1;
    do {
        largestPower++;
    } while (power(b, largestPower) <= number);
    largestPower--;
    int remainder = number;
    for (int i = largestPower; i >= 0; i--) {
        int digit = remainder / power(b, i);
        remainder = remainder % power(b, i);
        newNumber += numToLetter(digit);
    }
    return newNumber;
}

// tests for palindrome
bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; 2 * (i + 1) <= n; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int b;
    cin >> b;

    for (int i = 1; i <= 300; i++) {
        //cout << base(i * i, b) << "\n";
        if (isPalindrome(base(i * i, b))) {
            cout << base(i, b) << " " << base(i * i, b) << "\n";
        }
    }
}
