import java.util.*;
import java.io.*;

public class Day9B {
    private static int[] r = new int[10], c = new int[10];
    private static Set<Integer> vst = new HashSet<>();
    private static void move(int i) {
        if (Math.abs(r[i]-r[i-1]) <= 1 && Math.abs(c[i]-c[i-1]) <= 1) return;
        if (r[i] < r[i-1]) r[i]++;
        if (r[i-1] < r[i]) r[i]--;
        if (c[i] < c[i-1]) c[i]++;
        if (c[i-1] < c[i]) c[i]--;
        if (i == 9) {
            visit(r[i], c[i]);
            return;
        }
        move(i+1);
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
                r[0] += dr;
                c[0] += dc;;
                move(1);
            }
        }
        
        System.out.println(vst.size());
    }
}