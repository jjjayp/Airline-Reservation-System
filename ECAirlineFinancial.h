#ifndef ECAirlineFinancial_h
#define ECAirlineFinancial_h

#include "ECFlightItinerary.h"

class ECAirlineFinancial
{
public:
    ECAirlineFinancial();
    virtual ~ECAirlineFinancial();
    double Price(const ECFlightItinerary &itinerary) const;

private:
    static constexpr double FIXEDPRICE = 120.0;
};

#endif