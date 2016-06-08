#include "CLOCK.h"
//���캯��
CLOCK::CLOCK() {
}

//��������
CLOCK::~CLOCK() {
    for(auto frame : frames) {
        delete frame.page;
    }
}

//����ҳ��
inline Missing CLOCK::requireFrame(const int pageId, int & frameId, const bool alter) {
    //ҳ������
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            //���ʴ���
            frame.page->visit = 1;
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
    while(frames[pointer].page->visit == 1) {
        frames[pointer++].page->visit = 0;
        if(pointer >= TOTAL_PAGE_FRAMES) {
            pointer -= TOTAL_PAGE_FRAMES;
        }
    }
    delete frames[pointer].page;
    frames[pointer].page = new Page;
    frames[pointer].page->id = pageId;
    frames[pointer].page->visit = 1;
    frameId = frames[pointer++].id;
    if(pointer >= TOTAL_PAGE_FRAMES) {
        pointer -= TOTAL_PAGE_FRAMES;
    }
    return MissingPageAndReplace;
}
