/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode *addPoly(PolyNode *poly1, PolyNode *poly2) {
        unordered_map<int, int> poly;
        unordered_set<int> p;
        while (poly1) {
            poly[poly1->power] += poly1->coefficient;
            p.insert(poly1->power);
            poly1 = poly1->next;
        }
        while (poly2) {
            poly[poly2->power] += poly2->coefficient;
            p.insert(poly2->power);
            poly2 = poly2->next;
        }
        vector<int> powers(p.begin(), p.end());
        sort(powers.begin(), powers.end(), [](auto &p1, auto &p2) {
            return p2 < p1;
        });
        auto pointerToHead = new PolyNode();
        auto curr = pointerToHead;
        for (int power: powers) {
            if (poly[power] == 0) continue;
            auto newNode = new PolyNode(poly[power], power);
            curr->next = newNode;
            curr = curr->next;
        }
        return pointerToHead->next;
    }
};