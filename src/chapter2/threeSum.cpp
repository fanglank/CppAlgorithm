#include <vector>
#include <algorithm>
using namespace std;
void sumTwo(vector<int> nums, int i, vector<vector<int> > &result)
{
    int j = i + 1;
    int k = nums.size();
    while (j < k)
    {
        if (nums[i] + nums[j] + nums[k] == 0)
        {
            vector<int> sub;
            sub.push_back(nums[i]);
            sub.push_back(nums[j]);
            sub.push_back(nums[k]);
            result.push_back(sub);
            int temp = nums[j];
            while (nums[j] == temp && j < k)
            {
                ++j;
            }
        }
        else if (nums[i] + nums[j] + nums[k] < 0)
        {
            ++j;
        }
        else
        {
            --k;
        }
    }
}
vector<vector<int> > threeSum(vector<int> nums)
{
    vector<vector<int> > result;
    if (nums.size() > 3)
    {
        sort(nums.begin(), nums.end(), [](int &a, int &b) -> bool
             { a < b; });
        // nums.
        int i = 0;
        while(i < nums.size() - 2) {
            sumTwo(nums, i, result);
            int temp = nums[i];
            while(i < nums.size() && nums[i] == temp){
                ++i;
            }
        }
    }

    return result;
}
