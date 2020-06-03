class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {int n=A.size();
       int max_sum=INT_MIN; //global maximum sum using comaprison
        int temp_max=0;    //temp maximum and if it is greater than global max than replace
        int array_sum=0;       //Total sum of array
        int min_sum=INT_MAX;  //global minimum sum 
        int temp_min=0;            //temp min and if it is less than min_sum then replace it with min_sum
        for(int i=0;i<n;i++){
            
            
            array_sum+=A[i];
            temp_max+=A[i];
            
          max_sum=max_sum<temp_max?temp_max:max_sum;
            temp_max=temp_max<0?0:temp_max;          //if 0 is greater than temp_max so temp_max=0
            
            temp_min+=A[i];
            min_sum=min_sum>temp_min?temp_min:min_sum;
            temp_min=temp_min>0?0:temp_min;                   //if temp_min>0 so replace it with 0
            
        }
         if(array_sum==min_sum)
        return max_sum; //if all elements of array is negative than arraysum=minsum
    return max(max_sum,(array_sum-min_sum));  //for the circular array find the max of maximum sum and the other sum of the array which can be greater than max_sum (array_sum-min_sum)
                                                
    }
};