#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	vector<pair<int,int>> jewels; //���Դ� ����, ����
	int w, n, curW=0, answer = 0;
	cin>>w>>n;

	jewels.assign(n, {0,0});

	for(int i=0; i<n; i++){
		cin>>jewels[i].second>>jewels[i].first;
	}

	sort(jewels.begin(), jewels.end(), greater<>());

	for(int i=0; i<n; i++){
		if(jewels[i].second<=w-curW){ //�ݼ� ����� �� ���� �״�� �ֱ�
			curW += jewels[i].second;
			answer += jewels[i].second*jewels[i].first;
		}
		else{ //�ݼ� ����� �� �ȵ��� ���̸�ŭ �߶� �ֱ�
			answer += (w-curW)*jewels[i].first;
			curW = w;
		}
		if(curW==w){
			break;
		}
	}

	cout<<answer;

	return 0;
}