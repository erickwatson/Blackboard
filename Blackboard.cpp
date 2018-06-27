// Blackboard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Blackboard.h"




Blackboard::Blackboard()
{

}


Blackboard::~Blackboard()
{
}

BlackboardItemType Blackboard::getType(std::string key)
{
	auto it = m_data.find(key);

	if (it != m_data.end())	// If we find existing data with same key
	{
		return it->second.type;
	}

	return INVALID;
}


bool Blackboard::set(std::string key, float valueIn) 
{
	auto it = m_data.find(key);

	if (it != m_data.end())	// If we find existing data with same key
	{
		// We will only fail if existing data is a pointer,
		// because pointers need to be deleted first
		if (it->second.type == POINTER)
			return false;	// Alternative would be to delete the pointer memory, so we can overwrite it
	}

	BlackboardItem data;
	data.type = FLOAT;
	data.floatValue = valueIn;

	m_data[key] = data;
	return true;
}

bool Blackboard::set(std::string key, void * valueIn)
{
	auto it = m_data.find(key);

	if (it != m_data.end())	// If we find existing data with same key
	{
		// If there's already some memory in a pointer, we'll delete it first
		if (it->second.type == POINTER)
		{
			delete it->second.pointerValue;
		}
	}

	BlackboardItem data;
	data.type = POINTER;
	data.pointerValue = valueIn;

	m_data[key] = data;
	return true;
}

bool Blackboard::get(std::string key, float& valueOut) 
{
	auto it = m_data.find(key);
	if (it != m_data.end())	// If we find existing data with same key
	{
		if (it->second.type == FLOAT)
		{
			valueOut = it->second.floatValue;
			return true;
		}
	}
	return false;
}

bool Blackboard::get(std::string key, int & valueOut)
{
	auto it = m_data.find(key);
	if (it != m_data.end())	// If we find existing data with same key
	{
		if (it->second.type == INT)
		{
			valueOut = it->second.intValue;
			return true;
		}
	}
	return false;
}
