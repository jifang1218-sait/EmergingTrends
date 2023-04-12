package demo.decorator;

class NewsPaper implements INewsPaper {
	@Override
	public void output() { 
		System.out.println("NewsPaper::output");
	}
}