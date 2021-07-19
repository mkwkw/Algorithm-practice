#include <iostream>
//2021 scpc 만점 80점 통과 수행시간 0.48347초 
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N;
	int num[100001];
	int idx[100001];
	int chk[100001];
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 1;
	    
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin>>N;
		
		
		for(int i=0; i<N; i++){
		    cin>>num[i];
		    idx[i]=i+1;
			chk[i]=0;
		}
		
		int i,j,k;
		int m=1;
		for(i=0; i<N; i++){
		    chk[i]=m;
		    
		    if(idx[i]+num[i]<=N) chk[idx[i]+num[i]]=min(chk[i],chk[idx[i]+num[i]]);
		    
		    else m++;
		}
		
		for(int i=1; i<N; i++){
		    if(chk[i-1]!=chk[i]) Answer++;
		}
		
		/*for(int i=0; i<N; i++){
			cout<<"IDX"<<idx[i]<<endl;
			cout<<"NUM"<<num[i]<<endl;
			cout<<"CHK"<<chk[i]<<endl;
		}*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
