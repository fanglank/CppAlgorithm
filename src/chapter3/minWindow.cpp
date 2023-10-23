#include <vector>
#include <map>
using namespace std;
string minWin(string s, string t)
{
    map<char, int> charToCount;
    for (char ch : t)
    {
        charToCount[ch] = charToCount[ch] + 1;
    }
    int count = charToCount.size();
    int start = 0, end = 0, minStart = 0, minEnd = 0;
    int minLength = INT_MAX;
    while (end < s.length() || count == 0 && end == s.length())
    {
        if (count > 0)
        {
            char endCh = s[end];
            if (charToCount.count(endCh) > 0)
            {
                charToCount[endCh] = charToCount[endCh] - 1;
                if (charToCount[endCh] == 0)
                {
                    count--;
                }
            }
            end++;
        }
        else
        {
            if (end - start < minLength)
            {
                minLength = end - start;
                minStart = start;
                minEnd = end;
            }

            char startCh = s[start];
            if (charToCount.count(startCh) > 0)
            {
                charToCount[startCh] = charToCount[startCh] + 1;
                if (charToCount[startCh] == 1)
                {
                    count++;
                }
            }
            start++;
        }
    }

    return minLength < INT_MAX ? s.substr(minStart, minEnd-minStart) : "";
}

string minWin1(string s, string t) {
    map<char, int> need, window;
    for(char c:t) {
        need[c]++;
    }

    int left =0 ,right =0,valid =0;
    int start =0, len = INT_MAX;
    while(right < s.size()) {
        char c = s[right];
        right++;
        if(need.count(c)) {
            window[c]++;
            if(window[c]==need[c]) {
                valid++;
            }
        }
        //当right指针移动到已经包含了need中所有的字符
        while(valid==need.size()) {
            if(right - left < len) {
                start = left;
                len = right -left;

            }

            char d = s[left];
            left++;
            if(need.count(d)){
                if(window[d] == need[d]){
                    valid--;
                }
                window[d]--;
            }
        }
    }
    return len ==INT_MAX?"":s.substr(start,len);
}