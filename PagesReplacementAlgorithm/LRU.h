#pragma once
#include "PageManager.h"
#include "Stack.h"
/**
 * �������ʹ���û��㷨
 */
class LRU : public PageManager {
public:
    //�������ʹ���û��㷨
    LRU();
    //��������
    ~LRU();
    //����ҳ��
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //ҳ����ʼ�¼
    Stack<Page> pages;
    //�����ʵ�ҳ������ջ��
    void moveToTop(const int pageId);
};
