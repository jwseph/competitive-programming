import java.util.*;
import java.io.*;

public class Day15A {
    private static int stoi(String str, int i, int j) {
        return Integer.parseInt(str.substring(i, (str.length()+j-1)%str.length()+1));
    }
    private static class Interval {
        int l, r;
        Interval(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day15.in"));
        
        Set<Integer> b = new HashSet<>();
        List<Interval> a = new ArrayList<>();
        int Y = 2000000;
        while (in.hasNext()) {
            for (int i = 0; i < 2; i++) in.next();
            int sx = stoi(in.next(), 2, -1), sy = stoi(in.next(), 2, -1);
            for (int i = 0; i < 4; i++) in.next();
            int bx = stoi(in.next(), 2, -1), by = stoi(in.next(), 2, 0);
            if (by == Y) b.add(bx);

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

        int res = -b.size();
        while (!s.empty()) res += s.peek().r-s.pop().l;

        System.out.println(res);
    }
}
