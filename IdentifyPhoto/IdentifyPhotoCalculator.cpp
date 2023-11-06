#include "../stdafx.h"
#include "IdentifyPhotoCalculator.h"
#include "../Scene/Episode1IdentifyPhotoScene.h"

IdentifyPhotoCalculator::IdentifyPhotoCalculator(const Array<int>& should_be_selected):
	should_be_selected_(should_be_selected)
{
}

Array<int> IdentifyPhotoCalculator::calc_wrong_selected_photos(Array<IdentifyPhotoData> identify_photo_data)
{
	Array<int> actual_selected;
	for(int i = 0; i< identify_photo_data.size(); i++)
	{
		if(identify_photo_data.at(i).is_selected)
		{
			actual_selected.push_back(i);
		}
	}

	std::ranges::sort(should_be_selected_);
	std::ranges::sort(actual_selected);

	Array<int> wrong_selected;
	std::ranges::set_difference(actual_selected, should_be_selected_, std::back_inserter(wrong_selected));

	return wrong_selected;
}

Array<int> IdentifyPhotoCalculator::not_selected_photos(Array<IdentifyPhotoData> identify_photo_data)
{
	Array<int> actual_selected;
	for(int i = 0; i< identify_photo_data.size(); i++)
	{
		if(identify_photo_data.at(i).is_selected)
		{
			actual_selected.push_back(i);
		}
	}
	std::ranges::sort(should_be_selected_);
	std::ranges::sort(actual_selected);

	Array<int> not_selected;
	std::ranges::set_difference(should_be_selected_, actual_selected, std::back_inserter(not_selected));

	return not_selected;
}
