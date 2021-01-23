#include <iostream>

class Receiver {
    public:
        void Action(){
            std::cout<<"Receiver Action"<<std::endl;
        }
};

class Command {
    public:
        virtual ~Command(){}
        virtual void Run() = 0;
    protected:
        Command(){}
};

class Command_A : public Command {
    public:
        Command_A(Receiver *r): receiver(r){}
        ~Command_A(){
            delete receiver;
        }
        void Run(){
            receiver->Action();
        }
    private:
        Receiver *receiver;
};

class Invoker {
    public:
        void Set(Command *c){
            command = c;
        }
        void Invoke(){
            command->Run();
        }
    private:
        Command *command;
};

int main()
{
    Command_A cmdA(new Receiver());
    Invoker inv;
    inv.Set(&cmdA);
    inv.Invoke();
    return 0;
}
