#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];
map<int, int> prices;

int main()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prices[a[i]]++;
    }

    for (auto it = prices.begin(); it != prices.end(); ) {
        if (prices.find(it->first + k) != prices.end()) {
            prices.erase(it->first + k);
        }

        it = next(it);
    }
    cout << prices.size();
    return 0;
}
