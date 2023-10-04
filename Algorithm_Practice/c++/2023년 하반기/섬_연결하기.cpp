#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//크루스칼 알고리즘 - 그래프의 모든 정점들을 가장 적은 비용으로 연결 - 최소신장트리 - n개의 노드, n-1개의 간선
//그리디 알고리즘의 일종
//1. 간선 가중치 오름차순으로 정렬
//2. 간선 가중치 작은 것부터 조사
//3. 사이클을 만들어내지 않는다면 해당 간선과 연결 - a-b라면 union-find로 a노드의 집합고 b노드의 집합이 다르면 연결, 같으면 연결하지 않음.
//4. n-1개의 간선이 연결되면 끝
struct Node{
    int cost; //간선 가중치
    int a; //섬1
    int b; //섬2
};

bool comp(const Node &node1, const Node &node2){
    return node1.cost<node2.cost;
}

int solution(int n, vector<vector<int>> costs) {
    vector<Node> node;
    vector<int> parent; //사이클 판단 - union-find - 할 때 사용할 부모 노드 저장 배열
    int edgeCnt = 0;    
    int answer = 0;
    
    if(n==0){
        return 0;
    }
    
    //초기화
    for(int i=0; i<costs.size(); i++){
        node.push_back({costs[i][2], min(costs[i][0], costs[i][1]), max(costs[i][0], costs[i][1])});
    }
    
    for(int i=0; i<n; i++){
        parent.push_back(i);
    }
    
    //간선 가중치 오름차순 정렬
    sort(node.begin(), node.end(), comp);
    
    //먼저 가장 작은 간선 가중치 갖는 간선 선택
    edgeCnt = 1;
    answer = node[0].cost;
    parent[node[0].b] = node[0].a; //둘 중 더 큰 노드의 부모 노드 바꾸기
    
    //이후 간선 - 사이클 생기는 지 판단하고(양 노드의 부모 노드가 같은가)
    //사이클 생기지 않으면 edgeCnt++, answer에 더하고, 부모 노드 바꾸기
    //edgeCnt == n-1이면 끝내기
    for(int i=1; i<node.size(); i++){
        int parentA = parent[node[i].a];
        int parentB = parent[node[i].b];
        if(parentA!=parentB){
            edgeCnt += 1;
            //cout<<"edge cnt "<<edgeCnt<<'\n';
            answer += node[i].cost;
        
    //         cout<<parent[4]<<'\n';
            if(parentA<parentB){
                //cout<<parentA<<' '<<parentB<<'\n';
                for(int j=0; j<n; j++){
                    //cout<<"j: "<<j<<" parent "<<parent[j]<<' '<<parentB<<'\n';
                    if(parent[j]==parentB){
                        //cout<<"j: "<<j<<" parent "<<parent[node[i].b]<<'\n';
                        parent[j] = parentA;
                    }
                }
            }
            else{
                for(int j=0; j<n; j++){
                    if(parent[j]==parentA){
                        parent[j] = parentB;
                    }
                }
            }
            
            // for(int j=0; j<n; j++){
            //     cout<<parent[j]<<' ';
            // }
            // cout<<'\n';
            
            if(edgeCnt == n-1){
                break;
            }
            
        }          
    }
//     for(int i=0; i<node.size(); i++){
//         cout<<node[i].cost<<' '<<node[i].a<<' '<<node[i].b<<'\n';
//     }
    //     for(int i=0; i<n; i++){
    //     cout<<parent[i]<<' ';
    // }
    // cout<<'\n';

    
    return answer;
}