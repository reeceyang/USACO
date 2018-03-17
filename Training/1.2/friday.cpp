/*
ID: reeceya1
TASK: friday
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> thirteens = {0, 0, 0, 0, 0, 0, 0};

    int weekday = 2; // 0 is saturday
    for (int year = 1900; year <= 1900 + n - 1; year++) {
        bool isLeapYear = false;
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            isLeapYear = true;
        }
        for (int month = 1; month <= 12; month++) {
            int days = 31;
            switch(month) {
                case 4:
                case 6:
                case 9:
                case 11:
                    days = 30;
                    break;
                case 2:
                    if (isLeapYear) {
                        days = 29;
                    } else  {
                        days = 28;
                    }
            }
            for (int day = 1; day <= days; day++) {
                weekday = (weekday + 1) % 7;
                if (day == 13) {
                    thirteens[weekday]++;
                }
            }
        }
    }
    for (int i = 1; i < 7; i++) {
        cout << thirteens[i] << " ";
    }
    cout << thirteens[0] << "\n";
}

