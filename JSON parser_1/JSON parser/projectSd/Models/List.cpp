#include "List.h"
//it is hardcoded because method read is not implemented
List::List() : JsonValue(NodeType::object)
{
	this->key = "perfect";

	std::list<JsonValue*> l;
	l.push_back(new SimpleValue("name", "maria"));
	listValues.push_back(new Object("maya", l));
}

//overrided write method in order to illustrate an object
//if there is list inside the list - the function is called recursively
void List::write(std::ostream& out) const
{
	int size = key.length();
	out << "	\"" << key << "\": [" << std::endl;
	for (JsonValue* element : listValues) {
		if (element->getType() == NodeType::list )
		{
			element->write(out);
			out << "	";
		}
		else
		{
			out << "	";
			element->write(out);
		}
	}
	
	for (int i = 0; i < size  +4; i++)
	{
		out << " ";
	}
	out << "	    ]" << std::endl;
}

//overrided findIn method in order to find an element by given key
void List::findIn(const std::string& key, std::list<JsonValue*>& values)
{
	std::regex regexRuleForKey(key);
	std::string keyValue = "\"" + this->key + "\"";

	for (JsonValue* element : listValues) 
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
}

int List::getSize() const
{
	return listValues.size();
}