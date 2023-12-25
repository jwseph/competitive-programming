import java.util.*;
import java.io.*;

public class Day8A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day8.in"));
        
        int res = 0;
        while (in.hasNext()) for (String s: in.nextLine().split(" \\| ")[1].split(" ")) if (s.length() <= 4 || s.length() == 7) res++;
        
        System.out.println(res);
    }
}
