//Brute Force
int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    //map stores the element and it's frequency
    unordered_map<int,int> mpp;
    for(int i = 0;i < n;i++){
        mpp[nums[i]]++;
    }
    int arr_dist = mpp.size();
    mpp.clear();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        unordered_map<int, int> subFreq;
        for(int j = i; j < n; j++) {
            subFreq[nums[j]]++;
            if(subFreq.size() == arr_dist) cnt++;
        }
    }
    return cnt;
}
//Optimal Approach(Sliding Window + Hash Map)
int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    //map stores the element and it's frequency
    unordered_map<int,int> mpp;
    for(int i = 0;i < n;i++){
        mpp[nums[i]]++;
    }
    int arr_dist = mpp.size();
    mpp.clear();
    int l = 0,r = 0;
    int count = 0;
    while(r < n){
        mpp[nums[r]]++;
        while(mpp.size() == arr_dist){
            count += n - r;
            //shrink the window from left
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        r++;
    }
    return count;
}