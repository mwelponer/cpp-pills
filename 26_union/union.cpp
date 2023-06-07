#include <iostream>

struct Vec2 { int x, y; };

// operator overriding to output Vec2
std::ostream& operator<<(std::ostream& stream, Vec2& vec){
    stream << vec.x << ", " << vec.y;
    return stream;
}

struct Vec4 { 
    int x, y, z, w;
    // a way to treat Vec4 as a couple of Vec2
    Vec2& getA() { return *((Vec2*)&x); } // type punning from Vec4 to Vec2
    Vec2& getB() { return *((Vec2*)&z); } // type punning from Vec4 to Vec2
};

// a way to treat Vec4 as a couple of Vec2, using union
struct BetterVec4 {
    union {
        struct { int x, y, z, w; };
        struct { Vec2 a, b; };
    };
};

int main() {
    // treting Vec4 as a couple of Vec2 using type punning
    Vec4 vec{1, 2, 3, 4};
    std::cout << "vec: " << vec.getA() << std::endl;
    std::cout << "vec: " << vec.getB() << std::endl;

    // treating BetterVec4 as a couple of Vec2 using union
    BetterVec4 bvec{1, 2, 3, 4};
    std::cout << "bvec: " << bvec.a << std::endl;
    std::cout << "bvec: " << bvec.b << std::endl;
}