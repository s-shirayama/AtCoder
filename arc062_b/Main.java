import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int g = 0;
		int p = 0;
		int res = 0;
		String str = sc.next();
		for (int i = 0; i < str.length(); i++) {
			if (g > p) {
				p++;
				if (str.charAt(i) == 'g') res++;
			} else {
				g++;
				if (str.charAt(i) == 'p') res--;
			}
		}
		System.out.println(res);
	}
}