package demo.singleton;

public class Singleton1_3 {
	private static class SingletonHolder {
		private static final Singleton1_3 INSTANCE = new Singleton1_3();
	}
	private Singleton1_3 (){}
	public static final Singleton1_3 getInstance() {
		return SingletonHolder.INSTANCE;
	}
}
