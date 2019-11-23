import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
    public static void main(String args[]) {
        long t1 = System.nanoTime();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader in=new BufferedReader(new FileReader("piyush.txt"));
        String sin;

        while (!((sin = in.readLine()).equals("0"))) {
            int n = Integer.parseInt(sin);
            Point ar[] = new Point[n];
            Map<Point, Integer> m3 = new HashMap<Point, Integer>();
            for (int i = 0; i < n; i++) {
                StringTokenizer s = new StringTokenizer(in.readLine());
                int x = Integer.parseInt(s.nextToken());
                int y = Integer.parseInt(s.nextToken());
                ar[i] = new Point(x, y);
            }
            Arrays.sort(ar, new xsort<Point>());
            /*
             * for(Point p:ar) { System.out.println(p); }
             */
            for (int i = 0; i < n - 1; i++) {
                int x1 = ar[i].x;
                int x2 = ar[i + 1].x;
                if (x1 != x2)
                    continue;
                int y1 = ar[i].y;
                int y2 = ar[i + 1].y;
                i++;
                if (y1 == y2)
                    continue;
                else {
                    Integer f = m3.get(new Point(y1, y2));
                    m3.put(new Point(y1, y2), (f == null) ? 1 : f + 1);
                }
            }
            Iterator<Point> it3 = m3.keySet().iterator();
            long cal = 0;
            for (; it3.hasNext();) {
                int a = m3.get(it3.next());
                cal += (((long) a * (a - 1)) / 2);
            }
            System.out.println(cal);
            // System.out.println((double)(System.nanoTime()-t1)/1000000000.0);
        }
    }
}

class xsort<T> implements Comparator<T> {
    public int compare(T o1, T o2) {
        int x1 = ((Point) o1).x;
        int y1 = ((Point) o1).y;
        int x2 = ((Point) o2).x;
        int y2 = ((Point) o2).y;
        if (x1 < x2)
            return (-1);
        else if (x1 > x2)
            return (1);
        else
            return (y1 > y2 ? 1 : -1);
    }
}