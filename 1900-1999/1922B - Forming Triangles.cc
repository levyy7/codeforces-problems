// Problem 1922B "B. Forming Triangles" from codeforces.com

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
bool isNonDegenerate(int small1, int small2, int large) {
    return small1 + small2 > large;
}
*/

long long triangleCombinations(const vector<long long>& freqs, const vector<long long>& prefix_sums) {
    long long counter = 0;

    counter += (freqs[0]*(freqs[0] - 1)*(freqs[0] - 2))/6;
    for (int i = 1; i < freqs.size(); ++i) {
        counter += (freqs[i]*(freqs[i] - 1)*(freqs[i] - 2))/6;
        
        counter += prefix_sums[i - 1]*freqs[i]*(freqs[i] - 1)/2;
    }

    return counter;
}   

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> sticks(n);
        for (int i = 0; i < n; ++i) cin >> sticks[i];

        vector<long long> freqs(n + 1, 0);
        for (int i = 0; i < n; ++i) ++freqs[sticks[i]];

        vector<long long> prefix_sums(n + 1);
        prefix_sums[0] = freqs[0];
        for (int i = 1; i < n + 1; ++i) prefix_sums[i] = prefix_sums[i - 1] + freqs[i];

        cout << triangleCombinations(freqs, prefix_sums) << endl;
    }
}