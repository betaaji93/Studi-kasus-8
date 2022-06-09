#include <iostream>

using namespace std;
class urut{
  friend istream& operator>>(istream& in, urut& a);
	friend ostream& operator<<(ostream& out, urut& a);
  public :
    void urutan();

  private :
    void ngurut(int, int, int&);
		void penukaran(int*, int* );
		void penukaran1(string*, string* );
		int data[10],n,low,high; 
    string nama[20];
    string pertama [20][20],b,k;
	  int pertama1 [20][20];
    
};
//proses//////////////////
void urut::ngurut(int dari,int n, int &tempat)
{
	int min = data[dari];
	string min1 =nama[dari];
	tempat = dari;
	for( int i=dari+1; i<n ;i++){
	if(data[i]<min){
		min=data[i];
		min1=nama[i];
		tempat=i;
		}	
	}
}
void urut::penukaran(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void urut::penukaran1(string *a, string *b){
	string temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void urut::urutan(){
	
	int t;
	for(int i= 0; i<n; i++){
	
		ngurut( i , n , t );
		penukaran( &data[i], &data[t] );
		penukaran1( & nama[i], &nama[t]);
		
	}
  //output//////////////////////

		cout<<"\nhasil :\n";
		cout<<"kode\t|\tJudul\t|";
		cout<<"\n==========================\n";
		for(int b=0;b<n;b++){
			for(int k=0;k<2;k++){
				if(k%2==0){
				pertama1[b][k]=data[b];
				cout<<pertama1[b][k]<<"\t\t|\t";
				}
				else{
				pertama[b][k]=nama[b];
				cout<<pertama[b][k]<<"\t|\t";
				}
	
		}
				cout<<"\n==========================";
		cout<<endl;
	}
  
}

//input//////////////////////
istream& operator >> (istream& in, urut& a){
  cout<<"masukkan banyak buku : ";
  int n;
	in>>a.n;
	for(int i= 0; i<a.n;i++){
	cout<<"masukkan nama buku "<<i<<" : ";
	cin>>a.nama[i];
    cout<<"masukkan kode buku"<<i<<" : ";
    cin>>a.data[i];
    cout<<"===========================\n";
	}
	cout<<"buku setelah diurutkan : \n";
	a.urutan();

	return in;
}
int main(){
	urut run;
	cin>>run;
}