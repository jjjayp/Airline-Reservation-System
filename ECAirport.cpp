#include "ECAirport.h"
#include <stdexcept>
#include <utility>

ECAirport::ECAirport()
{
    operating = false;
    code = "";
    call = "";
}

ECAirport::ECAirport(const std::string &nameAP, const std::string &codeIATA)
{
    operating = true;
    call = nameAP;
    code = codeIATA;
}

ECAirport::ECAirport(const ECAirport &rhs)
{
    operating = rhs.operating;
    call = rhs.call;
    code = rhs.code;
}

std::string ECAirport::GetName() const {
    return call;
}

std::string ECAirport::GetCode() const {
    return code;
}

bool ECAirport::IsOperating() {
    return operating;
}


void ECAirport::SetOperating(bool f) {
    operating = f;
}

double ECAirportInfo::CalcTime(const std::string &ap1Code, const std::string &ap2Code) const {
    int travel = GetBetweenDist(ap1Code, ap2Code);
    return static_cast<double>(travel) / 500.0;
}

void ECAirportInfo::CreateAirport(const std::string &call, const std::string &code) {
    if (airports.find(code) == airports.end())
        airports[code] = ECAirport(call, code);
}

int ECAirportInfo::GetBetweenDist(const std::string &ap1Code, const std::string &ap2Code) const {
    auto it = travel.find(std::make_pair(ap1Code, ap2Code));
    return it->second;
}

void ECAirportInfo::SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist) {
    travel[std::make_pair(ap1Code, ap2Code)] = dist;
    travel[std::make_pair(ap2Code, ap1Code)] = dist; 
}

ECAirport &ECAirportInfo::GetAirport(const std::string &code) const {
    auto it = airports.find(code);
    return const_cast<ECAirport&>(it->second); 
}