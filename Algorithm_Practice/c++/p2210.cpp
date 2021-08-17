#include <iostream>
#include <vector>

using namespace std;
vector<int> v[5];
bool visited[1000000];
int result=0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int sum, int cnt) {
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
			dfs(nx, ny, sum * 10 + v[nx][ny], cnt+1); //다른 숫자 얻기 위해 sum*10+v[nx][ny]으로 계산
		}
	}
}

int main() {
	int a;


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a;
			v[i].push_back(a);
		
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, v[i][j], 0);
		}
	}
	cout << result;


}
