import java.util.*;
import java.io.*;

public class Day12B {
    private static int bfs(char arr[][], int s_r, int s_c, int e_r, int e_c, int max) {
        int nr = arr.length, nc = arr[0].length;
        boolean[][] vst = new boolean[nr][nc];
        Queue<List<Integer>> q = new LinkedList<>();
        q.add(Arrays.asList(s_r, s_c));
        for (int i = 0; i < max; i++) {
            for (int j = q.size(); j > 0; j--) {
                List<Integer> x = q.remove();
                int r = x.get(0), c = x.get(1);
                if (r == e_r && c == e_c) return i;
                if (vst[r][c]) continue;
                vst[r][c] = true;
                if (r-1 >= 0 && arr[r-1][c] <= arr[r][c]+1) q.add(Arrays.asList(r-1, c));
                if (r+1 < nr && arr[r+1][c] <= arr[r][c]+1) q.add(Arrays.asList(r+1, c));
                if (c-1 >= 0 && arr[r][c-1] <= arr[r][c]+1) q.add(Arrays.asList(r, c-1));
                if (c+1 < nc && arr[r][c+1] <= arr[r][c]+1) q.add(Arrays.asList(r, c+1));
            }
        }
        return Integer.MAX_VALUE;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day12.in"));
        
        List<String> lines = new ArrayList<String>();
        while (in.hasNext()) lines.add(in.next());
        int nr = lines.size(), nc = lines.get(0).length();
        char arr[][] = new char[nr][nc];
        List<List<Integer>> s_rc = new ArrayList<>();
        int e_r = -1, e_c = -1;
        for (int r = 0; r < nr; r++) for (int c = 0; c < nc; c++) {
            arr[r][c] = lines.get(r).charAt(c);
            if (arr[r][c] == 'S' || arr[r][c] == 'a') {
                s_rc.add(Arrays.asList(r, c));
                arr[r][c] = 'a';
            }
            if (arr[r][c] == 'E') {
                e_r = r;
                e_c = c;
                arr[r][c] = 'z';
            }
        }

        int res = Integer.MAX_VALUE;
        for (List<Integer> rc: s_rc) {
            res = Math.min(res, bfs(arr, rc.get(0), rc.get(1), e_r, e_c, res));
        }
        System.out.println(res);
    }
}
