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
 *
 * In order to speed up Catalan number calculation
 * we find a pattern for calculating current Catalan
 * number using previous one (it is very slow to
 * simply precalculate 1000 answers by using the
 * formula above)
 *
 *      (2 * (N + 1))!
 *  --------------------------- =
 *  ((N + 1) + 1)! * (N + 1)!
 *
 *       (2N + 2) * (2N + 1) * 2N!
 *  ---------------------------------- =
 *  (N + 1) * (N + 2) * N! * (N + 1)!
 *
 *  (2N + 2) * (2N + 1)
 *  ------------------- * CATALAN(N)
 *   (N + 1) * (N + 2)
 */

class Main
{
    BigDecimal fact[] = new BigDecimal[2001];
    BigDecimal result[] = new BigDecimal[1001];

    void precalc_factorial()
    {
        fact[0] = new BigDecimal(1);
        fact[1] = new BigDecimal(1);

        for (int i = 2; i < 2001; i++) {
            fact[i] = fact[i-1].multiply(new BigDecimal(i));
        }
    }

    void precalc()
    {
        precalc_factorial();

        result[1] = new BigDecimal(1);

        for (int i = 2; i < 1001; i++) {
            result[i] = result[i-1].multiply(new BigDecimal((2*(i-1)+2)*(2*(i-1)+1))).divide(new BigDecimal(((i-1)+1)*((i-1)+2)));
        }
    }

    void solve()
    {
        precalc();

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        while (in.hasNextInt()) {
            int n = in.nextInt();

            System.out.println(result[n]);
        }
    }

    public static void main(String args[])
    {
        Main problem = new Main();
        problem.solve();
    }
}
