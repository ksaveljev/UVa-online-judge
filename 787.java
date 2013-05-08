import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        (new UVa787()).solve();
    }
}

class UVa787 {
    final private Scanner sc = new Scanner(System.in);

    public void solve() {
        int n;

        while (sc.hasNext()) {
            List<BigInteger> nums = new ArrayList<BigInteger>();

            while (sc.hasNext() && ((n = sc.nextInt()) != -999999))
                nums.add(BigInteger.valueOf(n));

            BigInteger result = nums.get(0);

            for (int i = 0, sz = nums.size(); i < sz; i++) {
                BigInteger current = nums.get(i);
                result = result.max(current);

                for (int j = i + 1; j < sz; j++) {
                    current = current.multiply(nums.get(j));
                    result = result.max(current);
                }
            }

            System.out.println(result);
        }
    }
}
