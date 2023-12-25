import java.util.*;
import java.io.*;

public class Day14A {
    private static boolean drop(boolean[][] vst, int r, int c) {
        if (r == 399) return false;
        if (!vst[r+1][c]) return drop(vst, r+1, c);
        if (c-1 >= 0 && !vst[r+1][c-1]) return drop(vst, r+1, c-1);
        if (c+1 < 700 && !vst[r+1][c+1]) return drop(vst, r+1, c+1);
        vst[r][c] = true;
        return true;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day14.in"));
        boolean[][] vst = new boolean[400][700];

        String s = in.next();
        while (in.hasNext()) {
            String[] cs = s.split(",");
            int sr = Integer.parseInt(cs[1]);
            int sc = Integer.parseInt(cs[0]);
            while (in.hasNext() && (s = in.next()).equals("->")) {
                cs = in.next().split(",");
                int er = Integer.parseInt(cs[1]);
                int ec = Integer.parseInt(cs[0]);
                vst[er][ec] = true;
                for (int r = sr, c = sc; !(r == er && c == ec);) {
                    vst[r][c] = true;
                    if (r < er) r++;
                    if (r > er) r--;
                    if (c < ec) c++;
                    if (c > ec) c--;
                }
                sr = er;
                sc = ec;
            }
        }

        int res = 0;
        while (drop(vst, 0, 500)) res++;
        System.out.println(res);
    }
}
