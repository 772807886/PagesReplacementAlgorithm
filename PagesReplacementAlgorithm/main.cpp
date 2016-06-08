#include <iostream>
#include <ctime>
#include "LRU.h"
#include "FIFO.h"
#include "LFU.h"
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
    //ҳ���
    int frame_id;
    //�������ʹ���û��㷨
    LRU LRUManager;
    //ȱҳ�жϼ���
    unsigned int missing_page_lru = 0;
    //ҳ���û�����
    unsigned int page_algorithm_lru = 0;
    //ģ������
    cout << "******************** LRU ********************" << endl;
    for(auto i : arr) {
        cout << "����ҳ�ţ�" << i << "\t";
        switch(LRUManager.requireFrame(i, frame_id)) {
        case No:
            cout << "ҳ�����У�ҳ��ţ�";
            break;
        case MissingPage:
            missing_page_lru++;
            cout << "ҳ��δ���У�����ҳ����ҳ��ţ�";
            break;
        case MissingPageAndReplace:
            missing_page_lru++;
            page_algorithm_lru++;
            cout << "ҳ��δ���У�ҳ������������ҳ�沢�滻ҳ��ţ�";
            break;
        }
        cout << frame_id << endl;
    }
    cout << "#################### LRU ####################" << endl;
    //�Ƚ��ȳ��û��㷨
    FIFO FIFOManager;
    //ȱҳ�жϼ���
    unsigned int missing_page_fifo = 0;
    //ҳ���û�����
    unsigned int page_algorithm_fifo = 0;
    //ģ������
    cout << "******************** FIFO ********************" << endl;
    for(auto i : arr) {
        cout << "����ҳ�ţ�" << i << "\t";
        switch(FIFOManager.requireFrame(i, frame_id)) {
        case No:
            cout << "ҳ�����У�ҳ��ţ�";
            break;
        case MissingPage:
            missing_page_fifo++;
            cout << "ҳ��δ���У�����ҳ����ҳ��ţ�";
            break;
        case MissingPageAndReplace:
            missing_page_fifo++;
            page_algorithm_fifo++;
            cout << "ҳ��δ���У�ҳ������������ҳ�沢�滻ҳ��ţ�";
            break;
        }
        cout << frame_id << endl;
    }
    cout << "#################### FIFO ####################" << endl;
    //������û��㷨
    LFU LFUManager;
    //ȱҳ�жϼ���
    unsigned int missing_page_lfu = 0;
    //ҳ���û�����
    unsigned int page_algorithm_lfu = 0;
    //ģ������
    cout << "******************** LFU ********************" << endl;
    for(auto i : arr) {
        cout << "����ҳ�ţ�" << i << "\t";
        switch(LFUManager.requireFrame(i, frame_id)) {
        case No:
            cout << "ҳ�����У�ҳ��ţ�";
            break;
        case MissingPage:
            missing_page_lfu++;
            cout << "ҳ��δ���У�����ҳ����ҳ��ţ�";
            break;
        case MissingPageAndReplace:
            missing_page_lfu++;
            page_algorithm_lfu++;
            cout << "ҳ��δ���У�ҳ������������ҳ�沢�滻ҳ��ţ�";
            break;
        }
        cout << frame_id << endl;
    }
    cout << "#################### LFU ####################" << endl;
    //������
    cout << "�������ʹ���û��㷨LRU�㷨�����Ʋ���ҳ��ʧЧ"
        << missing_page_lru
        << "�Σ����з���ҳ���û�"
        << page_algorithm_lru
        << "�Ρ�"
        << endl;
    cout << "�Ƚ��ȳ��û��㷨FIFO�㷨�����Ʋ���ҳ��ʧЧ"
        << missing_page_fifo
        << "�Σ����з���ҳ���û�"
        << page_algorithm_fifo
        << "�Ρ�"
        << endl;
    cout << "������û��㷨LFU�㷨�����Ʋ���ҳ��ʧЧ"
        << missing_page_lfu
        << "�Σ����з���ҳ���û�"
        << page_algorithm_lfu
        << "�Ρ�"
        << endl;
    system("pause");
    return 0;
}
