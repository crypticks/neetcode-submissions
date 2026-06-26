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
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1) return false;

        DSU dsu(n);
        for(auto edge : edges)
        {
            if(!dsu.unionNodes(edge[0], edge[1])) return false;
        }
        return dsu.components() == 1;

    }
};
