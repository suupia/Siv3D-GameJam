#include "../stdafx.h"
#include "JSONDialogueReader.h"

namespace
{
	// for debug
	void ShowObject(const JSON& value)
	{
		switch (value.getType())
		{
		case JSONValueType::Empty:
			Console << U"empty";
			break;
		case JSONValueType::Null:
			Console << U"null";
			break;
		case JSONValueType::Object:
			for (const auto& object : value)
			{
				Console << U"[" << object.key << U"]";
				ShowObject(object.value);
			}
			break;
		case JSONValueType::Array:
			for (const auto& element : value.arrayView())
			{
				ShowObject(element);
			}
			break;
		case JSONValueType::String:
			Console << value.getString();
			break;
		case JSONValueType::Number:
			Console << value.get<double>();
			break;
		case JSONValueType::Bool:
			Console << value.get<bool>();
			break;
		case JSONValueType::Binary:
			Console << value.getBinary();
		}
	}
}


JSONDialogueReader::JSONDialogueReader(String path) : path_(std::move(path))
{
}

// public
Array<DialogueInfo> JSONDialogueReader::read_dialogues()
{
	const JSON json = JSON::Load(path_);

	if (not json)
	{
		throw Error{U"Failed to load {}`"_fmt(path_)};
	}

	Array<MessageInfo> message_infos;
	for (const auto& dialogue : json[U"Dialogue"].arrayView())
	{
		const auto name = dialogue[U"Name"].getString();
		const auto message = dialogue[U"Message"].getString();

		message_infos.push_back(MessageInfo(name, message));

	}

	return  Array<DialogueInfo>{DialogueInfo(message_infos)};
}

