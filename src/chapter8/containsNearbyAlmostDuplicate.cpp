#include <vector>

#include <unordered_map>

using namespace std;

int getBucketID(int num, int bucketSize){
    return num>0?num/bucketSize:(num+1)/bucketSize-1;
}

bool containsNearbyAlmostDuplicate(vector<int> nums, int k ,int t) {
    unordered_map<int,int> buckets;
    int bucketSize = t+1;
    for(int i =0;i <nums.size();i++){
        int num = nums[i];
        int id = getBucketID(num, bucketSize);

        if(buckets.count(id)
        || (buckets.count(id-1)&& buckets.count(id-1)+t>=num) 
        ||(buckets.count(id+1)&& buckets.count(id+1)-t<=num)){
            return true;
        }

        buckets[id] = num;
        if(i>=k){
            buckets.erase(getBucketID(nums[i-k], bucketSize));
        }

        return false;
    }
}

