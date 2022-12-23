#include <bits/stdc++.h>
#include <utility>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  long long int dest;
  long long int edgeNum;
  cin >> dest;
  cin >> edgeNum;
  long long int S = 1;
  typedef pair<int, int> pi;
  vector<pi> adjList[dest+1]; // pair.first is the node, pair.second is the edge weight
  int dist[dest+1];
  priority_queue<pi, vector<pi>, greater<pi> > q;
  long long int hold1;
  long long int hold2;
  long long int hold3;
  for (int q = 0; q < edgeNum; q++) {
    cin >> hold1 >> hold2 >> hold3;
    adjList[hold1].push_back(make_pair(hold2, hold3));
    adjList[hold2].push_back(make_pair(hold1, hold3));
  }
  /*for (int q = 0; q < dest+1; q++) {
    dist[q] = INT_MAX;
  }*/
  memset(dist, -1, sizeof(dist));
  dist[S] = 0;
  q.push(make_pair(0, S));
  while (!q.empty()) {
    pi cur = q.top();
    q.pop();
    int x = cur.second, d = cur.first;
    if (d > dist[x]) continue;
    for (vector<pi>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
        int nx = it->first, nd = max(d,it->second);
        if (dist[nx] != -1 && dist[nx] <= nd) continue;
        dist[nx] = nd;
        q.push(make_pair(nd, nx));
    }
  }
  cout << dist[dest];
}