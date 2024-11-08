#include<bits/stdc++.h>
using namespace std;

class Sach{
	private:
		string tensach;
		string tentg;
		int nsx;
		int sl;
	public:
		Sach(){
		}
		Sach(string tensach, string tentg, int nsx , int sl ):tensach(tensach),tentg(tentg),nsx(nsx),sl(sl){
		}
		friend istream& operator >> (istream& in, Sach &a){
			cin.ignore();
			cout<<"nhap ten sach: "; 
			getline(in, a.tensach);
			cout<<"nhap ten tac gia: "; 
			getline(in, a.tentg);
			cout<<"nhap nam san xuat: "; 
			cin>>a.nsx;
			cout<<"nhap so luong sach: "; 
			cin>>a.sl;
			return in;
		}
		friend ostream& operator<< (ostream& out ,const Sach& a){
			out<<a.tensach<<" "<<a.tentg<<" "<<a.nsx<<" "<<a.sl;
			return out;
		}
		bool operator < (Sach& a){
			return this->sl < a.sl; 
		}
		string gettensach(){
			return tensach; 
		} 
		string gettentg(){
			return tentg; 
		} 
		int getnsx(){
			return nsx; 
		} 
		int getsl(){
			return sl;
		}
		
};

class QLSACH{
	private:
		list<Sach> s; 
	public:
		void nhapsach(){
			Sach a; 
			cin>>a;
			s.push_back(a); 
		} 
		void xuatsach(){
			for (list<Sach>::iterator a = s.begin(); a != s.end(); a++) {
            	cout << *a << endl;
       		}
		}
		void xapxep(){
			s.sort(); 
			xuatsach(); 
		}
		void maxnsx(){
			float m = s.begin()->getnsx();
			for( list<Sach>::iterator a = s.begin(); a != s.end(); a++){
				if(a->getnsx() > m) m= a->getnsx(); 
			} 
			cout<<"Sach co nam san xuat gan nhat la : "<<endl; 
			for(list<Sach>::iterator a= s.begin();a != s.end();a++ ){
				if(a->getnsx() == m){
					cout<< *a<<endl; 
				} 
			} 
		}
		void timkiem(){
			int check =0;
			string name;
			cin.ignore();
			getline(cin, name);
			for( list<Sach>::iterator a = s.begin(); a != s.end(); a++){
				if(a->gettensach() == name){
					cout << *a; 
					check =1;
				} 
			}
			if(check == 0 ) cout<<"khong tim thay sach co ten : "<<name<<endl;
		}
		void xoasach(string name){
			int check=0; 
			for( list<Sach>::iterator a = s.begin(); a!= s.end();){
				if(a->gettensach() == name){
					a = s.erase(a);
					check=1; 
//					cap nhat iterator tro den tk tiep theo , khong de a++ len vong for vi iterator se cong 2 lan 
				} 
				else{
					a++;
				}
			}
			if(check == 1) cout<<"khong co sach co ten: "<<name<<endl; 
		}
};

class app{
	private:
		QLSACH s;
	public:
		void menu(){
			int option;
			do{
				cout << "\n--- MENU ---\n";
	            cout << "1. Thêm sach\n";
	            cout << "2. Xuat danh sách sach\n";
	            cout << "3. Sap xep danh sach sach theo so luong\n";
	            cout << "4. Tim sach có nam xuat ban gan nhat\n";
	            cout << "5. Xoa sach theo ten sach\n";
	            cout << "6. tim kiem sach\n";
	            cout << "0. Thoat\n";
	            cout << "Chon thao tac: ";
	            cin >> option;
	            switch (option) {
	                case 1:
	                    s.nhapsach();
	                    break;
	                case 2:
	                    s.xuatsach();
	                    break;
	                case 3:
	                    s.xapxep();
	                    cout << "Ða sap xep danh sach.\n";
	                    break;
	                case 4:
	                    s.maxnsx();
	                    break;
	              
	                case 5: {
	                    string name;
	                    cout << "Nhap ten sach can xoa: ";
	                    cin >> name;
	                    s.xoasach(name);
	                    break;
	                }
	                case 6:{
	                	s.timkiem(); 
						break;
					} 
	                case 0:
	                    cout << "Thoat chuong trinh.\n";
	                    break;
	                default:
	                    cout << "Lua chon không hop le  Vui long thu lai.\n";
	            }
	        } while (option != 0);
		} 
}; 

int main(){
	app a;
    a.menu();
    return 0;	
}
