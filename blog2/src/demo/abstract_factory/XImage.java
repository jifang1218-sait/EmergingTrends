
class XImage implements Image {
	public XImage() {
		System.out.println("XImage::XImage");
	}

	@Override
	public void rotate(double rad) { 
		System.out.println("XImage::rotate");
	}

	@Override
	public void scale(double factor) { 
		System.out.println("XImage::scale");
	}

	@Override
	public void transform(Matrix m) { 
		System.out.println("XImage::transform");
	}
}
