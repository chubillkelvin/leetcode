#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        string dir = "right";
        while (head) {
            matrix[i][j] = head->val;
            head = head->next;
            if (dir == "right") {
                if (j + 1 >= n || matrix[i][j + 1] != -1) {
                    dir = "down";
                    i++;
                } else {
                    j++;
                }
            } else if (dir == "down") {
                if (i + 1 >= m || matrix[i + 1][j] != -1) {
                    dir = "left";
                    j--;
                } else {
                    i++;
                }
            } else if (dir == "left") {
                if (j - 1 < 0 || matrix[i][j - 1] != -1) {
                    dir = "up";
                    i--;
                } else {
                    j--;
                }
            } else {
                if (i - 1 < 0 || matrix[i - 1][j] != -1) {
                    dir = "right";
                    j++;
                } else {
                    i--;
                }
            }
        }
        return matrix;
    }
};