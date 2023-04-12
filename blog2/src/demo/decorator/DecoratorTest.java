package demo.decorator;

public class DecoratorTest {
    public static void test() {
        INewsPaper newspaper = new NewsPaper();
        newspaper = new NewsPaperWithHeader(newspaper);
        newspaper = new NewsPaperWithFooter(newspaper);
        newspaper.output();
    }
}
