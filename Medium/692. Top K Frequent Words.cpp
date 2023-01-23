// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;

        for(string word: words) {
            if(counts.find(word) == counts.end()) {
                counts[word] = 0;
            }
            counts[word]++;
        }

        auto comparator = [&counts](string s1, string s2){
            if(counts[s1] == counts[s2]) {
                return s1 > s2;
            }
            return counts[s1] < counts[s2];
        };

        priority_queue<string, vector<string>, decltype(comparator)> heap(comparator);


        for(auto p: counts) {
            heap.push(p.first);
        }

        vector<string> ans;
        for(int i = 0; i < k; ++i) {
            ans.emplace_back(heap.top());
            heap.pop();
        }

        return ans;
    }
};