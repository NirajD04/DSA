class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int n=t.size();

        vector<int> days(n,0);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && t[st.top()]<=t[i]){
                st.pop();

            }
            if(!st.empty()){
                days[i]=st.top()-i;
            }
            else days[i]=0;

            st.push(i);
        }
        return days;
    }
};