package demo.factory_method;

public class FactoryMethodTest {
    public static void test() {
        Car ford = CarFactory.createCar("Ford");
        ford.run();
    }
}
