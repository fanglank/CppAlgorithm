#include <vector>
#include <climits>
using namespace std;
int minSubArrayLen(int k, vector<int> nums)
{
    int left = 0;
    int sum = 0;
    int minLength = INT_MAX;
    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (left <= right && sum >= k)
        {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}