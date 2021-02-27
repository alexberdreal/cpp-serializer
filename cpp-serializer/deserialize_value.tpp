#pragma once
template <typename T>
T Serializer::Serializable::deserializeValue(std::istream& is) {
    T value;
    is.read(reinterpret_cast<char*>(&value), sizeof(T));
    return value;
}

template<>
std::string Serializer::Serializable::deserializeValue(std::istream& is) {
    const auto len = static_cast<std::uint32_t>(deserializeValue<uint32_t>(is));
    std::string value;
    for (size_t i = 0; i < len; ++i) {
        value += deserializeValue<char>(is);
    }
    return value;
}