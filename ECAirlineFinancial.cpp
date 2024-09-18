#include "ECAirlineFinancial.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include <string>
#include <iostream>
using namespace std;

ECAirlineFinancial::ECAirlineFinancial() {}

ECAirlineFinancial::~ECAirlineFinancial() {}

double ECAirlineFinancial::Price(const ECFlightItinerary &itinerary) const
{
    return itinerary.GetFlightTime() * FIXEDPRICE;
}