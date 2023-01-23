// https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int power = 1;

        string num = to_string(n);
        sort(num.begin(), num.end());

        while(power <= 1000000000) {
            string pow = to_string(power);
            sort(pow.begin(), pow.end());
            if(num.compare(pow) == 0) {
                return true;
            }

            power = power << 1;
        }

        return false;
    }
};