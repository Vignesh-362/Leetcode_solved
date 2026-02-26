class Solution {
public:
    int numSteps(string s) {
        int c = 0, flag = 0, idx;

        for (int j = 0; j < s.size(); j++)
            if (s[j] == '1') {
                idx = j;
                break;
            }
        for (int i = s.size() - 1; i > idx; i--) {
            if (s[i] == '0')
                c++;
            else if (s[i] == '1') {
                s[i - 1] = s[i - 1] + 1;
                c += 2;
            } else if (s[i] == '2') {
                c++;
                s[i - 1] = s[i - 1] + 1;
            }
        }
        if (s[idx] == '2')
            c++;
        return c;
    }
};