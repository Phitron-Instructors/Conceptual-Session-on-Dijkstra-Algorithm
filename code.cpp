#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
vector<int> vis(N, 0);
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    vis[src] = true;
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        for (auto i : g[u])
        {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    int V = 9;
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    dijkstra(1);
    // printf("Vertex   Distance from Source\n");
    for (int i = 1; i <= v; ++i)
        cout << dist[i] << " ";
    return 0;
}
