class Solution {
    unordered_map<int, int> occupied;
public:
    int nextUnoccupied(int key) {
        while (key > 0) {
            if (occupied[--key] == 0) return key;
        }
        return 0;
    }

    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c: s) freq[c - 'a']++;
        for (int i = 0; i < 26; i++) occupied[freq[i]]++;
        int count = 0;
        for (int i = 0; i < 26; i++) {
            int curr = freq[i];
            if (curr != 0 && occupied[curr] > 1) {
                int next = nextUnoccupied(curr);
                occupied[curr]--;
                occupied[next]++;
                count += curr - next;
            }
        }
        return count;
    }
};