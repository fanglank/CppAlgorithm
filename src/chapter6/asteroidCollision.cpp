#include <vector>
#include <stack>
#include <iostream>
using namespace std;
vector<int> asteroidCollision(vector<int> asteroids)
{
    stack<int> sta;
    for (int as : asteroids)
    {
        while (!sta.empty() && sta.top() > 0 && sta.top() < -as)
        {
            sta.pop();
        }
        if (!sta.empty() && as < 0 && sta.top() == -as)
        {
            sta.pop();
        }
        else if (as > 0 || sta.empty() || sta.top() < 0)
        {
            sta.push(as);
        }
    }
    int *end = &sta.top() + 1;
    int *begin = end - sta.size();
    vector<int> result(begin, end);
    return result;
}