#pragma once
#include <string>
#include <iostream>

namespace Serializer {
    class Serializable {  //Inherit this class and override serialize(const std::ostream& os) and deserialize()
    protected:
        template <typename T>
        size_t serializeValue(std::ostream& os, const T& value);

        template <typename T>
        T deserializeValue(std::istream& is);

        template<>
        size_t serializeValue(std::ostream& os, const std::string& val);

        template<>
        std::string deserializeValue(std::istream& is);

    public:
        virtual void serialize() = 0;
        virtual void deserialize() = 0;
    };
}

#include "serialize_value.tpp"
#include "deserialize_value.tpp"