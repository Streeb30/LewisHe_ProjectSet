#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;

class Search {
    public:
        virtual bool matches(const Episode*) const = 0;
        virtual void print(ostream& ost) const = 0;
        friend ostream& operator<<(ostream& ost, const Search& search);
};

class H_Search : public virtual Search {
    protected:
        string host;
    public:
        H_Search(const string& host);
        virtual bool matches(const Episode*) const override;
        virtual void print(ostream& ost) const override;
};

class C_Search : public virtual Search {
    protected:
        string category;
    public:
        C_Search(const string& category);
        virtual bool matches(const Episode*) const override;
        virtual void print(ostream& ost) const override;
};

class HorC_Search : public H_Search, public C_Search {
    public:
        HorC_Search(const string& host, const string& category);
        virtual bool matches(const Episode*) const override;
        virtual void print(ostream& ost) const override;
};
#endif
