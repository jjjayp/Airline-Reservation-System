#ifndef ECAirlineOperation_h
#define ECAirlineOperation_h

#include <string>
#include <map>
#include <vector>
#include "ECFlight.h"

class ECAirport;
class ECAirlineOperation
{
public:
    ECAirlineOperation();
    virtual ~ECAirlineOperation();
    std::vector<ECFlight*> GetFlightsFrom(const std::string& a) const;
    void AddFlight(const std::string &from, const std::string &to, double time, int passengers, double cost);

private:
    std::vector<ECFlight*> flights;
};

#endif