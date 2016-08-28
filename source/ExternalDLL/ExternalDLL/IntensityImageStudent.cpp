#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	//done
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object

	int size = other.getWidth() * other.getHeight();
	this->set(other.getWidth(), other.getHeight());
	std::cout << this->getWidth() << 'x' << this->getHeight() << 'y';
	for (int i = 0; i < size; i++)
	{
		this->setPixel(i, other.getPixel(i));
	}

}

IntensityImageStudent::IntensityImageStudent(const IntensityImage &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	//TODO: Create a copy from the other object
	
	int size = other.getWidth() * other.getHeight();
	this->set(other.getWidth(), other.getHeight());
	std::cout << this->getWidth() << 'x' << this->getHeight() << '\n';
	for (int i = 0; i < size; i++) {
		this->setPixel(i, other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage
	storageWidth = width;
	storageHeight = height;
	storage = new Intensity[storageWidth * storageHeight];
}

IntensityImageStudent::~IntensityImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	delete[] storage;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	delete[] storage;
	storageWidth = width;
	storageHeight = height;
	storage = new Intensity(storageWidth * storageHeight);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	Intensity* tempStorage = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < storageWidth * storageHeight; i++)
	{
		tempStorage[i] = storage[i];
	}
	delete[] storage;
	storage = tempStorage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	setPixel(((y * storageWidth) + x), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	storage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	return storage[((y * storageWidth) + x)];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return storage[i];
}

void IntensityImageStudent::clear(Intensity pixel) {
	std::fill_n(storage, storageWidth * storageHeight, pixel);
}

void IntensityImageStudent::clear() {
	clear(255);
}