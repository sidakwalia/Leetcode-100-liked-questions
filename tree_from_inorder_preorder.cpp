// Construct Binary Tree from Preorder and Inorder Traversal
//########################################################=======Leetcode 105


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode helper(int[] preorder,int psi,int pei,int[] inorder,int isi,int iei){
        
        if(psi>pei || isi>iei)
            return null;
        TreeNode node=new TreeNode(preorder[psi]);
       int idx=isi;
        while(inorder[idx]!=preorder[psi]){
            idx++;
        }
                    

        int lpsi=psi+1;    //lpsi=left preorder starting index
      
        int lisi=isi;       //lisi=left inorder staarting index
        int liei=idx-1;      //liei=left inorder ending index
       
        int rpei=pei;        //rpei=right preorder ending index
        int risi=idx+1;         //risi=right inorder starting index
        int riei=iei;               //riei=right inorder ending index
          int lpei=lpsi+liei-lisi;     //left preorder ending index
         int rpsi=lpei+1;            //right preorder starting index
        
        node.left=helper(preorder,lpsi,lpei,inorder,lisi,liei);
            node.right=helper(preorder,rpsi,rpei,inorder,risi,riei);
            
            return node;
        
    }

    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
    }
}