#include <bits/stdc++.h>

using namespace std;

class Logger {
private:
    map<string, int> messageMap = {};

public:
    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        auto prevTime = messageMap.find(message);
        if (prevTime == messageMap.end() || timestamp - prevTime->second >= 10) {
            messageMap[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */