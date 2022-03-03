#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> ti; //������, ������, ���
const int INF = 1e6*5;

//����-����: ���� ����ġ ��� ������ ���ͽ�Ʈ��� ����� ��
vector<ll> bellmanFord(int n, int m, int start, vector<ti> &edges){
    //��� �÷ο�: 500*6000*(-10000) : int ���� �����Ƿ� long long ���
    vector<ll> dist(n+1,INF); //��� ���� INF�� �ʱ�ȭ (���������� k�������� ���� ���� dist[k])

    dist[start]=0; //������ 0���� �ʱ�ȭ

    for(int i=1; i<=n; i++){ //���� ��ȸ
        bool flag = true; //�� �̻� �ݺ����� ������ �ʿ䰡 ������ Ȯ��: true�̸� ����x, false�̸� ����o
        for(int j=0; j<m; j++){ //���� ��ȸ
            //s���� d�� ���� ������ ����ġ w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if(dist[s] == INF){ //���� ���������� s�� ���� ��ΰ� �߰ߵ��� �ʾ����Ƿ� ����x
                continue;
            }

            ll next_weight = dist[s]+w; //s������ ����ġ + s���� d������ ����ġ = ���� ����� s�������� d�� ���� ����ġ
            if(dist[d]>next_weight){ // �� ª�� ��η� �� �� �ִٸ�
                if(i==n){ //n��° �����̾��ٸ� ���� ����Ŭ�� �߻��� �� (����Ŭ�� �߻����� �ʴ� ��쿡�� �ִ� n-1��° ���ű��� �Ͼ)
                    return {INF+1}; //���� ��ü ���� INF+1�� �ٲ�
                }

                dist[d] = next_weight; //���� ����Ŭ�� �ƴ� ���, ���������� d���� ���� ����ġ ����
                flag=false;
            }
        }

        if(flag){
            break;
        }
    }
    return dist; 
}

int main(){
    int n,m,a,b,c;

    cin>>n>>m;
    
    vector<ti> edges(m); //���� ���� ������ ����

    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        edges[i]={a,b,c}; //������, ������, ����ġ ���� edges ���Ϳ� tuple ���·� ����
    }

    vector<ll> ans = bellmanFord(n,m,1,edges); //������:1

    if(ans[0]==INF+1){ //���� ����Ŭ�� �߻��� ��� -1 ���
        cout<<-1;
        return 0;
    }

    for(int i=2; i<=n; i++){ //ans[1]�� ������->�������̹Ƿ� ����, ans[i]==INF�� ���ŵ��� �ʾҴٴ� �� == �ش絵�÷� ���� ��ΰ� ���ٴ� �� : -1 ���
        cout<<((ans[i]==INF)? -1 : ans[i])<<'\n';
    }
}