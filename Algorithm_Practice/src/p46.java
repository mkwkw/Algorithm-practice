//C번
import java.io.*;
import java.util.*;
public class p46 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String brr[] = br.readLine().split(" ");
		int N = Integer.parseInt(brr[0]);
		int K = Integer.parseInt(brr[1]);
		double p[] = new double [N];
		double sum=0;
		double max = 0;
		brr = br.readLine().split(" ");
		for(int i=0; i<N; i++) {
			p[i] = 1-Double.parseDouble(brr[i]);
		}
		
		
		
		double mul = 1;
		for(int i=0; i<N; i++) {
			mul = mul*(p[i]);
			sum += mul;
				
		}
			
		if(K==1) {
			System.out.println(sum);
			System.exit(0);
		}
		else
			max = sum;
		
		int a[] = new int [K-1]; //자르는 부분 나타내는 배열
		double pm[] = new double [K]; //잘린 부분 합 나타내는 배열
		
		for(int i=0; i<K-1; i++) {
			a[i] = i;
		}
		//ex. K=2
		//a[0]=0;
		//a[1]=1;
		
		//K가 1이 아닌 경우 -> 어디서 끊을 것인가
		sum=0;
		int count = 0;
		int count1 = 0;
		for(int i=0; i<K-1; i++) {
			mul=1;
			for(int j=count1; j<a[i]; j++) {
				mul = mul*p[j];
				sum += mul;
				count++;
				System.out.println(sum);
				
				pm[i] += sum;
			}
			count1 = count;
		}
		mul=1;
		for(int j=a[K-2]; j<N; j++) {
			mul = mul*p[j];;
			sum += mul;
			System.out.println(sum);
			pm[K-1] += sum;
		}
		
		double result = 0;
		
		for(int i=0; i<K; i++) {
			System.out.println(pm[i]);
			result += pm[i];
		}
		
		if(result>max)
			max = result;
		System.out.println(max);

	}

}
