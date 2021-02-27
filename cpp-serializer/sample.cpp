#include <fstream>
#include <exception>
#include "Serializable.h"

class User : Serializer::Serializable {
private:
    std::string name;
    std::string surname;
    std::size_t age = NULL;
public:
    User(std::string n, std::string s, size_t a) : name(n), surname(s), age(a) {}

    User() {
        deserialize();
    }

    void serialize() override {
        std::ofstream fs("user.txt");
        serializeValue(fs, name);
        serializeValue(fs, surname);
        serializeValue(fs, age);
        fs.close();
    }
    void deserialize() override {
        std::ifstream fs;
        try {
            fs.open("user.txt");
            if (!fs.good()) throw std::runtime_error(std::string("i/o error"));
            name = deserializeValue<std::string>(fs);
            surname = deserializeValue<std::string>(fs);
            age = deserializeValue<size_t>(fs);
            std::cout << age << '\t' << name << '\t' << surname;
        }
        catch (std::runtime_error) {
            std::cout << "There is no input file to deserialize the object";
        }
        fs.close();
    }
};

int main()
{
    User us("alex", "berdnikov", 18);
    us.serialize();
    system("pause");
    return 0;
}