#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object

	int size = other.getWidth() * other.getHeight();
	this->set(other.getHeight(), other.getWidth());
	std::cout << this->getWidth() << 'x' << this->getHeight() << 'y';
	for (int i = 0; i < size; i++)
	{
		this->setPixel(i, other.getPixel(i));
	}

}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage
	storagewidht = width;
	storageheight = height;
	storage = new Intensity[storagewidht * storageheight];
}

IntensityImageStudent::~IntensityImageStudent() {
	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	delete[] storage;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	delete[] storage;
	storagewidht = width;
	storageheight = height;
	storage = new Intensity(storagewidht * storageheight);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	Intensity* tempstorage = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < storagewidht * storageheight; i++)
	{
		tempstorage[i] = storage[i];
	}
	delete[] storage;
	storage = tempstorage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	setPixel((y * storagewidht + x), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int throwError = 0, e = 1 / throwError;
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
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	return storage[(y * storagewidht + x)];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return storage[i];
}