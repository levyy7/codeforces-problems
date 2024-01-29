// Problem 1922C "C. Closest Cities" from codeforces.com
// Author: Eneko Sabate

#include <iostream>
#include <vector>

using namespace std;

/*
void print_vector(const vector<int>& v) {
    cout << endl;
    for (int e : v) cout << e << ' ';
    cout << endl;
}
*/

vector<int> compute_suffix(const vector<int>& positions) {
    vector<int> res(positions.size());

    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i < positions.size(); ++i) {
        int distToRight = positions[i] - positions[i - 1];
        int distToLeft = positions[i - 1] - positions[i - 2];
        res[i] = res[i - 1] + (distToRight < distToLeft ? 1 : distToRight);
    }

    return res;
}

vector<int> compute_prefix(const vector<int>& positions) {
    vector<int> res(positions.size());

    res[positions.size() - 1] = 0;
    res[positions.size() - 2] = 1;
    for (int i = positions.size() - 3; i >= 0; --i) {
        int distToRight = positions[i + 2] - positions[i + 1];
        int distToLeft = positions[i + 1] - positions[i];
        res[i] = res[i + 1] + (distToRight > distToLeft ? 1 : distToLeft);
    }

    return res;
}

int minimum_coins(const vector<int>& prefixes, const vector<int>& suffixes, int source, int destination) {
    if (source > destination) { // We have to move leftwards
        return (prefixes[destination] - prefixes[source]);
    }
    else { // We have to move rightwards
        return (suffixes[destination] - suffixes[source]);
    }
}


int main() {
    int t;
    cin >> t;

    while (t != 0) {
        int n;
        cin >> n;

        vector<int> cityPos(n); //Ordered
        for (int i = 0; i < n; ++i) cin >> cityPos[i];

        int m;
        cin >> m;

        vector<int> prefixes = compute_prefix(cityPos);
        vector<int> suffixes = compute_suffix(cityPos);

        while (m != 0) {
            int c1, c2;
            cin >> c1 >> c2;

            --c1; --c2; // Input comes in 1<= c1,c2 <= n format

            cout << minimum_coins(prefixes, suffixes, c1, c2) << endl;

            --m;
        }

        --t;
    }
}