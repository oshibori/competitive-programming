#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main() {
  int N, K;
  vector<int> g[100000];
  int v[100000];
  fill_n(v, 100000, INF);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> K;
  priority_queue<pair<int, int>> que;
  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    que.emplace(b, a);
    v[a] = b;
  }
  while (!que.empty()) {
    auto p = que.top();
    cerr << "debug: " << p.first << " " << p.second << endl;
    que.pop();
    for (auto &to : g[p.second]) {
      if (v[to] != INF) {
        if (abs(v[to] - v[p.second]) != 1) {
          cout << "No" << endl;
          return (0);
        }
      } else {
        v[to] = v[p.second] - 1;
        que.emplace(v[to], to);
      }
    }
  }

  cout << "Yes" << endl;
  for (int i = 0; i < N; i++)
    cout << v[i] << endl;
}
