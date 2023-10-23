#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document newDocument(name, id, license_limit);
    documents[id] = newDocument;
}

void DocumentManager::addPatron(int patronID) {
    Patron newPatron(patronID);
    patrons[patronID] = newPatron;
}

int DocumentManager::search(string name) {
    for (auto& kv : documents) {
        if (kv.second.get_name() == name) {
            return kv.first;
        }
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  
    auto docIt = documents.find(docid);
    auto patIt = patrons.find(patronID);

 
    if (docIt != documents.end() && patIt != patrons.end() && docIt->second.borrow_out()) {
        
        patIt->second.borrowDocument(docid);
        return true;
    }

    return false;
}
void DocumentManager::returnDocument(int docid, int patronID) {
    bool documentExists = documents.count(docid) > 0;
    bool patronExists = patrons.count(patronID) > 0;

    if (documentExists && patronExists) {
        Document& doc = documents[docid];
        Patron& patron = patrons[patronID];

        doc.returnback();
        patron.returnDocument(docid);
    }
}


map<int, Document> DocumentManager::getDocuments() {
    return documents;
}

map<int, Patron> DocumentManager::getPatrons() {
    return patrons;
}
