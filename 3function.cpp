#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){
    int xa,xb,xc,xd;
    float s,t,st;
    float minx,miny,maxx,maxy;
    bool forsw;
    float igo,igt;
    cout << "�T����ƪ����u�P�����W���@�I�����Y�P�_�C" << endl;
    cout << "��J�T����ƪ��U���Y�ơA�Ȥ䴩���" << endl;
    cin >> xa >> xb >> xc >> xd;
    if(xa == 0){
        cout << "�D�T�����" << endl;
        return 0;
    }
    cout << "�п�J�IP�y�СA�Ȥ䴩�����p��" << endl;
    cin >> s >> t;
    auto thfuma = [a = 2*xa,b = xb - 3*xa*s,c= -2*xb*s,d = t - xc*s -xd](float x){
        float outro = a * pow(x,3) + b * pow(x,2) + c * x + d;
        return outro;
    };
    int tempa = 3*xa;
    st = float(-xb)/tempa;
    float sgv = thfuma(s);
    float stgv = thfuma(st);
    auto lefinder = [thfuma = thfuma](float lx,float ly){
        bool forsw;
        float igo,igt;
        forsw = false;
        if(ly * thfuma(floor(lx)) <= 0){
            if(ly ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< lx << endl;
            }else if(thfuma(floor(lx)) ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< floor(lx) << endl;
            }else{
                cout << "�LP�����u���Ix�y�Ф���"<< floor(lx) << "�P"<< lx << "����"<< endl;
            }
        }else{
            for(int i = floor(lx);forsw == false;i = i-1){
                igo = thfuma(i);
                igt = thfuma(i-1);
                if(igo * igt <= 0){
                    forsw = true;
                    if(igo == 0){
                        cout << "�LP�����u���Ix�y�Ц��"<< i << endl;
                    }else if(igt == 0){
                        cout << "�LP�����u���Ix�y�Ц��"<< i-1 << endl;
                    }else{
                        cout << "�LP�����u���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                    }
                }
            }
        }
    };
    auto rifinder = [thfuma = thfuma](float lx,float ly){
        bool forsw;
        float igo,igt;
        forsw = false;
        if(ly * thfuma(floor(lx) +1) <= 0){
            if(ly ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< lx << endl;
            }else if(thfuma(floor(lx) +1) ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< floor(lx)+1 << endl;
            }else{
                cout << "�LP�����u���Ix�y�Ф���"<< lx << "�P"<< floor(lx)+1 << "����"<< endl;
            }
        }else{
            for(int i = floor(lx)+1;forsw == false;i = i+1){
                igo = thfuma(i);
                igt = thfuma(i+1);
                if(igo * igt <= 0){
                    forsw = true;
                    if(igo == 0){
                        cout << "�LP�����u���Ix�y�Ц��"<< i << endl;
                    }else if(igt == 0){
                        cout << "�LP�����u���Ix�y�Ц��"<< i+1 << endl;
                    }else{
                        cout << "�LP�����u���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                    }
                }
            }
        }
    };
    auto mifinder = [thfuma = thfuma](float lix,float liy,float lax,float lay){
        bool forsw;
        float igo,igt;
        forsw = false;
        if(lay * thfuma(floor(lax)+1) <= 0){
            if(lay ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< lax << endl;
            }else if(thfuma(floor(lax)+1) ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< floor(lax)+1 << endl;
            }else{
                cout << "�LP�����u���Ix�y�Ф���"<< lax << "�P"<< floor(lax)+1 << "����"<< endl;
            }
        }else if(liy * thfuma(floor(lix)) <= 0){
            if(liy ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< lix << endl;
            }else if(thfuma(floor(lix)) ==0){
                cout << "�LP�����u���Ix�y�Ц��"<< floor(lix) << endl;
            }else{
                cout << "�LP�����u���Ix�y�Ф���"<< floor(lix) << "�P"<< lix << "����"<< endl;
            }
        }else{
            for(int i = floor(lax)+1;forsw == false;i = i+1){
                igo = thfuma(i);
                igt = thfuma(i+1);
                if(igo * igt <= 0){
                    forsw = true;
                    if(igo == 0){
                        cout << "�LP�����u���Ix�y�Ц��"<< i << endl;
                    }else if(igt == 0){
                        cout << "�LP�����u���Ix�y�Ц��"<< i+1 << endl;
                    }else{
                        cout << "�LP�����u���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                    }
                }
            }
        }
    };
    
    if(xb != -3*xa*s){//���_��
        if(xa > 0){//�k�W��
            if(s < st){//�洫
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P�bf(x)�W
                if(maxy == 0 && miny == 0){//�Ϧ�
                    cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t << endl;
                }else if(maxy == 0){//���j��=0
                    cout << "���I��󷥤j�ȡAx�y�СG"<< maxx << endl;
                    rifinder(minx,miny);
                }else{//���p��=0
                    cout << "���I��󷥤p�ȡAx�y�СG"<< minx << endl;
                    lefinder(maxx,maxy);
                }
            }else if(maxy * miny <0){//���T��
                lefinder(maxx,maxy);//��
                mifinder(minx,miny,maxx,maxy);//��
                rifinder(minx,miny);//�k
            }else if(maxy * miny >0){//���@��
                if(maxx >0){//����
                    lefinder(maxx,maxy);
                }else{//���k
                    rifinder(minx,miny);
                }
            }else{//����
                cout << "Error hassei" << endl;
            }
        }else{//�k�U��
            if(s > st){//�w�q
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P�bf(x)�W
                if(maxy == 0 && miny == 0){//�Ϧ�
                    cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t<< endl;
                }else if(maxy == 0){//���j��=0
                    cout << "���I��󷥤j�ȡAx�y�СG"<< maxx << endl;
                    lefinder(minx,miny);
                }else{//���p��=0
                    cout << "���I��󷥤p�ȡAx�y�СG"<< minx << endl;
                    rifinder(maxx,maxy);
                }
            }else if(maxy * miny <0){//���T��
                rifinder(minx,miny);//�k
                mifinder(maxx,maxy,minx,miny);//��
                rifinder(minx,miny);//��
            }else if(maxy * miny >0){//���@��
                if(maxx >0){//���k
                    rifinder(maxx,maxy);
                }else{//����
                    lefinder(minx,miny);
                }
            }else{//����
                cout << "Error hassei" << endl;
            }
        }
    }else{//g�S���_��
        if(xa >0){//�k�W��
            if(sgv >0){
                lefinder(s,sgv);
            }else if(sgv < 0){
                rifinder(s,sgv);
            }else{
                cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t << endl;
            }
        }else{//�k�U��
            if(sgv > 0){
                rifinder(s,sgv);
            }else if(sgv < 0){
                lefinder(s,sgv);
            }else{
                cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t << endl;
            }
        }
    }
    
    system("pause");
}