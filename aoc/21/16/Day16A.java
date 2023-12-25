import java.util.*;
import java.io.*;

public class Day16A {
    private static Queue<Integer> q = new ArrayDeque<>();
    private static int get(int n) {
        int res = 0;
        while (n --> 0) res = (res<<1)|q.remove();
        return res;
    }
    private static int solve() {
        int v = get(3);
        int t = get(3);
        if (t == 4) {
            for (;;) {
                int p = get(1);
                get(4);
                if (p == 0) return v;
            }
        }
        boolean l = q.remove() == 0;
        int m = l ? -get(15)+q.size() : get(11);
        while (l ? (m != q.size()) : (m --> 0)) v += solve();
        return v;
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
