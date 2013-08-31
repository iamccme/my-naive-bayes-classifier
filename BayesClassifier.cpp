/*
 *BayesClassifier.cpp
 *@desc      朴素贝叶斯分类器
 *@author    chencheng
 *@email     cc@iamcc.me
 *@time      2013-06-06
 */

#include "BayesClassifier.h"
#include "PriorProbability.h"
#include "ClassConditionalProbability.h"

#include <iostream>
#include <algorithm>

bool cmp(ClassifyResult a, ClassifyResult b)
{
    return a.probility > b.probility;
}

ClassifyResult::ClassifyResult(void)
{
    this->probility = 0.0;
    this->classification = "";

}

//构造函数
BayesClassifier::BayesClassifier()
{
    trainPtr = new TrainingDataManager();
    spilterPtr = new ChineseSpliter("./friso-0.1/core/friso.ini");
}

BayesClassifier::~BayesClassifier()
{
    delete trainPtr;
    delete spilterPtr;
}

double BayesClassifier::zoomFactor = 10.0;

//计算给定的文本属性向量X在给定的分类Cj中的类条件概率

float BayesClassifier::clacProd(VS X, std::string Cj)
{
    float ret = 1.0;
    VSiter iter;
    for(iter = X.begin(); iter != X.end(); iter++)
    {
        std::string Xi = (*iter);
        ret *= ClassConditionalProbability::calculatePxc(Xi, Cj) * zoomFactor; 

    }

    ret *= PriorProbability::calculatePc(Cj);

    return ret;
}
//去掉停用词
VS BayesClassifier::DropStopWords(VS oldWords)
{
    VS newWords;
    VSiter iter;
    for(iter = oldWords.begin(); iter != oldWords.end(); iter++)
    {
        if(StopWordHandler::IsStopWord(*iter) == false)
            newWords.push_back(*iter);
    }

    return newWords;
}
        
//对给定的文本进行分类
std::string BayesClassifier::classify(std::string text)
{
    VS terms;
    spilterPtr->split(text, terms);
    terms = DropStopWords(terms);

    VS classifications = trainPtr->getTrainingClassifications();
    float probility = 0.0;
    std::vector<ClassifyResult> crs;

    VSiter iter;
    for(iter = classifications.begin(); iter != classifications.end(); iter++)
    {
        std::string Ci = (*iter);
        probility = clacProd(terms, Ci);

        ClassifyResult cr;
        cr.classification = Ci;
        cr.probility = probility;
        std::cout <<  "In process:"  << std::endl;
        std::cout << Ci <<  " : "  << probility << std::endl;
        crs.push_back(cr);

    }

    sort(crs.begin(), crs.end(), cmp);
    return crs[0].classification;
}


// 用于测试的主函数 
/*
int main(int argc, char* argv[])
{
    std::string text = "微软公司提出以446亿美元的价格收购雅虎中国网2月1日报道 美联社消息，微软公司提出以446亿美元现金加股票的价格收购搜索网站雅虎公司。微软提出以每股31美元的价格收购雅虎。微软的收购报价较雅虎1月31日的收盘价19.18美元溢价62%。微软公司称雅虎公司的股东可以选择以现金或股票进行交易。微软和雅虎公司在2006年底和2007年初已在寻求双方合作。而近两年，雅虎一直处于困境：市场份额下滑、运营业绩不佳、股价大幅下跌。对于力图在互联网市场有所作为的微软来说，收购雅虎无疑是一条捷径，因为双方具有非常强的互补性。(小桥)";
    BayesClassifier classfier;
    std::string result = classfier.classify(text);
    std::cout << "此项属于" << result << std::endl;

    return 0;
}
*/

