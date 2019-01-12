class Solution {
private:
    map<int,int> mapping;
public:
    Solution() {
        mapping.insert(pair<char,char>(')','('));
        mapping.insert(pair<char,char>(']','['));
        mapping.insert(pair<char,char>('}','{'));
    }
    
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            auto it = mapping.find(s[i]);
            if (it == mapping.end()) {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                if (it->second != st.top())
                    return false;
                st.pop();
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};