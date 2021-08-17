#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

int N, M, result=0;
int node[1001]; //기준 노드 저장 - 집합 구분할 때 사용
vector<pair<int, pair<int, int>>> Edge; //(값, (노드, 노드))형태
bool visited[1001];

int find(int a) {
	if (node[a] == a) return a;
	else return node[a] = find(node[a]);
}

bool samenode(int a, int b) {
	a = find(a);
	b = find(b);

	return (a == b);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b)
		node[b] = a;
}

int main() {
	int N;
	int M;

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

	
	for (int i = 0; i < M; i++) {
		if (!samenode(Edge[i].second.first, Edge[i].second.second)) {
			merge(Edge[i].second.first, Edge[i].second.second);
			result += Edge[i].first;
		}		
	}	

	cout << result;
}
