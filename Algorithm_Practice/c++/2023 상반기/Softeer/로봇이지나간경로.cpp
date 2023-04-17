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


bool verify(int r, int c, int n, int m){
	if(r<0 || r>=n || c<0 || c>=m || board[r][c]!='#'){
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

		if(verify(nextR, nextC, n, m) && !visited[nextR][nextC]){
            if(prevDir == i){
                result += 'A';
            }
            else{
                if((i-prevDir)%4 <(i-prevDir+4)%4){
                    for(int j=prevDir; j<=(i-prevDir)%4; j++){
                        result += 'R';  
                    }
                }
                else{
                    for(int j=prevDir; j<=(i-prevDir+4)%4; j++){
                        result += 'L';  
                    }
                }
                
            }
            cout<<"res: "<<result<<'\n';
            if(i==1 || i==3){
                //for(int j=r; j<=nextR; j++){
                    for(int k=c; k<nextC; k++){
                        visited[r][k] = true;
                    }
                //}
            }
            else if(i==0 || i==2){
                for(int j=r; j<nextR; j++){
                    //for(int k=c; k<=nextC; k++){
                        visited[j][c] = true;
                    //}
                }
            }

            /*
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    cout<<visited[j][k]<<' ';
                }
                cout<<"\n";
            }
            */
			
			dfs(nextR, nextC, n, m, i);
            //result="";
            
		}
	}

}

int main(int argc, char** argv)
{
	//처음 방향 경우의 수: 4가지 - 백트래킹?
	

	int n, m, a, b, firstDir;
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
                cout<<"start: "<<i<<" "<<j<<'\n';

				for(int k=0; k<4; k++){
					if(verify(i+dr[k], j+dc[k], n, m)){
                        cout<<"firstDir: "<<k<<'\n';
						dfs(i,j,n,m,k);

                        cout<<"allPassed: "<<allPassed(n,m)<<'\n';

						if(allPassed(n,m)){
							if(answer==""){
								answer = result;
								a = i+1;
								b = j+1;
								firstDir = k;
							}
							else{
								if(result.length()<answer.length()){
									answer = result;
									a = i+1;
									b = j+1;
									firstDir = k;
								}
							}
						}
                        for(int c=0; c<n; c++){
                            for(int d=0; d<m; d++){
                                cout<<visited[c][d]<<' ';
                            }
                            cout<<"\n";
                        }
                        cout<<"ans: "<<answer<<" result: "<<result<<'\n';
                        result = "";
					}
				}
				
			
			}

		}
	}

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