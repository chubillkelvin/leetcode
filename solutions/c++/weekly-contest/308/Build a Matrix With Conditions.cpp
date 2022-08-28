// TLE :(

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    vector<Node *> bottom;
    vector<Node *> right;
};

class Solution {
    vector<int> top;
    vector<int> side;
    unordered_map<Node *, bool> visitedBot;
    unordered_map<Node *, bool> visitedRight;
public:
    bool checkBot(Node *node, unordered_set<Node *> &visited, int score) {
        visitedBot[node] = true;
        if (top[node->val - 1] == -1 || top[node->val - 1] >= score) top[node->val - 1] = score - 1;
        for (auto child: node->bottom) {
            if (visited.count(child)) return true;
            visited.insert(child);
            if (checkBot(child, visited, top[node->val - 1])) return true;
            visited.erase(child);
        }
        return false;
    };

    bool checkRight(Node *node, unordered_set<Node *> &visited, int score) {
        visitedRight[node] = true;
        if (side[node->val - 1] == -1 || side[node->val - 1] >= score) side[node->val - 1] = score - 1;
        for (auto child: node->right) {
            if (visited.count(child)) return true;
            visited.insert(child);
            if (checkRight(child, visited, side[node->val - 1])) return true;
            visited.erase(child);
        }
        return false;
    };

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        int n = rowConditions.size();
        int m = colConditions.size();
        vector<Node *> nodes;
        for (int i = 0; i < k; i++) {
            auto node = new Node();
            node->val = i + 1;
            nodes.push_back(node);
        }
        for (int i = 0; i < n; i++) {
            auto r = rowConditions[i];
            int above = r[0] - 1;
            int below = r[1] - 1;
            nodes[above]->bottom.push_back(nodes[below]);
        }
        for (int i = 0; i < m; i++) {
            auto c = colConditions[i];
            int left = c[0] - 1;
            int right = c[1] - 1;
            nodes[left]->right.push_back(nodes[right]);
        }
        top = vector<int>(k, -1);
        for (int i = 0; i < k; i++) {
            auto curr = nodes[i];
            if (visitedBot[curr]) continue;
            unordered_set<Node *> check;
            if (checkBot(curr, check, k + 1)) return {};
        }
        side = vector<int>(k, -1);
        for (int i = 0; i < k; i++) {
            auto curr = nodes[i];
            if (visitedRight[curr]) continue;
            unordered_set<Node *> check;
            if (checkRight(curr, check, k + 1)) return {};
        }
        vector<pair<int, int>> pos(k, {-1, -1});
        vector<vector<int>> q1;
        for (int i = 0; i < k; i++) q1.push_back({top[i], i});
        std::sort(q1.begin(), q1.end(), [](auto &p1, auto &p2) {
            return p1[0] > p2[0];
        });
        for (int i = 0; i < k; i++) {
            auto curr = q1[i];
            pos[curr[1]].first = i;
        }
        vector<vector<int>> q2;
        for (int i = 0; i < k; i++) q2.push_back({side[i], i});
        std::sort(q2.begin(), q2.end(), [](auto &p1, auto &p2) {
            return p1[0] > p2[0];
        });
        for (int i = 0; i < k; i++) {
            auto curr = q2[i];
            pos[curr[1]].second = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            auto curr = pos[i];
            ans[curr.first][curr.second] = i + 1;
        }
        return ans;
    }
};
