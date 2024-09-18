#ifndef ECAirlineSimulator_h
#define ECAirlineSimulator_h

#include <string>
#include <set>
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirport.h"
#include "ECFlight.h"

class ECAirlineOperation;
class ECAirlineTicketing;
class ECAirlineFinancial;
class ECFlightItinerary;

class ECAirlineSimulator
{
public:
    ECAirlineSimulator();
    virtual ~ECAirlineSimulator();
    void AddAirport(const std::string &name, const std::string &code);
    void SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist);
    void AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate);
    void DoneFlightAdding();
    void SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &flightlogs ) const;
    ECAirlineOperation *GetAirlineOp() { return pAirlineOp; }
    ECAirlineTicketing *GetAirlineTicketing() { return pAirlineTicket; }
    void PreferLowPrice();
    void PreferEarlyArrival();
    void PreferShortTime();
    
private:
    void Init();
    std::vector<ECFlightItinerary> flightlogs;
    ECAirlineOperation *pAirlineOp;
    ECAirlineFinancial *pAirlineFin;
    ECAirlineTicketing *pAirlineTicket;

    bool f;
};

#endif /* ECAirlineSimulator_h */