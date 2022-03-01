#include <iostream>
#include <vector>
using namespace std;

bool rows[9][10] = {0, }; //rows[i][num]: i행에 num 존재 
bool cols[9][10] = {0, }; //cols[i][num]: i열에 num 존재 
bool square[9][10] = {0, }; //square[i][num]: i번째 3*3 영역에 num이 존재하는가

int find_square(int i, int j){ //사각형 영역번호 찾기
	return 3*(i/3)+(j/3);
}

//blank 배열을 하나씩 백트래킹으로 돌면서 적절한 숫자를 찾는다.
bool backtracking(vector<vector<int>> &answer, vector<pair<int, int>> &blank, int idx, int s){ 
	if(idx == s){ //빈 칸(0)이었던 것 모두 채움 (blank 배열 모두 끝남) - backtracking 종료 조건
		return true;
	}
	
	int r = blank[idx].first;
	int c = blank[idx].second;
	int a = find_square(r,c);
	
	for(int num=1; num<=9; num++){ //1~9까지 어떤 수가 맞는지 탐색
		if(!rows[r][num] && !cols[c][num] && !square[a][num]){ //가로, 세로, 사각형에 없는 숫자라면 일단 true로 상태 바꾸고 answer에 저장함.
			rows[r][num]=1;
			cols[c][num]=1;
			square[a][num]=1;
			
			answer[r][c]=num;
			
			if(backtracking(answer, blank, idx+1, s)){ //blank배열 탐색 끝남
				return true;
			}
			
			else{ //blank 끝까지 탐색했는데 true리턴이 안된다면 문제가 있는 것임. 다시 idx로 돌아와서 true로 바꾸었던 것을 false로 다시 바꿈, 그리고 for문이 다시 돌아가며 다음 숫자가 알맞는지 다시 탐색
				rows[r][num]=0;
				cols[c][num]=0;
				square[a][num]=0;
			}
		}
	}
	return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku){
    vector<vector<int>> answer(9, vector<int>(9, 0));  // 정답 = 현재의 상태를 저장하는 배열
		vector<pair<int, int>> blank;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(sudoku[i][j]==0){ //빈 칸인 경우
					blank.push_back(make_pair(i,j));
				}
				else{//숫자가 써있는 경우
					rows[i][sudoku[i][j]]=1; //true
					cols[j][sudoku[i][j]]=1; //true
					square[find_square(i,j)][sudoku[i][j]]=1; //true
					answer[i][j]=sudoku[i][j];//숫자 복사
					
				}
			}
		}
		
	int s = blank.size();
	backtracking(answer, blank, 0,s);
	return answer;
}

int main(){
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) cin >> sudoku[i][j];
    }
    auto output = solution(sudoku);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) cout << output[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

