/*
 *ClassConditionalProbability.cpp 

 *@author    chencheng
 *@email     chencheng1022@gmail.com
 *@date:     2013-05-31
 */

#include "ClassConditionalProbability.h"
#include <iostream>

TrainingDataManager* ClassConditionalProbability::tmd = new TrainingDataManager();
float ClassConditionalProbability::M = 0.0;

float ClassConditionalProbability::calculatePxc(std::string x, std::string c) 
{
    float ret = 0.0;
    float Nxc = tmd->getCountContainKeyOfClassification(c, x);
    float Nc = tmd->getTrainingFileCountOfClassification(c);
    float V = tmd->getTrainingClassifications().size();

    ret = (Nxc + 1) / (Nc + M + V);
            
    return ret;                    

};

// 用于测试的主函数//
/* 
int main(int argc, char* argv[])
{
    float Pxc;
    Pxc = ClassConditionalProbability::calculatePxc("汽车", "C000007");
    std::cout << "C000007中汽车的分类条件概率是：" << Pxc << std::endl;

    return 0;
}
*/
