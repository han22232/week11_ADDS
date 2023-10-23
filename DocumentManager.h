#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H
#include <string>
using namespace std;
#include <map>
#include "Document.h"
#include "Patron.h"

class DocumentManager
{
private:
    map<int, Document> documents;
    map<int, Patron> patrons;

public:
    void addDocument(string name, int id, int license_limit);

    void addPatron(int patronID);

    int search(string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

    bool borrowDocument(int docid, int patronID); // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

    void returnDocument(int docid, int patronID);

    map<int, Document> getDocuments();
    
    map<int, Patron> getPatrons();
};
#endif // DOCUMENTMANAGER_H
