#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;


signed main() {
    int testCase; cin >> testCase;
    while (testCase--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int suneet_cards[2] = { a1, a2 };
        int slavic_cards[2] = { b1, b2 };

        int suneet_wins = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int suneet_score = 0;
                int slavic_score = 0;

                if (suneet_cards[i] > slavic_cards[j]) {
                    suneet_score++;
                }
                else if (suneet_cards[i] < slavic_cards[j]) {
                    slavic_score++;
                }

                if (suneet_cards[1 - i] > slavic_cards[1 - j]) {
                    suneet_score++;
                }
                else if (suneet_cards[1 - i] < slavic_cards[1 - j]) {
                    slavic_score++;
                }

                if (suneet_score > slavic_score) {
                    suneet_wins++;
                }
            }
        }

        cout << suneet_wins << endl;
    }
}
