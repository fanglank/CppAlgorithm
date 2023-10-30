#include <unordered_map>
#include <vector>
#include <random>
using namespace std;
class RandomizedSet
{
private:
    unordered_map<int, int> numToLocation;
    vector<int> nums;
public:
    RandomizedSet(/* args */);
    bool insert(int val);
    bool remove(int val);
    int getRandom();
    ~RandomizedSet();
};

RandomizedSet::RandomizedSet(/* args */)
{

}
bool RandomizedSet::insert(int val){
    if(numToLocation.count(val) > 0){
        return false;
    }
    std::pair<int, int> mpair(val, nums.size());
    numToLocation.insert(mpair);
    nums.push_back(val);
    return true;
}

bool RandomizedSet::remove(int val){
    if(!numToLocation.count(val) > 0){
        return false;
    }
    int location = numToLocation[val];

    std::pair<int, int> mpair(nums[nums.size() -1], location);
    numToLocation.insert(mpair);
    numToLocation.erase(val);
    nums[location] = nums[nums.size() -1];
    nums.erase(nums.begin() + location -1);
    return true;
}
int RandomizedSet::getRandom() {
    default_random_engine e;
    uniform_int_distribution<unsigned> r(0,nums.size());
    return nums[r(e)];
    
}

RandomizedSet::~RandomizedSet()
{
}
