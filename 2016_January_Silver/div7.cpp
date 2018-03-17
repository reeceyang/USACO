#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cows.push_back(x);
    }

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        int currentCount = 0;
        int maxCount = 0;
        for (int j = i; j < n; j++) {
            currentCount++;
            sum += cows[j];
            if (sum % 7 == 0 && currentCount > maxCount) {
                maxCount = currentCount;
            }
        }
        if (maxCount > maximum) {
            maximum = maxCount;
        }
    }

    cout << maximum;
}
