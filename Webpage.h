#pragma once

#include <string>
using namespace std;

class Webpage {
public:
    Webpage();
    Webpage(const string& webpageUrl, const time_t& timeVisited);
    string getUrl();
    time_t getTime();

private:
    string url;
    time_t time;
};
