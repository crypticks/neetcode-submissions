class DSU
{
  vector<int> parent, sizes;
  int comps;

  public:
  DSU(int n)
  {
    comps = n;
    parent.resize(n+1);
    sizes.resize(n+1);
    for(int i = 0; i<=n; i++)
    {
      parent[i] = i;
      sizes[i] = 1;
    }
  }

  int find(int n)
  {
    if(parent[n] != n)
    {
      parent[n] = find(parent[n]);
    }
    return parent[n];
  }

  bool unionNodes(int a, int b)
  {
    int fa = find(a), fb = find(b);
    if(fa == fb) return false;
    if(sizes[fa] < sizes[fb])
    {
      swap(fa, fb);
    }
    comps--;
    sizes[fa] += sizes[fb];
    parent[fb] = fa;
    return true;
  }

  int components()  { return comps; }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAcc;
        for(int i  = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                const string& email = accounts[i][j];
                if(emailToAcc.count(email))
                {
                    dsu.unionNodes(i, emailToAcc[email]);
                } else emailToAcc[email] = i;
            }
        }

        map<int, vector<string>> emailGroup;
        for(auto& [email, acc] : emailToAcc)
        {
            int leader = dsu.find(acc);
            emailGroup[leader].push_back(email);
        }

        vector<vector<string>> res;
        for(auto& [acc, emails] : emailGroup)
        {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[acc][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }
        return res;
    }
};