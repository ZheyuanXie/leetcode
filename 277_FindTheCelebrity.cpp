// 1012 ms
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> nums_know(n,0);
        vector<int> nums_known(n,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (knows(i,j)) {
                        nums_know[i]++;
                        nums_known[j]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums_know[i] == 0 && nums_known[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};


// 104 ms
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> nums_know(n,0);
        vector<int> nums_known(n,n-1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && (nums_know[i] == 0 || nums_known[j] == n-1)) {
                    if (knows(i,j)) {
                        nums_know[i]++;
                    } else {
                        nums_known[j]--;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums_know[i] == 0 && nums_known[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};