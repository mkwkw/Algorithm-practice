#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int answer = 1000000000;
int temp = 0;

/*
struct Yarn {
    int a;
    int b;
    int c;
};

void backtracking(vector<map<int, int>> &cow, vector<bool> visited, int pos, int n, int cowCnt){

    if(pos==n){
        answer = min(answer, cowCnt);
        return;
    }

    for(auto yarn : cow[pos]){
        int num = yarn.first;
        
        if(visited[num]){
            continue;
        }

        visited[num] = true;
        //cout<<"pos: "<<pos<<" num: "<<num<<" cowCnt: "<<cowCnt<<'\n';
        backtracking(cow, visited, num, n, cowCnt+cow[pos][num]);
        visited[num] = false;
    }
}*/

//백트래킹, bfs 모두 시간초과!
//다익스트라!

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<map<int, int>> cow;
    //vector<bool> visited;
    //queue<Yarn> yarnQ; 
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<int> dist; //idx까지의 거리
    int n, m, a, b, c;

    cin>>n>>m;

    cow.assign(n+1, map<int, int>());
    //visited.assign(n+1, false);
    dist.assign(n+1, 100000000);

    //양방향
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;

        if(cow[a].find(b)==cow[a].end()){
            cow[a][b] = c;
            cow[b][a] = c;
        }
        else{
            cow[a][b] = min(cow[a][b], c);
            cow[b][a] = min(cow[b][a], c);
        }
    }

    //1까지의 거리: 0
    dist[1] = 0;
    pq.push({1,0});

    while(!pq.empty()){
        int pos = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        for(auto yarn : cow[pos]){
            if(dist[yarn.first]>dist[pos]+yarn.second){ //기존 다음 인덱스까지 거리 > 지금 인덱스+다음 인덱스까지 거리 -> 갱신
                dist[yarn.first] = dist[pos]+yarn.second;
                pq.push({yarn.first, yarn.second});
            }
        }
    }

    cout<<dist[n];

    //visited[1] = true;
    //backtracking(cow, visited, 1, n, 0);
    
    /*
    for(auto yarn : cow[1]){
        yarnQ.push({1, yarn.first, yarn.second});
    }

    while(!yarnQ.empty()){
        int a = yarnQ.front().a;
        int b = yarnQ.front().b;
        int c = yarnQ.front().c;

        //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<'\n';

        if(b==n){
            answer = min(answer, c);
        }
        if(c>answer){
            //cout<<"pop: "<<c<<" ans: "<<answer<<'\n';
            yarnQ.pop();
        }

        visited[a] = true;
        for(auto yarn : cow[b]){
            if(visited[yarn.first]){
                continue;
            }
            else{
                //cout<<"a: "<<b<<" b: "<<yarn.first<<" c: "<<c+yarn.second<<'\n';
                if(c+yarn.second>answer){
                    //cout<<"cont: "<<c+yarn.second<<" ans: "<<answer<<'\n';
                    continue;
                }
                yarnQ.push({b, yarn.first, c+yarn.second});
            }
        }

        yarnQ.pop();
    }
    */

    //cout<<answer;

}
