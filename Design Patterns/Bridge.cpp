#include <iostream>

class Implementor {
    public:
        virtual ~Implementor(){}
        virtual void Run() = 0;
};

class Implementor_A : public Implementor {
    public:
        ~Implementor_A(){}
        void Run(){
            std::cout<<"Implementor A"<<std::endl;
        }
};

class Implementor_B : public Implementor {
    public:
        ~Implementor_B(){}
        void Run(){
            std::cout<<"Implementor B"<<std::endl;
        }
};

class Bridge {
    public:
        virtual ~Bridge(){}
        virtual void Run() = 0;
};

class Bridge_Class : public Bridge {
    public:
        ~Bridge_Class(){}
        Bridge_Class(Implementor *impl){
            this->implementor = impl;
        }
        void Run(){
            this->implementor->Run();
        }
    private:
        Implementor *implementor;
};

int main()
{
    Implementor *impA = new Implementor_A();
    Bridge *b = new Bridge_Class(impA);
    b->Run();
    delete impA;
    delete b;
    return 0;
}
