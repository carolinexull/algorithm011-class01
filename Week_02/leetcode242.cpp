class Solution {
public:
    bool isAnagram(string s, string t) {
        unsigned int hash[26];
        int i;

        for (i = 0; i < 26; i++)
            hash[i] = 0;

        if (s.length() != t.length())
            return false;

        for (i = 0; i < s.length(); i++)
        {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }

        for (i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
                return false;
        }

        return true;
    }
};