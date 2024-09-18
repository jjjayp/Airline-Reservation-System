//
//  ECConsoleUIListBox.cpp
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#include "ECConsoleUIListBox.h"

using namespace std;

ECConsoleUIListBox::ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR): ECConsoleUIItem(xUL, yUL, xLR, yLR), one(0), indice(0)
{
    countt = GetHeight();
}

void ECConsoleUIListBox::AddChoice(const string &text)
{
    options.push_back(text);
}

void ECConsoleUIListBox::Choose(int rIndex)
{
    if (IsValidIndex(rIndex))
    indice = rIndex;
}

bool ECConsoleUIListBox::IsValidIndex(int index) const
{
    return (index >= 0) && (index < options.size());
}

int ECConsoleUIListBox::ConvertToRelativeIndex(int r) const
{
    return r - GetYUL();
}

bool ECConsoleUIListBox::IsIndexVisible(int index) const
{
    return (index >= one) && (index < one + countt);
}

std::string ECConsoleUIListBox::GetTextAtRow(int r) const {
    int relativeRow = ConvertToRelativeIndex(r);
    int itemIndex = one + relativeRow;
    
    if (IsIndexVisible(itemIndex))
    return (itemIndex == indice) ? (">" + options[itemIndex]) : options[itemIndex];
    return "";
}

int ECConsoleUIListBox::GetHighlightPosition(int &xLeft, int &xRight) const {
    if (!IsSelectedIndexVisible())
    return -1;
    xLeft = 0;  
    xRight = GetWidth(); 
    return indice - one; 
}

bool ECConsoleUIListBox::IsSelectedIndexVisible() const
{
    return (indice >= one) && (indice < one + countt);
}

void ECConsoleUIListBox::HdlKeyUp()
{
    if (indice > 0)
    {
        indice--;
        if (one > indice)
        one = indice;
    }
}

void ECConsoleUIListBox::HdlKeyDown() {
    if (indice < options.size() - 1)
    {
        indice++;
        int a = one + countt;
        if (indice >= a)
        one = indice - countt + 1;
    }
}