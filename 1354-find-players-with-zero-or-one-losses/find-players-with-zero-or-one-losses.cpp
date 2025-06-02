class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        unordered_set<int> players;

        for(auto match: matches){
            int win=match[0]; 
            int loss=match[1];

            losses[loss]++;

            players.insert(win);
            players.insert(loss);
        }

        vector<int> noloss, oneloss;

        for(auto player: players){
            if(losses[player]==0){
                noloss.push_back(player);
                
            }
            if(losses[player]==1){
                oneloss.push_back(player);
            }
        }
        sort(noloss.begin(), noloss.end());
        sort(oneloss.begin(), oneloss.end());

        vector<vector<int>> ans;
        ans.push_back(noloss);
        ans.push_back(oneloss);

        return ans;
    }
};