import java.util.*;
import java.io.*;

public class Day15B {
    private static int stoi(String str, int i, int j) {
        return Integer.parseInt(str.substring(i, (str.length()+j-1)%str.length()+1));
    }
    private static class Interval {
        int l, r;
        Interval(int l, int r) {
            this.l = Math.max(0, Math.min(4000001, l));
            this.r = Math.max(0, Math.min(4000001, r));
        }
    }
    public static int check(int[][] sxy, int[][] bxy, int Y) throws FileNotFoundException {
        List<Interval> a = new ArrayList<>();
        for (int i = 0; i < sxy.length; i++) {
            int sx = sxy[i][0], sy = sxy[i][1], bx = bxy[i][0], by = bxy[i][1];
            int d = Math.abs(sx-bx)+Math.abs(sy-by);
            int dy = Math.abs(sy-Y), dx = d-dy;
            if (dy > d) continue;
            a.add(new Interval(sx-dx, sx+dx+1));
        }
        
        // Merge intervals
        Stack<Interval> s = new Stack<>();
        Collections.sort(a, (r1, r2) -> r1.l-r2.l);
        s.push(a.get(0));
        for (int i = 1; i < a.size(); i++) {
            if (s.peek().r < a.get(i).l) {
                s.push(a.get(i));
                continue;
            }
            s.peek().r = Math.max(s.peek().r, a.get(i).r);
        }

        if (s.size() == 1) return -1;
        s.pop();
        return s.peek().r;
    }
    public static void main(String[] args) throws FileNotFoundException {
        int n = 0;
        Scanner in = new Scanner(new File("Day15.in"));
        while (in.hasNext()) {
            in.nextLine();
            n++;
        }
        in = new Scanner(new File("Day15.in"));
        int[][] sxy = new int[n][2], bxy = new int[n][2];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 2; i++) in.next();
            sxy[j][0] = stoi(in.next(), 2, -1);
            sxy[j][1] = stoi(in.next(), 2, -1);
            for (int i = 0; i < 4; i++) in.next();
            bxy[j][0] = stoi(in.next(), 2, -1);
            bxy[j][1] = stoi(in.next(), 2, 0);
        }

        for (int y = 0; y < 4000001; y++) {
            int x = check(sxy, bxy, y);
            if (x != -1) {
                System.out.println(x*4000000L+y);
            }
        }
    }
}
