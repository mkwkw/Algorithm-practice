#include <string>
#include <vector>

using namespace std;

//dp
//1000000007로 나누는 것 잊지 말기!
int solution(int n) {
    int answer = 0;
    vector<int> tile; //인덱스: 세로의 길이
    
    tile.assign(n+1,0);
    
    //세로의 길이:1
    tile[1] = 1;
    
    //세로의 길이:2
    tile[2] = 2;
    
    //세로의 길이:3
    //tile[3] = tile[1]+tile[2];
    for(int i=3; i<=n; i++){
        tile[i] = (tile[i-2]+tile[i-1])%1000000007;
    }
    
    answer = tile[n];
    
    return answer;
}