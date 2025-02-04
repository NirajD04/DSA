class Solution {
public:

    int BS(vector<int>&arr1 , int first , int last , int target){
        int mid ;
        while(first <= last)
    {
         mid = (first+last)/2;
        if (arr1[mid] == target)
            return mid;
        else if (target > arr1[mid])
            first= mid+1 ;
        else
          last = mid-1 ; 
    }
    return -1 ;
    }
    int pivot(vector<int>&arr){
        int s = 0 , e = arr.size()-1 ;
        while(s<e){
           int mid = (s+e)/2 ;
            if(arr[mid]<arr[s] && arr[mid]<arr[e] && (e-s==2 || e==s))
                return mid;
            else if(e-s==1 && arr[e]<arr[s])return e;
            else if(arr[mid]>arr[s])s=mid;
            else
            e=mid;
           
        }
        return -1 ;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size() ;
        if(n==1) return nums[0]==target;
        vector<int> arr ;
        for(int i=0;i<n;i++){
            if(i==0 and nums[i]!=nums[n-1] ||i==0 and n==2 || i>0 and nums[i]!=nums[i-1])
                arr.push_back(nums[i]);
        }

        for(auto it : arr)
            cout<<it<<" ";
        
        int Pivot = pivot(arr) ;
        cout<<Pivot;
        if(Pivot==-1){
            if(BS(arr,0,arr.size()-1,target)==-1) return false ;
            return true ;
        }
        int right = BS(arr , Pivot ,arr.size()-1  , target) ;
        int left =  BS(arr , 0 , Pivot-1 , target ) ;
        if(right==-1 and left==-1)return false;
        return true ;
    }
};