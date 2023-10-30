class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // rnd gives 4 digit precision to avoid precision errors within the ceil call
        double rnd = round((log(buckets) / log((minutesToTest/minutesToDie) + 1)) * 1000);
        return (int) ceil(rnd / 1000);
    }
};