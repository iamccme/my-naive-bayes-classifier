/*
 *PriorProbability.h 

 *@author    chencheng
 *@email     chencheng1022@gmail.com
 *@date:     2013-05-31
 */
#ifndef PRIOR_PROBABILITY_H
#define PRIOR_PROBABILITY_H


#include "comm.h"
#include "TrainingDataManager.h"

/* 该类为静态类，但是C++并没有静态类的定义。 该类不应该被实例化*/
class PriorProbability
{
    public:
    /*
     *先验概率
     @param c 给定的分类
     @return 给定条件下的先验概率
     * */
        static float calculatePc(std::string c); 
    private:
        static TrainingDataManager* tmd;

};

#endif

