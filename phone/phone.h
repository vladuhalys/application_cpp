#ifndef PHONE_H
#define PHONE_H

#include "../os/os.h"

class InterfacePhone abstract
{
    public:
    virtual void call() = 0;
    virtual void sendSMS() = 0;
    virtual void browseInternet() = 0;
};

class Phone : public InterfacePhone
{
protected:
    string _name;
    string _model;
    string _color;
    OS * _os = nullptr;
public:
    Phone() = delete;
    Phone(string name, string model, string color, OS * os) : _name(name), _model(model), _color(color), _os(os) {}

    void setName(string name) { this->_name = name; }
    string getName() { return this->_name; }
    void setModel(string model) { this->_model = model; }
    string getModel() { return this->_model; }
    void setColor(string color) { this->_color = color; }
    string getColor() { return this->_color; }
    void setOS(OS * os)
    {
        if (_os != nullptr)
        {
            delete _os;
        }
        this->_os = os;
    }
    OS * getOS() { return this->_os; }
    
    virtual ~Phone(){}
};
#endif // PHONE_H
