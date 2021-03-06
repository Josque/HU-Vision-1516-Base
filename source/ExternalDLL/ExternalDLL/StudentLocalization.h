/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "Localization.h"
#include "IntensityImageStudent.h"
#include "Feature.h"
#include "Point2D.h"

class StudentLocalization :
	public Localization {
public:

	static int * getHistogramX(const IntensityImage & image, int alpha, int startY);
	static int getTopOfHead(const IntensityImage & image);

	static void findSidesInHistogram(int * histogram, int size, int * first, int * last);

	bool stepFindHead(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindChinContours(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const;

};

