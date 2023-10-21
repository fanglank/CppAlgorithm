#include <vector>
#include <map>
using namespace std;
int subarraySum(vector<int> nums, int k){
    map<int, int> sumToCount;
    sumToCount[0] = 1;
    int sum = 0;
    int count = 0;
    for(auto num : nums) {
        sum+=num;
        count +=sumToCount[sum -k];//num之前有多少个 sum -k
        sumToCount[sum] = sumToCount[sum] + 1;
    }
    return count;
}