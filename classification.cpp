// Bu dosyada Classification isminde bir sınıf yarattık.
// Bu sınıf veri setini işleyerek öğrenecek ve sonucu ikili
// sınıf halinde çıktı olacak.

#include"classification.hpp"

#define SPACE ' '
#define EOL   '\n'

using namespace std;

int main(){

	vector<float> yas, boy, kilo;
	vector<string> cinsiyet;

	const char *p="Dosya Adı: ";
	cout<<p;
	string strTemp;
	cin>>strTemp;
	cout<<endl;

	ifstream readText(strTemp);
		string yorum="";
		string mainText="";
		if(readText.is_open()){
			char st;
			while(readText.get(st)){ //karakter oku
				if(st == '#'){
					while(readText.get(st)){
						if(st != EOL){
							yorum += st;
						}
						else{ 
							yorum += st;
							readText.get(st);
							break;
						}
					}
				}

				string temp="";
				while(st != SPACE){
					temp += st;
					readText.get(st);
				}
				yas.push_back(strtof((temp).c_str(),0));
				temp = "";

				readText.get(st);
				while(st != SPACE){
					temp += st;
					readText.get(st);
				}
				boy.push_back(strtof((temp).c_str(),0));
				temp ="";

				readText.get(st);
				while(st != SPACE){
					temp += st;
					readText.get(st);
				}
				kilo.push_back(strtof((temp).c_str(),0));
				temp ="";

				readText.get(st);
				while(st != EOL){
					temp += st;
					readText.get(st);
				}
				cinsiyet.push_back(temp);
				temp ="";
			}
		}
		readText.close();

		cout<<"Yorum      : "<<yorum<<endl;
		
		//Yaşları yazdır:
		cout<<"Yaşlar     : ";
		for(auto i=yas.begin(); i!=yas.end(); ++i)
			cout<<*i<<" ";
		cout<<endl;
		//Boyları yazdır:
		cout<<"Boylar     : ";
		for(auto i=boy.begin(); i!=boy.end(); ++i)
			cout<<*i<<" ";
		cout<<endl;
		//Kiloları yazdır:
		cout<<"Kilolar    : ";
		for(auto i=kilo.begin(); i!=kilo.end(); ++i)
			cout<<*i<<" ";
		cout<<endl;
		//Cinsiyetleri yazdır:
		cout<<"Cinsiyetler: ";
		for(auto i=cinsiyet.begin(); i!=cinsiyet.end(); ++i)
			cout<<*i<<" ";
		cout<<endl;

	float number = 10.0;
	string str ="23.5";
	number += strtof((str).c_str(),0);//string to float
	cout<<number<<endl;

	return 0;
}
