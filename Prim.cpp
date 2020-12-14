#include<iostream>
#include<conio.h>
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 
#include<fstream>
using namespace std;

int a[100][100];//ma tran trong so do thi
int n;//so dinh cua do thi
int m;//so canh cua do thi
int sc;//so canh cua cay khung nho nhat
int w;//Do dai cua cay khung nho nhat
int chuaxet[100];//mang danh dau danh sach dinh da them vao cay khung nho nhat.
int cck[100][3];//anh sach canh cua cay khung nho nhat

void nhap(void){
 int i, j, k;
 ifstream file("baotrum.txt", ios::in);//doc file
 file >> n;
 file >> m;
 cout<<"So dinh: "<<n<<endl;
 cout<<"So canh: "<<m<<endl;
 //khoi tao ma tran trong so cua do thi a[i][j] = MAX.
 for (i = 1; i <= n; i++){
  chuaxet[i] = TRUE;//Gán nhãn cho các dinh
  for (j = 1; j <= n; j++)
   a[i][j] = MAX;
 }

 //nhap danh sách cac canh tu file baotrum.txt
 for (int p = 1; p <= m; p++){
  file>>i>>j>>k;
  a[i][j] = k;
  a[j][i] = k;
 }
}

void PRIM(void){
 int k, top, min, l, t, u;
 int s[100];//mang chua cac dinh cua cay khung nho nhat
 sc = 0; w = 0; u = 1;
 top = 1;
 s[top] = u;// thêm dinh u bat ki vao dinh s[]
 chuaxet[u] = FALSE;
 while (sc<n - 1) {
  min = MAX;
  //tim canh co do dai nho nhat voi cac dinh trong mang s[].
  for (int i = 1; i <= top; i++){
   t = s[i];
   for (int j = 1; j <= n; j++){
    if (chuaxet[j] && min>a[t][j]){
     min = a[t][j];
     k = t;
     l = j;
    }
   }
  }
  sc++;
  w = w + min;
  //thêm vào danh sach canh cua cay khung
  cck[sc][1] = k;
  cck[sc][2] = l;
  chuaxet[l] = FALSE; 
  top++;
  s[top] = l;
 }
}
void Result(void){
 cout<<"Do dai ngan nhat:"<< w<<endl;
 cout<<"Cac canh cua cay khung nho nhat"<<endl;
 for (int i = 1; i <= sc; i++)
  cout<< cck[i][1]<<" "<< cck[i][2]<<endl;
}
int main(){
 nhap(); 
 PRIM();
 Result();
 getch();
}
