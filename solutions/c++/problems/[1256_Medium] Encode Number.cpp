class Solution {
public:
    string encode(int num) {
        int power = 0;
        int prev = 0;
        int curr = 0;
        while (curr < num) {
            prev = curr;
            curr += pow(2, ++power);
        }
        string bitString = bitset<64>(num - prev - 1).to_string();
        return bitString.substr(64 - power, power);
    }
};