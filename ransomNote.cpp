// Very clever solution of the problem ransomNote, 0 ms runtime really amazing


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int lookUp[26];
        int mask = 0;

        memset(lookUp, 0, sizeof(lookUp) );

        for(int i = 0; i < ransomNote.size(); ++i)
        {
            int c = ransomNote[i] - 97;
            ++lookUp[c];
            mask |= 1 << c;
        }

        for(int i = 0; i < magazine.size(); ++i)
        {
            int c = magazine[i] - 97;
            --lookUp[c];

            if(lookUp[c] == 0)
            {
                mask &= ~(1 << c);
                if(mask == 0)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
