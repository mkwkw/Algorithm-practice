//백준 1018
//체스판 다시 칠하기
//WB연속 or BW연속

import java.io.*;
public class p4 {
	private static String chess [][];
	private static int n;
	private static int m;
	private static int count;
	
	private static int func(int i, int j) {
		count=0;
		int ii = i%2;
		int jj = j%2;
		
		
		if(chess[i][j].equals("W")) {
			for(int a=i; a<i+8; a++) {
				
				for(int b=j; b<j+8; b++) {
					if(a%2==ii && b%2==jj && !chess[a][b].equals("W"))
						count++;
					else if(((a%2==ii && b%2!=jj)||(a%2!=ii && b%2==jj)) && !chess[a][b].equals("B"))
						count++;
					else if(a%2!=ii && b%2!=jj && !chess[a][b].equals("W"))
						count++;
					else
						continue;
					
				}
			}
		}
		
		else {
			for(int a=i; a<i+8; a++) {
				
				for(int b=j; b<j+8; b++) {
					if(a%2==i%2 && b%2==j%2 && !chess[a][b].equals("B"))
						count++;
					else if(((a%2==ii && b%2!=jj)||(a%2!=ii && b%2==jj)) && !chess[a][b].equals("W"))
						count++;
					else if(a%2!=i%2 && b%2!=j%2 && !chess[a][b].equals("B"))
						count++;
					else
						continue;
					
				}
			}
		}
		return count;
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String arr[] = br.readLine().split(" ");
		n = Integer.parseInt(arr[0]);
		m = Integer.parseInt(arr[1]);
		chess = new String[n][m];
		
		for(int i=0; i<n; i++) {
			chess[i] = br.readLine().split("");
		}
		
		int smallest = 2500;
		int f = 0;
		
		for(int i=0; i<n-7; i++) {
			
			for(int j=0; j<m-7; j++) {
				f = func(i,j);
				
				if(smallest>f)
					smallest=f;
			}
		}
		
		System.out.println(smallest);

	}

}
