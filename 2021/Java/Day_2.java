import java.io.File;
import java.util.Scanner;

public class Main {

    private static final String filename = "Day_2.txt";
    public static void part1 () {
        try {
            File f = new File(filename);
            Scanner s = new Scanner(f);
            int horizontal = 0;
            int depth = 0;
            while (s.hasNextLine()) {
                String input = s.next();
                switch (input) {
                    case "forward" -> horizontal += s.nextInt();
                    case "up" -> depth -= s.nextInt();
                    case "down"-> depth += s.nextInt();
                }
            }
            System.out.println("Part 1 (Horizontal, Depth): (" + horizontal + ", " + depth + ") => " + horizontal * depth);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }
    public static void part2 () {
        try {
            File f = new File(filename);
            Scanner s = new Scanner(f);
            int horizontal = 0;
            int depth = 0;
            int aim = 0;
            while (s.hasNextLine()) {
                String input = s.next();
                switch (input) {
                    case "forward" -> {
                        int t = s.nextInt();
                        horizontal += t;
                        depth += t * aim;
                    }
                    case "up" -> aim -= s.nextInt();
                    case "down"-> aim += s.nextInt();
                }
            }
            System.out.println("Part 2 (Horizontal, Depth): (" + horizontal + ", " + depth + ") => " + horizontal * depth);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }

    /**
     * The main execution point of the program.
     *
     * @param args The arguments given to the executable.
     */
    public static void main (String[] args) {
        part1();
        part2();
    }
}
