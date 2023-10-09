class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1)
        {
            return n == 0 || abs(n - flowerbed[0]) == 1;
        }

        int flowersLeft = n;
        if(flowerbed[0] == 0 && flowerbed[1] == 0 && flowersLeft > 0)
        {
            flowerbed[0] = 1;
            flowersLeft--;
        }

        if(flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0 && flowersLeft > 0)
        {
            flowerbed[flowerbed.size() - 1] = 1;
            flowersLeft--;
        }

        if (flowersLeft <= 0) return true;

        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if(flowerbed[i-1] == flowerbed[i] && flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0)
            {
                flowersLeft--;
                flowerbed[i] = 1;
            }
        }

        return flowersLeft <= 0;
    }
};