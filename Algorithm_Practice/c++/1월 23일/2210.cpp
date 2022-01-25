//중-숫자판 점프
#include <iostream>
#include <vector>

using namespace std;

//인덱스에 해당하는 수가 만들어졌는지를 저장한 배열 반환
vector<bool> dfs(vector<vector<int>> &v, vector<bool> &visited, int x, int y, int sum, int cnt) { //x, y : 현재 좌표, sum: 만들어진 수, cnt: 이동 횟수
	//4방향 나타내는 좌표를 가로축, 세로축으로 나누어 배열로 저장 (0,1), (0,-1), (1,0), (-1,0) 
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	if (cnt == 5) { //다섯 번 이동, 여섯자리 수가 만들어지면 이전에 만들었던 수인지 검사
		if (visited[sum] == false) { //새로운 여섯자리 수이면 false -> true로 바꿈.
			visited[sum] = true;
		}
		
		return visited; //방문 배열 리턴
	}

	for (int i = 0; i < 4; i++) { //4방향으로 이동
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) { //범위 체크
			visited = dfs(v, visited, nx, ny, sum * 10 + v[nx][ny], cnt+1); //범위 안에 들어오면 만들어진 수 갱신, 이동횟수 갱신
		}
	}

	return visited;
}

int solution(vector<vector<int>> &v){
	int result = 0; //다른 조합 개수
	vector<bool> visited; //인덱스에 해당하는 숫자가 만들어진 적이 있는지 저장
	visited.assign(1000000, false); //방문 배열 초기화
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited = dfs(v, visited, i, j, v[i][j], 0);
		}
	}

	//방문 배열에서 true인 것들만 세서 result로 반환
	for(int i=0; i<1000000; i++){
		if(visited[i]){
			result++;
		}
	}
	return result;

}

int main() {
	vector<vector<int>> board;
	int num, result;
	
	//숫자판 초기화
	board.assign(5, vector<int>(5,0)); 

	//숫자판 입력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			board[i][j]=num;
		
		}
	}

	//만들 수 있는 서로 다른 여섯 자리의 수들의 개수 구하기
	result = solution(board);

	//출력
	cout << result;


}