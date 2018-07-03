/*
ID: reeceya1
LANG: C++11
TASK: crypt1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> digits;
    for (int i = 0; i < n; i++) {
        int digit;
        cin >> digit;
        digits.push_back(digit);
    }
    sort(digits.begin(), digits.end());

    int counter = 0;
    for (auto a : digits) {
        for (auto e : digits) {
            if (e * a >= 10) {
                continue;
            }
            for (auto d : digits) {
                if (d * a >= 10) {
                    continue;
                }
                for (auto b : digits) {
                    for (auto c : digits) {
                        int eabc = e * (100 * a + 10 * b + c);
                        if (eabc >= 1000) {
                            continue;
                        }
                        bool allFound = true;
                        for (auto c : to_string(eabc)) {
                            if (!binary_search(digits.begin(), digits.end(), c - '0')) {
                                allFound = false;
                                break;
                            }
                        }
                        if (!allFound) {
                            continue;
                        }
                        int dabc = d * (100 * a + 10 * b + c);
                        if (dabc >= 1000) {
                            continue;
                        }
                        for (auto c : to_string(dabc)) {
                            if (!binary_search(digits.begin(), digits.end(), c - '0')) {
                                allFound = false;
                                break;
                            }
                        }
                        if (!allFound) {
                            continue;
                        }
                        int deabc = (10 * d + e) * (100 * a + 10 * b + c);
                        if (deabc >= 10000) {
                            continue;
                        }
                        for (auto c : to_string(deabc)) {
                            if (!binary_search(digits.begin(), digits.end(), c - '0')) {
                                allFound = false;
                                break;
                            }
                        }
                        if (!allFound) {
                            continue;
                        }
                        counter++;
                    }
                }
            }
        }
    }
    cout << counter << "\n";
}

