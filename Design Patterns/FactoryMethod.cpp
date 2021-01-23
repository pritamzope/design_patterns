#include <iostream>

class Product {
    public:
        virtual ~Product(){}
        virtual void Run() = 0;
};

// if there are 2 similar products
class Product_A : public Product {
    public:
        ~Product_A(){}
        void Run(){
            std::cout<<"Product A"<<std::endl;
        }
};

class Product_B : public Product {
    public:
        ~Product_B(){}
        void Run(){
            std::cout<<"Product B"<<std::endl;
        }
};

class Creator {
    public:
        virtual ~Creator(){}
        virtual Product *CreateProduct_A() = 0;
        virtual Product *CreateProduct_B() = 0;
        virtual void RemoveProduct(Product *) = 0;
};

class ProductCreator : public Creator {
    public:
        Product *CreateProduct_A(){
            return new Product_A;
        }
        Product *CreateProduct_B(){
            return new Product_B;
        }
        void RemoveProduct(Product *product){
            delete product;
        }
};

int main()
{
    Creator *c = new ProductCreator();
    Product *A = c->CreateProduct_A();
    Product *B = c->CreateProduct_B();
    A->Run();
    B->Run();
    c->RemoveProduct(A);
    c->RemoveProduct(B);
    delete c;
    return 0;
}

