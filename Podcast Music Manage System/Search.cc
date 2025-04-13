#include "Search.h"

using namespace std;

ostream& operator<<(ostream& ost, const Search& search) {
    search.print(ost);
    return ost;
}

H_Search::H_Search(const string& host)
    : host(host) {}

bool H_Search::matches(const Episode* e) const {
    return e->getHost() == host;
}

void H_Search::print(ostream& ost) const {
    ost << "Search for host: " << host;
}

C_Search::C_Search(const string& category) : category(category) {}

bool C_Search::matches(const Episode* e) const {
    return e->getCategory() == category;
}

void C_Search::print(ostream& ost) const {
    ost << "Search for category: " << category;
}

HorC_Search::HorC_Search(const string& host, const string& category)
    : H_Search(host), C_Search(category) {}

bool HorC_Search::matches(const Episode* e) const {
    return H_Search::matches(e) || C_Search::matches(e);
}

void HorC_Search::print(ostream& ost) const {
    ost << "Search for host: " << host << " or category: " << category;
}
