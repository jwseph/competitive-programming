import java.util.*;
import java.io.*;

public class Day9A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day9.in"));
        
        char grid[][] = null;
        int w, h; {
            String input = "";
            while (in.hasNext()) input += in.next()+"\n";
            w = input.indexOf("\n")+2;
            h = input.length()/(w-1)+2;
            grid = new char[h][w];
            for (int c = 0; c < w; c++) grid[0][c] = grid[h-1][c] = ':';
            String[] lines = input.split("\n");
            for (int i = 0; i < lines.length; i++) {
                grid[i+1] = (":"+lines[i]+":").toCharArray();
            }
        }
        
        int res = 0;
        for (int r = 1; r < h-1; r++) for (int c = 1; c < w-1; c++) {
            if (grid[r][c] < grid[r+1][c] && grid[r][c] < grid[r-1][c] && grid[r][c] < grid[r][c-1] && grid[r][c] < grid[r][c+1]) {
                res += grid[r][c]+1-'0';
            }
        }
        System.out.println(res);
    }
}
