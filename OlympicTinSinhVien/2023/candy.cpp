#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> generators(n);
        int total_power = 0;

        for (int i = 0; i < n; ++i) {
            cin >> generators[i];
            total_power += generators[i];
        }

        // Sắp xếp mảng để dễ xác định các máy phát có năng lượng lớn
        sort(generators.begin(), generators.end(), greater<int>());

        // Tính tổng năng lượng khi không tính máy phát có năng lượng cao nhất
        int sum_without_max = total_power - generators[0];
        int faultable_count = 0;

        // Kiểm tra số lượng máy phát faultable
        for (int i = 0; i < n; ++i) {
            if (sum_without_max >= generators[i]) {
                faultable_count++;
            }
            sum_without_max += generators[i];
            if (i + 1 < n) sum_without_max -= generators[i + 1];
        }

        // In kết quả
        if (faultable_count == k) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
