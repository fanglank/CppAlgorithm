
bool isPalindrome(string s, int start, int end) {
    while(start < end){
        if(s[start] !=s[end]){
            break;
        }

        start ++;
        end --;
    }

    return start >=end;
}
bool validPalindrome(string s) {
    int start = 0;
    int end = s.length() -1;
    for(;start < s.length()/2;++start, --end){
        if(s[start] != s[end]) {
            break;
        }
    }
    return  start == s.length()/2||isPalindrome(s, start, end -1) || isPalindrome(s, start +1,end);
}