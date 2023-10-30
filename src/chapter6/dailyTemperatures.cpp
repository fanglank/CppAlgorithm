#include <vector>
#include <stack>

using namespace std;
vector<int> dailyTemperatures(vector<int> temperatures){
    vector<int> result;;
    stack<int> sta;
    for(int i =0;i<temperatures.size();i++){
        while (!sta.empty()&& temperatures[i] > temperatures[sta.top()])
        {
            int prev = sta.top();
            sta.pop();
            result.push_back(i - prev);
        }
        sta.push(i);
    }
    return result;
}