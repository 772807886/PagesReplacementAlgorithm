#pragma once
#include "PageManager.h"
/**
* ������û��㷨
*/
class LFU : public PageManager {
public:
    //������û��㷨
    LFU();
    //��������
    ~LFU();
    //����ҳ��
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
};
