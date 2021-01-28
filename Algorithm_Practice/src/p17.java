//���� 3079
//�Ա��ɻ�
//�̺�Ž��
import java.util.*;
public class p17 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong(); //�Ա��ɻ�� ����
		long m = sc.nextLong(); //��� �ο� ��
		
		long t[] = new long [100005]; //�� �Ա��ɻ���� �ҿ�ð�
		t[0]=0;
		for(int i=1; i<=n; i++) {
			t[i] = sc.nextLong();
		}
		long answer = 0;
		long high = (long)Math.pow(10, 18);
		long low = 1;
		long mid = 0;
		while(high>=low) {
			mid = (high+low)/2;
			long sum = 0;
			for(int i=1; i<=n; i++) {
				sum += mid/t[i];
				if(sum>=m)
					break;
			}
			if(sum>=m) {
				answer = mid;
				high = mid-1;
				
			}
			else {
				low = mid+1;
			}
		}
		System.out.println(answer);
		
		sc.close();
	}

}
