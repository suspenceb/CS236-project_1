//
// Created by suspe on 10/26/2022.
//

#ifndef INC_236PROJECT_1_HEADER_H
#define INC_236PROJECT_1_HEADER_H
#include <string>
#include <vector>

using namespace std;

class Header {
private:
    vector<string> rows;

public:
    void tostring();
    void makeHeader(vector<string>);
};


#endif //INC_236PROJECT_1_HEADER_H
