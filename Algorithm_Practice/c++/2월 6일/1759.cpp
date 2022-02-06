#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE=15;

int l,c;
vector<pair<char, bool>> alpha;
vector<char> result(SIZE);

bool decide(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    return false;
}

void backtracking(int vcnt, int ccnt, int start){ 
    
    int cnt = vcnt+ccnt;

    //전체 길이, 모음 개수, 자음 개수 조건 만족하면 출력 후 다음으로 넘어감
    if(cnt==l && vcnt>=1 && ccnt>=2){
        for(int i=0; i<l; i++){
            cout<<result[i];
        }
        cout<<'\n';
        return;
    }

    //오름차순으로 나오므로 현재 인덱스를 받아서 다음에 돌릴 때에는 현재 인덱스+1해야함
    for(int i=start; i<c; i++){
        
        result[cnt] = alpha[i].first;
            
        if(alpha[i].second){ // 모음이면
             backtracking(vcnt+1, ccnt, i+1);
        }
        else{ //자음이면
            backtracking(vcnt, ccnt+1, i+1);
        }
           
    }
}

int main(){

    char ch;
    cin>>l>>c;

    for(int i=0; i<c; i++){
        cin>>ch;
        if(decide(ch)){ //모음이면 true, 자음이면 false
            alpha.push_back(make_pair(ch, true));
        }
        else{
            alpha.push_back(make_pair(ch, false));
        }
    }

    sort(alpha.begin(), alpha.end());

    backtracking(0,0,0);
}

//가능한 모든 경우의 수를 따져야한다.
//따라서 백트래킹을 사용해야한다.
//답이 될만한지 판단하고, 그렇지 않으면 탐색하지 않고 다시 전으로 넘어가서 탐색을 계속한다.
//오름차순으로 출력해야하므로 현재 인덱스를 받고 현재 인덱스+1 해서 백트래킹 함수를 작동한다.