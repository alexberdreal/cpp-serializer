#pragma once

template <typename T>

size_t Serializer::Serializable::serializeValue(std::ostream& os, const T& value) {
    const auto startPosition = os.tellp();
    os.write(reinterpret_cast<const char*>(&value), sizeof(value));
    return static_cast<size_t>(os.tellp() - startPosition);
}

template<>
size_t Serializer::Serializable::serializeValue(std::ostream& os, const std::string& val) {
    const auto startPosition = os.tellp();
    const auto len = static_cast<std::uint32_t>(val.size());
    serializeValue(os, len);
    if (len > 0) os.write(val.data(), len);
    return static_cast<size_t>(os.tellp() - startPosition);
}

