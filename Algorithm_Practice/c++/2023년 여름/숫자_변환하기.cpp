#include <string>
#include <vector>
#include <queue>

using namespace std;

//bfs
//처음부터 x와 y가 같은 경우도 고려해야함!!
int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int,int>> operation; //tempX, 연산 횟수
    vector<bool> visited;
    
    visited.assign(y-x+1, false);
    
    //더하기, 곱하기 모두 값을 증가시키는 연산이므로
    //x에 연산을 한 값이 y보다 커지면 안 됨.
    
    //처음부터 x==y인 경우
    if(x==y){
        return 0;
    }
    
    operation.push({x,0});
    visited[0] = true;
     
    while(!operation.empty()){
        int tempX = operation.front().first;
            
            if(tempX+n==y){
                answer = operation.front().second+1;
                break;
            }
            else if(tempX+n<y && !visited[tempX+n-x]){
                operation.push({tempX+n, operation.front().second+1});
                visited[tempX+n-x] = true;
            }
            
            if(tempX*2==y){
                answer = operation.front().second+1;
                break;
            }
            else if(tempX*2<y && !visited[tempX*2-x]){
                operation.push({tempX*2, operation.front().second+1});
                visited[tempX*2-x] = true;
            }
            
            if(tempX*3==y){
                answer = operation.front().second+1;
                break;
            }
            else if(tempX*3<y && !visited[tempX*3-x]){
                operation.push({tempX*3, operation.front().second+1});
                visited[tempX*3-x] = true;
            }
        operation.pop();
    }
    
    return answer;
}