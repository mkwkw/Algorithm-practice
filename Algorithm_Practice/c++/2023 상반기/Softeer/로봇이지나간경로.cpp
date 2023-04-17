#include <iostream>
#include <vector>

using namespace std;

//상 -> 우 -> 하 -> 좌 (R), 반대로 (L)
int dr[4]={-2,0,2,0};
int dc[4]={0,2,0,-2};
vector<string> board;
vector<vector<bool>> visited;
string result = "", answer = "";
char dir;

//백트래킹으로 인자에 문자열 넘기면서 하나씩 확인하도록 - 1인 부분 좌표 벡터에 넣어서 문자열 길이 == 벡터의 크기 될 때까지 탐색하도록
bool verify(int r, int c, int n, int m, int dir){
	if(r<0 || r>=n || c<0 || c>=m){
		return false;
	}

	bool flag = true;
	switch(dir){
		case 0:
		if(!(board[r][c] == '#' && board[r+1][c] == '#')){
			flag = false;
		}
		break;

		case 1:
		if(!(board[r][c] == '#' && board[r][c-1] == '#')){
			flag = false;
		}
		break;

		case 2:
		if(!(board[r][c] == '#' && board[r-1][c] == '#')){
			flag = false;
		}
		break;

		case 3:
		if(!(board[r][c] == '#' && board[r][c+1] == '#')){
			flag = false;
		}
		break;	
	}

	if(!flag){
		return false;
	}

	return true;
}

bool allPassed(int n, int m){
	bool flag = true;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(board[i][j]=='#' && !visited[i][j]){
				flag = false;
				break;
			}
		}
		if(!flag){
			break;
		}
	}

	return flag;
}

void dfs(int r, int c, int n, int m, int prevDir){

	if(visited[r][c]){
		return;
	}

	visited[r][c] = true;

	for(int i=0; i<4; i++){
		//cout<<"prevDir: "<<prevDir<<" nowDir: "<<i<<'\n';
		int nextR = r + dr[i];
		int nextC = c + dc[i];

		if(verify(nextR, nextC, n, m, i) && !visited[nextR][nextC]){
            if(prevDir == i){
                result += 'A';
            }
            else{
                if(prevDir-i == -1){
					result += 'R';
				}
				else if(prevDir-i == 1){
					result += 'L';
				}
				else if(prevDir-i == 3){
					result += 'R';
				}
				else if(prevDir-i == -3){
					result += 'L';
				}
				else{
					result += "RR"; //이런 경우가 있나?
				}
                result += 'A';
            }
            //cout<<"res: "<<result<<'\n';

			switch(i){
				case 0:
				visited[r-1][c] = true;
				break;

				case 1:
                visited[r][c+1] = true;
				break;

				case 2:
				visited[r+1][c] = true;
                break;

				case 3:
				visited[r][c-1] = true;
				break;

			}
			
			dfs(nextR, nextC, n, m, i);
            //result="";
            
		}
	}

}

int main(int argc, char** argv)
{

	int n, m, a, b, firstDir, startR=-1, startC=-1;
	char firstDirChar;
	cin>>n>>m;

	board.assign(n, "");
	visited.assign(n, vector<bool>(m, false));

	for(int i=0; i<n; i++){
		cin>>board[i];
	}

	for(int i=0; i<n; i++){
		result = "";
		for(int j=0; j<m; j++){
			
			visited.assign(n, vector<bool>(m, false));

			if(board[i][j]=='#'){
                //cout<<"start: "<<i+1<<" "<<j+1<<'\n';

				for(int k=0; k<4; k++){
					if(verify(i+dr[k], j+dc[k], n, m, k)){
						result = "";
                        //cout<<"firstDir: "<<k<<'\n';
						dfs(i,j,n,m,k);

                        //cout<<"allPassed: "<<allPassed(n,m)<<'\n';

						if(allPassed(n,m)){
							startR = i;
							startC = j;
							firstDir = k;

							break;
						}
					}
				}

				if(startR>-1){
					break;
				}
			}
			if(startR>-1){
				break;
			}

		}

		if(startR>-1){
			break;
		}
	}	

	answer = result;
	a = startR+1;
	b = startC+1;						
						
	switch(firstDir){
		case 0:
		firstDirChar = '^';
		break;
		case 1:
		firstDirChar = '>';
		break;
		case 2:
		firstDirChar = 'v';
		case 3:
		firstDirChar = '<';
	}
	
	
	cout<<a<<' '<<b<<'\n'<<firstDirChar<<'\n'<<answer;
	

	return 0;
}