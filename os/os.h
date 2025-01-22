#ifndef OS_H
#define OS_H

#include "../application_store/store.h"

class InterfaceOperationSystem abstract
{
    public:
    virtual void installApp(Application& app) = 0;
    virtual void uninstallApp(Application& app) = 0;
    virtual void updateApp(Application& app) = 0;
    virtual void showAllApps() = 0;
};

class OS : public InterfaceOperationSystem
{
protected:
    string _name;
    string _version;
    Store * _store = nullptr;
public:
    OS() = delete;
    OS(string name, string version, Store * _store) : _name(name), _version(version), _store(_store) {}

    void showAllApps() override
    {
        this->_store->showAllApps();
    }

    void installApp(Application& app) override
    {
        this->_store->installApp(app);
    }

    void uninstallApp(Application& app) override
    {
        this->_store->uninstallApp(app);
    }

    void updateApp(Application& app) override
    {
        this->_store->updateApp(app);
    }

    void setName(string name) { this->_name = name; }
    string getName() { return this->_name; }

    virtual ~OS(){}
};
#endif // OS_H
