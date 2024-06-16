#include "JsonValue.h"

JsonValue::JsonValue(NodeType type) :type(type)
{

}

NodeType JsonValue::getType() const
{
	return this->type;
}