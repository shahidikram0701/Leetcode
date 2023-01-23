// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char_count;
        for(char c: s) {
            if(char_count.find(c) == char_count.end()) {
                char_count[c] = 0;
            }
            char_count[c]++; 
        }
        
        auto comparator = [&char_count](char c1, char c2) {
            return char_count[c1] == char_count[c2] ? 
                    c1 > c2 : 
                    char_count[c1] > char_count[c2]; 
            } ;
        
        sort(s.begin(), s.end(), comparator);
        
        return s;
    }
};

// Approach 2

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char_count;
        string unique_chars = "";
        for(char c: s) {
            if(char_count.find(c) == char_count.end()) {
                char_count[c] = 0;
                unique_chars += c;
            }
            char_count[c]++; 
        }
        
        auto comparator = [&char_count](char c1, char c2) {return char_count[c1] <= char_count[c2]; };
        
        priority_queue<char, vector<char>, decltype(comparator)> heap(comparator);
        
        for(char c: unique_chars) {
            heap.push(c);
        }
        string ans = "";
        while(!heap.empty()) {
            char c = heap.top();
            for(int i = 0; i < char_count[c]; ++i) {
                ans += c;
            }
            heap.pop();
        }
        
        return ans;
    }
};
