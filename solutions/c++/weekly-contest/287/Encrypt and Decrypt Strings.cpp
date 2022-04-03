#include <bits/stdc++.h>

using namespace std;

class Encrypter {
    unordered_map<char, string> keyMap;
    unordered_map<string, unordered_set<string>> decryptCount;
    unordered_map<string, string> encryptMap;
public:
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary) {
        int n = keys.size();
        for (int i = 0; i < n; i++) keyMap[keys[i]] = values[i];
        for (auto word: dictionary) {
            string temp;
            for (char c: word) temp += keyMap[c];
            encryptMap[word] = temp;
            decryptCount[temp].insert(word);
        }
    }

    string encrypt(string word1) {
        if (encryptMap.find(word1) != encryptMap.end()) return encryptMap[word1];
        string temp;
        for (char c: word1) temp += keyMap[c];
        return encryptMap[word1] = temp;
    }

    int decrypt(string word2) {
        return decryptCount[word2].size();
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */