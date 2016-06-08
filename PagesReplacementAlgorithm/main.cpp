#include <iostream>
#include <ctime>
#include "LRU.h"
using namespace std;

#define __LENGTH__ 1000

int main(int argc, char** argv) {
    //ҳ������˳���
    int arr[__LENGTH__];
    srand((unsigned int)time(NULL));
    for(auto& i : arr) {
        //���ҳ��
        i = rand() % 100;
    }
    //ȱҳ�жϼ���
    unsigned int missing_page;
    //ҳ���û�����
    unsigned int page_algorithm;
    //�������ʹ���û��㷨
    LRU LRUManager;
    missing_page = page_algorithm = 0;
    //ҳ���
    int frame_id;
    //ģ������
    for(auto i : arr) {
        cout << "����ҳ�ţ�" << i << "\t";
        switch(LRUManager.requireFrame(i, frame_id)) {
        case No:
            cout << "ҳ�����У�ҳ��ţ�";
            break;
        case MissingPage:
            missing_page++;
            cout << "ҳ��δ���У�����ҳ����ҳ��ţ�";
            break;
        case MissingPageAndReplace:
            missing_page++;
            page_algorithm++;
            cout << "ҳ��δ���У�ҳ������������ҳ�沢�滻ҳ��ţ�";
            break;
        }
        cout << frame_id << endl;
    }
    //������
    cout << "LRU�㷨�����Ʋ���ҳ��ʧЧ"
        << missing_page
        << "�Σ����з���ҳ���û�"
        << page_algorithm
        << "�Ρ�"
        << endl;
    system("pause");
    return 0;
}
