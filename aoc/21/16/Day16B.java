import java.util.*;
import java.io.*;

public class Day16B {
    private static Queue<Integer> q = new ArrayDeque<>();
    private static int get(int n) {
        int res = 0;
        while (n --> 0) res = (res<<1)|q.remove();
        return res;
    }
    private static long solve() {
        get(3);
        int t = get(3);
        if (t == 4) {
            long res = 0;
            for (;;) {
                int p = get(1);
                res = res<<4|get(4);
                if (p == 0) return res;
            }
        }
        boolean l = q.remove() == 0;
        int m = l ? -get(15)+q.size() : get(11)-1;
        long res = solve();
        while (l ? (m != q.size()) : (m --> 0)) {
            switch (t) {
                case 0: res += solve(); break;
                case 1: res *= solve(); break;
                case 2: res = Math.min(res, solve()); break;
                case 3: res = Math.max(res, solve()); break;
                case 5: res = (res > solve())?1:0; break;
                case 6: res = (res < solve())?1:0; break;
                case 7: res = (res == solve())?1:0; break;
            }
        }
        return res;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day16.in"));

        for (char c: in.next().toCharArray()) {
            int x = (c < 'A') ? (c-'0') : (c-'A'+10);
            for (int i = 3; i >= 0; i--) q.add((x>>i)&1);
        }

        System.out.println(solve());
    }
}
