/*
ID: reeceya1
LANG: C++11
TASK: milk2
*/

#include <bits/stdc++.h>

using namespace std;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> farmers;
    for (int i = 0; i < n; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        //if (startTime != endTime) {
        farmers.push_back(make_pair(startTime, endTime));
        //}
    }

    sort(farmers.begin(), farmers.end());
    int maxMilk = 0, maxIdle = 0, maxEndTime = 0;

    //n = farmers.size();

    for (int i = 0; i < n; i++) {
        int startTime = farmers[i].first;
        int endTime = farmers[i].second;
        if (endTime > maxEndTime) {
            maxEndTime = endTime;
        }
        for (int j = 0; j < n; j++) {
            if (farmers[j].second > endTime) {
                if (farmers[j].first <= endTime) {
                    endTime = farmers[j].second;
                } else {
                    break;
                }
            }
        }
        int milkTime = endTime - startTime;
        if (milkTime > maxMilk) {
            maxMilk = milkTime;
        }
        int idleTime = 0;
        for (int i = 0; i < n; i++) {
            //cout << i << " " << farmers[i].first << " " << endTime << " " << (farmers[i].first > endTime ? "true" : "false") << "\n";
            if (farmers[i].first > endTime) {
                idleTime = farmers[i].first - endTime;
                break;
            }
        }
        if (idleTime > maxIdle) {
            maxIdle = idleTime;
        }
        //cout << endTime << "\n";
    }
    /*int index = 0;
    int endTime = farmers[index].second;
    while (index < n) {
        int idleTime = 0;
        //int stackCounter = 0;
        //bool found = false;
        int j;
        for (j = index + 1; j < n; j++) {
            if (farmers[j].second <= endTime) {
                index++;
            }
            if (farmers[j].first > endTime) {
                break;
            }
        }
        //j -= 1;
        if (j == index + 1) {
            idleTime = farmers[j].first - endTime;
        }
        endTime = farmers[j].second;
        for (int j = i + 1; j < n; j++) {
            if (farmers[j].first > endTime && (j == i + 1 || stackCounter > 0)) {
                found = true;
                idleTime = farmers[j].first - endTime;
                break;
            }
            if (farmers[j].first > farmers[i].first && farmers[j].second < endTime) {
                stackCounter++;
            }
            if (farmers[j].first > endTime) {
                found = true;
            }
        }
        if (!found) {
            break;
        }
        if (idleTime > maxIdle) {
            maxIdle = idleTime;
        }
        index = j;
    }*/

    /*sort(farmers.begin(), farmers.end(), sortBySecond);
    for (int i = 0; i < n - 1; i++) {
        int idleTime = 0;
        if (farmers[i].second < farmers[i + 1].first) {
            idleTime = farmers[i + 1].first - farmers[i].second;
        }
        if (idleTime > maxIdle) {
            maxIdle = idleTime;
        }
    }*/
    cout << maxMilk << " " << maxIdle << "\n";
}
