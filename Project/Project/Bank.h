//
// Created by Market Trading Simulator Team on 3/18/18.
//
#ifndef UNTITLED10_BANK_H
#define UNTITLED10_BANK_H

#include <iostream>
#include "Investment.h"
using namespace std;

class Bank {

private:
    //BANK VARIABLE DECLARATIONS
    float maxIR;
    float minIR;
    float IR;
    int maxFee;
    int minFee;
    int fee;
    string bankName;
    string bankType;
    int maxBonus;
    int minBonus;
    int bonus;

    float accountBalance;
    string accountHolderName;

    Investment investment1;
    Investment investment2;
    Investment investment3;
    Investment investment4;
    Investment investment5;


public:
    float getMaxIR();
    float getMinIR();
    float getIR();
    int getMaxFee();
    int getMinFee();
    int getFee();
    string getBankName();
    string getBankType();
    int getMaxBonus();
    int getMinBonus();
    int getBonus();

    float getAccountBalance();
    string getAccountHolderName();

    Investment getInvestment1();
    Investment getInvestment2();
    Investment getInvestment3();
    Investment getInvestment4();
    Investment getInvestment5();

    void setMaxIR(float);
    void setMinIR(float);
    void setIR(float);
    void setMaxFee(int);
    void setMinFee(int);
    void setFee(int);
    void setBankName(string);
    void setBankType(string);
    void setMaxBonus(int);
    void setMinBonus(int);
    void setBonus(int);

    void setAccountBalance(float);
    void setAccountHolderName(string);

    void setInvestment1(Investment userInvestment);
    void setInvestment2(Investment userInvestment);
    void setInvestment3(Investment userInvestment);
    void setInvestment4(Investment userInvestment);
    void setInvestment5(Investment userInvestment);

};

//Accessors for Bank Class
float Bank::getMaxIR() {
    return maxIR;
}

float Bank::getMinIR(){
    return minIR;
}

float Bank::getIR(){
    return IR;
}

int Bank::getMaxFee(){
    return maxFee;
}

int Bank::getMinFee() {
    return minFee;
}

int Bank::getFee(){
    return fee;
}

string Bank::getBankName() {
    return bankName;
}

string Bank::getBankType() {
    return bankType;
}

int Bank::getMaxBonus() {
    return maxBonus;
}

int Bank::getMinBonus() {
    return minBonus;
}

int Bank::getBonus() {
    return bonus;
}

float Bank::getAccountBalance() {
    return accountBalance;
}

string Bank::getAccountHolderName() {
    return accountHolderName;
}

Investment Bank::getInvestment1() {
    return investment1;
}

Investment Bank::getInvestment2() {
    return investment2;
}

Investment Bank::getInvestment3() {
    return investment3;
}

Investment Bank::getInvestment4() {
    return investment4;
}

Investment Bank::getInvestment5() {
    return investment5;
}

//Mutators for Bank Class
void Bank::setMaxIR(float maxIRinput){
    maxIR = maxIRinput;
}

void Bank::setMinIR(float  minIRinput){
    minIR = minIRinput;
}

void Bank::setIR(float IRinput){
    IR = IRinput;
}

void Bank::setMaxFee(int maxFeeInput){
    maxFee = maxFeeInput;
}

void Bank::setMinFee(int minFeeInput){
    minFee = minFeeInput;
}

void Bank::setFee(int feeInput){
    fee = feeInput;
}

void Bank::setBankName(string bankNameInput){
    bankName = bankNameInput;
}

void Bank::setBankType(string bankTypeInput){
    bankType = bankTypeInput;
}

void Bank::setMaxBonus(int maxBonusInput){
    maxBonus = maxBonusInput;
}

void Bank::setMinBonus(int minBonusInput){
    minBonus = minBonusInput;
}

void Bank::setBonus(int bonusInput){
    bonus = bonusInput;
}

void Bank::setAccountBalance(float accountBalanceInput) {
    accountBalance = accountBalanceInput;
}

void Bank::setAccountHolderName(string accountHolderNameInput){
    accountHolderName = accountHolderNameInput;
}

void Bank::setInvestment1(Investment userInvestment){
    investment1 = userInvestment;
}

void Bank::setInvestment2(Investment userInvestment){
    investment2 = userInvestment;
}

void Bank::setInvestment3(Investment userInvestment){
    investment3 = userInvestment;
}

void Bank::setInvestment4(Investment userInvestment){
    investment4 = userInvestment;
}

void Bank::setInvestment5(Investment userInvestment){
    investment5 = userInvestment;
}

#endif //UNTITLED10_BANK_H
