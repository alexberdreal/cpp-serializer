# cpp-serializer

Serialization/deserialization of C++ object.

An easy way to provide an ability of serialization/deserialization for your own class:
1. Include "Serializable.h" in your .cpp file.
2. Inherit Serializable class from Serializer namespace.
3. Override serialize() and deserialize() methods. (De)Serialize all the fields you need with (de)serializeValue().

That's all!

Always remember about the opportunity to catch I/O exceptions in your class.
