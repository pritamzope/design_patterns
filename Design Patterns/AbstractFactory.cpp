#include <iostream>

// if there are 2 different products
class Product_A {
    public:
    virtual ~Product_A(){}
    virtual void Run() = 0;
};

class Product_B {
    public:
    virtual ~Product_B(){}
    virtual void Execute() = 0;
};

class Product_A_1 : public Product_A {
    public:
        ~Product_A_1(){}
        void Run(){
            std::cout<<"Product A 1"<<std::endl;
        }
};

class Product_A_2 : public Product_A {
    public:
        ~Product_A_2(){}
        void Run(){
            std::cout<<"Product A 2"<<std::endl;
        }
};

class Product_B_1 : public Product_B {
    public:
        ~Product_B_1(){}
        void Execute(){
            std::cout<<"Product B 1"<<std::endl;
        }
};

class Product_B_2 : public Product_B {
    public:
        ~Product_B_2(){}
        void Execute(){
            std::cout<<"Product B 2"<<std::endl;
        }
};

class AbstractFactory {
    public:
        virtual ~AbstractFactory(){}
        virtual Product_A *CreateProduct_A() = 0;
        virtual Product_B *CreateProduct_B() = 0;
        virtual void RemoveProduct_A(Product_A *) = 0;
        virtual void RemoveProduct_B(Product_B *) = 0;
};

class Factory_X : public AbstractFactory {
    public:
        virtual ~Factory_X(){}
        Product_A *CreateProduct_A(){
            return new Product_A_1;
        }
        Product_B *CreateProduct_B(){
            return new Product_B_1;
        }
        void RemoveProduct_A(Product_A *A){
            delete A;
        }
        void RemoveProduct_B(Product_B *B){
            delete B;
        }
};

class Factory_Y : public AbstractFactory {
    public:
        virtual ~Factory_Y(){}
        Product_A *CreateProduct_A(){
            return new Product_A_2;
        }
        Product_B *CreateProduct_B(){
            return new Product_B_2;
        }
        void RemoveProduct_A(Product_A *A){
            delete A;
        }
        void RemoveProduct_B(Product_B *B){
            delete B;
        }
};

void FactoryX_Test()
{
    std::cout<<"FactoryX Test:- "<<std::endl;
    Factory_X *X = new Factory_X();
    Product_A *A = X->CreateProduct_A();
    Product_B *B = X->CreateProduct_B();
    A->Run();
    B->Execute();
    X->RemoveProduct_A(A);
    X->RemoveProduct_B(B);
    delete X;
}

void FactoryY_Test()
{
    std::cout<<"FactoryY Test:- "<<std::endl;
    Factory_Y *Y = new Factory_Y();
    Product_A *A = Y->CreateProduct_A();
    Product_B *B = Y->CreateProduct_B();
    A->Run();
    B->Execute();
    Y->RemoveProduct_A(A);
    Y->RemoveProduct_B(B);
    delete Y;
}

int main()
{
    FactoryX_Test();
    FactoryY_Test();
    return 0;
}
