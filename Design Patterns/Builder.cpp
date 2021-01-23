#include <iostream>

class Product {
    public:
        void Do_A(int value){
            std::cout<<"Do A "<<value<<std::endl;
        }
        void Do_B(int value){
            std::cout<<"Do B "<<value<<std::endl;
        }
};

class Builder {
    public:
        virtual ~Builder(){}
        virtual void Build_A() = 0;
        virtual void Build_B() = 0;

        Product Get(){
            return p;
        }

    protected:
        Product p;
};

class BuilderX : public Builder {
    public:
        void Build_A(){
            p.Do_A(100);
        }
        void Build_B(){
            p.Do_B(200);
        }
};

class BuilderY : public Builder {
    public:
        void Build_A(){
            p.Do_A(1000);
        }
        void Build_B(){
            p.Do_B(2000);
        }
};

class Director {
    public:
        Director(): builder(){}
        ~Director(){
            if(builder)
                delete builder;
        }

        void Set(Builder *b){
            if(builder)  
                delete builder;
            this->builder = b;
        }
        Product Get(){
            return builder->Get();
        }
        void Construct(){
            builder->Build_A();
            builder->Build_B();
        }
    
    private:
        Builder *builder;
};

int main()
{
    Director d;

    std::cout<<"Builder X:"<<std::endl;
    d.Set(new BuilderX);
    d.Construct();

    std::cout<<"Get Current Product:"<<std::endl;
    Product P = d.Get();
    P.Do_A(123);
    P.Do_B(456);

    std::cout<<"Builder Y"<<std::endl;
    d.Set(new BuilderY);
    d.Construct();

    return 0;
}

