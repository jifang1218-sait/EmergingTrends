package demo.decorator;

class NewsPaperWithFooter implements INewsPaper {
	@Override
	public void output() { 
		this.newsPaper.output();
		this.printFooter();
	}

	public void printFooter() { 
		System.out.println("NewsPaperWithFooter::printFooter");
	}

	private INewsPaper newsPaper;

	public NewsPaperWithFooter(INewsPaper newsPaper) { 
		this.newsPaper = newsPaper;
	}
}