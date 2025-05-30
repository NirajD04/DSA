class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t lastbit = n & 1; // check last bit is one or not;

            uint32_t reverse_lastbit =
                lastbit << (31 - i); // reverse hogi last bit; 001 -> 100;

            result = result | reverse_lastbit; // store in reuslt;

            n = n >> 1; // 10011- ---> 00110
        }
        return result;
    }
};