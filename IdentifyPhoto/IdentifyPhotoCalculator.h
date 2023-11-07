#pragma once
#include "../IdentifyPhoto/IdentifyPhotoData.h"

class IdentifyPhotoCalculator
{
public:
	IdentifyPhotoCalculator(const Array<int>& should_be_selected);
	Array<int> calc_wrong_selected_photos(Array<IdentifyPhotoData> identify_photo_data);
	Array<int> not_selected_photos(Array<IdentifyPhotoData> identify_photo_data);

private:
	Array<int> should_be_selected_;

};
