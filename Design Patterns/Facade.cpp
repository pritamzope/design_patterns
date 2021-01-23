#include <iostream>

class Subsystem_A {
    public:
        void Run(){
            std::cout<<"Subsystem A"<<std::endl;
        }
};

class Subsystem_B {
    public:
        void Run(){
            std::cout<<"Subsystem B"<<std::endl;
        }
};

class Subsystem_C {
    public:
        void Run(){
            std::cout<<"Subsystem C"<<std::endl;
        }
};

class Facade {
    public:
        Facade(): sA(), sB(), sC(){}
        void Run(){
            sA.Run();
            sB.Run();
            sC.Run();
        }
    private:
        Subsystem_A sA;
        Subsystem_B sB;
        Subsystem_C sC;
};

int main()
{
    Facade *f = new Facade();
    f->Run();
    delete f;
    return 0;
}
