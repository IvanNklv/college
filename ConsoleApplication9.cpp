#include <iostream>

template<typename T>
class Repository8 {
public:
    T data[8]{};

    void Set(int index, T value) {
        if (index >= 0 && index < 8)
            data[index] = value;
    }

    T Get(int index) const {
        if (index >= 0 && index < 8)
            return data[index];
        return T{};
    }
};


template<>
class Repository8<bool> {
public:
    Repository8() : bits(0) {}

    void Set(int index, bool value) {
        if (index < 0 || index >= 8) return;

        if (value)
            bits |= (1u << index);     
        else
            bits &= ~(1u << index);
    }

    bool Get(int index) const {
        if (index < 0 || index >= 8) return false;
        return (bits >> index) & 1u;
    }

private:
    unsigned char bits;
};
    int main() {
      
        return 0;
    };
