#include<iostream>
#include<conio.h>
#define MAX 50
#define TRUE 1
#define FALSE  0
#include<fstream>
using namespace std;

int n, m, minl, connect;
int dau[500], cuoi[500], w[500];//mang chua dinh dau, cuoi va do dai cac canh cua do thi.
int daut[50], cuoit[50], father[50];

void Init(void){
 ifstream file("baotrum.txt", ios::in);
 file>>n>>m;
 cout<<"So dinh do thi: "<< n <<endl;
 cout<<"So canh do thi:" << m <<endl;
 
 //nhap danh sach ke`
 for (int i = 1; i <= m; i++){
  file>>dau[i]>>cuoi[i]>>w[i];
 }
}

void Heap(int First, int Last){
 int j, k, t1, t2, t3;
 j = First;
 
 while (j <= (Last / 2)){
  if ((2 * j) < Last && w[2 * j + 1] < w[2 * j])
   k = 2 * j + 1;
  else
   k = 2 * j;
  if (w[k] < w[j]){
   t1 = dau[j];
   t2 = cuoi[j];
   t3 = w[j];
   dau[j] = dau[k];
   cuoi[j] = cuoi[k];
   w[j] = w[k];
   dau[k] = t1;
   cuoi[k] = t2;
   w[k] = t3;
   j = k;
  }
  else j = Last;
 }
}

int Find(int i){
 int tro = i;
 while (father[tro] > 0)
 tro = father[tro];
 return(tro);
}

void Union(int i, int j){
 int x = father[i] + father[j];
 
 if (father[i] > father[j]) {
  father[i] = j;
  father[j] = x;
 }
 else {
  father[j] = i;
  father[i] = x;
 }
}

void Kruskal(void){
 int last, u, v, r1, r2, ncanh, ndinh;
 
 for (int i = 1; i <= n; i++)
  father[i] = -1;
 //su dung thuat toan vun dong de sap xep cac canh cua do thi theo thu tu khong giam cua do dai.
 for (int i = m / 2; i > 0; i--)
  Heap(i, m);
 last = m; ncanh = 0; ndinh = 0; minl = 0; connect = TRUE;
 //Lua chon canh bo sung vao cay khung
 while (ndinh < n - 1 && ncanh < m){
  ncanh = ncanh + 1;
  u = dau[1];
  v = cuoi[1];
  //Tìm goc cua phan hoach 1.
  r1 = Find(u);
  //Tìm goc cua phan hoach 2.
  r2 = Find(v);
  if (r1 != r2) {//neu 2 goc khac nhau thi canh dang xet co the them duoc vao do thi.
   ndinh = ndinh + 1;
   Union(r1, r2);
   daut[ndinh] = u;
   cuoit[ndinh] = v;
   minl = minl + w[1];
  }
  dau[1] = dau[last];
  cuoi[1] = cuoi[last];
  w[1] = w[last];
  last = last - 1;
  Heap(1, last);
 }
 if (ndinh != n - 1) connect = FALSE;
}

void Result(void){
 cout<<"Do dai cay khung nho nhat:"<< minl<<endl;
 cout<<"Cac canh cua cay khung nho nhat:"<<endl;
 for (int i = 1; i < n; i++)
  cout<< daut[i]<<" "<<cuoit[i]<<endl;
}

int main(){
 Init();
 Kruskal();
 Result();
 getch();
}
