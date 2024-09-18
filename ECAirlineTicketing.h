#ifndef ECAirlineTicketing_h
#define ECAirlineTicketing_h

#include <vector>
#include <string>
#include "ECFlightItinerary.h"
#include "ECAirlineOperation.h"

class ECAirlineTicketing
{
public:
    explicit ECAirlineTicketing(ECAirlineOperation* operation);
    void SearchForFlights(const std::string &from, const std::string &to, std::vector<ECFlightItinerary> &itineraries);

private:
    ECAirlineOperation* operation;
    void DepthFirstSearch(const std::string &currentAirport, const std::string &destination, std::vector<ECFlightItinerary> &itineraries, std::vector<ECFlight*> &currentPath, double lastArrivalTime) const;
};
#endif /* ECAirlineTicketing_h */ 