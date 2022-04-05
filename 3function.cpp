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
    cout << "輸入三次函數的各項係數，僅支援整數" << endl;
    cin >> xa >> xb >> xc >> xd;
    if(xa == 0){
        cout << "非三次函數" << endl;
        return 0;
    }
    cout << "請輸入點P座標，僅支援有限小數" << endl;
    cin >> s >> t;
    int tempa = 3*xa;
    st = float(-xb)/tempa;
    float sgv = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,s);
    float stgv = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,st);
    if(xb != -3*xa*s){//g有震盪
        if(xa > 0){//右上升
            if(s < st){
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P在f(x)上
                if(maxy == 0 && miny == 0){//反曲
                    cout << "此點位於反曲點上，座標：" << s << "," << t << endl;
                }else if(maxy == 0){//極大值=0
                    cout << "切點位於極大值，x座標："<< maxx << endl;
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                        cout << "切點x座標介於"<< minx << "與"<< floor(minx) + 1<< "之間"<< endl;
                    }else{
                        for(int i = floor(minx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                            }
                        }
                    }
                }else{//極小值=0
                    cout << "切點位於極小值，x座標："<< minx << endl;
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                        cout << "切點x座標介於"<< floor(maxx) << "與"<< maxx << "之間"<< endl;
                    }else{
                        for(int i = floor(maxx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                            }
                        }
                    }
                }
            }else if(maxy * miny <0){//有三解
                forsw = false;//左
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                    cout << "切點x座標介於"<< floor(maxx) << "與"<< maxx << "之間"<< endl;
                }else{
                    for(int i = floor(maxx);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                        }
                    }
                }
                forsw = false;//中
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                    cout << "切點x座標介於"<< maxx << "與"<< floor(maxx) + 1<< "之間"<< endl;
                }else if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                    cout << "切點x座標介於"<< floor(minx) << "與"<< minx << "之間"<< endl;
                }else{
                    for(int i = floor(maxx)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                        }
                    }
                }
                forsw = false;//右
                if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                    cout << "切點x座標介於"<< minx << "與"<< floor(minx) + 1<< "之間"<< endl;
                }else{
                    for(int i = floor(minx)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                        }
                    }
                }
            }else if(maxy * miny >0){//有一解
                if(maxx >0){//往左
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                        cout << "切點x座標介於"<< floor(maxx) << "與"<< maxx << "之間"<< endl;
                    }else{
                        for(int i = floor(maxx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                            }
                        }
                    }
                }else{//往右
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                        cout << "切點x座標介於"<< minx << "與"<< floor(minx)+1 << "之間"<< endl;
                    }else{
                        for(int i = floor(minx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                            }
                        }
                    }
                }
            }else{//防錯
                cout << "Error hassei" << endl;
            }
        }else{//右下降
            if(s > st){
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P在f(x)上
                if(maxy == 0 && miny == 0){//反曲
                    cout << "此點位於反曲點上，座標：" << s << "," << t<< endl;
                }else if(maxy == 0){//極大值=0
                    cout << "切點位於極大值，x座標："<< maxx << endl;
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                        cout << "切點x座標介於"<< floor(minx) << "與"<< minx << "之間"<< endl;
                    }else{
                        for(int i = floor(minx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                            }
                        }
                    }
                }else{//極小值=0
                    cout << "切點位於極小值，x座標："<< minx << endl;
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                        cout << "切點x座標介於"<< maxx << "與"<< floor(maxx)+1 << "之間"<< endl;
                    }else{
                        for(int i = floor(maxx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                            }
                        }
                    }
                }
            }else if(maxy * miny <0){//有三解
                forsw = false;//右
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                    cout << "切點x座標介於"<< maxx << "與"<< floor(maxx)+1 << "之間"<< endl;
                }else{
                    for(int i = floor(maxx)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                        }
                    }
                }
                forsw = false;//中
                if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)) <= 0){
                    cout << "切點x座標介於"<< floor(maxx) << "與"<< maxx << "之間"<< endl;
                }else if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)+1) <= 0){
                    cout << "切點x座標介於"<< minx << "與"<< floor(minx)+1 << "之間"<< endl;
                }else{
                    for(int i = floor(maxx);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                        }
                    }
                }
                forsw = false;//右
                if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                    cout << "切點x座標介於"<< floor(minx) << "與"<< minx << "之間"<< endl;
                }else{
                    for(int i = floor(minx);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                        }
                    }
                }
            }else if(maxy * miny >0){//有一解
                if(maxx >0){//往右
                    forsw = false;
                    if(maxy * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(maxx)+1) <= 0){
                        cout << "切點x座標介於"<< maxx << "與"<< floor(maxx)+1 << "之間"<< endl;
                    }else{
                        for(int i = floor(maxx)+1;forsw == false;i = i+1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                            }
                        }
                    }
                }else{//往左
                    forsw = false;
                    if(miny * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(minx)) <= 0){
                        cout << "切點x座標介於"<< floor(minx) << "與"<< minx << "之間"<< endl;
                    }else{
                        for(int i = floor(minx);forsw == false;i = i-1){
                            igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                            igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                            if(igo * igt <= 0){
                                forsw = true;
                                cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                            }
                        }
                    }
                }
            }else{//防錯
                cout << "Error hassei" << endl;
            }
        }
    }else{//g沒有震盪
        if(xa >0){//右上升
            if(sgv >0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)) <= 0){
                    cout << "切點x座標介於"<< floor(s) << "與"<< s << "之間"<< endl;
                }else{
                    for(int i = floor(s);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                        }
                    }
                }
            }else if(sgv < 0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)+1) <= 0){
                    cout << "切點x座標介於"<< s << "與"<< floor(s)+1 << "之間"<< endl;
                }else{
                    for(int i = floor(s)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                        }
                    }
                }
            }else{
                cout << "此點位於反曲點上，座標：" << s << "," << t << endl;
            }
        }else{//右下降
            if(sgv > 0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)+1) <= 0){
                    cout << "切點x座標介於"<< s << "與"<< floor(s)+1 << "之間"<< endl;
                }else{
                    for(int i = floor(s)+1;forsw == false;i = i+1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i+1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                        }
                    }
                }
            }else if(sgv < 0){
                forsw = false;
                if(sgv * thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,floor(s)) <= 0){
                    cout << "切點x座標介於"<< floor(s) << "與"<< s << "之間"<< endl;
                }else{
                    for(int i = floor(s);forsw == false;i = i-1){
                        igo = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i);
                        igt = thrfun(2*xa,xb - 3*xa*s,-2*xb*s,t - xc*s -xd,i-1);
                        if(igo * igt <= 0){
                            forsw = true;
                            cout << "切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
                        }
                    }
                }
            }else{
                cout << "此點位於反曲點上，座標：" << s << "," << t << endl;
            }
        }
    }
    
    system("pause");
}