#ifndef ECFlightItinerary_h
#define ECFlightItinerary_h

#include <vector>
#include <string>

class ECFlight;
class ECAirlineFinancial;

class ECFlightItinerary
{
public:
    ECFlightItinerary();
    int GetNumSegments() const;
    ECFlight *GetSegment(int segIndex) const;
    double GetFlightTime() const;
    double GetTimeAllSegments() const;
    double GetDepartTime() const;
    double GetArrivalTime() const;
    double GetPrice() const;
    void SetPrice(double price);
    void AddSegment(const ECFlight &flight);
    friend bool operator==(const ECFlightItinerary& lhs, const ECFlightItinerary& rhs);
    void Dump() const;
    
private:
    std::vector<ECFlight> s;
    double estimatedPrice;
};

#endif /* ECFlightItinerary_h */
