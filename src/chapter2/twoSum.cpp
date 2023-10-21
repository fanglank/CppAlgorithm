#include <vector>
using namespace std;
namespace chapter2{
    vector<int> twoSum(vector<int> numbers, int target){
        int i =0;
        int j = numbers.size()-1;
        while(i < j && numbers[i] + numbers[j] != target){
            if(numbers[i] + numbers[j] < target) {
                i++;
            }
            else {
                j--;
            }
        }
        vector<int> result;
        result.push_back(i);
        result.push_back(j);
        return result;
    }
}