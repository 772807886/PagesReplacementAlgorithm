#pragma once
#include "PageFrame.h"
#define TOTAL_PAGE_FRAMES 20
/**
 * ҳ�����
 */
class PageManager {
public:
    //ҳ����
    PageManager();
    //��������
    ~PageManager();
    //����ҳ��
    virtual bool requireFrame(const int pageId, int& frameId) = 0;
protected:
    //ҳ��
    PageFrame frames[TOTAL_PAGE_FRAMES];
};

//���캯��
inline PageManager::PageManager() {
    for(auto& frame : frames) {
        frame.page = nullptr;
    }
}

//��������
inline PageManager::~PageManager() {
}
