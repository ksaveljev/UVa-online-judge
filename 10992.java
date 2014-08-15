import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        (new UVa10992()).solve();
    }
}

class UVa10992 {
    private final Scanner sc = new Scanner(System.in);
    private final BigInteger start = new BigInteger("2148");
    private final BigInteger two = new BigInteger("2");
    private final BigInteger four = new BigInteger("4");
    private final BigInteger five = new BigInteger("5");
    private final BigInteger seven = new BigInteger("7");
    private final BigInteger eleven = new BigInteger("11");
    private final BigInteger fifteen = new BigInteger("15");
    private final BigInteger twenty = new BigInteger("20");
    private final BigInteger twentyeight = new BigInteger("28");
    private final BigInteger thirtysix = new BigInteger("36");
    private final BigInteger hundred = new BigInteger("100");
    private final BigInteger fourhundred = new BigInteger("400");

    private void checkGhost(String ghostName, BigInteger diff, BigInteger nYear, List<String> ghosts) {
        if (diff.remainder(nYear).compareTo(BigInteger.ZERO) == 0) {
            ghosts.add(ghostName);
        }
    }

    private boolean isLeapYear(BigInteger year) {
        if (year.remainder(fourhundred).compareTo(BigInteger.ZERO) == 0) return true;
        if (year.remainder(hundred).compareTo(BigInteger.ZERO) == 0) return false;
        if (year.remainder(four).compareTo(BigInteger.ZERO) == 0) return true;

        return false;
    }

    private List<String> ghostVisitsIn(BigInteger year) {
        List<String> ghosts = new ArrayList<String>();

        if (year.compareTo(start) == -1) return ghosts;

        BigInteger diff = year.subtract(start);

        checkGhost("Tanveer Ahsan", diff, two, ghosts);
        checkGhost("Shahriar Manzoor", diff, five, ghosts);
        checkGhost("Adrian Kugel", diff, seven, ghosts);
        checkGhost("Anton Maydell", diff, eleven, ghosts);
        checkGhost("Derek Kisman", diff, fifteen, ghosts);
        checkGhost("Rezaul Alam Chowdhury", diff, twenty, ghosts);
        checkGhost("Jimmy Mardell", diff, twentyeight, ghosts);
        checkGhost("Monirul Hasan", diff, thirtysix, ghosts);
        
        if (isLeapYear(year)) ghosts.add("K. M. Iftekhar");

        return ghosts;
    }

    public void solve() {
        boolean first = true;

        while (sc.hasNext()) {
            String input = sc.next();

            BigInteger year = new BigInteger(input);

            if (year.compareTo(BigInteger.ZERO) == 0) break;

            if (first) {
                first = false;
            } else {
                System.out.println();
            }

            System.out.println(year.toString());

            List<String> ghosts = ghostVisitsIn(year);
            if (ghosts.isEmpty()) {
                System.out.println("No ghost will come in this year");
            } else {
                for (String ghost : ghosts) System.out.println("Ghost of " + ghost + "!!!");
            }
        }
    }
}
