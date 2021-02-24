//19597
//6번
//틀렸습니다
import java.io.*;
public class p44 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()); //테스트 개수
		
		int n = 2;
		char st[][] = new char[200][];
		char arr[][] = new char[200][200];
		
		
		
		
		for(int i=0; i<t; i++) {
			
			n = Integer.parseInt(br.readLine()); //문자열 개수
//			st = new char [n][]; //문자열 담을 배열
//			arr = new char[t][n];
			
			for(int j=0; j<n; j++) {
				arr[i][j]='0';
			}
			
			for(int j=0; j<n; j++) {
				st[j] = br.readLine().toCharArray();
			}
			
			for(int j=0; j<n-1; j++) {
				if(st[j][0]>st[j+1][0])
					arr[i][j+1]='1';
					
			}
			
			
			
			
		}
		for(int i=0; i<t; i++) {
			for(int j=0; j<n; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
	}

}
