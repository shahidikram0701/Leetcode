// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        vector<int> hcuts;
        vector<int> vcuts;

        int prev = 0;
        for(int hcut: horizontalCuts) {
            hcuts.push_back(hcut - prev);
            prev = hcut;
        }
        hcuts.push_back(h - prev);

        prev = 0;
        for(int vcut: verticalCuts) {
            vcuts.push_back(vcut - prev);
            prev = vcut;
        }
        vcuts.push_back(w - prev);

        // print(hcuts);
        // print(vcuts);

        long maxHeight = (*max_element(hcuts.begin(), hcuts.end())) % 1000000007;
        long maxWidth = (*max_element(vcuts.begin(), vcuts.end())) % 1000000007;

        long ans = (maxHeight * maxWidth) % 1000000007;
        return int(ans);
    }

    void print(vector<int>& v) {
        for(int i: v) {
            cout << i << " ";
        } cout << endl;
    }
};