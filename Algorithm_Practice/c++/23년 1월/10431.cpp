#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int t, tc, height, cnt;
    
    cin>>t;

    for(int i=0; i<t; i++){
        cnt=0;
        vector<int> heights(20);
        
        cin>>tc;
        for(int j=0; j<20; j++){
            cin>>heights[j];
        }

        for(int j=0; j<20; j++){
            for(int k=0; k<j; k++){
                if(heights[k]>heights[j]){
                    cnt++;
                }
            }
        }
    
        cout<<tc<<' '<<cnt<<'\n';
    }

}

//����
//1. �������������� �ʿ��� �� ���Ƽ� set�� ����Ͽ� �л����� Ű�� �ְ� Ű �Է��� ���� ������ ũ�� ���Ͽ� ��� ���� - Ʋ�Ƚ��ϴ�. & �ʹ� ����
//2. �����غ��� ���Ϳ� �ְ� �ڽ��� �տ� �ִ� ���� �߿� �ڽź��� ���� ���� �� ���� ���� ���ϸ� ��. 