#pragma once
#include "PageManager.h"
/**
 * �Ľ�ʱ���û��㷨�������ڴ��޸������
 */
class CLOCK2 : public PageManager {
public:
    //�Ľ�ʱ���û��㷨
    CLOCK2();
    //��������
    ~CLOCK2();
    //����ҳ��
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //ʱ��ָ��
    int pointer = 0;
};
