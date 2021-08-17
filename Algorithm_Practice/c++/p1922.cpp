#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

int N, M, result=0;
int node[1001]; //기준 노드 저장 - 집합 구분할 때 사용
vector<pair<int, pair<int, int>>> Edge; //(값, (노드, 노드))형태
bool visited[100001];


int main() {
	int N;
	int M;
	int minprice = 10001;
	int nextnode = 0;

	for (int i = 0; i < 100001; i++)
		visited[i] = false;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		node[i] = i; //기준 노드 자기자신으로 일단 초기화
	}
	
	for (int i = 0; i < M; i++) {
		int a, b, c, temp;
		cin >> a >> b >> c;

		if (a > b) {
			temp = b;
			b = a;
			a = temp;
		}

		Edge.push_back(make_pair(c, make_pair(a, b)));
	}
	//edges 배열에 각 간선 정보들 저장, 최솟값 저장

	sort(Edge.begin(),Edge.end()); //값 기준 내림차순 정렬
	cout << "\n";
	for (int i = 0; i < M; i++) {

		cout << Edge[i].second.first << " " << Edge[i].second.second<<" "<<Edge[i].first<<"\n";
	}

	for (int i = 0; i < M; i++) {
		if (!visited[Edge[i].second.first] && !visited[Edge[i].second.second]) {
			result += Edge[i].first;
			visited[Edge[i].second.first] = true;
			visited[Edge[i].second.second] = true;
			node[Edge[i].second.first] = min(node[Edge[i].second.first], node[Edge[i].second.second]);
			for (int j = 1; j <= N; j++) {
				if(node[j]==node[Edge[i].second.second])
					node[j] = node[Edge[i].second.first];
				
			}
		}
		else if(!visited[Edge[i].second.first] && visited[Edge[i].second.second]){
			result += Edge[i].first;
			visited[Edge[i].second.first] = true;
			node[Edge[i].second.first] = min(node[Edge[i].second.first],node[Edge[i].second.second]);
			node[Edge[i].second.second] = node[Edge[i].second.first];
		}
		else if (visited[Edge[i].second.first] && !visited[Edge[i].second.second]) {
			result += Edge[i].first;
			visited[Edge[i].second.second] = true;
			node[Edge[i].second.first] = min(node[Edge[i].second.first], node[Edge[i].second.second]);
			node[Edge[i].second.second] = node[Edge[i].second.first];
		}
		else {//둘 다 방문된 상태 //같은 집합-cycle 생성-연결x or 다른 집합-연결o 
			if (node[Edge[i].second.first] == node[Edge[i].second.second]) { //같은 집합
				continue;
			}
			else {
				result += Edge[i].first;
				node[Edge[i].second.first] = min(node[Edge[i].second.first], node[Edge[i].second.second]);
				node[Edge[i].second.second] = node[Edge[i].second.first];
			}
		}
		for (int i = 1; i <= N; i++) {
		cout << "Node: " << node[i]<<"\n";
		}
		cout << result<<"\n";
	}

	

	cout << result;

	/*for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (edges[j].left == i) {
				if (edges[j].price < minprice) {
					minprice = edges[j].price;
					nextnode = edges[j].right;
				}
					
			}
		}
	}*/
}