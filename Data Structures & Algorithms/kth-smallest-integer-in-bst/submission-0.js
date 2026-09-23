/**
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    /**
     * @param {TreeNode} root
     * @param {number} k
     * @return {number}
     */
    kthSmallest(root, k) {
        const stack = [];
        let cur = root;

        while (cur || stack.length > 0) {
            while (cur) {
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();

            if (--k === 0) return cur.val;

            cur = cur.right;
        }
        return -1; // unreachable if 1 <= k <= n
    }
}