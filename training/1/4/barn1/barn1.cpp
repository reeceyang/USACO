/*
ID: reeceya1
LANG: C++11
TASK: barn1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int maxBoards, totalStalls, cows;
    cin >> maxBoards >> totalStalls >> cows;
    //cout << maxBoards << " " << totalStalls << " " << cows << "\n";

    vector<int> cowStalls;
    for (int i = 0; i < cows; i++) {
        int stall;
        cin >> stall;
        cowStalls.push_back(stall);
    }
    sort(cowStalls.begin(), cowStalls.end());
    vector<int> gaps;
    for (int i = 0; i < cows - 1; i++) {
        gaps.push_back(cowStalls[i + 1] - cowStalls[i] - 1);
        //cout << gaps[i] << "\n";
    }
    sort(gaps.rbegin(), gaps.rend());
    int blocked = cowStalls[cows - 1] - cowStalls[0] + 1;
    for (int i = 0; i < maxBoards - 1 && i < cows - 1; i++) {
        blocked -= gaps[i];
    }
    cout << blocked << "\n";
    /*vector<bool> stalls (totalStalls);
    vector<bool> boards (totalStalls);
    int maxStall = 0;
    int minStall = totalStalls - 1;
    for (int i = 0; i < cows; i++) {
        int stall;
        cin >> stall;
        //cout << stall << "\n";
        stalls[stall] = true;
        if (stall > maxStall) {
            maxStall = stall;
        }
        if (stall < minStall) {
            minStall = stall;
        }
    }
    //cout << maxStall << " " << minStall << "\n";
    for (int i = minStall; i <= maxStall; i++) {
        boards[i] = true;
    }

    int stallsCovered = maxStall - minStall + 1;
    for (int j = 0; j < maxBoards - 1; j++) {
        int maxGap = 0;
        int gapStart, gapEnd;
        int currentGap = 0;
        int currentStart = minStall + 1;
        int currentEnd = currentStart;
        for (int i = minStall + 1; i <= maxStall; i++) {
            if (boards[i] == false) {
                currentStart++;
                currentEnd = currentStart;
                continue;
            }
            if (stalls[i] == false) {
                currentEnd++;
                currentGap++;
            }
            if (stalls[i] == true) {
                if (currentGap > maxGap) {
                    maxGap = currentGap;
                    gapStart = currentStart;
                    gapEnd = currentEnd;
                }
                currentGap = 0;
                currentStart++;
                currentEnd = currentStart;
            }
        }

        for (int i = gapStart; i <= gapEnd; i++) {
            boards[i] = false;
        }
        stallsCovered -= maxGap;
    }
    for (int i = 0; i < totalStalls; i++) {
        cout << (stalls[i] ? "C" : " ");
    }
    cout << "\n";
    for (int i = 0; i < totalStalls; i++) {
        cout << (boards[i] ? "B" : " ");
    }
    cout << "\n";
    cout << stallsCovered << "\n";*/
}
