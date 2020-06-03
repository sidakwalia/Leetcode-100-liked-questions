//Leetcode problem 547 Friend circle using union find




class Solution {
public:
    vector<int> par;
    int findpar(int vtx){                 //Finding parent using union find
        if(par[vtx]==vtx)
            return vtx;
        
        else
            return par[vtx]=findpar(par[vtx]);
    }
    
    
    
    
    
    int findCircleNum(vector<vector<int>>& M) {
     int n=M.size();
        for(int i=0;i<n;i++){                  //Filling the vector with the number itself
            par.push_back(i);
    }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]!=0 && i!=j)                //i!=j because a friend will be a friend of himself
                {
                    int p1=findpar(i);                    //finding the same parent 
                    int p2=findpar(j);
                    if(p1!=p2){                                
                        par[p1]=p2;                          //changing the parent of p1
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(par[i]==i)                                        //if parent ==i that means those leaders will be universal friend and count++ is used to count those leaders
                ++count;
        }
        return count;
    }
};