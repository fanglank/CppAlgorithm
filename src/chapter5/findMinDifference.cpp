#include <vector>
#include <string>
#include <limits>
using namespace std;

int helper(vector<bool> minuteFlags) {
    int minDiff = minuteFlags.size() -1;
    int prev = -1;
    int first = minuteFlags.size() -1;
    int last = -1;
    for(int i =0;i<minuteFlags.size(); i++) {
        if(minuteFlags[i]) {
            if(prev >=0) {
                minDiff = min(i-prev,minDiff);
            }
            prev = i;
            first = min(i, first);
            last = max(i, last);
        }
    }
    minDiff = min(static_cast<int>(first + minuteFlags.size()-last),minDiff);
    return minDiff;
}

int findMinDifference(vector<string> timePoints){
    if(timePoints.size() > 1440){
        return 0;
    }

    vector<bool> minuteFlags(1440);
    // vector<string> v
    for(string time : timePoints) {
        size_t pos = time.find(":");
        int min = stoi(time.substr(0,pos))*60 + stoi(time.substr(pos+1, time.length()-pos));
        if(minuteFlags[min]) {return 0;}
        minuteFlags[min] = true;

    }
    return helper(minuteFlags);
}

