class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mm;
        int bulls = 0;
        int cows = 0;

        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] == guess[i])
            {
                bulls++;
                mm[secret[i]]--;
            }
            mm[secret[i]]++;
        }

        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] != guess[i])
            {
                if(mm[guess[i]] > 0)
                {
                    cows++;
                    mm[guess[i]]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};