// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            int rem_target = target - arr[i];
            
            int l = i + 1;
            int r = n - 1;
            
            while(l < r) {
                int s = arr[l] + arr[r];
                
                if(s < rem_target) {
                    ++l;
                } else if (s > rem_target) {
                    --r;
                } else {
                    // cout << "(" << arr[i] << ", " << arr[l] << ", " << arr[r] << ")" << " --> "; 
                    int to_add = 0;
                    if(arr[l] == arr[r]) {
                        int num_elms = r - l + 1;
                        to_add = ((num_elms * (num_elms - 1)) / 2) % (1000000007) ;
                        l += num_elms;
                        r -= num_elms;
                        
                    } else {
                        int l_same = 1;
                        int r_same = 1;
                        ++l;
                        --r;
                        while(l <= r and arr[l] == arr[l-1]) {
                            ++l_same;
                            ++l;
                        }

                        while(l <= r and arr[r] == arr[r+1]) {
                            ++r_same;
                            --r;
                        }

                        to_add = (l_same * r_same) % (1000000007);
                        
                    }
                    
                    // cout << to_add << endl; 
                    ans = (ans + (to_add)) % (1000000007);
                }
                
            } 
        }
        return ans;
        
    }
};