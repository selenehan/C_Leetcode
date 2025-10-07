/**

Longest Substring Without Repeating Characters:
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/


int lengthOfLongestSubstring(char* s) {
    if (s == NULL) return 0;

    int last[256];
    for (int i = 0; i < 256; i++) last[i] = -1;

    int left = 0;
    int best = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = (unsigned char)s[right];
        
        if (last[c] >= left) {
            left = last[c] + 1;
        }

        last[c] = right;

        int currLen = right - left + 1;
        if (currLen > best) best = currLen;
    }

    return best;
}

/**

make array last[256] and fill with -1
left = 0
best = 0

for right from 0 to end of string:
    c = s[right]
    if last[c] >= left:
        left = last[c] + 1 
    last[c] = right
    best = max(best, right - left + 1)

return best

*/
