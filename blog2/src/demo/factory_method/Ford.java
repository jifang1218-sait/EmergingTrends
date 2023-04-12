package demo.factory_method;

class Ford implements Car {
	@Override
	public void run() {
		System.out.println("Ford is Running…");
	}

	@Override
	public void stop() {
		System.out.println("Ford is Stopping…");
	}
}