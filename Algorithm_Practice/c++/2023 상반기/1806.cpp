#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    vector<int> num;

    cin>>n>>s;

    num.assign(n, 0);
    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    int low = 0, high = 0, answer = 0;
    int tempSum = num[0];
    int tempLen = n+1;
    while(low<=high && high<n){
        if(tempSum>=s){ //���� ��
            tempLen = min(tempLen, high-low+1);
            //cout<<high<<" "<<low<<' '<<tempSum<<'\n';
            tempSum -= num[low];
            ++low;
        }
        else{ //tempSum�� s���� ������ high�� ������ ���Ҹ� �ϳ� �� ����.
            ++high;
            tempSum += num[high];
        }
    }

    //�κ������� s�̻��� ���� ���� �� ���� ���
    if(tempLen<n+1){
        answer = tempLen;
    }

    cout<<answer;

}