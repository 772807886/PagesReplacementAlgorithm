#pragma once
#include "PageManager.h"
#include "Queue.h"
/**
 * �Ƚ��ȳ��û��㷨
 */
class FIFO : public PageManager {
public:
    //�������ʹ���û��㷨
    FIFO();
    //��������
    ~FIFO();
    //����ҳ��
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //ҳ����ʼ�¼
    Queue<Page> pages;
};
