class Solution {
public:
    string reverseVowels(string s) {
        const char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        vector<int> vowelIndices;

        for(int i = 0; i < s.length(); i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(s[i] == vowels[j]) vowelIndices.push_back(i);
            }
        }

        int i = 0;
        int j = vowelIndices.size() - 1;
        while(i < j)
        {
            char temp = s[vowelIndices[i]];
            s[vowelIndices[i]] = s[vowelIndices[j]];
            s[vowelIndices[j]] = temp;

            i++;
            j--;
        }

        return s;
    }
};