#include "Json.h"
#include "simpleValue.h"
#include "Object.h"

Json::Json()
{
	std::list<JsonValue*> list;
	list.push_back(new Object());
	this->jsonValues = list;
}

//helper function which check if the file is with correct data using regular expressions
bool Json::validation(std::istream& in)
{

	std::regex regexRuleCurlyBracketStart("\\s*[{]\\s*");
	std::regex regexRuleSquareBracketStart("\\s*[[]\\s*");
	std::regex regexRuleForLine("(\\s*([\"])(\\w*)([\"])):\\s*[\"][(.*)\\w\\s-*]*[\"](.*)");

	std::regex regexRuleSquareBracketsForLine("\\s*(.+)\\w(.+):\\s?[[]");
	std::regex regexRuleCurlyBracketsForLine("\\s*(.+)\\w(.+):\\s?[{]");
	std::regex regexRuleCurlyBracketEnd("\\s*[}][,]?");
	std::regex regexRuleSquareBracketEnd("\\s*[\\]][,]?");
	std::string content;
	std::stack<char> collection;


	while (!in.eof())
	{
		std::getline(in, content);

		if (std::regex_match(content, regexRuleCurlyBracketStart))
		{
			collection.push('{');
		}
		else if (std::regex_match(content, regexRuleSquareBracketStart))
		{
			collection.push('[');
		}
		else if (std::regex_search(content, regexRuleForLine))
		{
			continue;
		}
		else if (std::regex_match(content, regexRuleCurlyBracketsForLine))
		{
			collection.push('{');
		}
		else if (std::regex_match(content, regexRuleSquareBracketsForLine))
		{
			collection.push('[');
		}
		else if (std::regex_match(content, regexRuleCurlyBracketEnd))
		{
			if (collection.top() == '{')
			{
				collection.pop();
			}
			else
			{
				return false;
			}
		}
		else if (std::regex_match(content, regexRuleSquareBracketEnd))
		{
			if (collection.top() == '[')
			{
				collection.pop();
			}
			else
			{
				return false;
			}
		}
		else if (content == "")
		{
			return collection.empty();
		}
		else
		{
			return false;
		}
	}
	if (std::regex_match(content, regexRuleCurlyBracketEnd))
	{
		return collection.empty();
	}
}

bool Json::validationCheck(const std::string& filepath)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		throw "Could not find file!";
	}
	bool isValid = validation(file);
	file.close();
	return isValid;
}

void Json::addElement(JsonValue* value)
{
	jsonValues.push_back(value);
}

void Json::removeElement(JsonValue* value)
{
	jsonValues.remove(value);
}

//function which print the object using write function which is overrided in the three classes
//and by checkin which JSON value we have, the function use different class
void Json::print(std::ostream& out) const
{
	out << "{" << std::endl;
	for (JsonValue* element : jsonValues)
	{
		element->write(out);
	}
	out << "}" << std::endl;
}

//find elements by given key using findIn function which is overrided in the three classes
//and by checkin which JSON value we have, the function use different class
std::list<JsonValue*> Json::find(const std::string& key)
{
	std::list<JsonValue*> values;
    
	for (JsonValue* element : jsonValues)
	{
		element->findIn(key, values);
	}
	return values;
}

