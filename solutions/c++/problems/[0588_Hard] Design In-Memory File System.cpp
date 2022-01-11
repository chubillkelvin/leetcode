struct FileNode {
    string content;

    FileNode(string content) {
        this->content = content;
    }
};

struct DirNode {
    vector <string> ls;
    unordered_map<string, DirNode *> children;
    unordered_map<string, FileNode *> files;
};

class FileSystem {
    DirNode *root;
public:
    FileSystem() {
        root = new DirNode();
    }

    vector <string> ls(string path) {
        if (path == "/") {
            sort(root->ls.begin(), root->ls.end());
            return root->ls;
        }
        auto pair = getNodeAndEnd(path);
        auto node = pair.first;
        string end = pair.second;
        if (node->children[end]) {
            node = node->children[end];
            sort(node->ls.begin(), node->ls.end());
            return node->ls;
        } else {
            return vector < string > {end};
        }
    }

    void mkdir(string path) {
        auto curr = root;
        auto p = parsePath(path);
        while (!p.empty()) {
            string currPath = p.front();
            if (!curr->children[currPath]) {
                curr->children[currPath] = new DirNode();
                curr->ls.push_back(currPath);
            }
            curr = curr->children[currPath];
            p.pop_front();
        }
    }

    void addContentToFile(string filePath, string content) {
        auto p = parsePath(filePath);
        string end = p.back();
        p.pop_back();
        string dirPath = getFullPath(p);
        mkdir(dirPath);
        auto node = getNode(dirPath);
        if (node->files[end]) {
            node->files[end]->content += content;
        } else {
            node->ls.push_back(end);
            node->files[end] = new FileNode(content);
        }
    }

    string readContentFromFile(string filePath) {
        auto pair = getNodeAndEnd(filePath);
        auto node = pair.first;
        string end = pair.second;
        return node->files[end]->content;
    }

    list <string> parsePath(string path) {
        int n = path.size();
        list <string> p;
        if (n == 1) return p;
        string temp = "";
        for (int i = 0; i < n; i++) {
            char c = path[i];
            if (c == '/') {
                if (!temp.empty()) p.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) p.push_back(temp);
        return p;
    }

    string getFullPath(list <string> p) {
        string fullPath = "/";
        while (!p.empty()) {
            fullPath += p.front();
            p.pop_front();
            if (!p.empty()) fullPath += '/';
        }
        return fullPath;
    }

    DirNode *getNode(string path) {
        auto p = parsePath(path);
        auto curr = root;
        while (!p.empty()) {
            string currPath = p.front();
            curr = curr->children[currPath];
            p.pop_front();
        }
        return curr;
    }

    pair<DirNode *, string> getNodeAndEnd(string path) {
        auto p = parsePath(path);
        string end = p.back();
        p.pop_back();
        string dirPath = getFullPath(p);
        auto node = getNode(dirPath);
        return make_pair(node, end);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */