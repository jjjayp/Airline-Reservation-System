//
//  ECConsoleUIListBox.h
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#ifndef ECConsoleUIListBox_h
#define ECConsoleUIListBox_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"

//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUIListBox : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this list box
    ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR );
    
    // Add a choice item
    void AddChoice(const std::string &text);
    
    // Choose an item
    void Choose(int rIndex);
    
    // Get the chosen one
    int GetChoice() const { return indice; }
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const override;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const override;

    // Are there any other function you might need to override?

    virtual void HdlKeyUp() override;
    virtual void HdlKeyDown() override;
    virtual bool IsHandlingKeys() const override
    {
        return true;
    }
    
private:
    bool IsSelectedIndexVisible() const;
    bool IsValidIndex(int index) const;
    int ConvertToRelativeIndex(int r) const;
    bool IsIndexVisible(int index) const;
    std::vector<std::string> options;
    int one;
    int countt;
    int indice;
};

#endif /* ECConsoleUIListBox_h */