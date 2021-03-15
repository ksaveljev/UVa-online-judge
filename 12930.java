import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
    BigDecimal fact[] = new BigDecimal[601];
    BigDecimal result[] = new BigDecimal[301];

    void solve()
    {
        int tc = 0;
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        while (in.hasNext()) {
            tc++;
            String a = in.next();
            String b = in.next();

            BigDecimal bda = new BigDecimal(a);
            BigDecimal bdb = new BigDecimal(b);

            int result = bda.compareTo(bdb);

            System.out.print("Case " + tc + ": ");
            if (result == 1) {
                System.out.println("Bigger");
            } else if (result == -1) {
                System.out.println("Smaller");
            } else {
                System.out.println("Same");
            }
        }
    }

    public static void main(String args[])
    {
        Main problem = new Main();
        problem.solve();
    }
}
