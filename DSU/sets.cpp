#include <bits/stdc++.h>

using namespace std;

class Dsu{
    int n;
    vector <int> parent;
    vector <int> rank;
    public:
    Dsu(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        make_set(n);
    }
    void make_set(int n)
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    
    int find(int x)
    {
        if(parent[x] != x)
        {
            return find(parent[x]);
        }
        return find(parent[x]);
    }
    
    void union(int a, int b)
    {
        int roota = find(a);
        int rootb = find(b);
        
        if(roota == rootb)
        return;
        
        if(rank[a] > rank[b])
        {
            parent[b] = a;
            rank[a]++;
        }
        else if(rank[b] > rank[a])
        {
            parent[a] = b;
            rank[b]++;
        }
        else
        {
            parent[b] = a;
            rank[a]++;
        }
    }
};

int findIslands(vector <vector <int>> arr);

int main()
{
    int m, n;
    cin >> m >> n;
    
    vector <vector <int>> arr(m, vector <int> (n));
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << findIslands(arr);
}

int findIslands(vector <vector <int>> arr)
{
    int m = arr.size();
    int n = arr[0].size();
    Dsu *temp = new Dsu(m * n);
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j])
            {
                    if(j - 1 >= 0 && arr[i][j - 1])
                    {
                        temp->union(i * n + j, i * n + j - 1);
                    }
                    if(j + 1 < n && arr[i][j + 1])
                    {
                        temp->union(i * n + j, i * n + j + 1)
                    }
                    if(i + 1 < m && j - 1 >= 0 && arr[i + 1][j - 1])
                    {
                        temp->union(i * n + j, (i + 1) * n + j - 1)
                    }
                    if(i + 1 < m && arr[i + 1][j])
                    {
                        temp->union(i * n + j, (i + 1) * n + j);
                    }
                    if(i + 1 < m && j + 1 < n && arr[i + 1][j + 1])
                    {
                        temp->union(i * n + j, (i + 1) * n + j + 1);
                    }
            }
        }
    }
    return 1;
}

