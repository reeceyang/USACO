#include <bits/stdc++.h>

using namespace std;

int maxRegionSize(vector<pair<int, int>> coords) {
    /*for (int i = 0; i < coords.size(); i++) {
        cout << coords[i].first << " " << coords[i].second << "\n";
    }*/
    vector<vector<pair<int, int>>> regions;
    vector<pair<int, int>> temp;
    temp.push_back(coords[0]);
    regions.push_back(temp);

    for (int i = 1; i < coords.size(); i++) {
        pair<int, int> coord = coords[i];
        unordered_set<int> matches;
        // go through all regions
        for (int j = 0; j < regions.size(); j++) {
            vector<pair<int, int>> regionCoords = regions[j];
            for (auto coord2 : regionCoords) {
                if (coord2.first + 1 == coord.first && coord2.second == coord.second) {
                    matches.insert(j);
                }
                if (coord2.first - 1 == coord.first && coord2.second == coord.second) {
                    matches.insert(j);
                }
                if (coord2.first == coord.first && coord2.second + 1 == coord.second) {
                    matches.insert(j);
                }
                if (coord2.first == coord.first && coord2.second - 1 == coord.second) {
                    matches.insert(j);
                }
            }
        }
        //cout << "matches: " << matches.size() << "\n";
        if (matches.size() == 0) {
            // make new region
            vector<pair<int, int>> temp2;
            temp2.push_back(coord);
            regions.push_back(temp2);
            //cout << "make new region: " << coord.first << " " << coord.second << "\n";
        }
        if (matches.size() == 1) {
            regions[*matches.begin()].push_back(coord);
        }
        if (matches.size() > 1) {
            int base = *matches.begin();
            regions[base].push_back(coord);
            matches.erase(base);
            for (int j : matches) {
                regions[base].reserve(regions[base].size() + regions[j].size());
                regions[base].insert(regions[base].end(), regions[j].begin(), regions[j].end());
                //cout << matches[j] << "\n";
                regions[j].erase(regions[j].begin(), regions[j].end());
            }
        }
    }
    // count region size hopefully?
    int maxSize = 0;
    for (int i = 0; i < regions.size(); i++) {
        //cout << "region: " << i << "\n";
        /*for (int j = 0; j < regions[i].size(); j++) {
            cout << regions[i][j].first << " " << regions[i][j].second << "\n";
        }*/
        int thisSize = regions[i].size();
        if (thisSize > maxSize) {
            maxSize = thisSize;
        }
    }
    return maxSize;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);

    int n;
    cin >> n;

    // maps id number to vector of coordinates
    unordered_map<int, vector<pair<int, int>>> cows;
    unordered_set<int> ids;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int id;
            cin >> id;
            ids.insert(id);
            cows[id].push_back(make_pair(i, j));
            //cout << id << " " << idNumbers[id][0].first << " " << idNumbers[id][0].second << "\n";
        }
    }

    int maxSingle = 1, maxTeam = 2;
    int idsSize = ids.size();
    for (int i = 0; i < idsSize; i++) {
        //cout << "id: " << id << "\n";
        int id = *(next(ids.begin(), 0));
        vector<pair<int, int>> coords = cows[id];
        if (coords.size() > maxSingle) {
            int single = maxRegionSize(coords);
            if (single > maxSingle) {
                maxSingle = single;
            }
        }
        ids.erase(id);
        for (int id2 : ids) {
            //cout << "id: " << id << " id2: " << id2 << "\n";
            vector<pair<int, int>> coords2 = cows[id2];
            vector<pair<int, int>> combined;
            if (coords.size() + coords2.size() > maxTeam) {
                combined.reserve(coords.size() + coords2.size());
                combined.insert(combined.end(), coords.begin(), coords.end());
                combined.insert(combined.end(), coords2.begin(), coords2.end());
                int team = maxRegionSize(combined);
                if (team > maxTeam) {
                    maxTeam = team;
                }
            }
        }
    }

    cout << maxSingle << "\n" << maxTeam << "\n";
}

