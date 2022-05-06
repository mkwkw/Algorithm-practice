#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int main(){
    int n;
    string word;
    
    cin>>word;

    n = word.length();

    vector<vector<string>> flip(n);

    flip[0].push_back(word); //1만큼 뒤집든 아니든
    for(int i=1; i<n; i++){ //flip[i]에 i+1만큼 뒤집든 아니든 한 것 넣음.
        for(int j=0; j<flip[i-1].size(); j++){
            flip[i].push_back(flip[i-1][j]); // 안 뒤집음

            for(int k=0; k<(i+1)/2; k++){
                swap(flip[i-1][j][k], flip[i-1][j][i-k]);
                flip[i].push_back(flip[i-1][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<flip[i].size(); j++){
            if(word>flip[i][j]){
                word = flip[i][j];
            }
        }
    }

    cout<<word;
}

//메모리 초과
*/
int main()
{
	string word, temp;
	int len, i;

	cin >> word;
	len = word.length();

	temp.push_back(word[0]);
	for (i = 1; i < len; i++){

        //temp의 맨 앞글자가 word[i]보다 크면 뒤집기
		if (temp[0] >= word[i]){
			reverse(temp.begin(), temp.end()); //뒤집어주는 라이브러리
			temp.push_back(word[i]); //word[i] 넣고
			reverse(temp.begin(), temp.end()); //다시 뒤집기
		}
         //temp의 맨 앞글자가 word[i]보다 크지 않으면 뒤집기 안하고 word[i] 넣기
		else{
			temp.push_back(word[i]);
		}
	}

	cout << temp;

}