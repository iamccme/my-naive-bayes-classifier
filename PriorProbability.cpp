/*
 *PriorProbability.cpp
 *@desc      计算先验概率
 *@author    chencheng
 *@email     cc@iamcc.me
 *@date:     2013-05-31
 */

#include "PriorProbability.h"
#include <iostream>

TrainingDataManager* PriorProbability::tmd = new TrainingDataManager();

float PriorProbability::calculatePc(std::string c) 
{
    float ret = 0.0;
    float Nc = tmd->getTrainingFileCountOfClassification(c);
    float N = tmd->getTrainingFileCount();

    if(N != 0)
        ret = Nc / N;
            
    return ret;                    

};

// 用于测试的主函数
/*
int main(int argc, char* argv[])
{
    float Pc;
    Pc = PriorProbability::calculatePc("C000007");
    std::cout << "C000007的先验概率是：" << Pc << std::endl;

    return 0;
}
*/
