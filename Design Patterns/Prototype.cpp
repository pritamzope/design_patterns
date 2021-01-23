#include <iostream>

class Prototype {
    public:
        virtual ~Prototype(){}
        virtual Prototype *Clone() = 0;
        virtual void Run() = 0;
};

class ProductA : public Prototype {
    public:
        ~ProductA(){}
        Prototype *Clone(){
            return new ProductA();
        }
        void Run(){
            std::cout<<"Product A"<<std::endl;
        }
};

class ProductB : public Prototype {
    public:
        ~ProductB(){}
        Prototype *Clone(){
            return new ProductB();
        }
        void Run(){
            std::cout<<"Product B"<<std::endl;
        }
};

class Prototype_Client {
    private:
        Prototype *type_1 = nullptr, *type_2 = nullptr;
    public:
        Prototype_Client(){
            type_1 = new ProductA();
            type_2 = new ProductB();
        }
        ~Prototype_Client(){
            if(type_1)
                delete type_1;
            if(type_2)
                delete type_2;
        }
        Prototype *Make_Clone(std::string product){
            if(product == "A"){
                return type_1->Clone();
            }else if(product == "B")
                return type_2->Clone();
            return nullptr;
        }
};

int main()
{
    Prototype_Client pc;

    Prototype *p1 = pc.Make_Clone("A");
    Prototype *p2 = pc.Make_Clone("B");
    p1->Run();
    p2->Run();

    delete p1;
    delete p2;

    return 0;
}
