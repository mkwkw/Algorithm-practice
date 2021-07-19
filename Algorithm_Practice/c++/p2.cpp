/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/
//scpc 2번 해결 못 함
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char Answer;

int main()
{
	int T, test_case;
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
        int n,t;
        char N[50001]="";
        char A[50001]="";
        string Answer="";
		
		/////////////////////////////////////////////////////////////////////////////////////////////
	    cin>>n>>t;
	    scanf("%s", &N);
	    
	    int size=0;
	    for(int i=0; N[i]!='\0'; i++){
	        size++;
	    }
	    
	    for(int i=0; i<t; i++){
	        if(N[i]=='0') A[i+t]='0';
	        else A[i+t]='1';
	    }
	     for(int i=n-t; i<n; i++){
	        if(N[i]=='0') A[i-t]='0';
	        else A[i-t]='1';
	    }
	    
	    for(int i=t; i<n-t; i++){
	        if(N[i]=='0'){ 
				A[i+t]='0';
			 	A[i-t]='0';
			}
	        else{
				if(A[i-t]=='0') A[i+t]='1';
				else A[i+t]='0';
				 
	            if(A[i+t]=='0') A[i-t]='1';
	        	else A[i-t]='0';
				 
	        	//if(A[i-t]=='\0'&& A[i+t]=='\0') {N[i+t]='1'; A[i-t]='0';
				//}
	            
	        }
	    }
	     Answer = A;
	   
		/////////////////////////////////////////////////////////////////////////////////////////////
	   
	    
	    /*for(int i=0; i<n; i++){
	    	cout<<"A: ";
			cout<<A[i]<<" ";
		}*/
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
