//
//  ECAirport.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECAirport_h
#define ECAirport_h

#include <string>
#include <set>
#include <map>

class ECAirport 
{
public:
    ECAirport(); 
    ECAirport(const std::string &nameAP, const std::string &codeIATA);
    ECAirport(const ECAirport &rhs);
    std::string GetName() const;
    std::string GetCode() const;
    bool IsOperating();
    void SetOperating(bool f);
    
private:
    std::string call;
    std::string code;
    bool operating;
};

class ECAirportInfo
{
public:
    void CreateAirport(const std::string &call, const std::string &code);
    ECAirport &GetAirport(const std::string &code) const;
    void SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist);
    int GetBetweenDist(const std::string &ap1Code, const std::string &ap2Code) const;
    double CalcTime(const std::string &ap1Code, const std::string &ap2Code) const;
    static ECAirportInfo& GetInstance()
    {
        static ECAirportInfo instance;
        return instance;
    }
    void operator=(const ECAirportInfo&) = delete;
    
private:
    std::map<std::pair<std::string, std::string>, int> travel;
    std::map<std::string, ECAirport> airports;
    static constexpr double RATE = 500.0;
};

#endif /* ECAirport_h */