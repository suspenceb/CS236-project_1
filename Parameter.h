//
// Created by suspe on 10/4/2022.
//

#ifndef INC_236PROJECT_1_PARAMETER_H
#define INC_236PROJECT_1_PARAMETER_H
#include "string"

class Parameter {
private:
    std::string p;
public:
    const std::string &getP() const;

    void setP(const std::string &p);
};


#endif //INC_236PROJECT_1_PARAMETER_H
