#include "simpleValue.h"

SimpleValue::SimpleValue(const std::string& key, const std::string& value) : JsonValue(NodeType::simpleValue)
{
	this->key = key;
	this->value = value;
}

//overrided write method in order to illustrate a simple value
void SimpleValue::write(std::ostream& out) const
{
	out << "	\"" << key << "\":\"" << value << "\"" << std::endl;
}

//overrided findIn method in order to find an element by given key
void SimpleValue::findIn(const std::string& key, std::list<JsonValue*>& values)
{
	std::regex regexRuleForKey(key);
	std::string keyValue = "\"" + this->key + "\"";
	if ( std::regex_match( keyValue, regexRuleForKey))
	{
	     values.push_back(this); 
	}
}


std::string SimpleValue::getValue()
{
	return value;
}

std::string SimpleValue::getKey()
{
	return key;
}
