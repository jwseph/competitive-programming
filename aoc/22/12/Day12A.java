import java.util.*;
import java.io.*;

public class Day12A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day12.in"));
        
        List<String> lines = new ArrayList<String>();
        while (in.hasNext()) lines.add(in.next());
        int nr = lines.size(), nc = lines.get(0).length();
        char arr[][] = new char[nr][nc];
        boolean vst[][] = new boolean[nr][nc];
        int s_r = -1, s_c = -1;
        int e_r = -1, e_c = -1;
        for (int r = 0; r < nr; r++) for (int c = 0; c < nc; c++) {
            arr[r][c] = lines.get(r).charAt(c);
            if (arr[r][c] == 'S') {
                s_r = r;
                s_c = c;
                arr[r][c] = 'a';
            }
            if (arr[r][c] == 'E') {
                e_r = r;
                e_c = c;
                arr[r][c] = 'z';
            }
        }

        Queue<List<Integer>> q = new LinkedList<>();
        q.add(Arrays.asList(s_r, s_c));
        int res = -1;
        for (int i = 0; res == -1; i++) {
            for (int j = q.size(); j > 0; j--) {
                List<Integer> x = q.remove();
                int r = x.get(0), c = x.get(1);
                if (r == e_r && c == e_c) {
                    res = i;
                    break;
                }
                if (vst[r][c]) continue;
                vst[r][c] = true;
                if (r-1 >= 0 && arr[r-1][c] <= arr[r][c]+1) q.add(Arrays.asList(r-1, c));
                if (r+1 < nr && arr[r+1][c] <= arr[r][c]+1) q.add(Arrays.asList(r+1, c));
                if (c-1 >= 0 && arr[r][c-1] <= arr[r][c]+1) q.add(Arrays.asList(r, c-1));
                if (c+1 < nc && arr[r][c+1] <= arr[r][c]+1) q.add(Arrays.asList(r, c+1));
            }
        }
        System.out.println(res);
    }
}
