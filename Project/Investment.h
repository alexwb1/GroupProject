//
// Created by Market Trading Simulator Team on 3/18/18.
//

#ifndef UNTITLED10_INVESTMENT_H
#define UNTITLED10_INVESTMENT_H
#include <iostream>
#include "Bank.h"

using namespace std;

class Investment {

private:
    string type;
    string name;
    int stability;
    float value;
    int previousValue;
    int predictedValue;
    int numberOwned;
    int valueOwned;
    int numberSold;
    float totalInvestment;

public:

    string getType();
    string getName();
    int getStability();
    float getValue();
    int getPreviousValue();
    int getPredictedValue();
    int getNumberOwned();
    int getValueOwned();
    int getNumberSold();

    float getTotalInvestment();

    void setType(string typeInput);
    void setName(string nameInput);
    void setStability(int stabilityInput);
    void setValue(float value);
    void setPreviousValue(int previousValueInput);
    void setPredictedValue(int predictedValueInput);
    void setNumberOwned(int numberOwnedInput);
    void setValueOwned(int valueOwnedInput);
    void setNumberSold(int numberSoldInput);

    void setTotalInvestment(float totalInvestmentInput);

};

//Accessors for Investment Class
string Investment::getType(){
    return type;
}

string Investment::getName(){
    return name;
}

int Investment::getStability() {
    return stability;
}

float Investment::getValue() {
    return value;
}

int Investment::getPreviousValue() {
    return previousValue;
}

int Investment::getPredictedValue() {
    return predictedValue;
}

int Investment::getNumberOwned() {
    return numberOwned;
}

int Investment::getValueOwned() {
    return valueOwned;
}

int Investment::getNumberSold() {
    return numberSold;
}

float Investment::getTotalInvestment() {
    return totalInvestment;
}

//Mutators for Investment Class
void Investment::setType(string typeInput){
    type = typeInput;
}

void Investment::setName(string nameInput) {
    name = nameInput;
}

void Investment::setStability(int stabilityInput) {
    stability = stabilityInput;
}

void Investment::setValue(float valueInput) {
    value = valueInput;
}

void Investment::setPreviousValue(int previousValueInput) {
    previousValue = previousValueInput;
}

void Investment::setPredictedValue(int predictedValueInput) {
    predictedValue = predictedValueInput;
}

void Investment::setNumberOwned(int numberOwnedInput) {
    numberOwned = numberOwnedInput;
}

void Investment::setValueOwned(int valueOwnedInput){
    valueOwned = valueOwnedInput;
}

void Investment::setNumberSold(int numberSoldInput) {
    numberSold = numberSoldInput;
}

void Investment::setTotalInvestment(float totalInvestmentInput) {
    this->totalInvestment = totalInvestmentInput;
}


#endif //UNTITLED10_INVESTMENT_H
