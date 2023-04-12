package demo.factory_method;

public class MercedesBenz implements Car {
    @Override
	public void run() {
		System.out.println("Mercedes-Benz is Running…");
	}

	@Override
	public void stop() {
		System.out.println("Mercedes-Benz is Stopping...");
	}
}

