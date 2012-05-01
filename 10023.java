import java.util.Scanner;
import java.math.*;

class Main {
    public static void main(String[] args) {
        (new UVa10023()).solve();
    }
}

class UVa10023 {
    final private Scanner sc = new Scanner(System.in);

    public void solve() {
        int n;
        String input;

        n = sc.nextInt();

        while (n > 0) {
            n--;
            BigInteger num = sc.nextBigInteger();

            System.out.println(SqRtN(num));
            if (n > 0)
                System.out.println();
        }
    }

    /* 
     * Newton-Raphson
     *
     * stolen from the internetz
     */
    BigInteger SqRtN(BigInteger N)
    {
        BigInteger G = new BigInteger((N.shiftRight((N.bitLength() + 1) / 2)).toString());
        BigInteger LastG = null;
        BigInteger One = new BigInteger("1");

        if (N.compareTo(One) == 0)
            return One;

        while (true)
        {
            LastG = G;
            G = N.divide(G).add(G).shiftRight(1);
            int i = G.compareTo(LastG);
            if (i == 0) return G;
            if (i < 0)
            {
                if (LastG.subtract(G).compareTo(One) == 0)
                    if (G.multiply(G).compareTo(N) < 0 && LastG.multiply(LastG).compareTo(N) > 0) return G;
            }
            else
            {
                if (G.subtract(LastG).compareTo(One) == 0)
                    if (LastG.multiply(LastG).compareTo(N) < 0 && G.multiply(G).compareTo(N) > 0) return LastG;
            }
        }
    }
}
