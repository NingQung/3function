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
    cout << "三次函數的切線與平面上任一點的關係判斷。" << endl;
    cout << "輸入三次函數的各項係數，僅支援整數" << endl;
    cin >> xa >> xb >> xc >> xd;
    if(xa == 0){
        cout << "非三次函數" << endl;
        return 0;
    }
    cout << "請輸入點P座標，僅支援有限小數" << endl;
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
                cout << "過P的切線切點x座標位於"<< lx << endl;
            }else if(thfuma(floor(lx)) ==0){
                cout << "過P的切線切點x座標位於"<< floor(lx) << endl;
            }else{
                cout << "過P的切線切點x座標介於"<< floor(lx) << "與"<< lx << "之間"<< endl;
            }
        }else{
            for(int i = floor(lx);forsw == false;i = i-1){
                igo = thfuma(i);
                igt = thfuma(i-1);
                if(igo * igt <= 0){
                    forsw = true;
                    if(igo == 0){
                        cout << "過P的切線切點x座標位於"<< i << endl;
                    }else if(igt == 0){
                        cout << "過P的切線切點x座標位於"<< i-1 << endl;
                    }else{
                        cout << "過P的切線切點x座標介於"<< i-1 << "與"<< i << "之間"<< endl;
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
                cout << "過P的切線切點x座標位於"<< lx << endl;
            }else if(thfuma(floor(lx) +1) ==0){
                cout << "過P的切線切點x座標位於"<< floor(lx)+1 << endl;
            }else{
                cout << "過P的切線切點x座標介於"<< lx << "與"<< floor(lx)+1 << "之間"<< endl;
            }
        }else{
            for(int i = floor(lx)+1;forsw == false;i = i+1){
                igo = thfuma(i);
                igt = thfuma(i+1);
                if(igo * igt <= 0){
                    forsw = true;
                    if(igo == 0){
                        cout << "過P的切線切點x座標位於"<< i << endl;
                    }else if(igt == 0){
                        cout << "過P的切線切點x座標位於"<< i+1 << endl;
                    }else{
                        cout << "過P的切線切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
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
                cout << "過P的切線切點x座標位於"<< lax << endl;
            }else if(thfuma(floor(lax)+1) ==0){
                cout << "過P的切線切點x座標位於"<< floor(lax)+1 << endl;
            }else{
                cout << "過P的切線切點x座標介於"<< lax << "與"<< floor(lax)+1 << "之間"<< endl;
            }
        }else if(liy * thfuma(floor(lix)) <= 0){
            if(liy ==0){
                cout << "過P的切線切點x座標位於"<< lix << endl;
            }else if(thfuma(floor(lix)) ==0){
                cout << "過P的切線切點x座標位於"<< floor(lix) << endl;
            }else{
                cout << "過P的切線切點x座標介於"<< floor(lix) << "與"<< lix << "之間"<< endl;
            }
        }else{
            for(int i = floor(lax)+1;forsw == false;i = i+1){
                igo = thfuma(i);
                igt = thfuma(i+1);
                if(igo * igt <= 0){
                    forsw = true;
                    if(igo == 0){
                        cout << "過P的切線切點x座標位於"<< i << endl;
                    }else if(igt == 0){
                        cout << "過P的切線切點x座標位於"<< i+1 << endl;
                    }else{
                        cout << "過P的切線切點x座標介於"<< i << "與"<< i+1 << "之間"<< endl;
                    }
                }
            }
        }
    };
    
    if(xb != -3*xa*s){//有震盪
        if(xa > 0){//右上升
            if(s < st){//交換
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P在f(x)上
                if(maxy == 0 && miny == 0){//反曲
                    cout << "此點位於反曲點上，座標：" << s << "," << t << endl;
                }else if(maxy == 0){//極大值=0
                    cout << "切點位於極大值，x座標："<< maxx << endl;
                    rifinder(minx,miny);
                }else{//極小值=0
                    cout << "切點位於極小值，x座標："<< minx << endl;
                    lefinder(maxx,maxy);
                }
            }else if(maxy * miny <0){//有三解
                lefinder(maxx,maxy);//左
                mifinder(minx,miny,maxx,maxy);//中
                rifinder(minx,miny);//右
            }else if(maxy * miny >0){//有一解
                if(maxx >0){//往左
                    lefinder(maxx,maxy);
                }else{//往右
                    rifinder(minx,miny);
                }
            }else{//防錯
                cout << "Error hassei" << endl;
            }
        }else{//右下降
            if(s > st){//定義
                maxx = s;maxy = sgv;minx = st;miny = stgv;
            }else{
                maxx = st;maxy = stgv;minx = s;miny = sgv;
            }
            if(maxy == 0 || miny == 0){//P在f(x)上
                if(maxy == 0 && miny == 0){//反曲
                    cout << "此點位於反曲點上，座標：" << s << "," << t<< endl;
                }else if(maxy == 0){//極大值=0
                    cout << "切點位於極大值，x座標："<< maxx << endl;
                    lefinder(minx,miny);
                }else{//極小值=0
                    cout << "切點位於極小值，x座標："<< minx << endl;
                    rifinder(maxx,maxy);
                }
            }else if(maxy * miny <0){//有三解
                rifinder(minx,miny);//右
                mifinder(maxx,maxy,minx,miny);//中
                rifinder(minx,miny);//左
            }else if(maxy * miny >0){//有一解
                if(maxx >0){//往右
                    rifinder(maxx,maxy);
                }else{//往左
                    lefinder(minx,miny);
                }
            }else{//防錯
                cout << "Error hassei" << endl;
            }
        }
    }else{//g沒有震盪
        if(xa >0){//右上升
            if(sgv >0){
                lefinder(s,sgv);
            }else if(sgv < 0){
                rifinder(s,sgv);
            }else{
                cout << "此點位於反曲點上，座標：" << s << "," << t << endl;
            }
        }else{//右下降
            if(sgv > 0){
                rifinder(s,sgv);
            }else if(sgv < 0){
                lefinder(s,sgv);
            }else{
                cout << "此點位於反曲點上，座標：" << s << "," << t << endl;
            }
        }
    }
    
    system("pause");
}