#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

bool verify(int r, int c, int n){
	if(r<0 || r>=n || c<0 || c>=n){
		return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	vector<vector<char>> board;
	vector<vector<bool>> visited;
	vector<int> districtSize;
	queue<pair<int,int>> pos;

	int n;

	cin>>n;

	board.assign(n, vector<char>(n, ' '));
	visited.assign(n, vector<bool>(n, false));

	for(int i=0; i<n; i++){
		string input;
		cin>>input;

		for(int j=0; j<n; j++){
			board[i][j] = input[j];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int dSize = 0;
			if(board[i][j]=='1' && !visited[i][j]){
				visited[i][j] = true;
				pos.push({i, j});
				dSize = 1;

				while(!pos.empty()){
					int r = pos.front().first;
					int c = pos.front().second;

					for(int k=0; k<4; k++){
						int nextR = r+dr[k];
						int nextC = c+dc[k];

						if(verify(nextR, nextC, n) && board[nextR][nextC]=='1' && !visited[nextR][nextC]){
							dSize++;
							visited[nextR][nextC] = true;
							pos.push({nextR, nextC});
						}
					}
					pos.pop();
				}
				districtSize.push_back(dSize);
			}
		}
	}

	sort(districtSize.begin(), districtSize.end());

	cout<<districtSize.size()<<'\n';

	for(int i=0; i<districtSize.size(); i++){
		cout<<districtSize[i]<<'\n';
	}

	return 0;
}