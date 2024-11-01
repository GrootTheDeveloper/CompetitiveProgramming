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
        string s;
        cin >> s;
        bool valid = true;
        if (s.size() <= 2) valid = false;
        else {
            if (s[0] == '1' && s[1] == '0') {
                string tmp = s.substr(2);
                int num = stoll(tmp);
                string check = to_string(num);
                if (check.size() != tmp.size()) {
                    valid = false;
                }
                else {
                    if (num > 1) {
                        valid = true;
                    }
                    else valid = false;
                }
            }
            else {
                valid = false;
            }

        }
        if (valid) yes;
        else no;
        cout << endl;
    }

    return 0;
}