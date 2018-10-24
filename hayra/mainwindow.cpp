#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QTime>
#include <sys/stat.h>

using namespace std;

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    this->ui->setupUi(this);
    QPixmap logo;
    logo.load("/home/damon/Hayka/logo.png");
    this->ui->labelHayka->setPixmap(logo);
    actualizar();
    actualizar2();
    actualizar3();
    actualizar4();
    actualizar5();
    QPixmap image;
    image.load("/home/damon/Hayka/car.png");
    /*ifstream in3("/home/damon/Hayka/value3.txt");
    ifstream in4("/home/damon/Hayka/value4.txt");
    ifstream in5("/home/damon/Hayka/value5.txt");
    if(in3){
        QWidget *c=new QWidget;
        c=this->ui->tab_3;
        this->ui->tabWidget->addTab(,"car 3");

        actualizar3();
    }
    if(in4) actualizar4();
    if(in5) actualizar5();*/

    
}
mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::actualizar(){
    ifstream in("/home/damon/Hayka/info_2.txt");
    QPixmap image;
    image.load("/home/damon/Hayka/car.png");
    this->ui->label_21->setPixmap(image);

      string s,line;
      int contador=0;
      getline(in,line);
      while(getline(in, line)){
        s += line + "\n";
        int val=stoi(line);
        if(contador==0) this->ui->temp_motor->setValue(val);
        if(contador==1) this->ui->temp_refrigerante->setValue(val);
        if(contador==2) this->ui->temp_aire->setValue(val);
        if(contador==3) this->ui->temp_aceite_m->setValue(val);
        if(contador==4) this->ui->temp_aceite_t->setValue(val);
        if(contador==5) this->ui->temp_combust->setValue(val);
        if(contador==6) this->ui->temp_gases->setValue(val);
        if(contador==7) this->ui->angulo_ciguenal->setValue(val);
        if(contador==8) this->ui->ang_arbol_levas->setValue(val);
        if(contador==9) this->ui->aceleracion->setValue(val);
        if(contador==10) this->ui->ang_direc->setValue(val);
        if(contador==11) this->ui->volante_motor->setValue(val);
        if(contador==12) this->ui->flujo_masa_aire->setValue(val);
        if(contador==13) this->ui->pos_val_recircul->setValue(val);
        if(contador==14) this->ui->chispa->setValue(val);
        if(contador==15) this->ui->pres_combust->setValue(val);
        if(contador==16) this->ui->velocidad->setValue(val);
        if(contador==17) this->ui->rot_eje_trans->setValue(val);
        if(contador==18) this->ui->freno_antiblo->setValue(val);
        if(contador==19) this->ui->vuelco->setValue(val);
        if(contador==20) this->ui->inclinacion->setValue(val);
        if(contador==21) this->ui->viraje->setValue(val);
        if(contador==22) this->ui->par_motor->setValue(val);
        if(contador==23) this->ui->aceleracion->setValue(val);
        if(contador==24) this->ui->pres_deposito->setValue(val);
        if(contador==25) this->ui->alta_presion->setValue(val);
        if(contador<5 && val<=300){
            image.load("/home/damon/Hayka/image1.png");
            this->ui->label_21->setPixmap(image);
        }
        if(contador>5 && contador<10 && val<=300){
            image.load("/home/damon/Hayka/image2.png");
            this->ui->label_21->setPixmap(image);
        }
        if(contador>10 && contador<15 && val<=300){
            image.load("/home/damon/Hayka/image3.png");
            this->ui->label_21->setPixmap(image);
        }
        if(contador>15 && contador<20 && val<=300){
            image.load("/home/damon/Hayka/image4.png");
            this->ui->label_21->setPixmap(image);
        }
        if(contador>20 && contador<27 && val<=300){
            image.load("/home/damon/Hayka/image5.png");
            this->ui->label_21->setPixmap(image);
        }
        contador++;
    }
}
void mainwindow::actualizar2(){
    ifstream in("/home/damon/Hayka/info_3.txt");
    QPixmap image;
    image.load("/home/damon/Hayka/car.png");
    this->ui->label_25->setPixmap(image);

      string s,line;
      int contador=0;
      getline(in,line);
      while(getline(in, line)){
        s += line + "\n";
        int val=stoi(line);
        if(contador==0) this->ui->temp_motor_3->setValue(val);
        if(contador==1) this->ui->temp_refrigerante_3->setValue(val);
        if(contador==2) this->ui->temp_aire_3->setValue(val);
        if(contador==3) this->ui->temp_aceite_m_3->setValue(val);
        if(contador==4) this->ui->temp_aceite_t_3->setValue(val);
        if(contador==5) this->ui->temp_combust_3->setValue(val);
        if(contador==6) this->ui->temp_gases_3->setValue(val);
        if(contador==7) this->ui->angulo_ciguenal_3->setValue(val);
        if(contador==8) this->ui->ang_arbol_levas_3->setValue(val);
        if(contador==9) this->ui->aceleracion_3->setValue(val);
        if(contador==10) this->ui->ang_direc_3->setValue(val);
        if(contador==11) this->ui->volante_motor_3->setValue(val);
        if(contador==12) this->ui->flujo_masa_aire_3->setValue(val);
        if(contador==13) this->ui->pos_val_recircul_3->setValue(val);
        if(contador==14) this->ui->chispa_3->setValue(val);
        if(contador==15) this->ui->pres_combust_3->setValue(val);
        if(contador==16) this->ui->velocidad_3->setValue(val);
        if(contador==17) this->ui->rot_eje_trans_3->setValue(val);
        if(contador==18) this->ui->freno_antiblo_3->setValue(val);
        if(contador==19) this->ui->vuelco_3->setValue(val);
        if(contador==20) this->ui->inclinacion_3->setValue(val);
        if(contador==21) this->ui->viraje_3->setValue(val);
        if(contador==22) this->ui->par_motor_3->setValue(val);
        if(contador==23) this->ui->aceleracion_3->setValue(val);
        if(contador==24) this->ui->pres_deposito_3->setValue(val);
        if(contador==25) this->ui->alta_presion_3->setValue(val);
        if(contador<5 && val<=300){
            image.load("/home/damon/Hayka/image1.png");
            this->ui->label_25->setPixmap(image);
        }
        if(contador>5 && contador<10 && val<=300){
            image.load("/home/damon/Hayka/image2.png");
            this->ui->label_25->setPixmap(image);
        }
        if(contador>10 && contador<15 && val<=300){
            image.load("/home/damon/Hayka/image3.png");
            this->ui->label_25->setPixmap(image);
        }
        if(contador>15 && contador<20 && val<=300){
            image.load("/home/damon/Hayka/image4.png");
            this->ui->label_25->setPixmap(image);
        }
        if(contador>20 && contador<27 && val<=300){
            image.load("/home/damon/Hayka/image5.png");
            this->ui->label_25->setPixmap(image);
        }
        contador++;
    }
}
void mainwindow::actualizar3(){
    ifstream in("/home/damon/Hayka/info_4.txt");
    QPixmap image;
    image.load("/home/damon/Hayka/car.png");
    this->ui->label_215->setPixmap(image);

      string s,line;
      int contador=0;
      getline(in,line);
      while(getline(in, line)){
        s += line + "\n";
        int val=stoi(line);
        if(contador==0) this->ui->temp_motor_7->setValue(val);
        if(contador==1) this->ui->temp_refrigerante_7->setValue(val);
        if(contador==2) this->ui->temp_aire_7->setValue(val);
        if(contador==3) this->ui->temp_aceite_m_7->setValue(val);
        if(contador==4) this->ui->temp_aceite_t_7->setValue(val);
        if(contador==5) this->ui->temp_combust_7->setValue(val);
        if(contador==6) this->ui->temp_gases_7->setValue(val);
        if(contador==7) this->ui->angulo_ciguenal_7->setValue(val);
        if(contador==8) this->ui->ang_arbol_levas_7->setValue(val);
        if(contador==9) this->ui->aceleracion_7->setValue(val);
        if(contador==10) this->ui->ang_direc_7->setValue(val);
        if(contador==11) this->ui->volante_motor_7->setValue(val);
        if(contador==12) this->ui->flujo_masa_aire_7->setValue(val);
        if(contador==13) this->ui->pos_val_recircul_7->setValue(val);
        if(contador==14) this->ui->chispa_7->setValue(val);
        if(contador==15) this->ui->pres_combust_7->setValue(val);
        if(contador==16) this->ui->velocidad_7->setValue(val);
        if(contador==17) this->ui->rot_eje_trans_7->setValue(val);
        if(contador==18) this->ui->freno_antiblo_7->setValue(val);
        if(contador==19) this->ui->vuelco_7->setValue(val);
        if(contador==20) this->ui->inclinacion_7->setValue(val);
        if(contador==21) this->ui->viraje_7->setValue(val);
        if(contador==22) this->ui->par_motor_7->setValue(val);
        if(contador==23) this->ui->aceleracion_7->setValue(val);
        if(contador==24) this->ui->pres_deposito_7->setValue(val);
        if(contador==25) this->ui->alta_presion_7->setValue(val);
        if(contador<5 && val<=300){
            image.load("/home/damon/Hayka/image1.png");
            this->ui->label_215->setPixmap(image);
        }
        if(contador>5 && contador<10 && val<=300){
            image.load("/home/damon/Hayka/image2.png");
            this->ui->label_215->setPixmap(image);
        }
        if(contador>10 && contador<15 && val<=300){
            image.load("/home/damon/Hayka/image3.png");
            this->ui->label_215->setPixmap(image);
        }
        if(contador>15 && contador<20 && val<=300){
            image.load("/home/damon/Hayka/image4.png");
            this->ui->label_215->setPixmap(image);
        }
        if(contador>20 && contador<27 && val<=300){
            image.load("/home/damon/Hayka/image5.png");
            this->ui->label_215->setPixmap(image);
        }
        contador++;
    }
}
void mainwindow::actualizar4(){
    ifstream in("/home/damon/Hayka/info_5.txt");
    QPixmap image;
    image.load("/home/damon/Hayka/car.png");
    this->ui->label_216->setPixmap(image);

      string s,line;
      int contador=0;
      getline(in, line);
      while(getline(in, line)){
        s += line + "\n";
        int val=stoi(line);
        if(contador==0) this->ui->temp_motor_8->setValue(val);
        if(contador==1) this->ui->temp_refrigerante_8->setValue(val);
        if(contador==2) this->ui->temp_aire_8->setValue(val);
        if(contador==3) this->ui->temp_aceite_m_8->setValue(val);
        if(contador==4) this->ui->temp_aceite_t_8->setValue(val);
        if(contador==5) this->ui->temp_combust_8->setValue(val);
        if(contador==6) this->ui->temp_gases_8->setValue(val);
        if(contador==7) this->ui->angulo_ciguenal_8->setValue(val);
        if(contador==8) this->ui->ang_arbol_levas_8->setValue(val);
        if(contador==9) this->ui->aceleracion_8->setValue(val);
        if(contador==10) this->ui->ang_direc_8->setValue(val);
        if(contador==11) this->ui->volante_motor_8->setValue(val);
        if(contador==12) this->ui->flujo_masa_aire_8->setValue(val);
        if(contador==13) this->ui->pos_val_recircul_8->setValue(val);
        if(contador==14) this->ui->chispa_8->setValue(val);
        if(contador==15) this->ui->pres_combust_8->setValue(val);
        if(contador==16) this->ui->velocidad_8->setValue(val);
        if(contador==17) this->ui->rot_eje_trans_8->setValue(val);
        if(contador==18) this->ui->freno_antiblo_8->setValue(val);
        if(contador==19) this->ui->vuelco_8->setValue(val);
        if(contador==20) this->ui->inclinacion_8->setValue(val);
        if(contador==21) this->ui->viraje_8->setValue(val);
        if(contador==22) this->ui->par_motor_8->setValue(val);
        if(contador==23) this->ui->aceleracion_8->setValue(val);
        if(contador==24) this->ui->pres_deposito_8->setValue(val);
        if(contador==25) this->ui->alta_presion_8->setValue(val);
        if(contador<5 && val<=300){
            image.load("/home/damon/Hayka/image1.png");
            this->ui->label_216->setPixmap(image);
        }
        if(contador>5 && contador<10 && val<=300){
            image.load("/home/damon/Hayka/image2.png");
            this->ui->label_216->setPixmap(image);
        }
        if(contador>10 && contador<15 && val<=300){
            image.load("/home/damon/Hayka/image3.png");
            this->ui->label_216->setPixmap(image);
        }
        if(contador>15 && contador<20 && val<=300){
            image.load("/home/damon/Hayka/image4.png");
            this->ui->label_216->setPixmap(image);
        }
        if(contador>20 && contador<27 && val<=300){
            image.load("/home/damon/Hayka/image5.png");
            this->ui->label_216->setPixmap(image);
        }
        contador++;
    }
}
void mainwindow::actualizar5(){
    ifstream in("/home/damon/Hayka/info_6.txt");
    QPixmap image;
    image.load("/home/damon/Hayka/car.png");
    this->ui->label_217->setPixmap(image);

      string s,line;
      int contador=0;
      getline(in, line);
      while(getline(in, line)){
        s += line + "\n";
        int val=stoi(line);
        if(contador==0) this->ui->temp_motor_9->setValue(val);
        if(contador==1) this->ui->temp_refrigerante_9->setValue(val);
        if(contador==2) this->ui->temp_aire_9->setValue(val);
        if(contador==3) this->ui->temp_aceite_m_9->setValue(val);
        if(contador==4) this->ui->temp_aceite_t_9->setValue(val);
        if(contador==5) this->ui->temp_combust_9->setValue(val);
        if(contador==6) this->ui->temp_gases_9->setValue(val);
        if(contador==7) this->ui->angulo_ciguenal_9->setValue(val);
        if(contador==8) this->ui->ang_arbol_levas_9->setValue(val);
        if(contador==9) this->ui->aceleracion_9->setValue(val);
        if(contador==10) this->ui->ang_direc_9->setValue(val);
        if(contador==11) this->ui->volante_motor_9->setValue(val);
        if(contador==12) this->ui->flujo_masa_aire_9->setValue(val);
        if(contador==13) this->ui->pos_val_recircul_9->setValue(val);
        if(contador==14) this->ui->chispa_9->setValue(val);
        if(contador==15) this->ui->pres_combust_9->setValue(val);
        if(contador==16) this->ui->velocidad_9->setValue(val);
        if(contador==17) this->ui->rot_eje_trans_9->setValue(val);
        if(contador==18) this->ui->freno_antiblo_9->setValue(val);
        if(contador==19) this->ui->vuelco_9->setValue(val);
        if(contador==20) this->ui->inclinacion_9->setValue(val);
        if(contador==21) this->ui->viraje_9->setValue(val);
        if(contador==22) this->ui->par_motor_9->setValue(val);
        if(contador==23) this->ui->aceleracion_9->setValue(val);
        if(contador==24) this->ui->pres_deposito_9->setValue(val);
        if(contador==25) this->ui->alta_presion_9->setValue(val);
        if(contador<5 && val<=300){
            image.load("/home/damon/Hayka/image1.png");
            this->ui->label_217->setPixmap(image);
        }
        if(contador>5 && contador<10 && val<=300){
            image.load("/home/damon/Hayka/image2.png");
            this->ui->label_217->setPixmap(image);
        }
        if(contador>10 && contador<15 && val<=300){
            image.load("/home/damon/Hayka/image3.png");
            this->ui->label_217->setPixmap(image);
        }
        if(contador>15 && contador<20 && val<=300){
            image.load("/home/damon/Hayka/image4.png");
            this->ui->label_217->setPixmap(image);
        }
        if(contador>20 && contador<27 && val<=300){
            image.load("/home/damon/Hayka/image5.png");
            this->ui->label_217->setPixmap(image);
        }
        contador++;
    }
}
void mainwindow::on_tabWidget_currentChanged()//int index)
{
    actualizar();
    actualizar2();
    actualizar3();
    actualizar4();
    actualizar5();
}

void mainwindow::on_mainwindow_signalActualizar()
{
    actualizar();
    actualizar2();
}
