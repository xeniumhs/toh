#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

int ring[3][10] = {0};
int top[3] = {-1, -1, -1};
int a;
int n;
int moves=0;
int pegx[3];
int pegy=600;
char text[30];
char min_move[30];
int page;
int customColor = COLOR(221, 190, 234);
void move(int s, int e){
	setactivepage(page);
	
	
	getch();
	cleardevice();
	readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
	readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
	top[e]++;
	ring[e][top[e]]=ring[s][top[s]];
	top[s]--;
		for (int i=0;i<3;i++){
			readimagefile("peg_candel.jpg",pegx[i],pegy-30*n,pegx[i]+10,pegy+30);
		}
		
		
		for(int i=0;i<3;i++){
			for(int j=0;j<=top[i];j++){
//				rectangle(pegx[i]-20*ring[i][j],pegy-j*10,pegx[i]+20*ring[i][j],pegy+8-j*10);
				readimagefile("disk.jpg",pegx[i]-25*ring[i][j],pegy-j*30,pegx[i]+25*ring[i][j],pegy+30-j*30);
			}
		}
		
		outtextxy(100,100,"MIN MOVES : ");
		outtextxy(500,100,min_move);
		sprintf(text,"%d",moves);
		outtextxy(100,170,"TOTAL MOVES : ");
		outtextxy(500,170,text);
		setvisualpage(page);
		page=1-page;
		setactivepage(page);
//		setvisualpage(1-page);
}
void TOH(int n,int s,int m,int e){
	if(n>0){
		TOH(n-1,s,e,m);
		moves++;
		move(s,e);
//		getch();
		TOH(n-1,m,s,e);
	}
}

bool clicked = 0;

int main(){
	initwindow(1280,720,"TOH");
	char choice;
	page=0;
	setbkcolor(customColor);
	settextstyle(4, 0, 4);
		readimagefile("no_disks.jpg",0,0,getmaxx(),getmaxy());
		n=getch();
		n=n-48;
		int min_moves =pow(2,n)-1;
		sprintf(min_move,"%d",min_moves);
		int picked=0,picked_from=10;
		
		pegx[0]=getmaxx()/4;
		pegx[1]=pegx[0]*2;
		pegx[2]=pegx[0]*3;
			
			for(int i=n;i>0;i--){
				ring[0][n-i]=i;
				top[0]++;
				
			}
	
			readimagefile("start.jpg",0,0,getmaxx(),getmaxy());
			choice=getch();	
			cout<<"choice : "<<choice<<endl;
			switch(choice){
				case '2':{
					moves=0;
					cleardevice();
						readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
						for (int i=0;i<3;i++){
							readimagefile("peg_candel.jpg",pegx[i],pegy-30*n,pegx[i]+10,pegy+30);	
						}
						
						
						for(int i=0;i<3;i++){
							for(int j=0;j<=top[i];j++){
				//				rectangle(pegx[i]-20*ring[i][j],pegy-j*10,pegx[i]+20*ring[i][j],pegy+8-j*10);
								readimagefile("disk.jpg",pegx[i]-25*ring[i][j],pegy-j*30,pegx[i]+25*ring[i][j],pegy+30-j*30);
							}
						}
						outtextxy(100,100,"MIN MOVES : ");
						outtextxy(500,100,min_move);
						outtextxy(100,170,"TOTAL MOVES : ");
						sprintf(text,"%d",moves);
						outtextxy(500,170,text);
					TOH(n,0,1,2);
					getch();
					break;
				}
				case '1':{
					page=0;
					moves=0;
					while(1){
				//+++++++++++++++++++++++++++++++++++++++++==== WHILE LOOOP ======================================++++++++++++++++++++++++++++++++++++++++++++++++++
						
						
						
						setactivepage(page);
						
						cleardevice();
						readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
						for (int i=0;i<3;i++){
							readimagefile("peg_candel.jpg",pegx[i],pegy-30*n,pegx[i]+10,pegy+30);	
						}
						
						
						for(int i=0;i<3;i++){
							for(int j=0;j<=top[i];j++){
				//				rectangle(pegx[i]-20*ring[i][j],pegy-j*10,pegx[i]+20*ring[i][j],pegy+8-j*10);
								readimagefile("disk.jpg",pegx[i]-25*ring[i][j],pegy-j*30,pegx[i]+25*ring[i][j],pegy+30-j*30);
							}
						}
						outtextxy(100,100,"MIN MOVES : ");
						outtextxy(500,100,min_move);
						sprintf(text,"%d",moves);
						outtextxy(100,170,"TOTAL MOVES : ");
						outtextxy(500,170,text);
						page=1-page;
						
						if(GetAsyncKeyState(VK_LBUTTON)){
				//			cleardevice();
							clicked = 1;
							cout<<picked<<endl;
							if(picked>0){
								readimagefile("disk.jpg",mousex()-20*picked,mousey()-5,mousex()+20*picked,mousey()+30);
							}
							cout<<"top s "<<top[0]<<" top m "<<top[1]<<" top d "<<top[2]<<" ring s "<<ring[0][top[0]]<<" ring m "<<ring[1][top[1]]<<" ring d "<<ring[2][top[2]]<<endl;
							
						}
						
						setvisualpage(1-page);
						if(mousex()>getmaxx()/8 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*3 && mousey()<getmaxy() && clicked==0){
							while(mousex()>getmaxx()/8 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*3 && mousey()<getmaxy()){
				//				cout<<"source"<<endl;
								if(GetAsyncKeyState(VK_LBUTTON)){
									if(top[0]>-1 && ring[0][top[0]]>0){
									picked = ring[0][top[0]]; //ring 0 2 = 1
									top[0]--; 
									picked_from=0;
									}
				//					cleardevice();
									break;
								}
							}
						}
						else if(mousex()>(getmaxx()/8)*3 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*5 && mousey()<getmaxy() && clicked==0){
							while(mousex()>(getmaxx()/8)*3 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*5 && mousey()<getmaxy()){
				//				cout<<"mid"<<endl;
								if(GetAsyncKeyState(VK_LBUTTON)){
									if(top[1]>-1 && ring[1][top[1]]>0){
									picked = ring[1][top[1]];
									top[1]--;
									picked_from=1;
									}
				//					cleardevice();
									break;
								}
							}
						}
						else if(mousex()>(getmaxx()/8)*5 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*7 && mousey()<getmaxy() && clicked==0){
							while(mousex()>(getmaxx()/8)*5 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*7 && mousey()<getmaxy()){
				//				cout<<"destination";
								if(GetAsyncKeyState(VK_LBUTTON)){
									if(top[2]>-1 && ring[2][top[2]]>0){
										picked = ring[2][top[2]];
										top[2]--;
										picked_from=2;
									}
				//					cleardevice();
									break;
								}
							}
						}//end of destination
						
						if(GetAsyncKeyState(VK_LBUTTON)==false && clicked == 1){
							//cleardevice();
							cout<<"clearing\n";
							if(mousex()>getmaxx()/8 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*3 && mousey()<getmaxy()){
								if(top[0]<n && picked>0){
									if(top[0]==-1 || picked<ring[0][top[0]] && picked_from!=0){
										top[0]++;
										ring[0][top[0]]=picked;	
										moves++;
									}
									else{
										top[picked_from]++;
									}
								}
							}
							else if(mousex()>(getmaxx()/8)*3 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*5 && mousey()<getmaxy()){
								if(top[1]<n && picked>0){
									if(top[1]==-1 || picked<ring[1][top[1]] && picked_from!=1){
										top[1]++;
										ring[1][top[1]]=picked;
										moves++;
									}
									else{
										top[picked_from]++;
									}
								}
							}
							else if(mousex()>(getmaxx()/8)*5 && mousey()>pegy-500 && mousex()<(getmaxx()/8)*7 && mousey()<getmaxy()){
								if(top[2]<n && picked>0){
									if(top[2]==-1 || picked<ring[2][top[2]] && picked_from!=2){
										top[2]++;
										ring[2][top[2]]=picked;
										moves++;
									}
								}
							}
							else{
								top[picked_from]++;
							}
							clicked = 0;
							picked = 0;
							picked_from=4;
				//			cleardevice();
						}
						if(top[2]==n-1){
							cout<<"you won\n";
							page=0;
							choice=2;
							while(1){
								setactivepage(page); //0
								setvisualpage(1-page);//1
//								cleardevice();
//								char buf[3][30];
//								buff[0]="peg_candel_fire.jpg"
								readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
								readimagefile("you_won.jpg",200,100,563+150,+10+259+150);
								readimagefile("peg_candel.jpg",pegx[2],pegy-30*n,pegx[2]+10,pegy+30);
								for(int j=0;j<=top[2];j++){
									readimagefile("disk.jpg",pegx[2]-25*ring[2][j],pegy-j*30,pegx[2]+25*ring[2][j],pegy+30-j*30);
								}
								readimagefile("peg_candel_fire.jpg",pegx[2],pegy-30*n,pegx[2]+10,pegy-30*n+10);
								page=1-page;
								setvisualpage(1-page); //0
								delay(100);
								
								setactivepage(page);//1
								readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
							readimagefile("you_won.jpg",200,100,563+150,+10+259+150);
								readimagefile("peg_candel.jpg",pegx[2],pegy-30*n,pegx[2]+10,pegy+30);
								for(int j=0;j<=top[2];j++){
									readimagefile("disk.jpg",pegx[2]-25*ring[2][j],pegy-j*30,pegx[2]+25*ring[2][j],pegy+30-j*30);
								}
								readimagefile("peg_candel_fire2.jpg",pegx[2],pegy-30*n,pegx[2]+10,pegy-30*n+10);
								page=1-page;
								setvisualpage(1-page);//1
								delay(100);
								
								setactivepage(page);//0
								readimagefile("table.jpg",0,0,getmaxx(),getmaxy());
							readimagefile("you_won.jpg",200,100,563+140,+10+259+140);
								readimagefile("peg_candel.jpg",pegx[2],pegy-30*n,pegx[2]+10,pegy+30);
								for(int j=0;j<=top[2];j++){
									readimagefile("disk.jpg",pegx[2]-25*ring[2][j],pegy-j*30,pegx[2]+25*ring[2][j],pegy+30-j*30);
								}
								readimagefile("peg_candel_fire3.jpg",pegx[2],pegy-30*n,pegx[2]+10,pegy-30*n+10);
								if(kbhit()){
									return 0;
								}
								page=1-page;//0
							}
						}
						
					}	//eowhile			
					break;
				}
			}//user or comp choice
		
			
	
}
