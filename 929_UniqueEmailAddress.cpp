class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> seen;
        int cnt = 0;
        for (vector<string>::iterator it = emails.begin(); it != emails.end(); it++) {
            bool local = true;
            bool plus = false;
            string::iterator _at;
            string::iterator _plus;
            for (string::iterator it2 = it->begin(); it2 != it->end(); it2++) {
                if (local) {
                    if (*it2 == '@') {  // mark @, end of local name
                        local = false;
                        _at = it2;
                    }
                    if (*it2 == '.') it -> erase(it2,next(it2));  // remove all . in local name
                    if (*it2 == '+' && !plus) {  // mark +, begin of ignored part
                        plus = true;
                        _plus = it2;
                    }
                }
            }
            it -> erase(_plus,_at); // remove the after + part in local name
            if (cnt == 0 || seen.find(*it) == seen.end()) cnt++;
            seen.insert(*it);
        }
        return cnt;
    }
};