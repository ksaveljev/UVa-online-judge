import java.io.*;
import java.util.*;
import java.math.*;

/*
 * Number of binary trees which has N elements:
 *
 *      (2N)!
 * ---------------
 *  (N + 1)! * N!
 *
 *  http://en.wikipedia.org/wiki/Catalan_number
 *
 * The problem asks us to calculate the number
 * of binary trees which has N elements times
 * number of permutations of N
 *
 */

class Main
{
    BigDecimal fact[] = new BigDecimal[601];
    BigDecimal result[] = new BigDecimal[301];

    void precalc_factorial()
    {
        fact[0] = new BigDecimal(1);
        fact[1] = new BigDecimal(1);

        for (int i = 2; i < 601; i++) {
            fact[i] = fact[i-1].multiply(new BigDecimal(i));
        }
    }

    void precalc()
    {
        precalc_factorial();

        for (int i = 1; i < 301; i++) {
            result[i] = fact[2*i].divide(fact[i+1]);
        }
    }

    void solve()
    {
        precalc();

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        while (true) {
            int n = in.nextInt();

            if (n == 0)
                break;

            System.out.println(result[n]);
        }
    }

    public static void main(String args[])
    {
        Main problem = new Main();
        problem.solve();
    }
}
