#include <vector>
using namespace std;
bool isPalindrome(string s) {
    int i =0;
    int j =s.length()-1;
    while(i < j){
        char ch1 = s[i];
        char ch2 = s[j];

        if(ch1!=ch2){
            return false;
        }

        i++;
        j--;
    }

    return true;

}