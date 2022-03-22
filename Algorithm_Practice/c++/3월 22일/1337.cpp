#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinCnt(vector<int> &v, int n){
    int cnt=0, min_cnt=5, left, right;
    vector<int> five(4); //v[i] ���� ���ӵ� ���� 4�� ������ �迭
    sort(v.begin(), v.end()); //�������� ����

    //�� ������ - left�� v[i] ����Ű��, right�� �� �� v[n-1] ����Ű�� �� ����
    //v[right]�� 5���� ���� ���� �� ���� ū �ͺ��� ũ�� left�� right���� ���� ���� right ���̱�
    //�̷��� �ϸ� 5���� ���ڿ� �ش��ϴ� ���ڵ鸸 left~right ������ ���´�.
    //v = {5, 7, 9, 8492, 8493, 192398} �̸� left�� 0�� ��, right�� 2 ��, v[right]=9�� ����Ų��.
    for(int i=0; i<n; i++){
        left = i;
        right = n-1;

        for(int j=1; j<5; j++){
            five[j]=v[i]+j;
        }

        while(v[right]>five[4] && left<right){
            right--;
        }

        cnt = right-left+1;
        
        //�ּ��� �ʿ��� ���� ���� �Ǻ�
        if(min_cnt>(5-cnt)){
            min_cnt=5-cnt;
        }
    }

    return min_cnt;
}

int main(){
    vector<int> v; //�Է� ���� ��
    int n, answer; //�� ������ ���
    
    cin>>n;

    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];    
    }   

    answer = findMinCnt(v, n);

    cout<<answer;
}