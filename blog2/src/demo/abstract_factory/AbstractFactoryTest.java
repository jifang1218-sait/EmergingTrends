package demo.abstract_factory;

public class AbstractFactoryTest {
    public static void test() {
        // the type of platform is determined at runtime, 
        // or read from a configuration file when the application start, 
        // or created by other conditions etc..
        String type = "Win32"; 
        GraphicsFactory fac = creatFactory(type);
        GraphicsContext gc = fac.createGraphicsContext();
        gc.setPen(fac.createPen());
        gc.setBrush(fac.createBrush());

        gc.drawCar(new Point(10, 10));
        gc.drawHouse(new Point(10, 10));
        gc.drawTree(new Point(10, 10));
        gc.drawImage(new Point(10, 10), fac.createImage());
    }

    GraphicsFactory creatFactory(String type) {
        GraphicsFactory ret = null;
        // the type of platform is determined at runtime, 
        // or read from a configuration file etc..
        switch (type) {
            case "Win32": {
                ret = new WGraphicsFactory();
            } break;
            case "XServer": {
                ret = new XGraphicsFactory();
            }break;
        }
    
        return ret;
    }
}
