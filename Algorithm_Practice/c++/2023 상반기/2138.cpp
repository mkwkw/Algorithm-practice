#include <iostream>

using namespace std;

//string���� char �̿��ϴ� ���� �ξ� ����!
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

    //ù ��° ����ġ�� ������ ��� / ������ �ʴ� ��� ��� -> ù ��° ����ġ�� �������� ���ΰ� �������ִٸ�, ù ��° ������ ���¸� �����ϴ� ����ġ�� �� ��° ����ġ�� �ȴ�.
    //i��° ������ ���¸� �����ϴ� ���� i+1��° ����ġ

    //ù ��° ����ġ�� ������ ���
    bool flag1 = false;
    string firstO = pushSwitch(originalNum, 0);
    int cnt1 = 1;
    for(int i=0; i<n-1; i++){ //�տ������� ���� Ž��, i��° ���� & i+1��° ����ġ
        if(firstO[i]!=answerNum[i]){
            firstO = pushSwitch(firstO, i+1);
            cnt1++;
        } 
    }

    //ù ��° ����ġ�� ������ �ʴ� ���
    bool flag2 = false;
    string firstX = originalNum;
    int cnt2 = 0;
    for(int i=0; i<n-1; i++){ //�տ������� ���� Ž��, i��° ���� & i+1��° ����ġ
        if(firstX[i]!=answerNum[i]){
            firstX = pushSwitch(firstX, i+1);
            cnt2++;            
        } 
    }

    //����ġ ���� ����� ����� ������ ����
    if(answerNum[n-1] == firstO[n-1]){
        flag1 = true;
    }

    if(answerNum[n-1] == firstX[n-1]){
        flag2 = true;
    }
    
    int cnt = 0;
    //��� ��
    //�� �� ����� ���� ���
    if(flag1 && flag2){
        cnt = min(cnt1, cnt2);
    }
    //�ϳ��� ����� ���� ���
    else if(flag1 && !flag2){
        cnt = cnt1;
    }
    else if(!flag1 && flag2){
        cnt = cnt2;
    }
    //�� �� ����� �ٸ� ���
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