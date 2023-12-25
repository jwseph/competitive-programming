import java.util.*;
import java.io.*;

public class Day9A {
    private static int hr = 0, hc = 0, tr = 0, tc = 0;
    private static Set<Integer> vst = new HashSet<>();
    private static void move(int dr, int dc) {
        int pr = hr, pc = hc;
        hr += dr;
        hc += dc;
        if (Math.abs(hr-tr) <= 1 && Math.abs(hc-tc) <= 1) return;
        tr = pr;
        tc = pc;
        visit(tr, tc);
    }
    private static void visit(int r, int c) {
        vst.add((r+500)*1000+(c+500));
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day9.in"));

        visit(0, 0);
        while (in.hasNext()) {
            int dr = 0, dc = 0;
            switch (in.next().charAt(0)) {
                case 'D': dr = -1; break;
                case 'U': dr = 1; break;
                case 'L': dc = -1; break;
                case 'R': dc = 1; break;
            }
            for (int d = Integer.parseInt(in.next()); d > 0; d--) {
                move(dr, dc);
            }
        }
        
        System.out.println(vst.size());
    }
}