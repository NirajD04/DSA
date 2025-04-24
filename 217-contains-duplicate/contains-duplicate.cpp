// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         set<int> s(nums.begin(),nums.end());
//         int x=nums.size();
//         int y=s.size();
//         if(x==y){
//             return false;
//         }
//         else{
//             return true;
//         }
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     
     std:: sort(nums.begin(), nums.end());
     
     for(int i=1;i<nums.size();i++){

        
        if(nums[i]==nums[i-1]){
        
        return true;
    }
    }
    
     return false;
    
    }
    
    };
