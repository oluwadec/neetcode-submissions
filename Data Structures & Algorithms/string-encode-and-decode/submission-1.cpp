class Solution {
public:
    // Encodes a list of strings to a single string.
    std::string encode(const std::vector<std::string>& strs) {
        std::string encoded = "";
        for (const std::string& s : strs) {
            encoded += std::to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> result;
        int i = 0;
        int n = s.length();

        while (i < n) {
            // Find the delimiter '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Parse the length of the next string
            int len = std::stoi(s.substr(i, j - i));
            
            // Extract the string of length `len` after '#'
            i = j + 1; // Move past '#'
            result.push_back(s.substr(i, len));

            // Move pointer past the extracted string
            i += len;
        }

        return result;
    }
};