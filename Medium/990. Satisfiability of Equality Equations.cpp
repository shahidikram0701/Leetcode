// https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char> parents;

        for(auto equation: equations) {
            if(equation[1] == '!' or equation[0] == equation[3]) {
                continue;
            }
            char var1 = equation[0];
            char var2 = equation[3];

            char parent1 = _find(var1, parents);
            char parent2 = _find(var2, parents);

            if(parent1 != parent2) {
                _union(parent1, parent2, parents);
            }
        }

        for(auto equation: equations) {
            if(equation[1] == '=') {
                continue;
            }
            char var1 = equation[0];
            char var2 = equation[3];

            char parent1 = _find(var1, parents);
            char parent2 = _find(var2, parents);

            if(parent1 == parent2) {
                return false;
            }
        }

        return true;

    }

    char _find(char c, unordered_map<char, char>& parents) {
        if(parents.find(c) == parents.end()) {
            parents[c] = c;
        }
        if(parents[c] == c) {
            return parents[c];
        }
        return _find(parents[c], parents);
    }

    void _union(char c1, char c2, unordered_map<char, char>& parents) {        
        char small = min(c1, c2);
        char big = max(c1, c2);

        parents[big] = _find(small, parents);
    }
};