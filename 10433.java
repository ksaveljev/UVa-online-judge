import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        (new UVa10433()).solve();
    }
}

class UVa10433 {
    private final Scanner sc = new Scanner(System.in);
    private final BigInteger zero = new BigInteger("0");
    private final BigInteger one = new BigInteger("1");

    public void solve() {
        while (sc.hasNext()) {
            String input = sc.next();

            BigInteger n = new BigInteger(input);
            BigInteger n_squared = n.pow(2);

            String square = n_squared.toString();

            if (square.endsWith(input) && n.compareTo(zero) != 0 && n.compareTo(one) != 0) {
                System.out.println("Automorphic number of " + input.length() + "-digit.");
            } else {
                System.out.println("Not an Automorphic number.");
            }
        }
    }
}
