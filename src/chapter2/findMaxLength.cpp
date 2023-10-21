#include <vector>
#include <map>
#include <algorithm>
int findMaxLength(vector<int> nums) {
    map<int, int> sumToIndex;
    sumToIndex[0] = -1;
    int sum = 0;
    int maxLength = 0;
    for(int i =0; i< nums.size();i++) {
        sum+=nums[i]==0?-1:1;
        if(sumToIndex.count(sum)) {
            maxLength = max(maxLength, i-sumToIndex[sum]);
        }else {
            sumToIndex[sum] = i;
        }
    }
    return maxLength;
}