class Solution {
public:
    int strStr(string haystack, string needle) {
       if(haystack == " " || needle == " " || needle.length() > haystack.length()) return -1;
        int len = haystack.length(), i = 0, j = 0, pos = 0;
        while(i < len && j < needle.length()) {
            if(haystack[i++] == needle[j]) {
                j++;
            } else {
                i = i - j;
                j = 0;
                pos = i;
            }
        }
        return j == needle.length()? pos : -1;
    } 
    
};