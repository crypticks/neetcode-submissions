class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(find(nums.begin(), nums.end(), 1) != nums.end()) return false;

        int max = *max_element(nums.begin(), nums.end());
        vector<int> sieve(max+1, 0);
        int p = 2;
        while(p*p < max)
        {
            if(sieve[p] == 0)
            {
                for(int comp = p * p; comp <= max; comp+=p)
                {
                    sieve[comp] = p;
                }
            }
            p++;
        }

        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if(sieve[num] == 0)
            {
                adj[i].push_back(n + num);
                adj[n + num].push_back(i);
                continue;
            }

            while(num > 1)
            {
                int prime = (sieve[num] != 0) ? sieve[num] : num;
                adj[i].push_back(n + prime);
                adj[n+prime].push_back(i);
                while(num%prime == 0) num/=prime;
            }
        }


        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int& nei : adj[node]) {
                if (visited.find(nei) == visited.end()) {
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                return false;
            }
        }
        return true;
    }
};