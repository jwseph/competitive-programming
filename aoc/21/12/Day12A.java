import java.util.*;
import java.io.*;

public class Day12A {  // brute force (input length = 24)
    private static Map<String, List<String>> hash = new HashMap<String, List<String>>();
    private static Set<String> vst = new HashSet<String>();
    private static int res = 0;

    private static void dfs(String s) {
        if (s.equals("start")) {
            res++;
            return;
        }
        if (vst.contains(s)) return;
        boolean up = Character.isUpperCase(s.charAt(0));
        if (!up) vst.add(s);
        for (String s2: hash.get(s)) dfs(s2);
        if (!up) vst.remove(s);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day12.in"));
        
        while (in.hasNext()) {
            String s[] = in.next().split("-");
            for (int i = 0; i < 2; i++) {
                if (!hash.containsKey(s[i])) hash.put(s[i], new ArrayList<String>());
                hash.get(s[i]).add(s[1-i]);
            }
        }
        
        dfs("end");
        System.out.println(res);
    }
}
