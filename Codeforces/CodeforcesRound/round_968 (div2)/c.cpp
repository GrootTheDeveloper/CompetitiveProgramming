#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int MOD = 1e9 + 7;

string solve(string s) {
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto& [ch, count] : freq) {
        pq.emplace(count, ch);
    }

    string result(s.size(), ' ');
    int index = 0;
    vector<pair<int, char>> temp;

    while (!pq.empty()) {
        auto [count, ch] = pq.top();
        pq.pop();

        if (!temp.empty() && temp.back().second == ch) {

            auto [next_count, next_ch] = pq.top();
            pq.pop();
            pq.push({ count, ch });
            count = next_count;
            ch = next_ch;
        }

        for (int i = 0; i < count; ++i) {
            if (index >= s.size()) {
                index = 1;
            }
            result[index] = ch;
            index += 2;
        }

        temp.push_back({ count, ch });
    }

    return result;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << solve(s) << endl;
    }


    return 0;
}