package demo.abstract_factory;

class WImage implements Image {
	public WImage() {
		System.out.println("WImage::WImage");
	}

	@Override
	public void rotate(double rad) { 
		System.out.println("WImage::rotate");
	}

	@Override
	public void scale(double factor) { 
		System.out.println("WImage::scale");
	}

	@Override
	public void transform(Matrix m) { 
		System.out.println("WImage::transform");
	}
}
