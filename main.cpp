#include <QCoreApplication>

#include <iomanip>
#include <iostream>
#include <sstream>

class Base{
public:
    Base()= default;
    Base(int id){
        _id = id;
    }
    virtual void o() = 0;
    void print(){
        std::cout << "abfvausvf" << std::endl;
    }
protected:
    int _id;
};

class Sub : public Base{
public:

    void o() override{
        std::cout << "shi" << std::endl;
    }
};




using namespace std;
int main()
{
    Sub sub;
    sub.print();

return 0;

}
