class Solution {
public:
    vector<int> leftmax(vector<int> &height, int n){
        vector<int>leftmax(n);
        leftmax[0]=height[0];
        for(int i=1; i<n ;i++){
            leftmax[i]=max(height[i], leftmax[i-1]);
        }
        
        return leftmax;
    }

    vector<int> rightmax(vector<int> &height, int n){
        vector<int>rightmax(n);
        rightmax[n-1]=height[n-1];
        for(int i=n-2; i>=0 ;i--){
            rightmax[i]=max(height[i], rightmax[i+1]);
        }
        
        return rightmax;
    }
    
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left= leftmax(height, n);
        vector<int>right= rightmax(height, n);
        int sum=0;
        for(int i=0; i< n;i++){

            int water=min(left[i], right[i]) - height[i];

            sum+= water;
        }
        return sum;
    }
};