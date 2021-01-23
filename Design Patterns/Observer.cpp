#include <iostream>
#include <vector>

class Subject;

class Observer {
    public:
        virtual ~Observer(){}
        virtual int GetState() = 0;
        virtual void Update(Subject *) = 0;
};

class Observer_X : public Observer {
    public:
        Observer_X(int state){
            this->observer_state = state;
        }
        ~Observer_X(){}
        int GetState(){
            return this->observer_state;
        }
        void Update(Subject *s);
    private:
        int observer_state;
};

class Subject {
    public:
        virtual ~Subject(){}
        void Attach(Observer *o){
            observers.push_back(o);
        }
        void Detach(int index){
            observers.erase(observers.begin()+index);
        }
        void Notify(){
            for(auto x : observers)
                x->Update(this);
        }
        virtual int GetState() = 0;
        virtual void SetState(int) = 0;
    private:
        std::vector<Observer*> observers;
};

class Subject_X : public Subject {
    public:
        int GetState(){
            return subject_state;
        }
        void SetState(int state){
            subject_state = state;
        }
    private:
        int subject_state;
};

void Observer_X::Update(Subject *s){
    observer_state = s->GetState();
    std::cout<<"State Updated "<<observer_state<<std::endl;
}

int main()
{
    Observer_X ob1(123);
    Observer_X ob2(456);
    std::cout<<ob1.GetState()<<" "<<ob2.GetState()<<std::endl;
    Subject *s = new Subject_X();
    s->Attach(&ob1);
    s->Attach(&ob2);
    s->SetState(789);
    s->Notify();
    delete s;
    return 0;
}
