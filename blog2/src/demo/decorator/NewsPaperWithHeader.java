package demo.decorator;

class NewsPaperWithHeader implements INewsPaper {
	@Override
	public void output() { 
		this.printHeader();
		this.newsPaper.output();
	}

	public void printHeader() { 
		System.out.println("NewsPaperWithHeader::printHeader");
	}

	private INewsPaper newsPaper;

	public NewsPaperWithHeader(INewsPaper newsPaper) { 
		this.newsPaper = newsPaper;
	}
}