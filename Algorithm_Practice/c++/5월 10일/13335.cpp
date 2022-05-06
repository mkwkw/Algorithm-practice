#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, w, l;
    int weight=0, time=0; //���� �ٸ� ���� ����, ���� �ð� 
    queue<int> bridge; //�ٸ� ���� �ִ� Ʈ�� ����
    vector<int> trucks; //��� ���� Ʈ�� ����

    cin>>n>>w>>l;

    trucks.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>trucks[i];
    }

    for(int i=0; i<n; i++){
        while(true){
            if(bridge.size()==w){
                weight -= bridge.front();
                bridge.pop();
            }

            if(weight + trucks[i] <= l){
                break;
            }

            bridge.push(0); //Ʈ���� ���԰� l���� ũ�� ť�� 0�� ä���� ť�� ũ�Ⱑ ���� Ʈ���� ��ġ�� �ǵ��� �ϱ�
            time++;
        }

        bridge.push(trucks[i]); //��� ���̴� Ʈ�� ��
        weight += trucks[i];
        time++;
    }

    time += w; //������ Ʈ�� ������ �� �ɸ��� �ð�
    cout<<time;
}