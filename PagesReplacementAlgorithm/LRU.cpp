#include "LRU.h"
//���캯��
LRU::LRU() {
}

//��������
LRU::~LRU() {
    for(auto frame : frames) {
        delete frame.page;
    }
}

//����ҳ��
inline Missing LRU::requireFrame(const int pageId, int & frameId, const bool alter) {
    //ҳ������
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            moveToTop(pageId);
            return No;
        }
    }
    //���ڿ�ҳ��
    for(auto& frame : frames) {
        if(frame.page == nullptr) {
            frame.page = new Page;
            frame.page->id = pageId;
            frameId = frame.id;
            pages.push(*frame.page);
            return MissingPage;
        }
    }
    //ҳ���û�
    Page p1 = pages.getBottom();
    moveToTop(p1.id);
    pages.pop();
    for(auto& frame : frames) {
        if(frame.page->id == p1.id) {
            delete frame.page;
            frame.page = new Page;
            frame.page->id = pageId;
            frameId = frame.id;
            pages.push(*frame.page);
            return MissingPageAndReplace;
        }
    }
    return No;
}

//�����ʵ�ҳ������ջ��
inline void LRU::moveToTop(const int pageId) {
    Stack<Page> temp(pages.size());
    Page p1, p2;
    do {
        pages.pop(p1);
        temp.push(p1);
    } while(p1.id != pageId);
    temp.pop();
    while(!temp.isEmpty()) {
        temp.pop(p2);
        pages.push(p2);
    }
    pages.push(p1);
}
