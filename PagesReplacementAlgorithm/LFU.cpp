#include "LFU.h"
//���캯��
LFU::LFU() {
}

//��������
LFU::~LFU() {
    for(auto frame : frames) {
        delete frame.page;
    }
}

//����ҳ��
inline Missing LFU::requireFrame(const int pageId, int & frameId, const bool alter) {
    //ҳ������
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            //���ʴ���
            frame.page->visit++;
            return No;
        }
    }
    //���ڿ�ҳ��
    for(auto& frame : frames) {
        if(frame.page == nullptr) {
            frame.page = new Page;
            frame.page->id = pageId;
            frame.page->visit = 1;
            frameId = frame.id;
            return MissingPage;
        }
    }
    //ҳ���û�
    Page* p1 = frames[0].page;
    int min = p1->visit;
    for(auto frame : frames) {
        if(frame.page->visit < min) {
            p1 = frame.page;
            min = frame.page->visit;
        }
    }
    for(auto& frame : frames) {
        if(frame.page->id == p1->id) {
            delete frame.page;
            frame.page = new Page;
            frame.page->id = pageId;
            frame.page->visit = 1;
            frameId = frame.id;
            return MissingPageAndReplace;
        }
    }
    return No;
}
