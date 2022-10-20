// CPP program to illustrate
// Composite design pattern
#include <iostream>
#include <vector>
using namespace std;
 
class PageObject {
    public:
        virtual void Add(PageObject a)
        {
        }
        virtual void Remove()
        {
        }
        virtual void Delete(PageObject a)
        {
        }
};
 
class Page : public PageObject {
    public:
        void Add(PageObject a)
        {
            cout << "something is added to the page" << endl;
        }
        void Remove()
        {
            cout << "something is removed from the page" << endl;
        }
        void Delete(PageObject a)
        {
            cout << "something is deleted from page " << endl;
        }
};
 
class Copy : public PageObject {
    vector<PageObject> copyPages;
 
    public:
        void AddElement(PageObject a)
        {
            copyPages.push_back(a);
        }
 
        void Add(PageObject a)
        {
            cout << "something is added to the copy" << endl;
        }
        void Remove()
        {
            cout << "something is removed from the copy" << endl;
        }
        void Delete(PageObject a)
        {
            cout << "something is deleted from the copy";
        }
};
 
int main()
{
    Page a;
    Page b;
    Copy allcopy;
    allcopy.AddElement(a);
    allcopy.AddElement(b);
 
    allcopy.Add(a);
    a.Add(b);
 
    allcopy.Remove();
    b.Remove();
 
    return 0;
}