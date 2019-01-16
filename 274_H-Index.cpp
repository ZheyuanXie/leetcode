class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int hindex = 0;
        for (int i = 0; i < citations.size(); i++) {
            int total = i + 1;  //number of papers
            int citation = citations[citations.size() - 1 - i];
            if (total <= citation) hindex = total;
            else break;
        }
        return hindex;
    }
};