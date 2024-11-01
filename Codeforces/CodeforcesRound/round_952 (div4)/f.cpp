#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

struct power {
	int damage;
	int cooldown;
};

bool process(vector<power>attack,int numAttack, int health,int turn) {
	
	int currentDamage = 0;

	for (int i = 0; i < numAttack; i++) {
		currentDamage += attack[i].damage*((turn - 1) / attack[i].cooldown + 1);
	}
	return currentDamage >= health;
}
signed main() {

	int t; cin >> t;
	while (t--) {
		int health, numAttack;
		cin >> health >> numAttack;
		
		vector<power> attack(numAttack);
		int temp = health;
		for (int i = 0; i < numAttack; i++) {
			cin >> attack[i].damage;
			temp -= attack[i].damage;
		}

		for (int i = 0; i < numAttack; i++) {
			cin >> attack[i].cooldown;
		}
		if (temp <= 0) {
			cout << 1 << endl;
			continue;
		}

		int left = 1, right = 1e12;
		int answer = 0;
		while (left <= right) {
			int turn = (left + right) / 2;
			if (process(attack, numAttack, health, turn)) {
				answer = turn;
				right = turn - 1;
			}
			else {
				left = turn + 1;
			}
		}
		cout << answer << endl;

	}

}

