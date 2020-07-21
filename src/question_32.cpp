#include <iostream>
#include <queue>
using namespace std;


/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr)
			return ans;
		queue<TreeNode *> treeQueue;
		treeQueue.push(root);
		while(!treeQueue.empty())
		{
			TreeNode* tmpNode = treeQueue.front();
			treeQueue.pop();
			ans.push_back(tmpNode->val);
			if (tmpNode->left != NULL)
				treeQueue.push(tmpNode->left);
			if (tmpNode->right != NULL)
				treeQueue.push(tmpNode->right);
		}
		return ans;
    }
};

int main()
{

}
