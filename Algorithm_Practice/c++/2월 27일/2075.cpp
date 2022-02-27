#include <iostream>
#include <queue>

using namespace std;

int main(){

    //������ �ð��ʰ� �߻�
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<>> pq; //�������� ���� - pop���� �� ���� ���� �� ��������
    int n, answer;
    cin>>n;

    for(int i=0; i<n*n; i++){
        int num;
        cin>>num;
        pq.push(num);

        if(pq.size()>n){
            pq.pop();
        }
    }

    answer = pq.top();

    cout<<answer;

}

//�ð��ʰ� ����!
//�޸� ������ �ſ� �����Ƿ� pq�� n���� ���� ������ �Ѵ�.(pop�� �ݺ��Ѵ�)
//pq�� �������� ������ �ǵ��� �����Ͽ� pq�� front�� ���� ���� ���� ������ �Ѵ�.
//���� ���������� pq�� front�� n��° ū ���� ��ġ�ϰ� �ȴ�.