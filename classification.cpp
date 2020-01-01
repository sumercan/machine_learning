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

	//Erkeklerin ve kadınların yaş ortalaması:
	float erkekYas=0;
	float erkekBoy=0;
	float erkekKil=0;
	float kadinYas=0;
	float kadinBoy=0;
	float kadinKil=0;
	int ks=0;//kadın sayısı
	int es=0;//erkek sayısı
	for(auto i=0; i<cinsiyet.size(); i++){
		if(cinsiyet.at(i) == "E"){
			erkekYas += yas.at(i);
			erkekBoy += boy.at(i);
			erkekKil += kilo.at(i);
			es++;
		}
		else{
			kadinYas += yas.at(i);
			kadinBoy += boy.at(i);
			kadinKil += kilo.at(i);
			ks++;
		}
	}

	erkekYas = erkekYas/es;
	erkekBoy = erkekBoy/es;
	erkekKil = erkekKil/es;
	kadinYas = kadinYas/ks;
	kadinBoy = kadinBoy/ks;
	kadinKil = kadinKil/ks;
	cout<<"Kadınların Yaş Ortalaması:"<<kadinYas<<endl;
	cout<<"Erkeklerin Yaş Ortalaması:"<<erkekYas<<endl;
	cout<<"Kadınların Boy Ortalaması:"<<kadinBoy<<endl;
	cout<<"Erkeklerin Boy Ortalaması:"<<erkekBoy<<endl;
	cout<<"Kadınların Kilo Ortalaması:"<<kadinKil<<endl;
	cout<<"Erkeklerin Kilo Ortalaması:"<<erkekKil<<endl;

	ofstream outputFile("output.txt");
	outputFile<<"kyo: "<<kadinYas<<" "<<"eyo: "<<erkekYas
	<<" "<<"kbo: "<<kadinBoy<<" "<<"ebo: "<<erkekBoy<<" "
	<<"kko: "<<kadinKil<<" "<<"eko: "<<erkekKil;
	outputFile.close();

	float number = 10.0;
	string str ="23.5";
	number += strtof((str).c_str(),0);//string to float
	cout<<number<<endl;

	return 0;
}
