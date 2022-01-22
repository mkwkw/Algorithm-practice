#include <iostream>
#include <vector>

using namespace std;


int coin(vector<int> &v, int k, int idx){
    int cnt=0; //���� ����
    
    for(int i=idx; i>=0; i--){
        if(k==0){ //break ����
            break;
        }

        if(v[i]>k){
            continue;
        }

        cnt += k/v[i]; //��
        k %= v[i]; //������
    }
    return cnt;
}

int main(){
    int n, k, answer;
    vector<int> v;

    cin>>n>>k;

    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    answer = coin(v, k, n-1);

    cout<<answer;
}

//��� ������ �̿�