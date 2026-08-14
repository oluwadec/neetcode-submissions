#include <string> // Gives us std::string (text datatype)
#include <unordered_map> // Gives us std::unordered_map (Hash Map)

class Solution {
public: // Makes this function accessible to Leetcode's test runner

bool isAnagram(std::string& s, std::string& t) {
    if (s.length() != t.length()) {
        return false; // stop right here and return false
    }
    std::unordered_map<char, int> count;
    for (char c : s) {

        count[c]++;
    }
    for (char c : t) {

        count[c]--;
        if (count[c] < 0) {
            return false;
        }
    }
    return true;
}


};