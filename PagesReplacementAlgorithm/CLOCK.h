#pragma once
#include "PageManager.h"
/**
 * ʱ���û��㷨
 */
class CLOCK : public PageManager {
public:
    //ʱ���û��㷨
    CLOCK();
    //��������
    ~CLOCK();
    //����ҳ��
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //ʱ��ָ��
    int pointer = 0;
};
