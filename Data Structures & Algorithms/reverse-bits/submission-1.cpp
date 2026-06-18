class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for(int i = 0; i < 32; i++) {
            uint32_t temp = n&1;

            result |= temp<<(31 - i);

            n = n>>1;
        }

        return result;
    }
};
