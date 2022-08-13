class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        constexpr long q = 1000033;
        constexpr long p = 103;
        constexpr long char_map[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        
        int s_size = s.size();
        int word_size = words[0].size();
        int word_num = words.size();
        
        if (s_size < word_size)
            return {};
        
        long total_words_hash1 = 0;
        long total_words_hash2 = 0;
        
        for (auto &w: words) {
            long h = 0;
            for (auto c : w) {
                h = (h * p + char_map[c - 'a']) % q;
            }
            total_words_hash1 = (total_words_hash1 + h) % q;
            total_words_hash2 ^= h;
        }
        
        int it;
        int match_length = word_size * word_num;
        long h = 0, pow_p = 1;
        
        vector<int> ans{};
        vector<long> s_hashs1(word_size, 0);
        vector<long> s_hashs2(word_size, 0);
        
        for (it = 0; it < word_size; it++) {
            h = (h * p + char_map[s[it] - 'a']) % q;
            pow_p = (pow_p * p) % q;
        }
        
        s_hashs1.push_back(h);
        s_hashs2.push_back(h);
        
        for(; it < s_size; it++) {
            auto new_c = char_map[s[it] - 'a'];
            auto old_c = char_map[s[it - word_size] - 'a'];
            
            h = ((h * p - pow_p * old_c + new_c) % q + q) %q;
            s_hashs1.push_back(h + s_hashs1[(it + 1) - word_size]);
            s_hashs2.push_back(h ^ s_hashs2[(it + 1) - word_size]);
        }
        
        int hashs_size = s_hashs1.size();
        for (it = match_length; it < hashs_size; it++) {
            long val1 = ((s_hashs1[it] - s_hashs1[it - match_length]) % q + q) %q;
            long val2 = s_hashs2[it] ^ s_hashs2[it - match_length];
            
            if (val1 == total_words_hash1 && val2 == total_words_hash2) {
                ans.push_back(it - match_length);
            }
        }
        
        return ans;
    }
};