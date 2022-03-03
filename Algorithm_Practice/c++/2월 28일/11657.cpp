#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> ti; //시작점, 도착점, 비용
const int INF = 1e6*5;

//벨만-포드: 음수 가중치 계산 가능한 다익스트라와 비슷한 모델
vector<ll> bellmanFord(int n, int m, int start, vector<ti> &edges){
    //언더 플로우: 500*6000*(-10000) : int 범위 넘으므로 long long 사용
    vector<ll> dist(n+1,INF); //모든 정점 INF로 초기화 (시작점에서 k정점으로 가는 값이 dist[k])

    dist[start]=0; //시작점 0으로 초기화

    for(int i=1; i<=n; i++){ //정점 순회
        bool flag = true; //더 이상 반복문을 실행할 필요가 없는지 확인: true이면 갱신x, false이면 갱신o
        for(int j=0; j<m; j++){ //간선 순회
            //s에서 d로 가는 간선의 가중치 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if(dist[s] == INF){ //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신x
                continue;
            }

            ll next_weight = dist[s]+w; //s까지의 가중치 + s에서 d까지의 가중치 = 새로 계산한 s에서부터 d로 가는 가중치
            if(dist[d]>next_weight){ // 더 짧은 경로로 갈 수 있다면
                if(i==n){ //n번째 갱신이었다면 음의 사이클이 발생한 것 (사이클이 발생하지 않는 경우에는 최대 n-1번째 갱신까지 일어남)
                    return {INF+1}; //정점 전체 값을 INF+1로 바꿈
                }

                dist[d] = next_weight; //음의 사이클이 아닌 경우, 시작점에서 d까지 가는 가중치 갱신
                flag=false;
            }
        }

        if(flag){
            break;
        }
    }
    return dist; 
}

int main(){
    int n,m,a,b,c;

    cin>>n>>m;
    
    vector<ti> edges(m); //간선 정보 저장할 벡터

    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        edges[i]={a,b,c}; //시작점, 도착점, 가중치 값을 edges 벡터에 tuple 형태로 저장
    }

    vector<ll> ans = bellmanFord(n,m,1,edges); //시작점:1

    if(ans[0]==INF+1){ //음의 사이클이 발생한 경우 -1 출력
        cout<<-1;
        return 0;
    }

    for(int i=2; i<=n; i++){ //ans[1]은 시작점->시작점이므로 제외, ans[i]==INF는 갱신되지 않았다는 뜻 == 해당도시로 가는 경로가 없다는 뜻 : -1 출력
        cout<<((ans[i]==INF)? -1 : ans[i])<<'\n';
    }
}