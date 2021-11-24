#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

//프림 알고리즘 - 노드 중심
typedef pair<double, double> ci1;
typedef pair<int, double> ci2;

double distance(double a, double b, double c, double d){ //두 노드간 거리 계산
    double dist = sqrt((a-c)*(a-c)+(b-d)*(b-d));
    return dist;
}

void stellar(int n, vector<ci1> &v1){
    vector <ci2> v2[101]; //노드와 거리 저장
    priority_queue<pair<double, int>> pq; //거리와 노드 
    //(거리는 -를 붙여서 저장 - ex- 원래: 3,2,1 로 정렬 but -붙이면 -1, -2, -3으로 저장 - 최소 거리 구해야하므로 이렇게 하는 것이 편리)
    bool visited[101]={false}; //방문 체크
    double ans=0; //최소 거리

    for(int i=0; i<n; i++){
        double x = v1[i].first;
        double y = v1[i].second;
        for(int j=i+1; j<n; j++){
            double z = v1[j].first;
            double w = v1[j].second;
            double dist = distance(x,y,z,w);

            //v2에 각 노드와 지금 노드의 관계에 대한 정보 저장
            v2[i].push_back(make_pair(j, dist));
            v2[j].push_back(make_pair(i, dist));

        }
    }

    for(int i=0; i<v2[0].size(); i++){
        int next = v2[0][i].first; //노드 0과 연결했다고 가정하는 노드i
        double dist = v2[0][i].second; //노드 0과 노드if를 연결했을 때의 거리 

        pq.push(make_pair(-dist,next)); //최소 거리 구해야하므로 dist에 -붙여서 pq에 push
    }

    visited[0] = true; //노드0 방문 체크

    while(!pq.empty()){ //노드0에 대해서 넣은 pq를 돌면서 모든 노드 체크
        double dist = -pq.top().first; 
        int current = pq.top().second;
        pq.pop();

        if(!visited[current]){ //방문하지 않은 노드라면
            visited[current]=true;
            ans += dist;

            for(int i=0; i<v2[current].size(); i++){ //이 방문하지 않은 노드에 저장된 노드들도 전부 검사
                int next = v2[current][i].first;
                double dist = v2[current][i].second;

                if(!visited[next]){
                    pq.push(make_pair(-dist, next));
                }
            }
        }
    }
    cout<<ans;
}

int main(){
    vector<ci1> v1; //좌표 저장
    int n;
    cin>>n;

    v1.assign(n,make_pair(0,0));

    for(int i=0; i<n; i++){
        double x, y;
        cin>>x>>y;
        v1[i]=make_pair(x,y);
    }
    stellar(n,v1);
}