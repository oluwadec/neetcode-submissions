class Solution {
public:
    string minWindow(string s, string t) {
     if (s.length() < t.length()) return "";

        vector<int> t_freq(128, 0);
        int required = 0;

        for (char c : t) {
            if (t_freq[c] == 0) required++;
            t_freq[c]++;
        }

        vector<int> window_freq(128, 0);
        int matched = 0;
        int left = 0, start_idx = 0, min_len = INT_MAX;

        for (int right = 0; right < s.length(); right++) {
            char right_char = s[right];
            window_freq[right_char]++;

            if (t_freq[right_char] > 0 && window_freq[right_char] == t_freq[right_char]) {
                matched++;
            }

            while (matched == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                char left_char = s[left];
                window_freq[left_char]--;

                if (t_freq[left_char] > 0 && window_freq[left_char] < t_freq[left_char]) {
                    matched--;
                }

                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};