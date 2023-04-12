package demo.factory_method;

class CarFactory {
	public static Car createCar(String type) {
		Car ret = null;
		
		switch (type) {
			case "MercedesBenz": {
				ret = new MercedesBenz();
			} break;
			case "Ford": {
				ret = new Ford();
			} break;
			case "Toyota": {
				ret = new Toyota();	
			} break;
		}

		return ret;
	}
}