#include <vector>
#include <algorithm>
using namespace std;

bool hasGreaterThan1(vector<int> counts){
    for(int count: counts){
        if(count >1) {
            return true;
        }
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    if(s.length() == 0) {
        return 0;
    }
    vector<int> counts(256,0);
    int i =0;
    int j =-1;
    int longest =1;
    for(;i<s.length();i++){
        counts[s[i]]++;
        while(hasGreaterThan1(counts)){
            j++;
            counts[s[j]]--;
        }
        longest = max(i-j, longest);
    }

    return longest;
}

int lengthOfLongestSubstring1(string s) {
    if(s.length() == 0) {
        return 0;
    }
    vector<int> counts(256,0);
    int i =0;
    int j =-1;
    int longest =1;
    int countDup = 0;
    for(;i<s.length();i++){
        counts[s[i]]++;
        if(counts[s[i]]==2){
            countDup++;
        }
        while(countDup > 0){
            ++j;
            counts[s[j]]--;
            if(counts[s[j]] ==1){
                countDup--;
            }
        }
        longest = max(i-j,longest);
    }
    return longest;
}
