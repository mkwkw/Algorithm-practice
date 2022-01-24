//중 - 숫자판 점프 -  정리
#include <iostream>
#include <vector>

using namespace std;

bool visited[1000000]; //방문 체크
int result=0; //다른 조합 개수

void solution(vector<vector<int>> &v, int x, int y, int sum, int cnt) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	if (cnt == 5) {
		if (visited[sum] == false) {
			visited[sum] = true;
			result++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
			solution(v, nx, ny, sum * 10 + v[nx][ny], cnt+1);
		}
	}
	
}

int main() {
	vector<vector<int>> v;
	int num;
	v.assign(5, vector<int>(5,0));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			v[i].push_back(num);
		
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solution(v, i, j, v[i][j], 0);
		}
	}
	cout << result;


}