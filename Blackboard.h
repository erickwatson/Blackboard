#pragma once
#include <map>

enum BlackboardItemType {
	INVALID = 0,
	FLOAT,
	INT,
	CHAR,
	BOOL,
	POINTER
};

//class Expert
//{
//public:
//	Expert();
//	~Expert();
//
//	def getResponse();
//	def execute();
//
//};

class Blackboard
{
	//// returns true if id exists
	//define getEntry(id, item);
	//define setEntry(id, item);
	//def hasEntry(id);

	////contains key value pairs
	//entries;


public:
	Blackboard();
	~Blackboard();

	BlackboardItemType getType(std::string key);
	// Gets
	bool set(std::string key, float valueIn);
	bool set(std::string key, int& valueIn);
	bool set(std::string key, char valueIn);
	bool set(std::string key, bool valueIn);
	
	bool set(std::string key, void* valueIn);

	// Sets
	bool get(std::string key, float& valueOut);
	bool get(std::string key, int& valueOut);
	bool get(std::string key, char& valueOut);
	bool get(std::string key, bool& valueOut);

	template <typename T>
	bool get(std::string key, T*& valueOut)
	{
		auto it = m_data.find(key);

		if (it != m_data.end())	// If we find existing data with same key
		{
			if (it->second.type == POINTER)
			{
				valueOut = (T*)it->second.pointerValue;
				return true;
			}
		}
		return false;
	}



private:

	struct BlackboardItem {
		BlackboardItemType type;

		union {
			float floatValue;
			int intValue;
			unsigned int unsignedInt;
			char charValue;
			bool boolValue;
			void* pointerValue;
		};
	};

	std::map<std::string, BlackboardItem> m_data;

};

