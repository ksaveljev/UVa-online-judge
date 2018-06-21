import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        (new UVa10925()).solve();
    }
}

class UVa10925 {
    private final Scanner sc = new Scanner(System.in);
    private final BigInteger zero = new BigInteger("0");
    private final BigInteger one = new BigInteger("1");

    public void solve() {
	int n, f, counter = 0;;

        while (true) {
            counter++;
            n = sc.nextInt();
            f = sc.nextInt();

            if (n == 0 && f == 0) break;

            BigInteger sum = zero;
            for (int i = 0; i < n; i++) {
                String input = sc.next();
                BigInteger p = new BigInteger(input);
                sum = sum.add(p);
            }

            BigInteger result = sum.divide(BigInteger.valueOf(f));
            System.out.println("Bill #" + counter + " costs " + sum + ": each friend should pay " + result);
            System.out.println();
        }
    }
}
