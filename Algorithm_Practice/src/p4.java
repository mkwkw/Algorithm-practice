//백준 1018
//체스판 다시 칠하기
//WB연속 or BW연속

import java.io.*;
public class p4 {
	private static String chess [][];
	private static int n;
	private static int m;
	private static int count=0, count1, count2;
	
	private static int func(int i, int j) {
		
		count1=0;
		count2=0;
		int ii = i%2;
		int jj = j%2;
		
		
		
			for(int a=i; a<i+8; a++) {
				
				for(int b=j; b<j+8; b++) {
					if(a%2==ii && b%2==jj && !chess[a][b].equals("W"))
						count1++;
					else if(((a%2==ii && b%2!=jj)||(a%2!=ii && b%2==jj)) && !chess[a][b].equals("B"))
						count1++;
					else if(a%2!=ii && b%2!=jj && !chess[a][b].equals("W"))
						count1++;
					else
						continue;
					
				}
			}
		
		
		
			for(int a=i; a<i+8; a++) {
				
				for(int b=j; b<j+8; b++) {
					if(a%2==i%2 && b%2==j%2 && !chess[a][b].equals("B"))
						count2++;
					else if(((a%2==ii && b%2!=jj)||(a%2!=ii && b%2==jj)) && !chess[a][b].equals("W"))
						count2++;
					else if(a%2!=i%2 && b%2!=j%2 && !chess[a][b].equals("B"))
						count2++;
					else
						continue;
					
				}
			
			}
			
		//System.out.println("count1: "+count1);
		//System.out.println("count2: "+count2);
		if(count1>count2)
			count = count2;
		else
			count = count1;
			//count=count1;
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
