class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int largest = 0;
        int index = 1;
        int wins = 0;
        while(wins != k || index != arr.size())
        {
            if(arr[largest] < arr[index]) 
            {
                largest = index;
                wins = 1;
            }
            else wins++;
            index++;
        }
        return arr[largest];
    }
};