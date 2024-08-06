#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
#define         ull         unsigned long long
#define         int         long long
#define         ldb         long double
#define         endl        '\n'
#define         task        "CAU1"
#define		file		ios_base::sync_with_stdio(false); cin.tie(NULL); if (fopen(task".INP", "r")) { freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout); }
#define         Groot       signed main() 
const           int         oo = LLONG_MAX;
const           int         MAXN = 1e6 + 7;
const           int         MOD = 1e9 + 7;

using namespace std;

vector<bool> prime(1e6 + 1, true);
vector<int> primeNum;
void sieve() {
    prime[0] = prime[1] = true;
    for (int i = 2; i * i <= 1e6; i++) {
        if (prime[i]) {
            primeNum.push_back(i);
            for (int j = i * i; j <= 1e6; j += i) {
                prime[j] = false;
            }
        }
    }
}
signed main() {
    int a, b;
    sieve();
    while (cin >> a >> b) {

        map<int, int> divisor;
        int tmpA = a;

        for (int i : primeNum) {
            while (tmpA % i == 0) {
                divisor[i]++;
                tmpA /= i;
            }
            if (i > tmpA) break;
        }
        if (tmpA > 1) divisor[tmpA]++;

        int tmpB = b;
        for (int i : primeNum) {
            while (tmpB % i == 0) {
                divisor[i]--;
                tmpB /= i;
            }
            if (i > tmpB) break;
        }
        if (tmpB > 1) divisor[tmpB]--;

        int minStep = 0;

        for (auto it : divisor) {
            minStep += abs(it.second);
        }
        cout << minStep << endl;
    }
    return 0;
}