#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_NODE = 10000;

vector<int> graph[MAX_NODE + 1];

void createGraph(int maxDepth) {
    for (int i = 1; i <= MAX_NODE; ++i) {
        for (int depth = 1; depth <= maxDepth; ++depth) {
            int nextNode = i + depth;
            if (nextNode <= MAX_NODE) {
                graph[i].push_back(nextNode);
                graph[nextNode].push_back(i);
            }
        }
    }
}

int findMinKimbab(int start, int end) {
    vector<int> dist(MAX_NODE + 1, INT_MAX);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (dist[next] > dist[current] + 1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    return dist[end] - 1; // 시작 노드의 카운트를 뺍니다.
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        int start, end;
        cin >> start >> end;

        // 입력된 구역 번호의 최대값을 기반으로 그래프 생성
        int maxDepth = max(start, end);
        createGraph(maxDepth);

        int minKim = findMinKimbab(start, end);
        cout << "#" << i << " " << minKim << endl;

        // 그래프 초기화
        for (int j = 1; j <= MAX_NODE; ++j) {
            graph[j].clear();
        }
    }

    return 0;
}
