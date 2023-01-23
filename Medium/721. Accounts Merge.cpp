// https://leetcode.com/problems/accounts-merge

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> email_parent;
        vector<int> parents(n, -1);

        vector<vector<string>> ans;

        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            for(int j = 1; j < accounts[i].size(); ++j) {
                if(email_parent.find(accounts[i][j]) == email_parent.end()) {
                    email_parent[accounts[i][j]] = i;
                } else {
                    // cout << accounts[i][j] << endl;
                    int current_email_parent = email_parent[accounts[i][j]];
                    // cout << current_email_parent << endl;
                    while(parents[current_email_parent] != current_email_parent) {
                        current_email_parent = parents[current_email_parent];
                    }
                    // cout << current_email_parent << endl;
                    if(current_email_parent < parents[i]) {
                        for(int k = 0; k < n; ++k) {
                            if(parents[k] == parents[i]) {
                                parents[k] = current_email_parent;
                            }
                        }
                    } else {
                        for(int k = 0; k < n; ++k) {
                            if(parents[k] == current_email_parent) {
                                parents[k] = parents[i];
                            }
                        }
                    }
                }
            }
        }

        // for(auto p: parents) {
        //     cout << p << "; ";
        // } cout << endl;

        unordered_map<int, set<string>> m;
        for(int i = 0; i < n; ++i) {
            int parent_node = parents[i];
            if(m.find(parent_node) == m.end()) {
                m[parent_node] = set<string>{};
            }
            
            for(int j = 1; j < accounts[i].size(); ++j) {
                m[parent_node].insert(accounts[i][j]);
            }
        }

        for(auto p: m) {
            int idx = p.first;
            vector<string> subans;
            subans.emplace_back(accounts[idx][0]);
            for(auto s: p.second) {
                subans.emplace_back(s);
            }
            ans.emplace_back(subans);
        }

       
        return ans;
    }
};