package demo.singleton;

public class Singleton1_2 {
	private static Singleton1_2 _instance = new Singleton1_2();
	private Singleton1_2 (){}
	public static Singleton1_2 getInstance() {
		return _instance;
	}
}