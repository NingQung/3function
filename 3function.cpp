#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
float thrfun(float a,float b,float c,float d,float x){
    float outro = a * pow(x,3) + b * pow(x,2) + c * x + d;
    return outro;
}
int main(){
    int xa,xb,xc,xd;
    float s,t,st;
    bool forsw;
    float igo,igt;
    float minx,miny,maxx,maxy;
    cout << "��J�T����ƪ��U���Y�ơA�Ȥ䴩���" << endl;
    cin >> xa >> xb >> xc >> xd;
    if(xa == 0){
        cout << "�D�T�����" << endl;
        return 0;
    }
    cout << "�п�J�IP�y�СA�Ȥ䴩�����p��" << endl;
    cin >> s >> t;
    int tempa = 3*xa;
    st = float(-xb)/tempa;
    float sgv = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,s);
    float stgv = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,st);
    if(xb != -3*xa*s){//g���_��
        if(xa > 0){//�k�W��
            if(s < st){
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P�bf(x)�W
                if(maxy == 0 && miny == 0){//�Ϧ�
                    cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t << endl;
                }else if(maxy == 0){//���j��=0
                    cout << "���I��󷥤j�ȡAx�y�СG"<< maxx << endl;
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                        cout << "���Ix�y�Ф���"<< minx << "�P"<< floor(minx) + 1<< "����"<< endl;
                    }else{
                        for(int i = floor(minx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                            }
                        }
                    }
                }else{//���p��=0
                    cout << "���I��󷥤p�ȡAx�y�СG"<< minx << endl;
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                        cout << "���Ix�y�Ф���"<< floor(maxx) << "�P"<< maxx << "����"<< endl;
                    }else{
                        for(int i = floor(maxx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                            }
                        }
                    }
                }
            }else if(maxy * miny <0){//���T��
                forsw = false;//��
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                    cout << "���Ix�y�Ф���"<< floor(maxx) << "�P"<< maxx << "����"<< endl;
                }else{
                    for(int i = floor(maxx);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                        }
                    }
                }
                forsw = false;//��
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                    cout << "���Ix�y�Ф���"<< maxx << "�P"<< floor(maxx) + 1<< "����"<< endl;
                }else if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                    cout << "���Ix�y�Ф���"<< floor(minx) << "�P"<< minx << "����"<< endl;
                }else{
                    for(int i = floor(maxx)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                        }
                    }
                }
                forsw = false;//�k
                if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                    cout << "���Ix�y�Ф���"<< minx << "�P"<< floor(minx) + 1<< "����"<< endl;
                }else{
                    for(int i = floor(minx)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                        }
                    }
                }
            }else if(maxy * miny >0){//���@��
                if(maxx >0){//����
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                        cout << "���Ix�y�Ф���"<< floor(maxx) << "�P"<< maxx << "����"<< endl;
                    }else{
                        for(int i = floor(maxx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                            }
                        }
                    }
                }else{//���k
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                        cout << "���Ix�y�Ф���"<< minx << "�P"<< floor(minx)+1 << "����"<< endl;
                    }else{
                        for(int i = floor(minx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                            }
                        }
                    }
                }
            }else{//����
                cout << "Error hassei" << endl;
            }
        }else{//�k�U��
            if(s > st){
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P�bf(x)�W
                if(maxy == 0 && miny == 0){//�Ϧ�
                    cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t<< endl;
                }else if(maxy == 0){//���j��=0
                    cout << "���I��󷥤j�ȡAx�y�СG"<< maxx << endl;
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                        cout << "���Ix�y�Ф���"<< floor(minx) << "�P"<< minx << "����"<< endl;
                    }else{
                        for(int i = floor(minx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                            }
                        }
                    }
                }else{//���p��=0
                    cout << "���I��󷥤p�ȡAx�y�СG"<< minx << endl;
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                        cout << "���Ix�y�Ф���"<< maxx << "�P"<< floor(maxx)+1 << "����"<< endl;
                    }else{
                        for(int i = floor(maxx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                            }
                        }
                    }
                }
            }else if(maxy * miny <0){//���T��
                forsw = false;//�k
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                    cout << "���Ix�y�Ф���"<< maxx << "�P"<< floor(maxx)+1 << "����"<< endl;
                }else{
                    for(int i = floor(maxx)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                        }
                    }
                }
                forsw = false;//��
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                    cout << "���Ix�y�Ф���"<< floor(maxx) << "�P"<< maxx << "����"<< endl;
                }else if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                    cout << "���Ix�y�Ф���"<< minx << "�P"<< floor(minx)+1 << "����"<< endl;
                }else{
                    for(int i = floor(maxx);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                        }
                    }
                }
                forsw = false;//�k
                if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                    cout << "���Ix�y�Ф���"<< floor(minx) << "�P"<< minx << "����"<< endl;
                }else{
                    for(int i = floor(minx);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                        }
                    }
                }
            }else if(maxy * miny >0){//���@��
                if(maxx >0){//���k
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                        cout << "���Ix�y�Ф���"<< maxx << "�P"<< floor(maxx)+1 << "����"<< endl;
                    }else{
                        for(int i = floor(maxx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                            }
                        }
                    }
                }else{//����
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                        cout << "���Ix�y�Ф���"<< floor(minx) << "�P"<< minx << "����"<< endl;
                    }else{
                        for(int i = floor(minx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                            }
                        }
                    }
                }
            }else{//����
                cout << "Error hassei" << endl;
            }
        }
    }else{//g�S���_��
        if(xa >0){//�k�W��
            if(sgv >0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)) <= 0){
                    cout << "���Ix�y�Ф���"<< floor(s) << "�P"<< s << "����"<< endl;
                }else{
                    for(int i = floor(s);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                        }
                    }
                }
            }else if(sgv < 0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)+1) <= 0){
                    cout << "���Ix�y�Ф���"<< s << "�P"<< floor(s)+1 << "����"<< endl;
                }else{
                    for(int i = floor(s)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                        }
                    }
                }
            }else{
                cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t << endl;
            }
        }else{//�k�U��
            if(sgv > 0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)+1) <= 0){
                    cout << "���Ix�y�Ф���"<< s << "�P"<< floor(s)+1 << "����"<< endl;
                }else{
                    for(int i = floor(s)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i << "�P"<< i+1 << "����"<< endl;
                        }
                    }
                }
            }else if(sgv < 0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)) <= 0){
                    cout << "���Ix�y�Ф���"<< floor(s) << "�P"<< s << "����"<< endl;
                }else{
                    for(int i = floor(s);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "���Ix�y�Ф���"<< i-1 << "�P"<< i << "����"<< endl;
                        }
                    }
                }
            }else{
                cout << "���I���Ϧ��I�W�A�y�СG" << s << "," << t << endl;
            }
        }
    }
    
    system("pause");
}