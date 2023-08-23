#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
const int N = 1e3 + 7;
const int M = 1e9 + 7;
const int INF = numeric_limits<int>::max();

struct Edge
{
    int target, weight;
};

bool hasNegativeCycle = 0;
vector<int> bell_dist(N, INF), dij_dist(N, INF);
// vector<vector<int>> init_dist(N, vector<int> (N, INF));
vector<vector<int>> short_dist(N, vector<int>(N, INF));
// vector<vector<int>> dij_dist(N, vector<int> (N, INF));

void bellmanFord(vector<vector<Edge>> &graph, int numVertices, int source)
{
    vector<int> parent(numVertices + 1, -1);

    bell_dist[source] = 0;

    for (int i = 0; i <= numVertices - 1; ++i)
    {
        for (int u = 0; u <= numVertices; u++)
        {
            for (const Edge &edge : graph[u])
            {
                if (bell_dist[u] != INF && bell_dist[u] + edge.weight < bell_dist[edge.target])
                {
                    bell_dist[edge.target] = bell_dist[u] + edge.weight;
                    parent[edge.target] = u;
                }
            }
        }
    }

    for (int u = 0; u <= numVertices; u++)
    {
        for (const Edge &edge : graph[u])
        {
            if (bell_dist[u] != INF && bell_dist[u] + edge.weight < bell_dist[edge.target])
            {
                hasNegativeCycle = true;
                break;
            }
        }
    }
}

void dijkstra(vector<vector<Edge>> &graph, int numVertices, int source)
{
    vector<int> parent(numVertices + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));
    dij_dist[source] = 0;

    while (!pq.empty())
    {
        int curdij_dist = pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();

        if (curdij_dist > dij_dist[curVertex])
        {
            continue; // Skip outdated entries in the priority queue
        }

        for (const Edge &edge : graph[curVertex])
        {
            int newdij_dist = curdij_dist + edge.weight;
            if (newdij_dist < dij_dist[edge.target])
            {
                dij_dist[edge.target] = newdij_dist;
                parent[edge.target] = curVertex;
                pq.push(make_pair(newdij_dist, edge.target));
            }
        }
    }
}

void johnson(vector<vector<Edge>> &graph, int numVertices)
{
    bellmanFord(graph, numVertices, numVertices);
    if (hasNegativeCycle)
    {
        cout << -1 << "\n";
        return;
    }
    for (int u = 0; u < numVertices; u++)
    {
        for (Edge &edge : graph[u])
        {
            edge.weight = edge.weight + bell_dist[u] - bell_dist[edge.target];
        }
    }
    for (int u = 0; u < numVertices; u++)
    {
        dijkstra(graph, numVertices, u);
        for (int v = 0; v < numVertices; v++)
        {
            short_dist[u][v] = dij_dist[v];
        }
        dij_dist.assign(numVertices, INF);
    }
    for (int u = 0; u < numVertices; u++)
    {
        short_dist[u][u] = 0;
        for (Edge &edge : graph[u])
        {
            short_dist[u][edge.target] = short_dist[u][edge.target] + bell_dist[edge.target] - bell_dist[u];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        int numVertices, numEdges;
        cin >> numVertices >> numEdges;

        vector<vector<Edge>> graph(numVertices + 1);
        for (int i = 0; i < numEdges; ++i)
        {
            int source, target, weight;
            cin >> source >> target >> weight;
            graph[source].push_back({target, weight});
        }
        for (int i = 0; i < numVertices; i++)
        {
            graph[numVertices].push_back({i, 0});
        }
        johnson(graph, numVertices);
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << i << " " << j << " " << short_dist[i][j] << "\n";
            }
        }
    }
    return 0;
}
