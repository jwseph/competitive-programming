import java.util.*;
import java.io.*;

public class Day25A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day25.in"));

        List<String> lines = new ArrayList<String>();
        while (in.hasNext()) lines.add(in.next());

        int n = lines.size(), m = lines.get(0).length();
        char arr[][] = new char[n][m];
        for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
            arr[r][c] = lines.get(r).charAt(c);
        }
        int t;
        boolean br = false;
        for (t = 0; !br; t++) {
            br = true;
            char na[][] = new char[n][m];
            for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
                if (arr[r][c] == '>' && arr[r][(c+1)%m] == '.') {
                    na[r][c] = '.';
                    na[r][(c+1)%m] = '>';
                    br = false;
                } else if (na[r][c] == 0) {
                    na[r][c] = arr[r][c];
                }
            }
            arr = na;
            na = new char[n][m];
            for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
                if (arr[r][c] == 'v' && arr[(r+1)%n][c] == '.') {
                    na[r][c] = '.';
                    na[(r+1)%n][c] = 'v';
                    br = false;
                } else if (na[r][c] == 0) {
                    na[r][c] = arr[r][c];
                }
            }
            arr = na;
        }
        
        System.out.println(t);
    }
}