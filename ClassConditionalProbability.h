/*
 *ClassConditionalProbability.h

 *@author    chencheng
 *@email     chencheng1022@gmail.com
 *@date:     2013-05-31
 */
#ifndef CLASS_CONDITIONLPROBABILITY_H
#define CLASS_CONDITIONLPROBABILITY_H



#include "comm.h"
#include "TrainingDataManager.h"

/* 该类为静态类，但是C++并没有静态类的定义。 该类不应该被实例化
 *计算类条件概率
 *@param x 给定的文本属性
 *@param c 给定的分类
 *@return 给定条件下的先验概率
*/
class ClassConditionalProbability
{
    public:
        static float calculatePxc(std::string x, std::string c); 
    private:
        static TrainingDataManager* tmd;
        static float M;

};

#endif

