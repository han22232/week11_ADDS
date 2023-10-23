#include "Document.h"

Document::Document() {
    this->name = "";
    this->id = 0;
    this->sum_copies = 0;
    this->current_borrowed = 0;
}

Document::Document(string Doc_name, int Doc_id, int license_limit) {
    this->name = Doc_name;
    this->id = Doc_id;
    this->sum_copies = license_limit;
    this->current_borrowed = 0;
}

bool Document::borrow_out() {
    if(current_borrowed < sum_copies) {
        current_borrowed++;
        return true;
    } else {
        return false;
    }
}

void Document::returnback() {
    if(current_borrowed > 0) {
        current_borrowed--;
    }
}

string Document::get_name() {
    return name;
}

int Document::get_id() {
    return id;
}

void Document::set_id(string Doc_name) {
    this->name = Doc_name;
}

