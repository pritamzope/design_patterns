#include <iostream>

class Singleton {
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        static Singleton *GetInstance(){
            if(!instance)
                instance = new Singleton;
            return instance;
        }
        static void Remove(){
            if(instance)
                delete instance;
        }
        static void Run(){
            std::cout<<"Singleton"<<std::endl;
        }
    private:
        Singleton(){}
        static Singleton *instance;
};

Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton::GetInstance()->Run();
    Singleton::Remove();
    return 0;
}
