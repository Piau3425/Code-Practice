class Solution {
public:
    string reverseWords(string s) {
        int ldx = 0, rdx = 0;
        for (; rdx < s.size(); rdx++) {
            if (s[rdx] != ' ') {
                if (ldx != 0) s[ldx++] = ' ';
                while (rdx < s.size() && s[rdx] != ' ') s[ldx++] = s[rdx++];
            }
        }
        s.resize(ldx);
        reverse(s.begin(), s.end());

        for (int i = 0, st = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s.begin()+st, s.begin()+i);
                st = i+1;
            }
        }
        return s;
    }
};