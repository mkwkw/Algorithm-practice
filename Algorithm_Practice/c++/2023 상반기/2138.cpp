#include <iostream>

using namespace std;

//string보다 char 이용하는 것이 훨씬 빠름!
char changeNum(char c){

    if(c=='0'){
        return '1';
    }
    
    return '0';
    
}

string pushSwitch(string originalNum, int idx){

    if(idx==0){
        originalNum[0] = changeNum(originalNum[0]);
        originalNum[1] = changeNum(originalNum[1]);
    }
    else{
        originalNum[idx-1] = changeNum(originalNum[idx-1]);
        originalNum[idx] = changeNum(originalNum[idx]);
        originalNum[idx+1] = changeNum(originalNum[idx+1]);
    }

    return originalNum;
}

int countNum(string &originalNum, string &answerNum, int n){

    //첫 번째 스위치를 누르는 경우 / 누르지 않는 경우 고려 -> 첫 번째 스위치를 누르는지 여부가 정해져있다면, 첫 번째 전구의 상태를 결정하는 스위치는 두 번째 스위치가 된다.
    //i번째 전구의 상태를 결정하는 것은 i+1번째 스위치

    //첫 번째 스위치를 누르는 경우
    bool flag1 = false;
    string firstO = pushSwitch(originalNum, 0);
    int cnt1 = 1;
    for(int i=0; i<n-1; i++){ //앞에서부터 전구 탐색, i번째 전구 & i+1번째 스위치
        if(firstO[i]!=answerNum[i]){
            firstO = pushSwitch(firstO, i+1);
            cnt1++;
        } 
    }

    //첫 번째 스위치를 누르지 않는 경우
    bool flag2 = false;
    string firstX = originalNum;
    int cnt2 = 0;
    for(int i=0; i<n-1; i++){ //앞에서부터 전구 탐색, i번째 전구 & i+1번째 스위치
        if(firstX[i]!=answerNum[i]){
            firstX = pushSwitch(firstX, i+1);
            cnt2++;            
        } 
    }

    //스위치 누른 결과가 정답과 같은지 여부
    if(answerNum[n-1] == firstO[n-1]){
        flag1 = true;
    }

    if(answerNum[n-1] == firstX[n-1]){
        flag2 = true;
    }
    
    int cnt = 0;
    //결과 비교
    //둘 다 정답과 같은 경우
    if(flag1 && flag2){
        cnt = min(cnt1, cnt2);
    }
    //하나만 정답과 같은 경우
    else if(flag1 && !flag2){
        cnt = cnt1;
    }
    else if(!flag1 && flag2){
        cnt = cnt2;
    }
    //둘 다 정답과 다른 경우
    else{
        cnt = -1;
    }

    return cnt;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, answer;
    string originalNum, answerNum;

    cin>>n>>originalNum>>answerNum;

    answer = countNum(originalNum, answerNum, n);

    cout<<answer;
}