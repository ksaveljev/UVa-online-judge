import java.io.*;
import java.util.*;
import java.math.*;

/*
 *  http://en.wikipedia.org/wiki/Catalan_number
 *
 */

class Main
{
    BigDecimal fact[] = new BigDecimal[21];
    BigDecimal result[] = new BigDecimal[11];

    void precalc_factorial()
    {
        fact[0] = new BigDecimal(1);
        fact[1] = new BigDecimal(1);

        for (int i = 2; i < 21; i++) {
            fact[i] = fact[i-1].multiply(new BigDecimal(i));
        }
    }

    void precalc()
    {
        precalc_factorial();

        for (int i = 1; i < 11; i++) {
            result[i] = fact[2*i].divide(fact[i+1].multiply(fact[i]));
        }
    }

    void solve()
    {
        precalc();

        boolean first = true;
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        while (in.hasNextInt()) {
            int n = in.nextInt();

            if (!first)
                System.out.println();

            first = false;

            System.out.println(result[n]);
        }
    }

    public static void main(String args[])
    {
        Main problem = new Main();
        problem.solve();
    }
}
