// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        if(n == INT_MAX) {
            return -1;
        }
        string num = to_string(n);

        int i = num.length() - 1;

        while(i >= 0) {
            if(num[i] < num[i+1]) {
                break;
            }
            --i;
        }

        if(i < 0) {
            return -1;
        }

        int j = num.length() - 1;

        while(j > i) {
            if(num[j] > num[i]) {
                break;
            }
            --j;
        } 

        if(j == i) {
            return -1;
        }

        // cout << i << ": " << j << endl;

        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;

        int l = i + 1;
        int r = num.length() - 1;

        while(l < r) {
            char temp = num[l];
            num[l] = num[r];
            num[r] = temp;

            l++;
            --r;
        }

        // cout << num << endl;

        long ans = stol(num);
        if(ans > INT_MAX) {
            return -1;
        }

        return int(ans);
    }
};