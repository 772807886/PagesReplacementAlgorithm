#pragma once
#include "PageFrame.h"
#include "Missing.h"
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
    virtual Missing requireFrame(const int pageId, int& frameId, const bool alter = false) = 0;
protected:
    //ҳ��
    PageFrame frames[TOTAL_PAGE_FRAMES];
};

//���캯��
inline PageManager::PageManager() {
    int i = 1;
    for(auto& frame : frames) {
        frame.id = i++;
    }
}

//��������
inline PageManager::~PageManager() {
}
