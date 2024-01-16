class RandomizedSet
{
public:
    unordered_map<int, int> indexMap;
    vector<int> nums;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (indexMap.find(val) != indexMap.end())
            return false;

        indexMap[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (indexMap.find(val) == indexMap.end())
            return false;

        int index = indexMap[val];
        indexMap[nums.back()] = index;
        swap(nums[index], nums[nums.size() - 1]);
        indexMap.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom()
    {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */