#include <iostream>
#include <vector>

class Component {
    public:
        virtual ~Component(){}
        virtual void Add(Component *){}
        virtual void Remove(int){}
        virtual void Run() = 0;
};

class Composite : public Component {
    public:
        ~Composite(){
            for(auto x : children)
                delete x;
        }
        void Add(Component *c){
            children.push_back(c);
        }
        void Remove(int index){
            delete children[index];
            children.erase(children.begin() + index);
        }
        Component *GetChild(int index){
            return children[index];
        }
        void Run(){
            for(auto x : children)
                x->Run();
        }
    private:
        std::vector<Component*> children;        
};

class Leaf : public Component {
    public:
        Leaf(int i) : id(i){}
        ~Leaf(){}
        void Run(){
            std::cout<<"Leaf "<<id<<std::endl;
        }
    private:
        int id;
};

int main()
{
    Composite composite;
    composite.Add(new Leaf(123));
    composite.Run();
    return 0;
}
