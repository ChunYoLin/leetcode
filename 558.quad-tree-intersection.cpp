/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
    public:
        Node* intersect(Node* quadTree1, Node* quadTree2)
        {
            if (quadTree1->isLeaf && quadTree2->isLeaf)
                return new Node(quadTree1->val | quadTree2->val, true, NULL, NULL, NULL, NULL);
            else if (quadTree1->isLeaf && !quadTree2->isLeaf)
            {
                Node* topLeft = new Node(quadTree1->val, true, NULL, NULL, NULL, NULL);
                Node* topRight = new Node(quadTree1->val, true, NULL, NULL, NULL, NULL);
                Node* bottomLeft = new Node(quadTree1->val, true, NULL, NULL, NULL, NULL);
                Node* bottomRight = new Node(quadTree1->val, true, NULL, NULL, NULL, NULL);
                topLeft = intersect(topLeft, quadTree2->topLeft);
                topRight = intersect(topRight, quadTree2->topRight);
                bottomLeft = intersect(bottomLeft, quadTree2->bottomLeft);
                bottomRight = intersect(bottomRight, quadTree2->bottomRight);
                if (topLeft->val == true && topRight->val == true && bottomLeft->val == true && bottomRight->val == true)
                    return new Node(true, true, NULL, NULL, NULL, NULL);
                else
                    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
            }
            else if (quadTree2->isLeaf && !quadTree1->isLeaf)
            {
                Node* topLeft = new Node(quadTree2->val, true, NULL, NULL, NULL, NULL);
                Node* topRight = new Node(quadTree2->val, true, NULL, NULL, NULL, NULL);
                Node* bottomLeft = new Node(quadTree2->val, true, NULL, NULL, NULL, NULL);
                Node* bottomRight = new Node(quadTree2->val, true, NULL, NULL, NULL, NULL);
                topLeft = intersect(topLeft, quadTree1->topLeft);
                topRight = intersect(topRight, quadTree1->topRight);
                bottomLeft = intersect(bottomLeft, quadTree1->bottomLeft);
                bottomRight = intersect(bottomRight, quadTree1->bottomRight);
                if (topLeft->val == true && topRight->val == true && bottomLeft->val == true && bottomRight->val == true)
                    return new Node(true, true, NULL, NULL, NULL, NULL);
                else
                    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
            }
            else
            {
                Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
                Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
                Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
                Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
                if (topLeft->val == true && topRight->val == true && bottomLeft->val == true && bottomRight->val == true)
                    return new Node(true, true, NULL, NULL, NULL, NULL);
                else
                    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
            }
        }
};
