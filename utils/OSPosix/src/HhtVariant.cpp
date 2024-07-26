#include "HhtVariant.h"

#include "json/json.h"

namespace HHT {

class Variant::JsonHelper {
public:
    static Variant json2variant(const Json::Value& node);
    static Json::Value variant2json(const Variant& variant);
};

Variant Variant::JsonHelper::json2variant(const Json::Value& node) {
    switch (node.type()) {
    case Json::intValue:    return Variant((IntT)node.asInt64());
    case Json::uintValue:   return Variant((IntT)node.asInt64());
    case Json::realValue:   return Variant(node.asDouble());
    case Json::stringValue: return Variant(node.asString());
    case Json::booleanValue:return Variant(node.asBool());
    case Json::arrayValue: {
        ArrayT myArray;
        for (size_t index = 0; index < node.size(); ++index) {
            myArray.push_back(json2variant(node[(Json::ArrayIndex)index]));
        }
        return Variant(myArray);
    }
        break;
    case Json::objectValue: {
        MapT myMap;
        for (auto& key: node.getMemberNames()) {
            myMap[key] = json2variant(node[key]);
        }
        return Variant(myMap);
    }
        break;
    case Json::nullValue:
    default:
        break;
    }

    return Variant();
}

Json::Value Variant::JsonHelper::variant2json(const Variant& variant) {
    switch (variant.mType) {
    case Int:   return Json::Value((Json::Int64)variant.intValue());
    case Real:  return Json::Value(variant.realValue());
    case String:return Json::Value(variant.stringValue());
    case Bool:  return Json::Value(variant.boolValue());
    case Array: {
        Json::Value value(Json::arrayValue);
        const ArrayT& myArray = variant.arrayValueRefRef();
        for (const Variant& subVariant: myArray) {
            value.append(variant2json(subVariant));
        }
        return value;
    }
        break;
    case Map: {
        Json::Value value(Json::objectValue);
        const MapT& myMap =variant.mapValueRefRef();
        for (auto& myPair: myMap) {
            value[myPair.first] = variant2json(myPair.second);
        }
        return value;
    }
        break;

    case None:
    default:
        break;
    }
    return Json::Value();
}

/////////////////////////////////////////////////////

Variant Variant::fromJson(const std::string& jsonStr) {

    Json::Reader reader;
    Json::Value root;
    bool ret = reader.parse(jsonStr, root);
    if (!ret) {
        // parse failed
        return Variant();
    }
    return JsonHelper::json2variant(root);
}

std::string Variant::toJson() const {
    Json::Value jnode = JsonHelper::variant2json(*this);
    return Json::FastWriter().write(jnode);
}
std::string Variant::toStyledJson() const {
    Json::Value jnode = JsonHelper::variant2json(*this);
    return jnode.toStyledString();
}

}  //namespace hh
