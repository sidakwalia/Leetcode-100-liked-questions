auto speedUp=[](){
    std::ios::sync_with_stdio(nullptr);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();





class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int a=target-nums[i];
            if(m.count(a)){
                return {m[a],i};
            }
            else{
                m[nums[i]]=i;
            }
        }
        return {};
    }
};