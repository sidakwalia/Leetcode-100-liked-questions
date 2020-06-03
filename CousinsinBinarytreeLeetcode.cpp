auto speedUp=[](){                                        
    std::ios::sync_with_stdio(nullptr);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int heightfunc(TreeNode* root,int &parent,int value,int height){
        if(!root)
            return 0;
        if(root->val==value)
            return height;
        parent=root->val;
        int left=heightfunc(root->left,parent,value,height+1);                       //recursive call on left node of the tree
        if(left!=0)
            return left;
        
         parent=root->val;
        int right=heightfunc(root->right,parent,value,height+1);
        
            return right;
        
        
        
        
    }
    
    
    
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root==NULL)                
            return false;
        
        if(root->val==x||root->val==y)                            
            return false;
        
        int parent=-1;
        int xheight=heightfunc(root,parent,x,0);
        
         int yparent=-1;
        int yheight=heightfunc(root,yparent,y,0);
        
        if(parent!=yparent && xheight==yheight)              //for that node to be cousis there parent should be differrent and their height should be same
            return true;
        return false;
    }
};