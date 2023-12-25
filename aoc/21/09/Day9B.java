import java.util.*;
import java.io.*;

public class Day9B {
    private static char grid[][] = null;
    private static boolean vst[][] = null;
    
    private static int solve(int r, int c) {
        if (vst[r][c] || grid[r][c] == '9') return 0;
        int val = grid[r][c];
        if (!vst[r+1][c] && val > grid[r+1][c]) return 0;
        if (!vst[r-1][c] && val > grid[r-1][c]) return 0;
        if (!vst[r][c+1] && val > grid[r][c+1]) return 0;
        if (!vst[r][c-1] && val > grid[r][c-1]) return 0;
        vst[r][c] = true;
        int res = 1;
        if (!vst[r+1][c] && val < grid[r+1][c]) res += solve(r+1, c);
        if (!vst[r-1][c] && val < grid[r-1][c]) res += solve(r-1, c);
        if (!vst[r][c+1] && val < grid[r][c+1]) res += solve(r, c+1);
        if (!vst[r][c-1] && val < grid[r][c-1]) res += solve(r, c-1);
        return res;
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day9.in"));
        
        int w, h; {
            String input = "";
            while (in.hasNext()) input += in.next()+"\n";
            w = input.indexOf("\n")+2;
            h = input.length()/(w-1)+2;
            grid = new char[h][w];
            vst = new boolean[h][w];
            for (int c = 0; c < w; c++) grid[0][c] = grid[h-1][c] = '9';
            String lines[] = input.split("\n");
            for (int i = 0; i < lines.length; i++) {
                grid[i+1] = ('9'+lines[i]+'9').toCharArray();
            }
        }
        
        int res[] = new int[3];
        for (int r = 1; r < h-1; r++) for (int c = 1; c < w-1; c++) {
            if (grid[r][c] < grid[r+1][c] && grid[r][c] < grid[r-1][c] && grid[r][c] < grid[r][c-1] && grid[r][c] < grid[r][c+1]) {
                int s = solve(r, c);
                if (s > res[0]) {
                    res[0] = s;
                    Arrays.sort(res);
                }
                vst = new boolean[h][w];
            }
        }
        
        System.out.println(res[0]*res[1]*res[2]);
    }
}
