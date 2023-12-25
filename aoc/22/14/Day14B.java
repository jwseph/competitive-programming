import java.util.*;
import java.io.*;

public class Day14B {
    private static boolean drop(boolean[][] vst, int r, int c) {
        if (!vst[r+1][c]) return drop(vst, r+1, c);
        if (c-1 >= 0 && !vst[r+1][c-1]) return drop(vst, r+1, c-1);
        if (c+1 < 700 && !vst[r+1][c+1]) return drop(vst, r+1, c+1);
        vst[r][c] = true;
        if (r == 0 && c == 500) return false;
        return true;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day14.in"));
        boolean[][] vst = new boolean[400][700];

        String s = in.next();
        int mr = -1;
        while (in.hasNext()) {
            String[] cs = s.split(",");
            int sr = Integer.parseInt(cs[1]);
            int sc = Integer.parseInt(cs[0]);
            mr = Math.max(mr, sr);
            while (in.hasNext() && (s = in.next()).equals("->")) {
                cs = in.next().split(",");
                int er = Integer.parseInt(cs[1]);
                int ec = Integer.parseInt(cs[0]);
                mr = Math.max(mr, er);
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
        for (int c = 0; c < 700; c++) {
            vst[mr+2][c] = true;
        }

        int res = 1;
        while (drop(vst, 0, 500)) res++;
        System.out.println(res);
    }
}
