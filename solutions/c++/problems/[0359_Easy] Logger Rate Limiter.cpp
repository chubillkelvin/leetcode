class Logger {
    unordered_map<string, int> lastPrinted;
public:
    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (lastPrinted.find(message) == lastPrinted.end() || timestamp - lastPrinted[message] >= 10) {
            lastPrinted[message] = timestamp;
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