#include "Object.h"
#include "List.h"
#include "../Models/SimpleValue.h"

//hardcoded because method read is not implemented
Object::Object() : JsonValue(NodeType::object)
{
	this->key = "name";
	jsonChilds.push_back(new SimpleValue("hello", "world"));
	jsonChilds.push_back(new SimpleValue("love", "programming"));
}

Object::Object(std::string key, std::list<JsonValue*> list) : JsonValue(NodeType::object)
{
	this->key = key;
	this->jsonChilds = list;
}

//overrided write method in order to illustrate an object
//if there is object inside the object - the function is called recursively
void Object::write(std::ostream& out) const
{
	    int size = key.length();
		out << "	\"" << key << "\": {" << std::endl;
		for (JsonValue* element : jsonChilds) {
	
			if (element->getType() == NodeType::simpleValue)
			{
				out << "	";
				element->write(out);
			}
			else if (element->getType() == NodeType::object)
			{
				for (int i = 0; i < size + 5; i++)
				{
					out << " ";
				}
				out << "	}" << std::endl;
				dynamic_cast<Object*>(element)->write(out);
				out << "	";
				
				out << "}" << std::endl;
			}
			else if (element->getType() == NodeType::list)
			{
				for (int i = 0; i < size + 5; i++)
				{
					out << " ";
				}
				out << "	}" << std::endl;
				write(out);
				out << "	";
				out << "}" << std::endl;
			}
		}
		out << "	}" << std::endl;
}

int Object::getSize() const
{
	return jsonChilds.size();
}

//overrided findIn method in order to find an element by given key
//if there is object inside the object - the function is called recursively
void Object::findIn(const std::string& key, std::list<JsonValue*>& values)
{
	std::regex regexRuleForKey(key);
	std::string keyValue = "\"" + this->key + "\"";

	if (std::regex_match(keyValue, regexRuleForKey))
	{
		values.push_back(this);
	}
	for (JsonValue* element : jsonChilds) 
	{
		if (element->getType() == NodeType::simpleValue)
		{
			element->findIn(key, values);
		}
		else if (element->getType() == NodeType::object)
		{
			if (std::regex_match(keyValue, regexRuleForKey))
			{
				values.push_back(this);
			}
			else
			{
				element->findIn(key, values);
			}
		}
		else if (element->getType() == NodeType::list)
		{
		    element->findIn(key,values);
		}
	}
}
