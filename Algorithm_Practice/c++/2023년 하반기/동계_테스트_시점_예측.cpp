#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//bfs
//시간 초과가 나면 메모리를 많이 쓰는 방향으로 바꿔보기
//빈칸->외부로 바꿀 때, bfs 말고 board를 복사하는 방법 사용
//내부, 외부 판단 기준 - bfs로 외부 영역 표시
//얼음의 2변 이상이 외부의 공기와 접촉해있으면 한 시간 뒤에 녹아 없어짐.
//* 격자의 맨 가장자리에는 얼음이 없음.
//얼음이 모두 녹아 없어지는데 걸리는 시간
bool verify(int r, int c, int n, int m){
  if(r<0 || r>=n || c<0 || c>=m){
    return false;
  }
  return true;
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  //격자 - 얼음 표시
  //큐 - 얼음 정보 - 녹아 없어질 얼음을 temp에 넣고 한 번에 없애기&격자의 상태 변경, 아직 없어지지 않으면 다시 push
  int n,m,answer=0;
  int dr[4] = {0,0,1,-1};
  int dc[4] = {1,-1,0,0};
  vector<vector<int>> board, board1; //얼음: 1, 빈칸:0
  queue<pair<int,int>> ice, temp, outside, blank; //얼음 좌표, 없어질 얼음 좌표
  
  cin>>n>>m;

  board.assign(n, vector<int>(m,0));
  board1.assign(n, vector<int>(m,0));
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>board[i][j];
      if(board[i][j]==1){
        ice.push({i,j});
      }
    }
  }

  //외부 영역 2로 board에 표시 - bfs 이용
  outside.push({0,0});
  board[0][0] = 2;
  while(!outside.empty()){
    int r = outside.front().first;
    int c = outside.front().second;

    for(int i=0; i<4; i++){
      int nextR = r+dr[i];
      int nextC = c+dc[i];
      if(verify(nextR,nextC,n,m) && board[nextR][nextC]==0){
        board[nextR][nextC] = 2;
        outside.push({nextR, nextC});
      }
    }
    outside.pop();
  }

  board1 = board;
  //없어질 얼음 판단
  //얼음 없애기
  //외부로 변경되는 빈칸 판단
  while(!ice.empty()){
    answer++;    
    
    //없어질 얼음 판단
    int totalIce = ice.size();
    for(int i=0; i<totalIce; i++){
      int r = ice.front().first;
      int c = ice.front().second;
      int cnt = 0; //외부(2)와 맞닿아있는 변의 개수
      for(int j=0; j<4; j++){
        int nextR = r+dr[j];
        int nextC = c+dc[j];
        if(board[nextR][nextC]==2){
          cnt++;
        }
      }
      //없어질 얼음
      if(cnt>=2){
        board1[r][c]=2;
        temp.push({r,c});
      }
      else{ //없어지지 않을 얼음
        ice.push({r,c});
      }
      ice.pop();
    }

    //외부로 변경되는 빈칸 판단
    while(!temp.empty()){
      int r = temp.front().first;
      int c = temp.front().second;
    cout<<r<<' '<<c<<'\n';
      for(int k=0; k<4; k++){
        int nextR = r+dr[k];
        int nextC = c+dc[k];

        if(verify(nextR, nextC, n, m) && board1[nextR][nextC]==0){
          temp.push({nextR, nextC});
          board1[nextR][nextC]=2;
        }
      }
      temp.pop();
    }

    board = board1;
  }  

  cout<<answer;
   return 0;
}