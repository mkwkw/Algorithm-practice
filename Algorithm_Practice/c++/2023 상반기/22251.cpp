#include <iostream>
#include <vector>
#include <string>

using namespace std;

//��� Ǯ������� ���� �ȿͼ�
//https://www.acmicpc.net/problem/22251 ����
//�ٽ� Ǯ���!

int change(vector<vector<bool>> &light, int n, int k, int p, int x){
    int res = 0;
    for(int i=1; i<=n; i++){ //1~n������ x�� ���� ��� Ȯ��
        if(i==x){
            continue;
        }
        int cnt = 0;
        int from = x, to = i; //����: x��, �ٲ� ��: i��
        for(int j=0; j<k; j++){//�� �ڸ��� ��
            for(int z=0; z<7; z++){
                if(light[from%10][z]!=light[to%10][z]){//���� �ڸ��� ��
                    cnt++;
                }
            }
            //�� �ڸ��� ���̱�
            from /= 10;
            to /= 10;
        }
        if(cnt<=p){
            res++;
        }
    }

    return res;

}

int main(){
    int n, k, p, x, answer = 0;
    cin>>n>>k>>p>>x;

    vector<vector<bool>> light;
    light.assign(10, vector<bool>(7, true));

    light[0]={true, true, true, false, true, true, true};
    light[1]={false, false, true, false, false, true, false};
    light[2]={true, false, true, true, true, false, true};
    light[3]={true, false, true, true, false, true, true};
    light[4]={false, true, true, true, false, true, false};
    light[5]={true, true, false, true, false, true, true};
    light[6]={true, true, false, true, true, true, true};
    light[7]={true, false, true, false, false, true, false};
    light[8]={true, true, true, true, true, true, true};
    light[9]={true, true, true, true, false, true, true};

    answer = change(light, n, k, p, x);

    cout<<answer;

}