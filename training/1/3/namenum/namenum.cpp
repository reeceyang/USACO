/*
ID: reeceya1
LANG: C++11
TASK: namenum
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> names;
vector<string> dictionary;

void permute(string number, int index) {
    switch(number[index]) {
        case '2':
            permute(number.replace(index, 1, "A"), index + 1);
            permute(number.replace(index, 1, "B"), index + 1);
            permute(number.replace(index, 1, "C"), index + 1);
            break;
        case '3':
            permute(number.replace(index, 1, "D"), index + 1);
            permute(number.replace(index, 1, "E"), index + 1);
            permute(number.replace(index, 1, "F"), index + 1);
            break;
        case '4':
            permute(number.replace(index, 1, "G"), index + 1);
            permute(number.replace(index, 1, "H"), index + 1);
            permute(number.replace(index, 1, "I"), index + 1);
            break;
        case '5':
            permute(number.replace(index, 1, "J"), index + 1);
            permute(number.replace(index, 1, "K"), index + 1);
            permute(number.replace(index, 1, "L"), index + 1);
            break;
        case '6':
            permute(number.replace(index, 1, "M"), index + 1);
            permute(number.replace(index, 1, "N"), index + 1);
            permute(number.replace(index, 1, "O"), index + 1);
            break;
        case '7':
            permute(number.replace(index, 1, "P"), index + 1);
            permute(number.replace(index, 1, "R"), index + 1);
            permute(number.replace(index, 1, "S"), index + 1);
            break;
        case '8':
            permute(number.replace(index, 1, "T"), index + 1);
            permute(number.replace(index, 1, "U"), index + 1);
            permute(number.replace(index, 1, "V"), index + 1);
            break;
        case '9':
            permute(number.replace(index, 1, "W"), index + 1);
            permute(number.replace(index, 1, "X"), index + 1);
            permute(number.replace(index, 1, "Y"), index + 1);
            break;
        default:
            auto k = lower_bound(dictionary.begin(), dictionary.end(), number);
            if (k < dictionary.end() && dictionary[k - dictionary.begin()] == number) {
                names.push_back(number);
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    ifstream dictFile;
    dictFile.open("dict.txt");
    string s;
    while (dictFile >> s) {
        dictionary.push_back(s);
    }

    string number;
    cin >> number;

    permute(number, 0);

    for (auto x : names) {
        cout << x << "\n";
    }

    if (names.size() == 0) {
        cout << "NONE" << "\n";
    }
}

