#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> questions;
    vector<int> sortedQuestions;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        questions.push_back(x);
        sortedQuestions.push_back(x);
        sum += x;
    }
    sort(sortedQuestions.begin(), sortedQuestions.end());

    vector<int> kvalues;
    int frontSum = 0;
    double maximum = 0;
    for (int k = 0; k < n - 2; k++) {
        frontSum += questions[k];
        if (questions[k] == sortedQuestions[0]) {
            sortedQuestions.erase(sortedQuestions.begin());
        }
        double average = (sum - frontSum - sortedQuestions[0]) / (n - (k + 1) - 1);
        if (average > maximum) {
            maximum = average;
            kvalues = {};
        }
        if (abs(average - maximum) < 1e-9) {
            kvalues.push_back(k + 1);
        }
    }
    cout << kvalues[0];
    for (int i = 1; i < kvalues.size(); i++) {
        cout << " " << kvalues[i];
    }
    cout << "\n";
}

