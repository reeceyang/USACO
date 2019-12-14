/*
ID: reeceya1
LANG: C++11
TASK: skidesign
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> hills;
    int minPay = 0;
    for (int i = 0; i < n; i++) {
        int hill;
        cin >> hill;
        minPay += hill * hill;
        hills.push_back(hill);
    }
    sort(hills.begin(), hills.end());
    /*for (auto hill : hills) {
        cout << hill <<     "\n";
    }*/
    for (int i = 0; i < n; i++) {
        int hill = hills[i];
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += (hill - hills[j]) * (hill - hills[j]);
        }
        cout << hill << " lowSum: " << sum << " upIndex: ";
        int index = distance(hills.begin(), upper_bound(hills.begin(), hills.end(), hill + 17));
        cout << index << " totalSum: ";
        for (int j = index; j < n; j++) {
            sum += (hill + 17 - hills[j]) * (hill + 17 - hills[j]);
        }
        cout << sum << "\n";
        if (sum < minPay) {
            minPay = sum;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int hill = hills[i];
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += (hill - hills[j]) * (hill - hills[j]);
        }
        cout << hill << " highSum: " << sum << " downIndex: ";
        int index = distance(hills.begin(), lower_bound(hills.begin(), hills.end(), hill - 17)) - 1;
        cout << index << " totalSum: ";
        for (int j = 0; j <= index; j++) {
            sum += (hill - 17 - hills[j]) * (hill - 17 - hills[j]);
        }
        cout << sum << "\n";
        if (sum < minPay) {
            minPay = sum;
        }
    }
    cout << minPay << "\n";
}

