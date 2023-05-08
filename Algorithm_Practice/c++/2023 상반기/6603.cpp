#include <iostream>
#include <vector>

using namespace std;

//k개 중에 6개 고르기
//순열, 조합
//백트래킹

vector<int> num, result;
vector<bool> visited;

void backtracking(int cnt, int startIdx, int k){
    if(cnt==6){
        for(int i=0; i<6; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=startIdx; i<k; i++){
        if(visited[i]){
            continue;
        }
        result[cnt] = num[i];
        visited[i] = true;
        backtracking(cnt+1, i+1, k);
        visited[i] = false;
    }
}

int main(){
    int k;
    
    while(cin>>k){
        if(k==0){
            return 0;
        }

        num.assign(k, 0);
        visited.assign(k, false);
        result.assign(6, 0);

        for(int i=0; i<k; i++){
            cin>>num[i];
        }

        for(int i=0; i<=k-6; i++){
            result[0] = num[i];
            visited[i] = true;
            backtracking(1, i+1, k);
            visited[i] = false;
        }
        
        cout<<'\n';
    }
}

