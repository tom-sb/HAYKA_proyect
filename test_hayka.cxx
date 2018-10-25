#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <bsd/stdlib.h>
#include <ctime>
#include <unistd.h>
#include "connect.h"

using namespace std;

class TestCar{
	private:
	public:
		int random_data(int Min,int Max){
			int rnd = (Min+(arc4random() % (int)(Max-Min+1)));
			return rnd;
		}

		char id_car(){
		cout << "Ingrese el id del automovil\n";
		char id(5);
		cin >> id;
		return id;
		}

		int temp_motor(){
			return random_data (70,160);
		}
		int temp_refrigerante(){
			return random_data (20,100);
		}
		int temp_aire(){
			return random_data (20,80);
		}
		int temp_aceite_motor(){
			return random_data (80,120);
		}
		int temp_aceite_transmision(){
			return random_data (80,120);
		}
		int temp_combustible(){
			return random_data (50,80);
		}
		int temp_gases(){
			return random_data (371,593);
		}
		int angulo_ciguenal(){
			return random_data (180,360);
		}
		int angulo_arbol_levas(){
			return random_data (180,720);
		}
		int angulo_direccion(){
			return random_data (5,10);
		}
		int volante_motor(){
			return random_data (0,10000);
		}
		int flujo_masa_aire(){
			return random_data (0,200);
		}
		int poscicion_valvula_de_recirculacion(){
			return random_data (1,10);
		}
		int chispa(){
			return random_data (0,1);
		}
		int presion_combustible(){
			return random_data (0,60);
		}
		int velocidad(int speed,int accel){
			speed=speed+accel;
			if(speed<0)
				return speed=0;
			else if (speed>350)
				return speed=350;
			else
				return speed;
		}

		int rotacion_eje_transmision(){
			return random_data (0,10000);
		}
		int freno_antibloqueo(){
			return random_data (0,1);
		}
		int vuelco(){
			return random_data (0,5);
		}
		int inclinacion(){
			return random_data (-90,90);
		}
		int viraje(){
			return random_data (-180,180);
		}
		int par_motor(){
			return random_data (-200,200);
		}
		int aceleracion(){
			return random_data (-20,50);
		}
		int presion_deposito(){
			return random_data (0,280);
		}
		int alta_presion(){
			return random_data (0,176);
		}

		bool engine_start(bool state){
			if (state==1)
				return 1;
			else
				return 0;
		}

};

int main (void){

	TestCar test;
	int sp=0;
	int a = test.aceleracion();
	int v = test.velocidad(sp,a);
	char i(5) ;
	i = test.id_car();

	while(test.engine_start(1)!=0){
			ofstream file;
			file.open("value.txt");
			file << "v"<< i << endl;
			file << a << endl;
			file << test.alta_presion() << endl;
			file << test.angulo_arbol_levas() << endl;
			file << test.angulo_ciguenal() << endl;
			file << test.angulo_direccion() << endl;
			file << test.chispa() << endl;
			file << test.flujo_masa_aire() << endl;
			file << test.freno_antibloqueo() << endl;
			file << test.inclinacion() << endl;
			file << test.par_motor() << endl;
			file << test.poscicion_valvula_de_recirculacion() << endl;
			file << test.presion_deposito() << endl;
			file << test.rotacion_eje_transmision() << endl;
			file << test.temp_aceite_motor() << endl;
			file << test.temp_aceite_transmision() << endl;
			file << test.temp_aire() << endl;
			file << test.temp_combustible() << endl;
			file << test.temp_gases() << endl;
			file << test.temp_motor() << endl;
			file << test.temp_refrigerante() << endl;
			file << test.presion_combustible() << endl;
			file << v << endl;
			file << test.viraje() << endl;
			file << test.volante_motor() << endl;
			file << test.vuelco() << endl;
			file.close();
			sent_data();
			sp+=v;

	}

	return 0;
}
