#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
    documents[id] = Document(name, id, license_limit);
}

void DocumentManager::addPatron(int patronID) {
    patrons[patronID] = Patron(patronID);
}

int DocumentManager::search(string name) {
    auto it = find_if(documents.begin(), documents.end(), [&](const pair<int, Document>& doc) { return doc.second.get_name() == name; });
    return it != documents.end() ? it->first : 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    // Simplifying condition check using logical AND operator
    if (documents.count(docid) && patrons.count(patronID) && documents[docid].borrow_out()) {
        patrons[patronID].borrowDocument(docid);
        return true;
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    // Check if both document and patron exist before trying to return the document
    if (documents.count(docid) && patrons.count(patronID)) {
        documents[docid].returnback();
        patrons[patronID].returnDocument(docid);
    }
}

map<int, Document> DocumentManager::getDocuments() {
    return documents;
}

map<int, Patron> DocumentManager::getPatrons() {
    return patrons;
}