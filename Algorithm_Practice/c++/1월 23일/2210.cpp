//��-������ ����
#include <iostream>
#include <vector>

using namespace std;

//�ε����� �ش��ϴ� ���� ������������� ������ �迭 ��ȯ
vector<bool> dfs(vector<vector<int>> &v, vector<bool> &visited, int x, int y, int sum, int cnt) { //x, y : ���� ��ǥ, sum: ������� ��, cnt: �̵� Ƚ��
	//4���� ��Ÿ���� ��ǥ�� ������, ���������� ������ �迭�� ���� (0,1), (0,-1), (1,0), (-1,0) 
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	if (cnt == 5) { //�ټ� �� �̵�, �����ڸ� ���� ��������� ������ ������� ������ �˻�
		if (visited[sum] == false) { //���ο� �����ڸ� ���̸� false -> true�� �ٲ�.
			visited[sum] = true;
		}
		
		return visited; //�湮 �迭 ����
	}

	for (int i = 0; i < 4; i++) { //4�������� �̵�
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) { //���� üũ
			visited = dfs(v, visited, nx, ny, sum * 10 + v[nx][ny], cnt+1); //���� �ȿ� ������ ������� �� ����, �̵�Ƚ�� ����
		}
	}

	return visited;
}

int solution(vector<vector<int>> &v){
	int result = 0; //�ٸ� ���� ����
	vector<bool> visited; //�ε����� �ش��ϴ� ���ڰ� ������� ���� �ִ��� ����
	visited.assign(1000000, false); //�湮 �迭 �ʱ�ȭ
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited = dfs(v, visited, i, j, v[i][j], 0);
		}
	}

	//�湮 �迭���� true�� �͵鸸 ���� result�� ��ȯ
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
	
	//������ �ʱ�ȭ
	board.assign(5, vector<int>(5,0)); 

	//������ �Է�
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			board[i][j]=num;
		
		}
	}

	//���� �� �ִ� ���� �ٸ� ���� �ڸ��� ������ ���� ���ϱ�
	result = solution(board);

	//���
	cout << result;


}