#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirport.h"
#include <algorithm>
#include "ECFlight.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

ECAirlineSimulator::ECAirlineSimulator()
{
    pAirlineOp = new ECAirlineOperation();
    pAirlineFin = new ECAirlineFinancial();
    pAirlineTicket = new ECAirlineTicketing(pAirlineOp);
}

ECAirlineSimulator::~ECAirlineSimulator()
{
    delete pAirlineOp;
    delete pAirlineFin;
    delete pAirlineTicket;
}

void ECAirlineSimulator::SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &flightlogs) const {
    pAirlineTicket->SearchForFlights(src, dest, flightlogs);
    std::cout << (flightlogs.empty() ? "No itineraries found from " + src + " to " + dest + "." :std::to_string(flightlogs.size()) + " itineraries found from " + src + " to " + dest + ":") << std::endl;
    for (auto &itinerary : flightlogs)
    {
        itinerary.Dump();
    }
}
    
void ECAirlineSimulator::AddAirport(const std::string &name, const std::string &code)
{
    ECAirportInfo::GetInstance().CreateAirport(name, code);
    std::cout << "Airport added: " << name << " (" << code << ")" << std::endl;
}

void ECAirlineSimulator::AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate)
{
    pAirlineOp->AddFlight(srcAirport, destAirport, tmDepart, maxPassengers, costOperate);
    cout << "Flight added: " << srcAirport << " -> " << destAirport << ", Departure: " << tmDepart << ", Max Passengers: " << maxPassengers << ", Cost: " << costOperate << endl;
}

void ECAirlineSimulator::DoneFlightAdding()
{
    f = true;
}

void ECAirlineSimulator::SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist)
{
    auto& info = ECAirportInfo::GetInstance();
    info.SetDistanceBtw(srcAirport, destAirport, dist);
    info.SetDistanceBtw(destAirport, srcAirport, dist);
}
void ECAirlineSimulator::PreferEarlyArrival() {}
void ECAirlineSimulator::PreferShortTime() {}
void ECAirlineSimulator::PreferLowPrice()
{
    std::sort(flightlogs.begin(), flightlogs.end(), [](const ECFlightItinerary &a, const ECFlightItinerary &b) {
        return a.GetPrice() < b.GetPrice();
    });
}