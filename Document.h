#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
using namespace std;

class Document{
    
    public:
    Document();
    Document(string Doc_name, int Doc_id, int license_limit);
    bool borrow_out();
    void returnback();
    string get_name();
    int get_id();
    void set_id(string Doc_name);
private:
    string name;
    int id;
    int sum_copies;
    int current_borrowed;
    
};
#endif