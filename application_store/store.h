#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
using namespace std;

class Application
{
protected:
    string _name;
    string _version;
public:
    Application() = default;
    Application(string name, string version) : _name(name), _version(version) {}

    void setName(string name) { this->_name = name; }
    string getName() { return this->_name; }
    void setVersion(string version) { this->_version = version; }
    string getVersion() { return this->_version; }

    //post increment
    Application operator++(int)
    {
        Application temp = *this;
        this->_version = to_string(stod(this->_version) + 1);
        return temp;
    }

    //pre increment
    Application& operator++()
    {
        this->_version = to_string(stod(this->_version) + 1);
        return *this;
    }
    
    virtual ~Application(){}
};

ostream& operator<<(ostream& out, Application& rhs)
{
    out << "Name: " << rhs.getName() << endl;
    out << "Version: " << rhs.getVersion() << endl;
    return out;
}

class IStore
{
public:
    void virtual installApp(Application& app) = 0;
    void virtual uninstallApp(Application& app) = 0;
    void virtual updateApp(Application& app) = 0;
    void virtual showAllApps() = 0;
};



class Store : public IStore
{
protected:
    string _name;
    string _version;
    Application * _application = nullptr;
    int _size = 10;
    int _count = 0;
public:
    Store()
    {
        this->_application = new Application[_size];
    }
    Store(Application * application, int size) : _application(application), _size(size) {}

    void setName(string name) { this->_name = name; }
    string getName() { return this->_name; }
    void setVersion(string version) { this->_version = version; }
    string getVersion() { return this->_version; }

    void installApp(Application& app) override
    {
        if (_count < _size)
        {
            _application[_count] = app;
            _count++;
            cout << "Application installed successfully!" << endl;
        }
        else
        {
            cout << "Store is full!" << endl;
        }
    }

    void uninstallApp(Application& app) 
    {
        for (int i = 0; i < _count; i++)
        {
            if (_application[i].getName() == app.getName() && _application[i].getVersion() == app.getVersion())
            {
                for (int j = i; j < _count - 1; j++)
                {
                    _application[j] = _application[j + 1];
                }
                _count--;
                cout << "Application uninstalled successfully!" << endl;
                return;
            }
        }
        cout << "Application not found!" << endl;
    }

    void updateApp(Application& app) override
    {
        for (int i = 0; i < _count; i++)
        {
            if (_application[i].getName() == app.getName() && _application[i].getVersion() == app.getVersion())
            {
                cout << "Application updated successfully!" << endl;
                return;
            }
        }
        cout << "Application not found!" << endl;
    }

    void showAllApps() override
    {
        for (int i = 0; i < _count; i++)
        {
            cout << "Application " << i + 1 << ":" << endl;
            cout << _application[i] << endl;
        }
    }

    virtual ~Store() {}
};

class GooglePlay : public Store
{
public:
    GooglePlay() : Store() {}
    GooglePlay(Application * application, int size) : Store(application, size) {}
    
    ~GooglePlay() override
    {
        delete[] _application;
    }
};

class AppStore : public Store
{
public:
    AppStore() : Store() {}
    AppStore(Application * application, int size) : Store(application, size) {}

    ~AppStore() override
    {
        delete[] _application;
    }
};

#endif // STORE_H
