#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> tips;
    int n;
    long long answer = 0; //n=10^5 �̰� �� ���� 10^5 �� ��, int ���� �ʰ�
    cin>>n;

    tips.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>tips[i];
    }

    sort(tips.begin(), tips.end(), greater<int>());

    for(int i=0; i<n; i++){
        int tip = tips[i]-i;
        if(tip<0){ //������ ��� 0���� ó��
            tip=0;
        }
        answer += tip;
    }

    cout<<answer;

}