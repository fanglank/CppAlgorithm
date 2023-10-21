#include <vector>
using namespace std;
int numSubArrayProductLessThanK(vector<int> nums, int k)
{
    long product = 1;
    int left = 0;
    int count = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        product *= nums[right];
        while (left <= right && product >= k)
        {
            product /= nums[left++];
        }
        count += right >= left ? right - left + 1 : 0;
    }
    return count;
}

//快慢指针
int removeDuplicates(vector<int> nums)
{
    int slow = 0;
    int fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

int removeElement(vector<int> nums, int val){
    int fast =0, slow =0;
    while (fast < nums.size())
    {
        if(nums[fast] !=val){
            nums[slow] = nums[fast];
            slow++;
        }
        fast ++;
    }
    return slow;
}