#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<int> num, res;
vector<bool> check;

int cal(int n){
    int result = 0;

    for(int i=0; i<n-1; i++){
        result += abs(res[i]-res[i+1]);
    }

    return result;
}

void dfs(int cnt, int n){

    // cout<<"cnt: "<<cnt<<" n: "<<n<<'\n';
    // for(int i=0; i<n; i++){
    //     cout<<res[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0; i<n; i++){
    //     cout<<check[i]<<' ';
    // }
    // cout<<'\n';


    if(cnt == n){
        answer = max(answer, cal(n));
        return;
    }

    for(int i=0; i<n; i++){
        if(check[i]){
            continue;
        }

        res[cnt] = num[i];
        check[i] = true;
        dfs(cnt+1, n);
        check[i] = false;
    }
}

int main(){
    int n;

    cin>>n;

    num.assign(n, 0);
    res.assign(n, 0);
    check.assign(n, false);
    
    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    //백트래킹
    //dfs(cnt) if(cnt==n){ 결과 계산, return}

    for(int i=0; i<n; i++){
        check[i] = true;
        res[0] = num[i];
        dfs(1, n);
        check[i] = false; 
    }

    cout<<answer;

}

/**
 * 쉽게 이해하기 위하여
 * 만약 입력이
 * 3
 * 20 1 15 이렇게라고 가정하면
 * 
 * 먼저 첫 번째로 위치할 숫자를 정해주고 check[0]에 체크를 한다.
 * k=0
 * 20
 * dfs 함수로 넘어간다. cnt=1, n=3
 *      for
 *      20은 체크가 되어있으므로(check[0]) 건너뛰고
 *      i=1
 *      체크가 되어있지 않은 1을 res[1]로 선택한다. check[1]에도 체크를 한다.
 *      다음 dfs 함수로 넘어간다. cnt=2, n=3
 *          for
 *          20, 1은 체크가 되어있으므로 건너뛰고
 *          j=2
 *          체크가 되어있지 않은 15를 res[2]로 선택한다. check[2]에도 체크를 한다.
 *          다음 dfs 함수로 넘어간다. cnt=3, n=3 (res={20,1,15})
 *              if문에 걸려서 answer를 계산(33)하고 이 dfs는 끝난다.
 *          check[j] = check[2] = false
 *          j<3이므로 for문이 끝난다.
 *      check[i] = check[1] = false
 *      i=2
 *      체크가 되어있지 않은 15를 res[1]로 선택한다. check[2]에도 체크를 한다.
 *      다음 dfs 함수로 넘어간다. cnt=2, n=3
 *          for
 *          20은 체크가 되어있으므로 건너뛰고
 *          j=1
 *          체크가 되어있지 않은 1을 res[2]로 선택한다. check[1]에도 체크를 한다.
 *          다음 dfs 함수로 넘어간다. cnt=3, n=3 (res={20,15,1})
 *              if문에 걸려서 answer를 계산(29<33, answer=33)하고 이 dfs는 끝난다.
 *          check[j] = check[1] = false
 *          j=2
 *          check[j] = check[2] = false
 *          j<3이므로 for문이 끝난다.
 *      check[i] = check[2] = false;
 *      i<3이므로 for문이 끝난다.
 * k=1
 * 첫 번째 숫자가 1로 바뀐다.
 * 동일한 흐름으로 진행된다.
 * {1,20,15}
 * {1,15,20}
 * k=2
 * 첫 번째 숫자가 15로 바뀐다.
 * 동일한 흐름으로 진행된다.
 * {15,1,20}
 * {15,20,1} 
*/