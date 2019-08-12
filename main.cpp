#include <stdio.h>
#include <wrl.h>
#include <stdio.h>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        char c[20];
        sprintf(c, "%d", x);
        int n = strlen(c);
        for (int i = 0; i < n; i++) {
            if (c[i] != c[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool isPalindromet(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        long long y = 0;
        while (x != 0) {
            y = y * 10 + x % 10;
            x /=10;
        }
        return temp == y;
    }
};

int main() {
    printf("%d",Solution().isPalindromet(1112));
}