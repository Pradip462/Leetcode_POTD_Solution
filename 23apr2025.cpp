class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> mpp;
            int maxSize = 0;
            int count = 0;
    
            for (int i = 1; i <= n; i++) {
                int x = i;
                int sum = 0;
                while (x != 0) {
                    sum += x % 10;
                    x /= 10;
                }
    
                mpp[sum]++;
    
                if (mpp[sum] == maxSize) {
                    count++;
                } else if (mpp[sum] > maxSize) {
                    maxSize = mpp[sum];
                    count = 1;
                }
            }
    
            return count;
        }
    };