#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
	int imageSize = image.getWidth() * image.getHeight();

	for (int i = 0; i < imageSize; i++)
	{
		intensityImage->setPixel(i, image.getPixel(i).g);
	}
	return intensityImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	int imageSize = image.getWidth() * image.getHeight();
	if (imageSize <= 40000) {
		IntensityImageStudent * intensityImage = new IntensityImageStudent(image);
		return intensityImage;
	}

	int newWidth;
	int newHeight;

	if (image.getWidth() > image.getHeight()){
		newWidth = 200;
		newHeight = newWidth * image.getHeight() / image.getWidth();
	}
	else
	{
		newHeight = 200;
		newWidth = newHeight * image.getWidth() / image.getHeight();
	}
	IntensityImageStudent * intensityImage = new IntensityImageStudent(newWidth, newHeight);
	int magic = 200 * newWidth / image.getWidth();
	for (int x = 0; x < newWidth; x++){
		for (int y = 0; y < newHeight; y++){
			intensityImage->setPixel(x, y, image.getPixel((x * 200) / magic, (y * 200) / magic));
		}
	}
	return intensityImage;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	/*Laplacian filter
	3x3
		 0 -1  0
		-1  4 -1
		 0 -1  0
	5x5
		-4 -1  0 -1 -4
		-1  2  3  2 -1
		 0  3  4  3  0
		-1  2  3  2 -1
		-4 -1  0 -1 -4*/

	IntensityImageStudent * newImage = new IntensityImageStudent(image.getWidth() - 4, image.getHeight() - 4);

	for (int x = 0; x < image.getWidth() - 4; x++){
		for (int y = 0; y < image.getHeight() - 4; y++){
			int oldPixel = image.getPixel(x, y);
			float sum = 0.0f;

			//5x5
			//rij 1
			sum += image.getPixel(2 + x - 2, 2 + y - 2) * -4.0f;
			sum += image.getPixel(2 + x - 1, 2 + y - 2) * -1.0f;
			sum += image.getPixel(2 + x, 2 + y - 2)		* 0.0f;
			sum += image.getPixel(2 + x + 1, 2 + y - 2) * -1.0f;
			sum += image.getPixel(2 + x + 2, 2 + y - 2) * -4.0f;

			//rij 2
			sum += image.getPixel(2 + x - 2, 2 + y - 1) * -1.0f;
			sum += image.getPixel(2 + x - 1, 2 + y - 1) * 2.0f;
			sum += image.getPixel(2 + x, 2 + y - 1)	* 3.0f;
			sum += image.getPixel(2 + x + 1, 2 + y - 1) * 2.0f;
			sum += image.getPixel(2 + x + 2, 2 + y - 1) * -1.0f;

			//rij 3
			sum += image.getPixel(2 + x - 2, 2 + y) * 0.0f;
			sum += image.getPixel(2 + x - 1, 2 + y) * 3.0f;
			sum += image.getPixel(2 + x, 2 + y)		* 4.0f;
			sum += image.getPixel(2 + x + 1, 2 + y) * 3.0f;
			sum += image.getPixel(2 + x + 2, 2 + y) * 0.0f;

			//rij 4
			sum += image.getPixel(2 + x - 2, 2 + y + 1) * -1.0f;
			sum += image.getPixel(2 + x - 1, 2 + y + 1) * 2.0f;
			sum += image.getPixel(2 + x, 2 + y + 1)	* 3.0f;
			sum += image.getPixel(2 + x + 1, 2 + y + 1) * 2.0f;
			sum += image.getPixel(2 + x + 2, 2 + y + 1) * -1.0f;

			//rij 5
			sum += image.getPixel(2 + x - 2, 2 + y + 2) * -4.0f;
			sum += image.getPixel(2 + x - 1, 2 + y + 2) * -1.0f;
			sum += image.getPixel(2 + x, 2 + y + 2)		* 0.0f;
			sum += image.getPixel(2 + x + 1, 2 + y + 2) * -1.0f;
			sum += image.getPixel(2 + x + 2, 2 + y + 2) * -4.0f;

			float average = sum / 125;

			newImage->setPixel(x, y, (int)average);
		}
	}
	return newImage;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	int T = 40;
	IntensityImageStudent * newImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int x = 0; x < image.getWidth(); x++) {
		for (int y = 0; y < image.getHeight(); y++){
			int oldPixel = image.getPixel(x, y);
			if (oldPixel < T){
				newImage->setPixel(x, x, 255);
			}
			else{
				newImage->setPixel(x, y, 0);
			}
		}
	}
	return newImage;
}