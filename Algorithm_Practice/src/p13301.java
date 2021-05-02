import java.io.*;
public class p13301 {
	
//	public static int fib(int n)
//	{
//		if(n==0)
//			return 1;
//		else if(n==1)
//			return 1;
//		else
//			return fib(n-1)+fib(n-2);
//	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
	
		int l1 = 4;
		int l2 = 6;
		
		int temp=0;
		for(int i=3; i<=n; i++) {
			temp = l1+l2;
			l1 = l2;
			l2 = temp;
		}
		
		System.out.println(temp);
//		int width[] = new int [100];
//		int height[] = new int [100];
//		
//		width[1] = fib(0);
//		height[1] = fib(0);
//		
//		width[2] = width[1];
//		height[2] = height[1]+fib(1); //2
//		
//		width[3] = width[2]+fib(2);
//		height[3] = height[2];
//		
//		width[4] = width[3];
//		height[4] = height[3]+fib(3);
//	
//		for(int i=5; i<=n; i++) {
//			if(n%2==0) {
//				width[i] = width[i-1];
//				height[i] = height[i-1]+fib(i-1);
//			}
//			else {
//				width[i] = width[i-1]+fib(i-1);
//				height[i] = height[i-1];
//			}
//				
//		}
//		
//		int result = 2*width[n]+2*height[n];
//		System.out.println(result);
		
	}

}
