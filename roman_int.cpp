#include <string>
#include <stdint.h>

using namespace std;
class Solutiont {
public:
    string a[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
    };

    string intToRoman(int num) {
        string ret = "";
        for (int i = 0; i < 4; i++) {
            ret = a[i][num % 10] + ret;
            num /= 10;
        }
        return ret;
    }

    int romanToInt(string s) {
        int ret = 0;
        int base = 1000;
        int x = 3, y = 3;
        int pos = 0;
        while (pos < s.size()) {
            if (pos + a[x][y].size() <= s.size()) {
                bool wrong = false;
                for (int i = 0;i < a[x][y].size();i++) {
                    if (a[x][y][i] != s[pos + i]) {
                        wrong = true;
                        break;
                    }
                }
                if (!wrong) {
                    pos += a[x][y].size();
                    ret += base * y;
                }
            }
            y--;
            if (y == 0) {
                base /= 10;
                x --;
                y = 9;
            }
        }
        return ret;
    }
};
