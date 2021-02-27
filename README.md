# cpp-serializer

Serialization/deserealization of C++ object.

The easy way to provide for your object an ability of serialization/deserialization for your own class:
1. Include "Serializable.h" in your .cpp file.
2. Inherit Serializable class from Serializer namespace.
3. Override serialize() and deserialize() methods.

That's all!

Always remember about the opportunity to catch I/O exceptions in your class.
