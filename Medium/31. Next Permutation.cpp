class Solution {
public:
    void nextPermutation(vector<int>& num) {
        int i = num.size() - 1;

        while(i >= 0) {
            if(i + 1 < num.size() and num[i] < num[i+1]) {
                break;
            }
            --i;
        }

        if(i < 0) {
            sort(num.begin(), num.end());
            return;
        }

        int j = num.size() - 1;

        while(j > i) {
            if(num[j] > num[i]) {
                break;
            }
            --j;
        } 

        if(j == i) {
            sort(num.begin(), num.end());
            return;
        }

        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;

        int l = i + 1;
        int r = num.size() - 1;

        while(l < r) {
            int temp = num[l];
            num[l] = num[r];
            num[r] = temp;

            l++;
            --r;
        }
    }
};