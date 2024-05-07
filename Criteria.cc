
#include "Criteria.h"

Cat_Criteria::Cat_Criteria(const string& cat) : category(cat) {
}

bool Cat_Criteria::matches(const Photo& p) const {
    return p.getCategory() == this->category;
}

void Cat_Criteria::print(ostream& ost) const {
    ost << "Matches photos with the " << category << " category" << endl;
}

Date_Criteria::Date_Criteria(const Date& start, const Date& end) : startDate(start), endDate(end) {
}

bool Date_Criteria::matches(const Photo& p) const {
    bool startTrue = startDate <= p.getDate();
    bool endTrue = p.getDate() <= endDate;
    return startTrue && endTrue;
}

void Date_Criteria::print(ostream& ost) const {
    ost << "Matches photos taken between " << startDate << " and " << endDate << endl;
}

CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& cat) : Cat_Criteria(cat), Date_Criteria(start, end) {
}

bool CandD_Criteria::matches(const Photo& p) const {
    return Cat_Criteria::matches(p) && Date_Criteria::matches(p);
}

void CandD_Criteria::print(ostream& ost) const {
    Cat_Criteria::print(ost);
    Date_Criteria::print(ost);
}

ostream& operator<<(ostream& ost, const Criteria& c) {
    c.print(ost);
    return ost;
}

bool Criteria::matches(const Photo&) const {
    return false;
}

void Criteria::print(ostream& ost) const {
    ost << "No criteria specified." << endl;
}
