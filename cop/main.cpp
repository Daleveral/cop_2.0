#include <iostream>
#include "man.h"
#include "game.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;


int main() 
{
	loop:  // ��β�����¿�ʼ��Ϸ,����ת���˴�

	cop the_cop(16,9);  // ��ʼ������
	bullet p1(19,19),p2(0,0),p3(0,19),p4(0,1);  // ��ʼ���ӵ�
	
	enemy enemy_arr[8]={enemy(2,3),enemy(3,15),enemy(7,3),enemy(15,4),enemy(6,5),enemy(15,16),enemy(10,7),enemy(12,9)};
	
    cout<<"\n\n    ����һ������(��)��һС͵(��)������������,��ٿ���Ľ�ɫ������С͵ ! \n\n";
    
    cout<<"    **       WASD�ֱ���� �������� �ĸ�������ƶ�       **\n\n";
    cout<<"    **  Яǹ״̬: IJKL�ֱ��� �������� �ĸ�������ӵ�  **\n\n";
    
    cout<<"    **  Я��״̬: IJKL�ֱ��ó� �������� �ĸ������ǽ��  **\n\n";  
	
    cout<<"    **  Я��״̬: IJKL�ֱ��޽� �������� �ĸ������ǽ��  **\n\n"; 
	
    cout<<"    **  Ĭ��ΪЯǹ״̬ , �� Q �л�ΪЯ��״̬            **\n\n"; 
	cout<<"    **  �� E �л�ΪЯ��״̬ , �� F �л�ΪЯǹ״̬       **\n\n";	 
		  
    cout<<"    ##  ��ʾ:�벻Ҫ��ͼ��С͵������,��Ҫʱʹ�����ǹ  ##\n\n";   
	cout<<"\n    ��ѡ���ʼС͵����,�������ֺ�س�\n    ( 1 - 7 �� ):   ";
	int k;
	cin>>k;
	if(k>4){k++;}
	for(int i=0;i<k;i++)
	{
		enemy_arr[i].if_exist =1; // ����С͵ 
	}	
	
	system("cls");
	game new_game(k,&the_cop,enemy_arr,&p1,&p2,&p3,&p4);	


    while (new_game.win_or_die==0)
    {
        new_game.HideCursor(); // ���ع��
        new_game.mapSign();  // ���е�ͼ���
        new_game.gotoxy(0,0); // ��ֹƵ��,ʹ�����ȶ�
        cout<<new_game;    // ��ӡ
        new_game.update_bullet();   // �ӵ�λ�ø���
        new_game.update_enemy();    // С͵λ�ø���
        new_game.updateWithInput(); //�������ӵ��������     
    }

    switch(new_game.win_or_die)
    {
        case 1: cout<<"\n\n!!!!!  ��ɹ�������С͵��������  !!!!!\n\n";break;
        case 2: cout<<"\n\n!!!!!  �㱻С͵������ !!!!!\n\n";break;
    }
        
	cout<<" �� r �������¿�ʼ��Ϸ, �ո�����˳�,\n\n";    
	
	while(1)
	{
	    if (kbhit())
	    {
		    char input = getch();
	
		    if(input == 'r') 
		    	{ system("cls"); goto loop; }
		    
		    if(input == ' ') 
				{break;}
	    }
	}
        
	return 0;
}
