
int countPalindrome(string s, int start, int end){
    int count =0;
    while(start >= 0 && end <s.length()&&s[start]==s[end]){
        count++;
        start--;
        end++;
    }
    return count;
}

int countSumstrings(string s) {
    if(s == "" || s.length()==0){
        return 0;
    }
    int count =0;
    for(int i=0;i<s.length();i++){
        count +=countPalindrome(s, i, i);
        count +=countPalindrome(s, i, i+1);
    }

    return count;
}