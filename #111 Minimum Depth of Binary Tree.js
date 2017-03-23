/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
  if(root===null)return 0
  return (root.left&&root.right)?
    1 + Math.min(minDepth(root.left),minDepth(root.right)):
    1 + Math.max(minDepth(root.left),minDepth(root.right))
};