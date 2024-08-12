//#include<iostream>
//#include<stdlib.h>
//#include<conio.h>
//#include<math.h>
//#include<graphics.h>
//using namespace std;
//
// int top[3];
// int a;
// int n;
//// int picked;
//// int pegx[3];
//// int pegy;
// int ring[3][10];
//
//// void move(int a,int b){
//// 	switch(a){
//// 			case 1:{
//// 				if(top[0]<n){
//				
//// 				switch(b){
//// 					case 2:{
//// 						if(ring[1][top[1]]<ring[0][top[0]]){
//// 							cout<<"Cant Be Placed \n";
//// 							getch();
//// 						}
//// 						else{
//// 						top[1]--;
//// 						ring[1][top[1]]=ring[0][top[0]];
//// 						top[0]++;
//// 						moves++;
//// 						}
//// 						break;	
//// 					}
//// 					case 3:{
//// 						if(ring[2][top[2]]<ring[0][top[0]]){
//// 							cout<<"Cant Be Placed \n";
//// 							getch();
//// 						}
//// 						else{
//// 						top[2]--;
//// 						ring[2][top[2]]=ring[0][top[0]];
//// 						top[0]++;
//// 						moves++;
//// 						}
//// 						break;
//// 					}
//// 				}	
//// 				}
//// 				else{
//// 					cout<<"NO RINGS LEFT";
//// 					getch();
//// 				}
//// 				break;
//// 			}
//			
//// 			case 2:{
//// 				if(top[1]<n){
//				
//// 				switch(b){
//// 					case 1:{
//// 						if(ring[0][top[0]]<ring[1][top[1]]){
//// 							cout<<"Cant Be Placed \n";
//// 							getch();
//// 						}
//// 						else{
//// 						top[0]--;
//// 						ring[0][top[0]]=ring[1][top[1]];
//// 						top[1]++;
//// 						moves++;
//// 						}
//// 						break;	
//// 					}
//// 					case 3:{
//// 						if(ring[2][top[2]]<ring[1][top[1]]){
//// 							cout<<"Cant Be Placed \n";
//// 							getch();
//// 						}
//// 						else{
//// 						top[2]--;
//// 						ring[2][top[2]]=ring[1][top[1]];
//// 						top[1]++;
//// 						moves++;
//// 						}
//// 						break;
//// 					}
//// 				}	
//// 				}
//// 				else{
//// 					cout<<"NO RINGS LEFT";
//// 					getch();
//// 				}
//// 				break;
//// 			}
//			
//// 			case 3:{
//// 				if(top[2]<n){
//					
//// 				switch(b){
//// 					case 1:{
//// 						if(ring[0][top[0]]<ring[2][top[2]]){
//// 							cout<<"Cant Be Placed \n";
//// 							getch();
//// 						}
//// 						else{
//// 						top[0]--;
//// 						ring[0][top[0]]=ring[2][top[2]];
//// 						top[2]++;
//// 						moves++;
//// 						}
//// 						break;	
//// 					}
//// 					case 2:{
//// 						if(ring[1][top[1]]<ring[2][top[2]]){
//// 							cout<<"Cant Be Placed \n";
//// 							getch();
//// 						}
//// 						else{
//// 						top[1]--;
//// 						ring[1][top[1]]=ring[2][top[2]];
//// 						top[2]++;
//// 						moves++;
//// 						}
//// 						break;
//// 					}
//// 				}	
//// 				}
//// 				else{
//// 					cout<<"NO RINGS LEFT";
//// 					getch();
//// 				}
//// 				break;
//// 			}
//			
//// 		}
//	
//// }
//
//void display(){
//
//		
//
//		// for(int i=0;i<3;i++){
//		// 	for(int j=top[i];j<n;j++){
//		// 		for(int k=1;k<=ring[i][j];k++){
//		// 			cout<<"#";
//		// 		}
//		// 	cout<<endl;
//		// 	}
//		// 	cout<<"\t____________________________\n";
//		// }
//		// cout<<"MAX MOVE : "<<pow(2,n)-1<<endl;
//		// cout<<"MOVES : "<<moves<<endl;
//
//		
//}
//
//// void TOH(int n,int s,int m,int e){
//// 	if(n>0){
//// 		TOH(n-1,s,e,m);
//// 		system("CLS");
//// 		moves++;
//// 		move(s,e);
//// 		display();
//// 		getch();
//		
//// 		TOH(n-1,m,s,e);
//// 	}
//// }
//
//bool clicked = 0;
//
//int main(){
//	initwindow(720,480,"TOH");
//	// int choice1,choice2;
//	cout<<"enter the level : ";
//	n=3;
////	cin>>n;
//int picked;
//int pegx[3];
//int pegy;
//
//
//	top[0]=-1;
//	top[1]=-1;
//	top[2]=-1;
//	
//	pegx[0]=getmaxx()/4;
//	pegx[1]=pegx[0]*2;
//	pegx[2]=pegx[0]*3;
//	pegy=300;
//
//		for (int i=0;i<3;i++)
//		{
//			line(pegx[i],pegy-200,pegx[i],pegy+10);	
//		}
//		top[0]=0;
//		for(int i=n;i>0;i--){
//			setfillstyle(1,3);
//			rectangle(pegx[0]-20*i,pegy-top[0]*10,pegx[0]+20*i,pegy+8-top[0]*10);
//			ring[0][i-1]=i;
//			top[0]++;
//		}
//		int j;
//	while(true){
//		cleardevice();
//		// display();
//
//		for (int i=0;i<3;i++)
//		{
//			line(pegx[i],pegy-200,pegx[i],pegy+10);	
//		}
//
//		for(int i=0;i<3;i++){
//			for(int j=0;j<=top[i];j++){
//				rectangle(pegx[0]-20*ring[i][n-1-j],pegy-j*10,pegx[0]+20*ring[i][n-1-j],pegy+8-j*10);
//			}
//		}
//		cout<<"displaying\n";
//		
//		if(GetAsyncKeyState(VK_LBUTTON)){
//			// while(GetAsyncKeyState(VK_LBUTTON)){
//			// 	cout<<"clicking"<<endl;
//			// }
//			// cleardevice();
//			clicked = 1;
//			cout<<picked<<endl;
//			rectangle(mousex()-20*picked,mousey()-5,mousex()+20*picked,mousey()+5);
//		}
//
//		if(GetAsyncKeyState(VK_LBUTTON)==false && clicked == 1){
//			if(mousex()>getmaxx()/8 && mousey()>100 && mousex()<(getmaxx()/8)*3 && mousey()<510){
//				top[0]--;
//			}
//			else if(mousex()>(getmaxx()/8)*3 && mousey()>100 && mousex()<(getmaxx()/8)*5 && mousey()<510){
//					top[1]++;
//					ring[1][top[1]]=picked;
//				}
//				
//				
//			}
//			clicked = 0;
//			// cleardevice();
//		}
//
//		if(mousex()>getmaxx()/8 && mousey()>100 && mousex()<(getmaxx()/8)*3 && mousey()<510 && clicked==0){
//			while(mousex()>getmaxx()/8 && mousey()>100 && mousex()<(getmaxx()/8)*3 && mousey()<510){
//				cout<<"source"<<endl;
//				if(GetAsyncKeyState(VK_LBUTTON)){
//					picked = ring[0][top[0]];
//					top[0]--;
//					// cleardevice();
//					break;
//				}
//			}
//		}
//		else if(mousex()>(getmaxx()/8)*3 && mousey()>100 && mousex()<(getmaxx()/8)*5 && mousey()<510 && clicked==0){
//			while(mousex()>(getmaxx()/8)*3 && mousey()>100 && mousex()<(getmaxx()/8)*5 && mousey()<510){
//				cout<<"mid"<<endl;
//				if(GetAsyncKeyState(VK_LBUTTON)){
//					top[1]++;
//					picked = top[1]; 
//					// cleardevice();
//					break;
//				}
//			}
//		}
//		else if(mousex()>(getmaxx()/8)*3 && mousey()>100 && mousex()<(getmaxx()/8)*5 && mousey()<510 && clicked==0){
//
//		}
//	}
//			
//					
//					
//					
//					
//					
//	
////	for(int i=0;i<n;i++){
////		for(int j=1;j<=i+1;j++){
//////			cout<<"#";
////			a=j; //1
////		}
////			ring[0][i]=a;
////			cout<<endl;
////	}
//	
//		
//	// cout<<"\n\t1.AI CONTROLED ? \nOr \n\t2.User Controled ?";
//	// cin>>choice1;
//	// if(choice1==1){
//	// 	TOH(n,1,2,3);	
//	// }
//	// else{	
//	// while(1){
//	// system("CLS");
//	// if(top[2]==0){
//	// 	cout<<"\n\t-----you won-----\n";
//	// 	getch();
//	// 	break;
//	// }
//	// else{
//	// 	display();
//		
//	// 	cout<<"from : ";
//	// 	cin>>choice1;
//	// 	cout<<"to : ";
//	// 	cin>>choice2;
//	// 	move(choice1,choice2);
//	// 	}	
//	// }
//	// }
//// }
