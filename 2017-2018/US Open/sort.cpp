#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> sorted, unsorted;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sorted.push_back(x);
        unsorted.push_back(x);
    }

    sort(sorted.begin(), sorted.end());
    int maxDisplace = 0;
    for (int i = 0; i < n; i++) {
        int sortedIndex = upper_bound(sorted.begin(), sorted.end(), unsorted[i]) - sorted.begin() - 1;
        if (sortedIndex < i && unsorted[i] != sorted[i]) {
            int displace = i - sortedIndex;
            if (displace > maxDisplace) {
                maxDisplace = displace;
            }
        }
    }

    // Bubble sort
    /*int moo = 0;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        moo++;
        for (int i = 0; i <= n - 2; i++) {
            if (unsorted[i + 1] < unsorted[i]) {
                swap(unsorted[i], unsorted[i + 1]);
                isSorted = false;
            }
        }
    }

    cout << moo << "\n";*/
    // + 1 is when the alg checks whether it is sorted
    cout << maxDisplace + 1 << "\n";
}
