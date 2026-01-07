/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
long long total;       // Poore tree ka sum
    long long maxProd;     // Maximum product track karne ke liye
    const int MOD = 1e9 + 7;  // Modulo value
    
    /*
     * Helper Function 1: calculateSum
     * --------------------------------
     * Tree ka total sum calculate karta hai using DFS.
     * 
     * ⚠️ FIX: Yeh function PUBLIC function se PEHLE declare hona chahiye!
     * C++ mein function use karne se pehle declare hona zaruri hai.
     */
    long long calculateSum(TreeNode* node) {
        // BASE CASE: Agar node NULL hai, sum = 0
        if (node == nullptr) {
            return 0;
        }
        // RECURSIVE CASE: Current + Left subtree + Right subtree
        return node->val + calculateSum(node->left) + calculateSum(node->right);
    }
    
    /*
     * Helper Function 2: findMaxProduct
     * ----------------------------------
     * Har subtree ke liye product calculate karke maximum track karta hai.
     */
    long long findMaxProduct(TreeNode* node) {
        // BASE CASE: NULL node ka sum = 0
        if (node == nullptr) {
            return 0;
        }
        
        // Calculate left and right subtree sums
        long long leftSum = findMaxProduct(node->left);
        long long rightSum = findMaxProduct(node->right);
        
        // Current subtree ka sum
        long long subtreeSum = node->val + leftSum + rightSum;
        
        // Calculate PRODUCT: subtreeSum × (total - subtreeSum)
        long long product = subtreeSum * (total - subtreeSum);
        
        // Update maximum product
        maxProd = max(maxProd, product);
        
        // Return current subtree sum for parent
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        total = 0;
        maxProd = 0;
        
        // PASS 1: Calculate TOTAL SUM of entire tree
        total = calculateSum(root);
        
        // PASS 2: Find maximum product by trying each split
        findMaxProduct(root);
        
        // Return result with modulo
        return maxProd % MOD;
        
    }
};