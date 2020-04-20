//
//  main.cpp
//  CodeGladiators2020Cpp
//
//  Created by Atif Karbelkar on 19/04/20.
//  Copyright © 2020 Karbelkar Designs. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

class TestCase {
private:
    int members = 0;
    int winCountPrediction = 0;
    int sizeOfOPowers;
    int sizeOfGPowers;
    long* teamOPowers;
    long* teamGPowers;
public:
    TestCase ();
    TestCase (int, std::string, std::string);
    void process();
};

TestCase::TestCase() {};

TestCase::TestCase(int members, std::string teamOPowers, std::string teamGPowers) {
    this->members = members;
    std::istringstream ssO(teamOPowers);
    this->teamOPowers = new long[members];
    for(int i=0; ssO; i++){
        std::string pow;
        long teamOPower;
        ssO >> pow;
        std::stringstream(pow) >> teamOPower;
        teamOPowers[i] = teamOPower;
    }
    std::istringstream ssG(teamGPowers);
    this->teamGPowers = new long[members];
    for(int i=0; ssG; i++){
        std::string pow;
        long teamGPower;
        ssG >> pow;
        std::stringstream(pow) >> teamGPower;
        teamGPowers[i] = teamGPower;
    }
    sizeOfGPowers = sizeof(teamGPowers);
    sizeOfOPowers = sizeof(teamOPowers);
};

void TestCase::process() {
    int nG = sizeOfGPowers / sizeof(teamGPowers[0]);
    int nO = sizeOfOPowers / sizeof(teamOPowers[0]);
    std::sort(teamGPowers, teamGPowers+nG);
    std::sort(teamOPowers, teamOPowers+nO, std::greater<long>());
    for(int i=0; i<members; i++) {
        long gPow = teamGPowers[i];
        for(int j=0; j<members; j++) {
            long oPow = teamOPowers[j];
            if(gPow>oPow & oPow>=0) {
                teamOPowers[j] = -1;
                winCountPrediction++;
                break;
            }
        }
    }
    std::cout << winCountPrediction << "\n";
};

TestCase* accept(int testcaseCount){
    TestCase* testCases = new TestCase[testcaseCount];
    for(int i=0; i<testcaseCount; i++){
        std::string members;
        int memberCount = 0;
        getline(std::cin, members);
        std::stringstream(members) >> memberCount;
        std::string teamOPowers;
        getline(std::cin, teamOPowers);
        std::string teamGPowers;
        getline(std::cin, teamGPowers);
        TestCase testCase (memberCount, teamOPowers, teamGPowers);
        testCases[i] = testCase;
    }
    return testCases;
};

void process(int testCaseCount, TestCase* testCases) {
    for(int i=0; i<testCaseCount; i++) {
        TestCase testCase = testCases[i];
        testCase.process();
    }
};

int main(int argc, const char * argv[]) {
    std::string tcCount;
    getline(std::cin, tcCount);
    int testcaseCount = 0;
    std::stringstream(tcCount) >> testcaseCount;
    TestCase* testCases = accept(testcaseCount);
    process(testcaseCount, testCases);
    return 0;
}


