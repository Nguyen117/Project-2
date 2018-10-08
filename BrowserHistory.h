#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(Webpage newSite)
	{
		navHistory.push_back(newSite);
		sitesVisited.push_back(newSite);
		navPos = navHistory.end();
		navPos = sitesVisted.end();
	}
    string back()
	{
		if (navPos != navHistory.begin())
		{
			navPos--;
		}
		else
		{
			cout << "You are at the beginning of the list" << endl;
			return navPos->getUrl;
		}
		
	}
	string forward()
	{
		if (navPos != navHistory.end())
		{
			navPos++;
		}
		else
		{
			cout << "You are at the end of the list" << endl;
			return navPos->getUrl;
		}
	}

    void readHistory(string fileName);

	string getUrl()
	{
		return navPos->getUrl;
	}
	size_t getNavSize()
	{
		return navHistory.size();
	}
	list<Webpage> getSitesVisited()
	{
		return sitesVisited;
	}

private:
    list<Webpage> navHistory;
    list<Webpage>::iterator navPos;
    list<Webpage> sitesVisited;
    int numSites;
};

void BrowserHistory::readHistory(string fileName) 
{
    string temp;
    int newTime;
    Webpage newSite;
    ifstream inFile(fileName.c_str());

    while(inFile >> temp) {
        if(temp == "new") {
            inFile >> temp >> newTime;
            newSite = Webpage(temp, time_t(newTime));
            visitSite(newSite);
        } else if(temp == "back") {
            back();
        } else if(temp == "forward") {
            forward();
        } else {
            throw logic_error("invalid command");
        }
    }
}
