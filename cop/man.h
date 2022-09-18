#ifndef __MAN_H__
#define __MAN_H__

class point
{
	public:
	int x,y;
	point(int xx,int yy)
	{
	x=xx;
	y=yy;
	}
	
};

class bullet :public point
{
	public:
		bullet(int px,int py):point(px,py){}
};

class cop : public point
{
	public:
		int face;
		cop(int px,int py):point(px,py){face =0;}
};


class enemy : public point
{	public:
		int if_exist;
		int flag;
		
		enemy(int px,int py):point(px,py)
		{
			if_exist =0;
			flag =0; // 默认小偷数量为 0 ,能动
		}  

};

#endif
