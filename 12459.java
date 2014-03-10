import java.util.Scanner;
import java.math.*;

class Main {
    public static void main(String[] args) {
        (new UVa12459()).solve();
    }
}

class UVa12459 {
    final private Scanner sc = new Scanner(System.in);

    public void solve() {
        int n;

        while (true) {
            n = sc.nextInt();
            if (n == 0) break;

            BigInteger males = BigInteger.ZERO;
            BigInteger females = BigInteger.ONE;

            for (int i = 1; i < n; i++) {
                BigInteger m = females.add(BigInteger.ZERO);
                BigInteger f = males.add(females);

                males = m;
                females = f;
            }

            System.out.println(males.add(females));
        }
    }
}
