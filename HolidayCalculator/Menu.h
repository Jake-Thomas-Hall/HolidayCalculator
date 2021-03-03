#pragma once

class MenuItem {
public:
    virtual ~MenuItem() {}
    virtual std::string item_text() const = 0;
    virtual void execute() = 0;
};

class MenuContainer {
private:
    std::string _strText;
    std::vector<std::unique_ptr<MenuItem>> _vecMenuItems;
    bool _boolExitMenu;
    int _iHighlightedIndex;
    HANDLE _hOutputConsole;
    HANDLE _hInputConsole;
public:
    MenuContainer(std::string const& text);
    void add_menu_item(std::unique_ptr<MenuItem> item);
    void execute();
    bool get_exit_menu() { return _boolExitMenu; }
    void set_exit_menu(bool exitMenu) { _boolExitMenu = exitMenu; }
};

class GeneralMenuItem : public MenuItem {
private:
    std::string _output;
protected:
    ClassContainer* _ptrClassContainer;
public:
    GeneralMenuItem(std::string output, ClassContainer* ptrClassContainer);
    std::string item_text() const { return _output; }
};

class AddPerson : public GeneralMenuItem {
public:
    AddPerson(std::string output, ClassContainer* ptrClassContainer) : GeneralMenuItem(output, ptrClassContainer) {};
    void execute();
};

class ViewCosts : public GeneralMenuItem {
public:
    ViewCosts(std::string output, ClassContainer* ptrClassContainer) : GeneralMenuItem(output, ptrClassContainer) {};
    void execute();
};

class MenuExit : public GeneralMenuItem {
private:
    MenuContainer* _menu_container;
public:
    MenuExit(std::string output, MenuContainer* menuContainer);
    void execute();
};

