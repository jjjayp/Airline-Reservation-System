#ifndef ECFlight_h
#define ECFlight_h

#include <string>
#include <tuple>

class ECFlight 
{
public:
    ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn);
    virtual ~ECFlight();
    friend bool operator==(const ECFlight& lhs, const ECFlight& rhs);
    double GetDepartureTime() const;
    double GetArrivalTime() const;
    void SetMaxNumPassengers(int m);
    int GetMaxPassengers() const;
    friend bool operator!=(const ECFlight& lhs, const ECFlight& rhs);
    std::string GetSource() const;
    std::string GetDest() const;

private:
    std::string src;
    std::string dest;
    double depart;
    int maxPassengers;
};

#endif /* ECFlight_h */