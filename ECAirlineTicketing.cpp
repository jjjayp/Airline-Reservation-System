#include "ECAirlineTicketing.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

ECAirlineTicketing::ECAirlineTicketing(ECAirlineOperation* op)
{
    operation = op;
}

void ECAirlineTicketing::SearchForFlights(const std::string &source, const std::string &destination, vector<ECFlightItinerary> &itineraries) {
    vector<ECFlight*> currentPath;
    DepthFirstSearch(source, destination, itineraries, currentPath, 0.0);
}

void ECAirlineTicketing::DepthFirstSearch(const std::string &currentAirport, const std::string &destination, vector<ECFlightItinerary> &itineraries, vector<ECFlight*> &currentPath, double lastArrivalTime) const {
    for (ECFlight* flight : currentPath)
    {
        if (flight->GetSource() == currentAirport)
        return;
    }
    if (currentAirport == destination) {
        ECFlightItinerary newItinerary;
        for (ECFlight* flight : currentPath) {
            newItinerary.AddSegment(*flight);
        }
        ECAirlineFinancial fin;
        double price = fin.Price(newItinerary);
        newItinerary.SetPrice(price);
        if (std::none_of(itineraries.begin(), itineraries.end(), [&newItinerary](const ECFlightItinerary& existingItinerary){
            return existingItinerary == newItinerary;
        })) {
            itineraries.push_back(newItinerary);
            cout << "Unique itinerary found with " << currentPath.size() << " segments." << endl;
        }
        return;
    }

    const vector<ECFlight*> departingFlights = operation->GetFlightsFrom(currentAirport);
    for (ECFlight* flight : departingFlights) {
        if (flight->GetDepartureTime() >= lastArrivalTime) {
            cout << "Visiting flight from " << flight->GetSource() << " to " << flight->GetDest() << endl;
            currentPath.push_back(flight);
            DepthFirstSearch(flight->GetDest(), destination, itineraries, currentPath, flight->GetArrivalTime());
            currentPath.pop_back();
        }
    }
}