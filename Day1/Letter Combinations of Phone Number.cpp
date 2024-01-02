// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

https://file+.vscode-resource.vscode-cdn.net/c%3A/Users/subra/Dropbox/My%20PC%20%28LAPTOP-778OGN6L%29/Desktop/6companies30days/Day1/1200px-telephone-keypad2svg.png?version%3D1704190884529

 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

class Solution {
public:
    void letter(int i, string &s, string &temp, vector<string> &ans, unordered_map<char, string> &m){
        if (i == s.size()){
            ans.push_back(temp);
            return;
        }
        string str = m[s[i]];
        for (int j = 0; j < str.size(); j++){
            temp.push_back(str[j]);
            letter(i + 1, s, temp, ans, m);    
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {} ;
        }
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> ans ;
        string temp ;
        letter(0 , digits , temp , ans , m) ;
        return ans;
    }
};