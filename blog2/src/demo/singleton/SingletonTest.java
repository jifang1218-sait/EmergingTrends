package demo.singleton;

public class SingletonTest {
    public static void test() {
        // test for singleton 1
        Singleton1 s1 = Singleton1.getInstance();
        Singleton1 s1_another = Singleton1.getInstance();
        if (s1 == s1_another) {
            System.out.println("Singleton1, same object.");
        }

        // test for singleton 1.1
        Singleton1 s1_1 = Singleton1_1.getInstance();
        Singleton1 s1_1_another = Singleton1_1.getInstance();
        if (s1_1 == s1_1_another) {
            System.out.println("Singleton1_1, same object.");
        }

        // test for singleton1.2
        Singleton1 s1_2 = Singleton1_2.getInstance();
        Singleton1 s1_2_another = Singleton1_2.getInstance();
        if (s1_2 == s1_2_another) {
            System.out.println("Singleton1_2, same object.");
        }

        // test for singleton 1.3
        Singleton1 s1_3 = Singleton1_3.getInstance();
        Singleton1 s1_3_another = Singleton1_3.getInstance();
        if (s1_1 == s1_3_another) {
            System.out.println("Singleton1_3, same object.");
        }

        // test for singleton1.4
        Singleton1 s1_4 = Singleton1_4.getInstance();
        Singleton1 s1_4_another = Singleton1_4.getInstance();
        if (s1_4 == s1_4_another) {
            System.out.println("Singleton1_4, same object.");
        }
}
