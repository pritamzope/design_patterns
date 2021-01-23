#include <iostream>

class Product {
    public:
        virtual ~Product(){}
        virtual void Run() = 0;
};

class Computer : public Product {
    public:
        ~Computer(){}
        void Run(){
            std::cout<<"Computer"<<std::endl;;
        }
};

class Decorator : public Product {
    public:
        ~Decorator(){}
        Decorator(Product *p){
            this->product = p;
        }
        virtual void Run(){
            product->Run();
        }
    private:
        Product *product;
};

class Monitor : public Decorator {
    public:
        ~Monitor(){}
        Monitor(Product *p) : Decorator(p){}
        void Run(){
            Decorator::Run();
            std::cout<<"Monitor"<<std::endl;
        }
};

class Harddisk : public Decorator {
    public:
        ~Harddisk(){}
        Harddisk(Product *p) : Decorator(p){}
        void Run(){
            Decorator::Run();
            std::cout<<"Harddisk"<<std::endl;
        }
};

int main()
{
    Product *c = new Computer();
    Decorator *mr = new Monitor(c);
    Decorator *hd = new Harddisk(mr);
    hd->Run();

    delete hd;
    delete mr;
    delete c;
    return 0;
}
