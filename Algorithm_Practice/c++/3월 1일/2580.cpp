#include <iostream>
#include <vector>
using namespace std;

bool rows[9][10] = {0, }; //rows[i][num]: i�࿡ num ���� 
bool cols[9][10] = {0, }; //cols[i][num]: i���� num ���� 
bool square[9][10] = {0, }; //square[i][num]: i��° 3*3 ������ num�� �����ϴ°�

int find_square(int i, int j){ //�簢�� ������ȣ ã��
	return 3*(i/3)+(j/3);
}

//blank �迭�� �ϳ��� ��Ʈ��ŷ���� ���鼭 ������ ���ڸ� ã�´�.
bool backtracking(vector<vector<int>> &answer, vector<pair<int, int>> &blank, int idx, int s){ 
	if(idx == s){ //�� ĭ(0)�̾��� �� ��� ä�� (blank �迭 ��� ����) - backtracking ���� ����
		return true;
	}
	
	int r = blank[idx].first;
	int c = blank[idx].second;
	int a = find_square(r,c);
	
	for(int num=1; num<=9; num++){ //1~9���� � ���� �´��� Ž��
		if(!rows[r][num] && !cols[c][num] && !square[a][num]){ //����, ����, �簢���� ���� ���ڶ�� �ϴ� true�� ���� �ٲٰ� answer�� ������.
			rows[r][num]=1;
			cols[c][num]=1;
			square[a][num]=1;
			
			answer[r][c]=num;
			
			if(backtracking(answer, blank, idx+1, s)){ //blank�迭 Ž�� ����
				return true;
			}
			
			else{ //blank ������ Ž���ߴµ� true������ �ȵȴٸ� ������ �ִ� ����. �ٽ� idx�� ���ƿͼ� true�� �ٲپ��� ���� false�� �ٽ� �ٲ�, �׸��� for���� �ٽ� ���ư��� ���� ���ڰ� �˸´��� �ٽ� Ž��
				rows[r][num]=0;
				cols[c][num]=0;
				square[a][num]=0;
			}
		}
	}
	return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku){
    vector<vector<int>> answer(9, vector<int>(9, 0));  // ���� = ������ ���¸� �����ϴ� �迭
		vector<pair<int, int>> blank;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(sudoku[i][j]==0){ //�� ĭ�� ���
					blank.push_back(make_pair(i,j));
				}
				else{//���ڰ� ���ִ� ���
					rows[i][sudoku[i][j]]=1; //true
					cols[j][sudoku[i][j]]=1; //true
					square[find_square(i,j)][sudoku[i][j]]=1; //true
					answer[i][j]=sudoku[i][j];//���� ����
					
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

