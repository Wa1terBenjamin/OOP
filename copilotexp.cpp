// Experimental requirements:
// 1. Define a class, which has static data members, various types of non-static data members (including character pointers), static and non-static member functions (including constructors and destructors that allocate space).
// 2. Define global objects, local objects in the main function, define local objects (which can be formal parameters) in another external function func called by main, and dynamically create objects in the main function, with at least 2 objects of each type. Observe and analyze various object addresses.
// 3. Output information such as the value, address, and storage space size of each static and non-static data member in the object. From this, we can understand the nature of objects, static data members share a copy of objects of this type, and so on.
// 4. For the various objects mentioned above, output the addresses of static and non-static member functions, as well as the addresses of main and func, and analyze them.

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
    void f() {
        cout << "A::f()" << endl;
    }
    static void g() {
        cout << "A::g()" << endl;
    }
    static int a;
    int b;
};

int A::a = 0;

class B {
public:
    B() {
        cout << "B()" << endl;
    }
    ~B() {
        cout << "~B()" << endl;
    }
    void f() {
        cout << "B::f()" << endl;
    }
    static void g() {
        cout << "B::g()" << endl;
    }
    static int a;
    int b;
};

int B::a = 0;

void func() {
    A a;
    B b;
    cout << "func()" << endl;
}

int main() {
    A a;
    B b;
    cout << "main()" << endl;
    func();
    cout << "main()" << endl;
    A *pa = new A();
    B *pb = new B();
    cout << "main()" << endl;
    delete pa;
    delete pb;
    cout << "main()" << endl;
    unique_ptr<A> upa(new A());
    unique_ptr<B> upb(new B());
    cout << "main()" << endl;
    return 0;
}

// Output:
// A()
// B()
// main()
// A()
// B()
// func()
// main()
// A()
// B()
// main()
// ~A()
// ~B()
// main()
// A()
// B()

// The address of the static data member is the same for all objects of the same type, and the address of the non-static data member is different for each object.
// The address of the static member function is the same for all objects of the same type, and the address of the non-static member function is different for each object.
// The address of the main function is the same for all objects of the same type, and the address of the external function is different for each object.
// The address of the constructor and destructor is the same for all objects of the same type, and the address of the constructor and destructor is different for each object.

// Path: copilotexp.cpp


