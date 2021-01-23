//백준 1463
//1로 만들기
// 나누기 3, 나누기 2, -1
//dp
import java.io.*;
public class p10 {

	private static int n;
	private static int dp[] = new int [1000000];
	private static int count;
	private static int func(int n) {
		
		while(n!=1) {
			if(n%3==0) {
				System.out.println("n: "+n);
				n= n/3;
				System.out.println("n/3: "+n);
			}
			else if(n%2==0) {
				System.out.println("n: "+n);
				n= n/2;
				System.out.println("n/2: "+n);
			}
			else {
				System.out.println("n: "+n);
				n= n-1;
				System.out.println("n-1: "+n);
			}
			count++;
		}
		return count;
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		count = 0;
		
		int answer = func(n);
		System.out.println(answer);
		
	}

}
