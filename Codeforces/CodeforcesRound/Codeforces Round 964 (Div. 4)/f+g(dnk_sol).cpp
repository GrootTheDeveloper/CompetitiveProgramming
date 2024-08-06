#include <iostream> 
int numTest;

int main() {
    std::cin >> numTest;
    for (int testCase = 1; testCase <= numTest; testCase++) {
        int lo = 2;
        int hi = 999;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            std::cout << "? " << 1 << ' ' << mid << std::endl;
            fflush(stdout);
            int S;
            std::cin >> S;
            if (S == mid) {
                lo = mid + 1;
            }
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        std::cout << "! " << ans << std::endl;
    }
    return 0;
}