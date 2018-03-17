/*
ID: reeceya1
LANG: C++11
TASK: transform
*/

#include <bits/stdc++.h>

using namespace std;

string toString(vector<string> v) {
    string s = "";
    for (auto x : v) {
        s += x + "\n";
    }
    return s;
}

string getSpaces(int n) {
    string s = "";
    for (int i = 0; i < n; i++) {
        s += " ";
    }
    return s;
}

// Returns rotation of pattern 90 degrees clockwise
vector<string> getRotation(vector<string> pattern, int n) {
    vector<string> rotation(n, getSpaces(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotation[i][j] = pattern[abs(j - (n - 1))][i];
        }
    }
    //cout << toString(rotation) << "\n";
    return rotation;
}

// Returns horizontal reflection of pattern
vector<string> getReflection(vector<string> pattern, int n) {
    vector<string> reflection(n, getSpaces(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reflection[i][j] = pattern[i][abs(n - 1 - j)];
        }
    }
    //cout << toString(reflection) << "\n";
    return reflection;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> before;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        before.push_back(s);
    }
    vector<string> after;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        after.push_back(s);
    }

    vector<string> reflection = getReflection(before, n);
    vector<string> rotation90 = getRotation(before, n);
    vector<string> rotation180 = getRotation(rotation90, n);
    vector<string> rotation270 = getRotation(rotation180, n);
    vector<string> refRotation90 = getRotation(reflection, n);
    vector<string> refRotation180 = getRotation(refRotation90, n);
    vector<string> refRotation270 = getRotation(refRotation180, n);

    int transformation = 7;
    if (before == after) {
        transformation = 6;
    }
    if (after == refRotation90 || after == refRotation180 || after == refRotation270) {
        transformation = 5;
    }
    if (after == reflection) {
        transformation = 4;
    }
    if (after == rotation270) {
        transformation = 3;
    }
    if (after == rotation180) {
        transformation = 2;
    }
    if (after == rotation90) {
        transformation = 1;
    }
    cout << transformation << "\n";
}

