#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <set>
#include <numeric>
using namespace std;

ECFlightItinerary::ECFlightItinerary() : estimatedPrice(0.0) {}

ECFlight *ECFlightItinerary::GetSegment(int segIndex) const {
    return (segIndex >= 0 && segIndex < static_cast<int>(s.size())) ? const_cast<ECFlight*>(&s[segIndex]) : nullptr;
}

double ECFlightItinerary::GetFlightTime() const {
    double totalFlightTime = 0.0;
    for (const ECFlight& flight : s) {
        totalFlightTime += flight.GetArrivalTime() - flight.GetDepartureTime();
    }
    return totalFlightTime;
}

int ECFlightItinerary::GetNumSegments() const
{
    return s.size();
}

double ECFlightItinerary::GetTimeAllSegments() const {
    return std::accumulate(s.begin(), s.end(), 0.0, 
        [](double total, const ECFlight& flight) {
            return total + flight.GetArrivalTime() - flight.GetDepartureTime();
        });
}

double ECFlightItinerary::GetArrivalTime() const {
    return !s.empty() ? s.back().GetArrivalTime() : 0.0;
}

double ECFlightItinerary::GetDepartTime() const {
    return !s.empty() ? s.front().GetDepartureTime() : 0.0;
}

double ECFlightItinerary::GetPrice() const {
    return GetFlightTime() * 120.0;
}

bool operator==(const ECFlightItinerary& lhs, const ECFlightItinerary& rhs) {
    if (lhs.GetNumSegments() != rhs.GetNumSegments()) {
        return false;
    }
    for (int i = 0; i < lhs.GetNumSegments(); ++i) {
        if (*lhs.GetSegment(i) != *rhs.GetSegment(i)) {
            return false;
        }
    }
    return true;
}
void ECFlightItinerary::Dump() const {}

void ECFlightItinerary::SetPrice(double price) {
    estimatedPrice = price;
}

void ECFlightItinerary::AddSegment(const ECFlight &flight)
{
    s.push_back(flight);
}