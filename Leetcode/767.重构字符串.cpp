/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */
// #include <bits\stdc++.h>
// using namespace std;
// // @lc code=start
// class Solution {
// public:
//     string reorganizeString(string S) {
//         int maxcount=0;
//         string maxcountch;
//         string res;
//         vector<int> num(26);
//         for (char &ch : S)
//         {//对每个字符计数 并累计出现次数最多的字符
//             num[ch - 'a']++;
//             if (num[ch - 'a']>maxcount){
//                 maxcount=num[ch - 'a'];
//                 maxcountch=ch;
//             }
//         }
//         if(maxcount-1<=S.size()-maxcount)
//         {//当能够重构字符串时，构造重构字符串
//             res.append(maxcountch);
//             while (maxcount)
//             {
                


//             }
            
//         }
//         else res="";
//         return res;
//     }
// };

class Solution {
public:
    string reorganizeString(string S) {
        if (S.length() < 2) {
            return S;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        string reorganizeArray(length, ' ');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
                reorganizeArray[oddIndex] = c;
                counts[i]--;
                oddIndex += 2;
            }
            while (counts[i] > 0) {
                reorganizeArray[evenIndex] = c;
                counts[i]--;
                evenIndex += 2;
            }
        }
        return reorganizeArray;
    }
};

// @lc code=end

