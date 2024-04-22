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
	loop:  // 结尾若重新开始游戏,则跳转至此处

	cop the_cop(16,9);  // 初始化警察
	bullet p1(19,19),p2(0,0),p3(0,19),p4(0,1);  // 初始化子弹
	
	enemy enemy_arr[8]={enemy(2,3),enemy(3,15),enemy(7,3),enemy(15,4),enemy(6,5),enemy(15,16),enemy(10,7),enemy(12,9)};
	
    cout<<"\n\n    你是一名警察(★)，一小偷(♀)正在行凶作恶,请操控你的角色，击败小偷 ! \n\n";
    
    cout<<"    **       WASD分别操作 上左下右 四个方向的移动       **\n\n";
    cout<<"    **  携枪状态: IJKL分别发射 上左下右 四个方向的子弹  **\n\n";
    
    cout<<"    **  携镐状态: IJKL分别敲除 上下左右 四个方向的墙壁  **\n\n";  
	
    cout<<"    **  携盾状态: IJKL分别修建 上下左右 四个方向的墙壁  **\n\n"; 
	
    cout<<"    **  默认为携枪状态 , 按 Q 切换为携镐状态            **\n\n"; 
	cout<<"    **  按 E 切换为携盾状态 , 按 F 切换为携枪状态       **\n\n";	 
		  
    cout<<"    ##  提示:请不要试图与小偷近身搏斗,必要时使用你的枪  ##\n\n";   
	cout<<"\n    请选择初始小偷数量,输入数字后回车\n    ( 1 - 7 个 ):   ";
	int k;
	cin>>k;
	if(k>4){k++;}
	for(int i=0;i<k;i++)
	{
		enemy_arr[i].if_exist =1; // 激活小偷 
	}	
	
	system("cls");
	game new_game(k,&the_cop,enemy_arr,&p1,&p2,&p3,&p4);	


    while (new_game.win_or_die==0)
    {
        new_game.HideCursor(); // 隐藏光标
        new_game.mapSign();  // 进行地图标记
        new_game.gotoxy(0,0); // 防止频闪,使界面稳定
        cout<<new_game;    // 打印
        new_game.update_bullet();   // 子弹位置更新
        new_game.update_enemy();    // 小偷位置更新
        new_game.updateWithInput(); //警察与子弹打出更新     
    }

    switch(new_game.win_or_die)
    {
        case 1: cout<<"\n\n!!!!!  你成功击毙了小偷，好样的  !!!!!\n\n";break;
        case 2: cout<<"\n\n!!!!!  你被小偷干死了 !!!!!\n\n";break;
    }
        
	cout<<" 按 r 键以重新开始游戏, 空格键则退出,\n\n";    
	
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
