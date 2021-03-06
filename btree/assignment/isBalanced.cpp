/*
is Balanced
Send Feedback
Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

#include "../BinaryTreeNode.h"
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class pair1{
  public:
    bool balanced;
    int height;
};

pair1 isBalanced1(BinaryTreeNode<int> *root){
    if(root == NULL){
        pair1 p;
        p.height = 0;
        p.balanced = true;
        return p;
    }
    pair1 lpair = isBalanced1(root->left);
    pair1 rpair = isBalanced1(root->right);
    pair1 ans;
    ans.height = max(lpair.height,rpair.height) + 1;
    ans.balanced = lpair.balanced && rpair.balanced;
    if(ans.balanced){
        if(abs(lpair.height - rpair.height) > 1){
            ans.balanced = false;
        }
    }
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBalanced1(root).balanced;
}



BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}
