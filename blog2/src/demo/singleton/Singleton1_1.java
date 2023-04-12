package demo.singleton;

public class Singleton1_1 {
	private volatile static Singleton1_1 _singleton;
	private Singleton1_1() {}
	public static Singleton1_1 getSingleton() {
		if (_singleton == null) {
			synchronized (Singleton1_1.class) {
				if (_singleton == null) {
					_singleton = new Singleton1_1();
				}
			}
		}

		return _singleton;
	}
}