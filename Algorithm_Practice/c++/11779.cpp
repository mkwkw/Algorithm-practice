#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; //(가중치, 위치 인덱스)
const int INF = 1e8;

//시작도시부터 도착도시까지 최단 경로를 구하는데 따로 path배열을 두어 해당 위치 이전의 지점의 인덱스를 저장한다.
//역추적 과정에서 path배열을 이용하여 경로를 구한다.

//역추적
vector<int> back(int x, vector<int> &path) { //x: 도착정점, 도착정점부터 역추적
    vector<int> result(0); //경로 저장할 벡터
    while (x != 0) {
        result.push_back(x);
        x = path[x]; //다음 정점
    }
    return result;
}

int dijkstra(int n, int s, int e, vector<vector<ci>> &graph, vector<int> &path) { //최소 비용 경로
    vector<int> dist(n + 1, INF); //거리 저장할 배열
    priority_queue<ci, vector<ci>, greater<>> pq; //우선순위 큐

    //시작 위치 초기화
    dist[s] = 0;
    pq.push({0, s}); //시작 위치: 비용:0, 인덱스:s

    while (!pq.empty()) {
        int weight = pq.top().first; //중간 비용
        int node = pq.top().second; //중간 정점
        pq.pop(); //pop

        if (weight > dist[node]) //이미 탐색한 정점 (이 코드 없으면 시간초과)
            continue;

        for (int i = 0; i < graph[node].size(); i++) { //중간 정점과 연결된 정점 탐색
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로
                dist[next_node] = next_weight; //비용 갱신
                path[next_node] = node; //경로 저장
                pq.push({next_weight, next_node}); //우선순위 큐에 push
            }
        }
    }
    return dist[e]; 
}

/**
 * 다익스트라 역추적
 * - 기본 문제: 최소 비용 구하기
 */

int main() {
    int n, m, a, b, c, s, e;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접 리스트
    vector<int> path(n + 1, 0); //경로 저장할 배열
    while (m--) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); //단방향 그래프-인접 리스트에 저장 (의미: a부터 b까지 비용 c)
    }
    cin >> s >> e; //시작 도시, 도착 도시

    //연산
    int ans = dijkstra(n, s, e, graph, path); //최소 비용
    vector<int> result = back(e, path); //경로

    //출력
    cout << ans << '\n' << result.size() << '\n'; 
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
    return 0;
}
