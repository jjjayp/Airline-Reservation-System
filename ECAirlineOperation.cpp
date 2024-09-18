//
//  ECAirlineOperation.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"

#include <iostream>
#include <string>

#include "ECFlight.h"
#include <algorithm>
#include <vector>
using namespace std;

ECAirlineOperation::ECAirlineOperation() {}

ECAirlineOperation::~ECAirlineOperation() {}

void ECAirlineOperation::AddFlight(const std::string &from, const std::string &to, double time, int passengers, double cost)
{
    flights.push_back(new ECFlight(from, to, time, passengers));
    std::cout << "Added flight: " << from << " to " << to << " at " << time << std::endl;
}
std::vector<ECFlight*> ECAirlineOperation::GetFlightsFrom(const std::string& a) const
{
    std::vector<ECFlight*> fromalr;
    std::copy_if(flights.begin(), flights.end(), std::back_inserter(fromalr), [&a](ECFlight* flight)
    {
        return flight->GetSource() == a;
    });
    return fromalr;
}