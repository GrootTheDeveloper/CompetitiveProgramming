int f[1005][1005];
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = (int) text1.size();
        int n2 = (int) text2.size(); 
        for (int i = 0; i <= n1; i++) {
            f[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++) {
            f[0][j] = 0; 
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1; 
                }
                else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[n1][n2]; 
    }
};