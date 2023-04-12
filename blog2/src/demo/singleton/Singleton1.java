package demo.singleton;

public class Singleton1 {
	private static Singleton1 _singleton;
	private Singleton1() {}
	public static Singleton1 getInstance() {
		if (_singleton == null) {
			_singleton = new Singleton1();
		}

		return _singleton;
	}
}