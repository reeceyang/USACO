/*
ID: reeceya1
LANG: C++11
TASK: dualpal
*/

#include <bits/stdc++.h>

using namespace std;

// exponent function
int power(int base, int exponent) {
    int product = 1;
    for (int i = 0; i < exponent; i++) {
        product *= base;
    }
    return product;
}

string toBase(int number, int b) {
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
        newNumber += to_string(digit);
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
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int n, s;
    cin >> n >> s;

    int found = 0;
    int current = s + 1;
    while (found < n) {
        int palindromes = 0;
        for (int base = 2; base <= 10; base++) {
            //cout << current << " " << toBase(current, base) << "\n";
            if (isPalindrome(toBase(current, base))) {
                palindromes++;
            }
        }
        if (palindromes >= 2) {
            found++;
            cout << current << "\n";
        }
        current++;
    }
}
