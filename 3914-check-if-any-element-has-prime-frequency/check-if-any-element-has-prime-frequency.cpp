class Solution {
public:
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;

        }
        for(auto [key, value]: mp){
            if(isPrime(value)){
                return true;
            }
        }
        return false;
    }
};