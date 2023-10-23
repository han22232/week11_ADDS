#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <vector>

class Patron
{
public:
    Patron();
    Patron(int PatronID);
    void borrowDocument(int docid);
    bool returnDocument(int docid);

private:
    int id;
    std::vector<int> borrowed;
};
#endif
