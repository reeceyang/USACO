/*
ID: reeceya1
LANG: C++11
TASK: milk
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int milkAmount, m;
    cin >> milkAmount >> m;

    vector<pair<int, int>> farmers;
    for (int i = 0; i < m; i++) {
        int price, amount;
        cin >> price >> amount;
        farmers.push_back(make_pair(price, amount));
    }

    sort(farmers.begin(), farmers.end());

    int currentAmount = 0;
    int cost = 0;
    int index = 0;
    while (currentAmount < milkAmount) {
        int price = farmers[index].first, amount = farmers[index].second;
        if (amount + currentAmount < milkAmount) {
            cost += amount * price;
            currentAmount += amount;
        } else {
            cost += (milkAmount - currentAmount) * price;
            currentAmount = milkAmount;
        }
        index++;
    }
    cout << cost << "\n";
}
