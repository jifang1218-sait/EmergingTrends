package demo.factory_method;

class Toyota implements Car {
	@Override
	public void run() {
		System.out.println("Toyota is Running…");
	}

	@Override
	public void stop() {
		System.out.println("Toyota is Stopping…");
	}
}