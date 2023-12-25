import java.util.*;
import java.io.*;

public class Day1A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day1.in"));
        
        int res = 0, last = in.nextInt();
        while (in.hasNextInt()) if (last < (last = in.nextInt())) res++;
        
        System.out.println(res);
    }
}
