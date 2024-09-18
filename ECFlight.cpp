#include "ECFlight.h"
#include "ECAirport.h"
#include <iostream>
#include <tuple>
using namespace std;

ECFlight::ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn)
    : src(srcIn), dest(destIn), depart(tmDepartIn), maxPassengers(maxPassengersIn)
{
    src = srcIn;
    dest = destIn;
    depart = tmDepartIn;
    maxPassengers = maxPassengersIn;
}

ECFlight::~ECFlight()
{
}

void ECFlight::SetMaxNumPassengers(int m)
{
    maxPassengers = m;
}

std::string ECFlight::GetSource() const
{
    return src;
}

std::string ECFlight::GetDest() const
{
    return dest;
}

int ECFlight::GetMaxPassengers() const
{
    return maxPassengers;
}


bool operator==(const ECFlight& lhs, const ECFlight& rhs) {
    return lhs.GetSource() == rhs.GetSource() &&
           lhs.GetDest() == rhs.GetDest() &&
           lhs.GetDepartureTime() == rhs.GetDepartureTime() &&
           lhs.GetArrivalTime() == rhs.GetArrivalTime();
}

bool operator!=(const ECFlight& lhs, const ECFlight& rhs) {
    return !(lhs == rhs);
}

double ECFlight::GetDepartureTime() const
{
    return depart;
}

double ECFlight::GetArrivalTime() const
{
    return depart + ECAirportInfo::GetInstance().CalcTime(src, dest);
}