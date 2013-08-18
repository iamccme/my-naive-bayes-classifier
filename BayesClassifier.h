/*
 *BayesClassifier.h
 * 朴素贝叶斯分类器
 *@author    chencheng
 *@email     chencheng1022@gmail.com
 *@time      2013-06-06
 */
#ifndef BAYES_CLASSIFIER_H
#define BAYES_CLASSIFIER_H


#include "comm.h"
#include "ChineseSpliter.h"
#include "TrainingDataManager.h"
#include "PriorProbability.h"
#include "ClassConditionalProbability.h"


class ClassifyResult
{
    public:
        ClassifyResult();
        double probility;
        std::string classification;
};

class BayesClassifier
{
    public:
        BayesClassifier();
        ~BayesClassifier();
        //计算给定的文本属性向量X在给定的分类Cj中的类条件概率
        float clacProd(VS X, std::string Cj);
        //去掉停用词
        VS DropStopWords(VS oldWords);
        //对给定的文本进行分类
        std::string classify(std::string text);

    private:
        TrainingDataManager* trainPtr;
        ChineseSpliter* spilterPtr;
        std::string TrainingDataPath;
        static double zoomFactor;
};

#endif
