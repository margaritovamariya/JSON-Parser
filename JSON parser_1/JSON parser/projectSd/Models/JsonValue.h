#pragma once
#include <fstream>
#include <string>
#include <list>

//the three types of elements in JSON
enum NodeType
{
	simpleValue,
	object,
	list
};

class JsonValue
{
protected:
	std::string key;
	NodeType type;
public:
	JsonValue(NodeType type);
	NodeType getType() const;

	//2 pure virtual functions to be overrided in the inherrited classes
	virtual void write(std::ostream& out) const = 0;
	virtual void findIn(const std::string& key, std::list<JsonValue*>& values) = 0;
};

