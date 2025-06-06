class Solution {
public:
    bool isPrime(int num) {
        if (num == 1) { // not a prime
            return false;
        }
        for (int div = 2; div * div <= num; div++) {
            if (num % div == 0) {
                return false;
            }
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for (int num = left; num <= right; num++) {
            if (isPrime(num) == true) {
                if (!primes.empty() && num - primes.back() <= 2) {
                    return {primes.back(), num}; // Early return
                }

                primes.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};