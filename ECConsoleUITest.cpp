// Test code for console UI
#include "ECTextViewImp.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUITextLabel.h"
#include "ECConsoleUIListBox.h"
#include "ECConsoleUIButton.h"
#include "ECAirport.h"
#include "ECFlight.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirlineSimulator.h"
#include <string>
#include <cmath>

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace  std;

// construct a simple UI
void AddHorizontalBars(ECConsoleUIView &view, int width) {
    string horizBar(width, '-');
    view.AddUIItem(new ECConsoleUITextLabel(0, 0, horizBar));
    view.AddUIItem(new ECConsoleUITextLabel(0, view.GetRowNumInView() - 1, horizBar));
}

void GetOne(const string& filename, set<string>& airports, ECAirlineOperation& AirOperation) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        istringstream ss(line);
        int type;
        ss >> type;

        switch (type) {
            case 1: {
                string code, desc;
                ss >> code;
                getline(ss, desc);
                airports.insert(code);
                break;
            }
            case 3: {
                string orig, dest;
                double time;
                int length;
                double cost;
                ss >> orig >> dest >> time >> length >> cost;
                AirOperation.AddFlight(orig, dest, time, length, cost);
                break;
            }
        }
    }
}

void AddLabelAndListBox(ECConsoleUIView &view, const string &labelText, int x, int y, const set<string> &choices, bool isOrigin = true) {
    view.AddUIItem(new ECConsoleUITextLabel(x, y, labelText));
    ECConsoleUIListBox *listBox = new ECConsoleUIListBox(x, y + 2, isOrigin ? 25 : 55, 8);
    for (const string& code : choices) {
        listBox->AddChoice(code);
    }
    listBox->Choose(0);
    view.AddUIItem(listBox);
}

void InitializeSearchComponents(ECConsoleUIView &view) {
    view.AddUIItem(new ECConsoleUITextLabel(13, 11, "---------------------"));
    view.AddUIItem(new ECConsoleUIButton(13, 12, 30, 12, "Search for flights"));
    view.AddUIItem(new ECConsoleUITextLabel(13, 13, "---------------------"));
    view.AddUIItem(new ECConsoleUITextLabel(19, 15, "Flights"));
}

ECConsoleUIListBox* InitializeFlightsBox(ECConsoleUIView &view) {
    ECConsoleUIListBox *flightsBox = new ECConsoleUIListBox(13, 17, 50, 19);
    flightsBox->AddChoice("Flight 123: EWR to IAH"); // Simulated example
    flightsBox->Choose(0);
    view.AddUIItem(flightsBox);
    return flightsBox;
}

void AddPassengerInput(ECConsoleUIView &view) {
}

void SimulateFlightSearch(ECConsoleUIView &view, ECConsoleUIListBox *flightsBox) {
    vector<ECFlightItinerary> itineraries;
    ECAirlineOperation* AirOperation = new ECAirlineOperation(); // Consider managing memory properly
    ECAirlineTicketing ticketing(AirOperation);
    ticketing.SearchForFlights("EWR", "IAH", itineraries); // Simulated user selections
    for (const auto& itinerary : itineraries) {
        flightsBox->AddChoice("Flight EWR to IAH"); // Adjusted to add dynamic data
    }
    view.Refresh();
}

// Main function refactored to use helpers
static void Test1(ECConsoleUIView &viewTest, const set<string>& airports) {
    viewTest.AddUIItem(new ECConsoleUITextLabel(10, 1, "Galaxy Airlines Flight Reservation System"));
    AddHorizontalBars(viewTest, viewTest.GetColNumInView());
    AddLabelAndListBox(viewTest, "Origination", 10, 4, airports, true);
    AddLabelAndListBox(viewTest, "Destination", 30, 4, airports, false);
    InitializeSearchComponents(viewTest);
    ECConsoleUIListBox* flightsBox = InitializeFlightsBox(viewTest);
    AddPassengerInput(viewTest);
    SimulateFlightSearch(viewTest, flightsBox);
}



int main(int argc, char *argv[]) {
    if (argc < 2)
        return 1; 
    string a = argv[1]; 

    ECTextViewImp wndTest;
    wndTest.AddStatusRow("UI test", "For demo only", true);

    ECConsoleUIView viewUI(&wndTest);

    ECAirlineOperation AirOperation;
    
    set<string> airports;

    GetOne(a, airports, AirOperation);
    Test1(viewUI, airports); 

    viewUI.Refresh();
    try {
        wndTest.Show();
    } catch(std::string ex) {
    }
    return 0;
}
