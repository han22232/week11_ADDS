#include <vector>
#include "Patron.h"

Patron::Patron() {
    id = 0;
}

Patron::Patron(int PatronID) {
    id = PatronID;
}

void Patron::borrowDocument(int docid) {
    borrowed.push_back(docid);
}

bool Patron::returnDocument(int docid) {
    for (auto it = borrowed.begin(); it != borrowed.end(); ++it) {
        if (*it == docid) {
            borrowed.erase(it);
            return true;
        }
    }
    return false;
}
