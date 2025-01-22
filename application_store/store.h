#ifndef STORE_H
#define STORE_H

#include <iostream>
using namespace std;

class IApplication
{
public:
    void virtual getInfo() = 0;
};

class Application : public IApplication
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

    void getInfo() override
    {
        cout << "Name: " << this->_name << endl;
        cout << "Version: " << this->_version << endl;
    }

    virtual ~Application(){}
};

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
            _application[i].getInfo();
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
