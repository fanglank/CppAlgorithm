#include <vector>
using namespace std;
int pivotIndex(vector<int> nums){
    int total = 0;
    for(int num : nums) {
        total+=num;
    }
    int sum =0;
    for(int i =0;i<nums.size(); i++){
        sum+=nums[i];
        if(sum - nums[i] == total - sum) {
            return i;
        }
    }
    return -1;
}