#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

bool visited[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

signed main() {

    int t; cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int m;
        cin >> m;
        vector<string> strings(m);
        for (int i = 0; i < m; ++i) {
            cin >> strings[i];
        }

        for (const auto& s : strings) {
            if (s.length() != n) {
                cout << "NO\n";
                continue;
            }

            unordered_map<int, char> intToChar;
            unordered_map<char, int> charToInt;
            bool isValid = true;

            for (int i = 0; i < n; ++i) {
                int num = a[i];
                char ch = s[i];

                if ((intToChar.count(num) && intToChar[num] != ch) ||
                    (charToInt.count(ch) && charToInt[ch] != num)) {
                    isValid = false;
                    break;
                }

                intToChar[num] = ch;
                charToInt[ch] = num;
            }

            if (isValid) {
                yes;
            }
            else {
                no;
            }
            cout << endl;
        }
    }

    return 0;
}
