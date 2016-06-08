#include "FIFO.h"
//���캯��
FIFO::FIFO() {
}

//��������
FIFO::~FIFO() {
}

//����ҳ��
inline Missing FIFO::requireFrame(const int pageId, int & frameId, const bool alter) {
    //ҳ������
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            return No;
        }
    }
    //���ڿ�ҳ��
    for(auto& frame : frames) {
        if(frame.page == nullptr) {
            frame.page = new Page;
            frame.page->id = pageId;
            frameId = frame.id;
            pages.enqueue(*frame.page);
            return MissingPage;
        }
    }
    //ҳ���û�
    Page p1;
    pages.dequeue(p1);
    for(auto& frame : frames) {
        if(frame.page->id == p1.id) {
            delete frame.page;
            frame.page = new Page;
            frame.page->id = pageId;
            frameId = frame.id;
            pages.enqueue(*frame.page);
            return MissingPageAndReplace;
        }
    }
    return No;
}
