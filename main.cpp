#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <ctime>
extern void showMenu();
extern void exitSystem();
extern void manager();
extern void managerShowMenu();
extern void manager01();
extern void manager02();
extern void manager03();
extern void manager04();
extern void manager05();
extern void manager06();
extern void userRegister();
extern void userLogIn();
extern void userShowMenu();
extern void buyer();
extern void buyer01();
extern void buyer02();
extern void buyer03();
extern void buyer04();
extern void buyer05();
extern void seller();
extern void seller01();
extern void seller02();
extern void seller03();
extern void seller04();
extern void seller05();
extern void selfInformationManagement();
extern void Info01();
extern void Info02();
extern void Info03();
using namespace std;
void SetColorAndBackground(int forgC, int backC) {
	WORD wColor = ((backC & 0x0F) << 4) + (forgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
struct Item{
	char ID[5];
	char name[21];
	double price;
	char time[11];
	char sellerID[5];
	int num;
	char status[10];
	char desciption[201];
};
struct Bill{
	char billID[5];
	char itemID[5];
	double onePrice;
	int num;
	char dealTime[11];
	char sellerID[5];
	char buyerID[5];
}; 
struct User
{
	char userID[5];
	char userCode[11];
	char userName[20];
	char phoneNumber[12];
	char adress[41];
	double moneyLeft;
	char status[5];
};
struct MoneyPutIn{
	double moneyIn;
	char time[11];
	char userID[5];
};
Item item[999];
Bill bill[999];
User user[999];
MoneyPutIn moneyPutIn[999];
int userNumberNow;
int main()
{
	ifstream in_file1("user.txt",ios::in);
	{
		if(!in_file1)
		{
			ofstream out_file1("user.txt",ios::out);
			out_file1.close();
		}
		else in_file1.close();
	}
	ifstream in_file2("item.txt",ios::in);
	{
		if(!in_file2)
		{
			ofstream out_file2("item.txt",ios::out);
			out_file2.close();
		}
		else in_file2.close();
	}
	ifstream in_file3("bill.txt",ios::in);
	{
		if(!in_file3)
		{
			ofstream out_file3("bill.txt",ios::out);
			out_file3.close();
		}
		else in_file3.close();
	}
	ifstream in_file0("moneyin.txt",ios::in);
	{
		if(!in_file0)
		{
			ofstream out_file0("moneyin.txt",ios::out);
			out_file0.close();
		}
		else in_file0.close();
	} 
	int operate1;
	while(true)
	{
		showMenu();
		SetColorAndBackground(4,0);
		cin>>operate1;
		SetColorAndBackground(7,0);
		switch (operate1)
	    {
		    case 1:system("cls");manager();break;
		    case 2:system("cls");userRegister();break; 
		    case 3:system("cls");userLogIn();break; 
		    case 4:exitSystem();break; 
		    default:system("cls");break; 
	    }
	} 
	return 0;
}
void showMenu(){ 
    cout<<"欢迎使用冬奥纪念品交易平台！"<<endl<<endl;
	cout<<"=============================================="<<endl;
	cout<<"1.管理员登录 2.用户注册 3.用户登录 4.退出程序"<<endl;
	cout<<"=============================================="<<endl;
	cout<<endl;
	cout<<"输入操作：";
}
void exitSystem(){
	cout<<endl<<"欢迎下次使用本交易系统！"<<endl<<endl;
	system("pause"); 
	exit(0);
}
void manager(){
	char managerName[6];
	char managerCode[7];
	cout << "请输入管理员姓名：";
	SetColorAndBackground(4,0);
	cin >> managerName;
	SetColorAndBackground(7,0);
	cout << "请输入密码：";
	SetColorAndBackground(4,0);
	cin >> managerCode;
	SetColorAndBackground(7,0);
	if (strcmp(managerName,"admin")==0&&strcmp(managerCode,"123456")==0)
	{
	    cout<<endl<<"--------登陆成功--------"<<endl<<endl;
		system("pause");
		system("cls");
	}
	else if(strcmp(managerName,"admin")!=0)
	{
		cout<<endl<<"-----用户名错误，登陆失败，返回主菜单-----"<<endl<<endl;
		system("pause");
		system("cls");
		return;
	}
	else if(strcmp(managerName,"admin")==0&&strcmp(managerCode,"123456")!=0)
	{
		cout<<endl<<"-----密码错误，登陆失败，返回主菜单-----"<<endl<<endl;
		system("pause");
		system("cls");
		return;
	}
	int operate2;
	while(true)
	{
		managerShowMenu();
		cout<<endl<<"请输入操作：";
		SetColorAndBackground(4,0);
		cin>>operate2;
		SetColorAndBackground(7,0);
		switch (operate2)
	    {
		    case 1:manager01();break; 
		    case 2:manager02();break; 
		    case 3:manager03();break; 
		    case 4:manager04();break; 
		    case 5:manager05();break;
		    case 6:manager06();break;
		    case 7:
			    cout<<endl<<"-------已注销！-------"<<endl<<endl;
				system("pause"); 
				system("cls");
				return;
				break;
		    default:system("cls");break; 
	    }
	}  
}
void managerShowMenu(){
	cout << "=====================================================================================" << endl;
	cout << "1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
	cout << "=====================================================================================" << endl;
}
void manager01(){ 
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	if(itemNumber!=0){
	cout<<"********************************************"
	    <<"******************************************************"<<endl;
	cout<<std::left<<setw(10)<<"商品ID"
	    <<std::left<<setw(15)<<"商品名称"
		<<std::left<<setw(10)<<"商品价格"
	    <<std::left<<setw(15)<<"上架时间"
		<<std::left<<setw(10)<<"商品数量"
		<<std::left<<setw(10)<<"卖家ID"
		<<std::left<<setw(10)<<"商品状态"
		<<std::left<<setw(40)<<"商品描述"<<endl; 
	for(int i=0;i<itemNumber;i++)
	{
		cout<<std::left<<setw(10)<<item[i].ID
		    <<std::left<<setw(15)<<item[i].name
		    <<std::left<<setw(10)<<item[i].price
			<<std::left<<setw(15)<<item[i].time
			<<std::left<<setw(10)<<item[i].num
			<<std::left<<setw(10)<<item[i].sellerID
			<<std::left<<setw(10)<<item[i].status
			<<std::left<<setw(15)<<item[i].desciption<<endl;
	}
	cout<<"********************************************"
	    <<"******************************************************"<<endl;
	}
	else{
		cout<<endl<<"暂时没有商品！"<<endl<<endl;
	}
	system("pause");
	system("cls");
	return;
	
}
void manager02(){
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	char searchName[21];
	cout<<"请输入商品名称：";
	SetColorAndBackground(4,0);
	cin>>searchName;
	SetColorAndBackground(7,0);
	int count00=0,count01=0; 
	for(int i=0;i<itemNumber;i++){
		if(strcmp(searchName,item[i].name)==0)
		{
			if(count00==0)
			{
				cout<<endl<<"匹配结果如下："<<endl<<endl;
				cout<<"********************************************************"
				    <<"********************************************************"<<endl;
				cout<<std::left<<setw(10)<<"商品ID"
				    <<std::left<<setw(15)<<"名称"
					<<std::left<<setw(10)<<"价格"
					<<std::left<<setw(15)<<"上架时间"
					<<std::left<<setw(10)<<"卖家ID"
					<<std::left<<setw(10)<<"数量"
					<<std::left<<setw(10)<<"商品状态"
					<<std::left<<setw(40)<<"商品描述"<<endl; 
				cout<<std::left<<setw(10)<<item[i].ID
			    <<std::left<<setw(15)<<item[i].name
			    <<std::left<<setw(10)<<item[i].price
			    <<std::left<<setw(15)<<item[i].time
			    <<std::left<<setw(10)<<item[i].sellerID
			    <<std::left<<setw(10)<<item[i].num
			    <<std::left<<setw(10)<<item[i].status
				<<std::left<<setw(40)<<item[i].desciption<<endl;
			    count00++;
			}
			else
			{
			    cout<<std::left<<setw(10)<<item[i].ID
			    <<std::left<<setw(15)<<item[i].name
			    <<std::left<<setw(10)<<item[i].price
			    <<std::left<<setw(15)<<item[i].time
			    <<std::left<<setw(10)<<item[i].sellerID
			    <<std::left<<setw(10)<<item[i].num
			    <<std::left<<setw(10)<<item[i].status
				<<std::left<<setw(40)<<item[i].desciption<<endl;
			    count00++;
			}
		}
		else count01++;
	}
	if(count01==itemNumber)
	{
		cout<<endl<<"=====没有找到您想要的商品！返回初始界面！====="<<endl<<endl;
	}
	else 
	cout<<"********************************************************"
	    <<"********************************************************"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	return;
}
void manager03(){ 
    int itemNumber=0,t; 
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	char searchID[5];
	cout<<"请输入要下架的商品ID：";
	SetColorAndBackground(4,0);
	cin>>searchID;
	SetColorAndBackground(7,0);
	int count01=0;
	for(t=0;t<itemNumber;t++){
		if(strcmp(searchID,item[t].ID)==0&&strcmp(item[t].status,"已下架")==0)
		{
			cout<<endl<<"该商品已被下架！"<<endl<<endl;
			system("pause");
			system("cls");
			return;
		}
		if(strcmp(searchID,item[t].ID)==0&&strcmp(item[t].status,"销售中")==0)
		{
			cout<<endl<<"确认下架该商品吗？"<<endl<<endl; 
			cout<<"***************************************"
			    <<"***************************************"<<endl;
			cout<<std::left<<setw(10)<<"商品ID"
			    <<std::left<<setw(15)<<"名称"
				<<std::left<<setw(10)<<"价格"
				<<std::left<<setw(15)<<"上架时间"
				<<std::left<<setw(10)<<"卖家ID"
				<<std::left<<setw(10)<<"数量"
				<<std::left<<setw(10)<<"商品状态"<<endl; 
			cout<<std::left<<setw(10)<<item[t].ID
			    <<std::left<<setw(15)<<item[t].name
			    <<std::left<<setw(10)<<item[t].price
			    <<std::left<<setw(15)<<item[t].time
			    <<std::left<<setw(10)<<item[t].sellerID
			    <<std::left<<setw(10)<<item[t].num
			    <<std::left<<setw(10)<<item[t].status<<endl;
			cout<<"***************************************"
			    <<"***************************************"<<endl;
		    break;
		
		}
		else count01++;
	}
	if(count01==itemNumber)
	{
		cout<<endl<<"=====没有找到您想要下架的商品！返回初始界面！====="<<endl<<endl;
	}
	else{
		cout<<endl<<"请选择(y/n)：";
		char yesorno;
		SetColorAndBackground(4,0);
		cin>>yesorno;
		SetColorAndBackground(7,0);
		if(yesorno=='y')
		{
			strcpy(item[t].status,"已下架");
			cout<<endl<<"下架成功"<<endl<<endl; 
		}
		else
		{
			cout<<endl<<"取消下架"<<endl<<endl;
		}
	}
	ofstream out_file10("item.txt",ios::out);
	for(int j=0;j<itemNumber;j++)
	{
		out_file10<<item[j].ID<<" "<<item[j].name<<" "<<item[j].price<<" "
		          <<item[j].time<<" "<<item[j].num<<" "<<item[j].sellerID<<" "
		          <<item[j].status<<" "<<item[j].desciption<<endl;
	}
	
	system("pause"); 
	system("cls");
	return;
	 
}
void manager04(){
	int billNumber=0;
	ifstream in_file6("bill.txt",ios::in);
	while(true)
	{
		in_file6>>bill[billNumber].billID
		>>bill[billNumber].itemID
		>>bill[billNumber].onePrice
		>>bill[billNumber].num
		>>bill[billNumber].dealTime
		>>bill[billNumber].buyerID
		>>bill[billNumber].sellerID;
		if(in_file6.fail())break;
		billNumber++;
	}
	in_file6.close();
	cout<<"*************************************************************************************"<<endl;
	cout<<std::left<<setw(10)<<"订单ID"
	    <<std::left<<setw(10)<<"商品ID"
		<<std::left<<setw(10)<<"交易单价"
		<<std::left<<setw(10)<<"数量"
	    <<std::left<<setw(15)<<"交易时间"
		<<std::left<<setw(10)<<"卖家ID"
		<<std::left<<setw(10)<<"买家ID"<<endl; 
	for(int i=0;i<billNumber;i++)
	{
		cout<<std::left<<setw(10)<<bill[i].billID
			   <<std::left<<setw(10)<<bill[i].itemID
		       <<std::left<<setw(10)<<bill[i].onePrice
			   <<std::left<<setw(10)<<bill[i].num
			   <<std::left<<setw(15)<<bill[i].dealTime
			   <<std::left<<setw(10)<<bill[i].sellerID
			   <<std::left<<setw(10)<<bill[i].buyerID<<endl;
	}
	cout<<"*************************************************************************************"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	return;
}
void manager05(){
	int userNumber=0;
	ifstream in_file7("user.txt",ios::in);
	while(true)
	{
		in_file7>>user[userNumber].userID>>user[userNumber].userName
		       >>user[userNumber].userCode>>user[userNumber].phoneNumber
			   >>user[userNumber].adress>>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file7.fail())break;
		userNumber++;
	}
	in_file7.close();
	cout<<"***********************************************************************************"<<endl;
	cout<<std::left<<setw(15)<<"用户ID"
	    <<std::left<<setw(15)<<"用户名"
		<<std::left<<setw(15)<<"联系方式"
	    <<std::left<<setw(15)<<"地址"
		<<std::left<<setw(15)<<"钱包余额"
		<<std::left<<setw(15)<<"用户状态"<<endl; 
	for(int i=0;i<userNumber;i++)
	{
		cout<<std::left<<setw(15)<<user[i].userID
		    <<std::left<<setw(15)<<user[i].userName
		    <<std::left<<setw(15)<<user[i].phoneNumber
			<<std::left<<setw(15)<<user[i].adress
			<<std::left<<setw(15)<<fixed<<setprecision(1)<<user[i].moneyLeft
			<<std::left<<setw(15)<<user[i].status<<endl;
	}
	cout<<"***********************************************************************************"<<endl;
	system("pause");
	system("cls");
	return;
}
void manager06(){
	int userNumber=0;
	int countp=0;
	ifstream in_file8("user.txt",ios::in);
	while(true)
	{
		in_file8>>user[userNumber].userID>>user[userNumber].userName
		       >>user[userNumber].userCode>>user[userNumber].phoneNumber
			   >>user[userNumber].adress>>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file8.fail())break;
		userNumber++;
	}
	in_file8.close();
	cout<<"请输入要封禁的用户ID：";
	char closeID[5];
	SetColorAndBackground(4,0);
	cin>>closeID;
	SetColorAndBackground(7,0);
	for(int i=0;i<userNumber;i++)
	{
		if(strcmp(user[i].userID,closeID)==0&&strcmp(user[i].status,"正常")==0)
		{
			cout<<endl<<"确认要封禁该用户吗？"<<endl;
	        cout<<"**************************************************************************"<<endl;
	        cout<<std::left<<setw(15)<<"用户ID"
			    <<std::left<<setw(15)<<"用户名"
				<<std::left<<setw(15)<<"联系方式"
				<<std::left<<setw(15)<<"地址"
				<<std::left<<setw(15)<<"钱包余额"<<endl; 
			cout<<std::left<<setw(15)<<user[i].userID
			    <<std::left<<setw(15)<<user[i].userName
		        <<std::left<<setw(15)<<user[i].phoneNumber
			    <<std::left<<setw(15)<<user[i].adress
				<<std::left<<setw(15)<<user[i].moneyLeft<<endl;
			cout<<"**************************************************************************"<<endl;
			char yesorno='k';
			while(yesorno!='y'&&yesorno!='n'){
			    cout<<endl<<"请选择(y/n)：";
				SetColorAndBackground(4,0);
			    cin>>yesorno;
			    SetColorAndBackground(7,0);
			} 
			if(yesorno=='y'){
				strcpy(user[i].status,"封禁");
				cout<<endl<<"封禁成功！"<<endl;
				break; 
			} 
			else {
				cout<<endl<<"已取消封禁操作！"<<endl;
				system("pause");
				system("cls");
				return; 
			}
		}
		else if(strcmp(user[i].userID,closeID)==0&&strcmp(user[i].status,"封禁")==0)
		{
			cout<<endl<<"该用户已被封禁！"<<endl<<endl;
			system("pause");
			system("cls");
			return;
		}
		else countp++;
	} 
	if(countp==userNumber)
	{
		cout<<endl<<"未找到您想封禁的用户！"<<endl<<endl;
		system("pause");
		system("cls");
		return;
	}
	ofstream out_file8("user.txt",ios::out);
	for(int i=0;i<userNumber;i++){
		out_file8<<user[i].userID<<" "<<user[i].userName<<" "
		       <<user[i].userCode<<" "<<user[i].phoneNumber<<" "
			   <<user[i].adress<<" "<<user[i].moneyLeft<<" "
			   <<user[i].status<<endl;
	}
	cout<<endl;
	system("pause");
	system("cls");
	return;
}
void userRegister(){
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID>>user[userNumber].userName
		       >>user[userNumber].userCode>>user[userNumber].phoneNumber
			   >>user[userNumber].adress>>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	cout<<"请输入您的用户名：";
	SetColorAndBackground(4,0);
	cin>>user[userNumber].userName;
	SetColorAndBackground(7,0);
	for(int i=0;i<userNumber;i++){
		if(strcmp(user[userNumber].userName,user[i].userName)==0)
		{
			cout<<endl<<endl<<"注册失败，用户名已被占用！"<<endl<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout<<"请设置您的账户的密码：";
	SetColorAndBackground(4,0);
	cin>>user[userNumber].userCode;
	SetColorAndBackground(7,0); 
	cout<<"请输入您的手机号码：" ;
	SetColorAndBackground(4,0);
	cin>>user[userNumber].phoneNumber;
	SetColorAndBackground(7,0);
	cout<<"请输入您的所在地址：";
	SetColorAndBackground(4,0);
	cin>>user[userNumber].adress;
	SetColorAndBackground(7,0);
	user[userNumber].moneyLeft=0.0;
	user[userNumber].userID[0]='U';
	user[userNumber].userID[1]='0'+(userNumber+1)/100;
	user[userNumber].userID[2]='0'+((userNumber+1)/10)%10;
	user[userNumber].userID[3]='0'+(userNumber+1)%10;
	user[userNumber].userID[4]='\0';
	strcpy(user[userNumber].status,"正常"); 
	cout<<endl
	    <<"--------注册成功！--------"
		<<endl<<endl; 
	ofstream out_file4("user.txt",ios::out);
	for(int i=0;i<=userNumber;i++){
		out_file4<<user[i].userID<<" "<<user[i].userName<<" "
		       <<user[i].userCode<<" "<<user[i].phoneNumber<<" "
			   <<user[i].adress<<" "<<user[i].moneyLeft<<" "
			   <<user[i].status<<endl;
	}
	system("pause");
	system("cls");
	return;
}
void userLogIn(){
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID>>user[userNumber].userName
		       >>user[userNumber].userCode>>user[userNumber].phoneNumber
			   >>user[userNumber].adress>>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	cout<<"请输入用户名：";
	char userLogName[11];
	SetColorAndBackground(4,0);
	cin>>userLogName;
	SetColorAndBackground(7,0);
	int count02=0;
	for(int i=0;i<userNumber;i++)
	{
		if(strcmp(user[i].userName,userLogName)==0)
		{
			cout<<"请输入密码：";
			char userLogCode[21];
			SetColorAndBackground(4,0);
			cin>>userLogCode;
			SetColorAndBackground(7,0);
			if(strcmp(userLogCode,user[i].userCode)==0&&strcmp(user[i].status,"正常")==0)
			{
				cout<<endl<<"-----登陆成功-----"<<endl<<endl; 
				userNumberNow=i;
				system("pause");
				system("cls");
			}
			else if(strcmp(userLogCode,user[i].userCode)!=0)
			{
				cout<<endl<<"-----登陆失败！密码错误！-----"<<endl<<endl;
				system("pause");
				system("cls");
				return;
			}
			else if(strcmp(user[i].status,"封禁")==0)
			{
				cout<<endl<<"-----登陆失败！您的账号已被封禁！-----"<<endl<<endl;
				system("pause");
				system("cls");
				return;
			}
			break; 
		}
		else count02++;
	}
	if(count02==userNumber)
	{
		cout<<endl<<"-----登陆失败！用户名输入错误！-----"<<endl<<endl;
		system("pause");
		system("cls");
		return;
	}
	while(true){
	    userShowMenu();
	    int operate3;
	    SetColorAndBackground(4,0);
	    cin>>operate3;
	    SetColorAndBackground(7,0);
	    if(operate3!=4)system("cls");
	    switch (operate3)
	    {
		    case 1:buyer();break;
		    case 2:seller();break;
		    case 3:selfInformationManagement();break;
		    case 4:
			    cout<<endl<<"-----已注销！-----"<<endl<<endl;
			    system("pause");
			    system("cls");
			    return;
	    }
    }
}
void userShowMenu(){
	cout<<"================================================="<<endl;
	cout<<"1.我是买家 2.我是卖家 3.个人信息管理 4.注销登录"<<endl;
	cout<<"================================================="<<endl;
	cout<<endl;
	cout<<"请输入操作：";
}
void buyer(){
	while(true){
	
	    cout<<"========================================================================================="<<endl;
	    cout<<"1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面"<<endl;
	    cout<<"========================================================================================="<<endl; 
	    cout<<endl;
	    cout<<"请输入操作：";
	    int operate5;
	    SetColorAndBackground(4,0);
	    cin>>operate5;
	    SetColorAndBackground(7,0);
	    switch(operate5)
	    {
		    case 1:buyer01();break;
		    case 2:buyer02();break;
		    case 3:buyer03();break;
		    case 4:buyer04();break;
		    case 5:buyer05();break;
		    case 6:
			    cout<<endl<<"即将返回用户主界面！"<<endl<<endl;
			    system("pause");
			    system("cls");
			    return;
	    }
	}
}
void buyer01(){
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	if(itemNumber!=0){
	cout<<"*********************************"
	    <<"*************************************************"<<endl;
	cout<<std::left<<setw(10)<<"商品ID"
	    <<std::left<<setw(15)<<"名称"
		<<std::left<<setw(10)<<"价格"
		<<std::left<<setw(15)<<"上架时间"
	    <<std::left<<setw(10)<<"卖家ID"
	    <<std::left<<setw(10)<<"商品状态"
		<<std::left<<setw(40)<<"商品描述"<<endl; 
	for(int i=0;i<itemNumber;i++)
	{
		if(item[i].num!=0&&(strcmp(item[i].status,"销售中")==0||strcmp(item[i].status,"补货中")==0))
		cout<<std::left<<setw(10)<<item[i].ID
		    <<std::left<<setw(15)<<item[i].name
		    <<std::left<<setw(10)<<item[i].price
			<<std::left<<setw(15)<<item[i].time
			<<std::left<<setw(10)<<item[i].sellerID
			<<std::left<<setw(10)<<item[i].status 
			<<std::left<<setw(40)<<item[i].desciption<<endl;
	}
	cout<<"*********************************"
	    <<"*************************************************"<<endl;
	}
	else cout<<endl<<"暂时没有商品！"<<endl<<endl;
	system("pause");
	system("cls");
	return;
}
void buyer02(){
    std::time_t t=std::time(0);
    std::tm* now=std::localtime(&t);
    int y=(now->tm_year+1900),m=(now->tm_mon+1),d=now->tm_mday;
    char ctime[20];
	if(d<=9&&m<=9)sprintf(ctime,"%d-0%d-0%d",y,m,d);
	if(d<=9&&m>9)sprintf(ctime,"%d-%d-0%d",y,m,d);
	if(d>9&&m<=9)sprintf(ctime,"%d-0%d-%d",y,m,d);
	if(d>9&&m>9)sprintf(ctime,"%d-%d-%d",y,m,d);
	int billNumber=0;
	ifstream in_file6("bill.txt",ios::in);
	while(true)
	{
		in_file6>>bill[billNumber].billID
		>>bill[billNumber].itemID
		>>bill[billNumber].onePrice
		>>bill[billNumber].num
		>>bill[billNumber].dealTime
		>>bill[billNumber].buyerID
		>>bill[billNumber].sellerID;
		if(in_file6.fail())break;
		billNumber++;
	}
	in_file6.close();
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID>>user[userNumber].userName
		       >>user[userNumber].userCode>>user[userNumber].phoneNumber
			   >>user[userNumber].adress>>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	cout<<"请输入商品ID：";
	char buyID[5];
	SetColorAndBackground(4,0);
	cin>>buyID;
	SetColorAndBackground(7,0);
	cout<<"请输入数量：";
	int buyNum;
	SetColorAndBackground(4,0);
	cin>>buyNum;
	SetColorAndBackground(7,0);
	int count01=0;
	int q; 
	for(q=0;q<itemNumber;q++){
		if(strcmp(buyID,item[q].ID)==0&&buyNum<=item[q].num&&user[userNumberNow].moneyLeft>=buyNum*item[q].price)
		{
			cout<<endl; 
			cout<<"*******************************"<<endl;
			cout<<"交易提醒！"<<endl;
			cout<<"交易时间："<<ctime<<endl;
			cout<<"交易单价："<<item[q].price<<endl;
			cout<<"交易数量："<<buyNum<<endl;
			cout<<"交易状态：交易成功"<<endl;
			cout<<"您的余额："<<user[userNumberNow].moneyLeft-buyNum*item[q].price<<endl;
			cout<<"*******************************"<<endl;
			item[q].num-=buyNum;
			if(item[q].num==0)
			{
				strcpy(item[q].status,"补货中");
			}
			for(int index=0;index<userNumber;index++)
			{
				if(strcmp(user[index].userID,item[q].sellerID)==0){
					user[index].moneyLeft+=buyNum*item[q].price;
					break;
				}
			}
			user[userNumberNow].moneyLeft-=buyNum*item[q].price;
			bill[billNumber].billID[0]='T';
	        bill[billNumber].billID[1]='0'+(billNumber+1)/100;
	        bill[billNumber].billID[2]='0'+((billNumber+1)/10)%10;
	        bill[billNumber].billID[3]='0'+(billNumber+1)%10;
	        bill[billNumber].billID[4]='\0';
	        strcpy(bill[billNumber].itemID,item[q].ID);
	        bill[billNumber].onePrice=item[q].price;
	        bill[billNumber].num=buyNum;
	        strcpy(bill[billNumber].dealTime,ctime);
	        strcpy(bill[billNumber].sellerID,item[q].sellerID);
	        strcpy(bill[billNumber].buyerID,user[userNumberNow].userID);
	        ofstream out_file4("user.txt",ios::out);
	        for(int j=0;j<userNumber;j++){
		        out_file4<<user[j].userID<<" "
				       <<user[j].userName<<" "
		               <<user[j].userCode<<" "
					   <<user[j].phoneNumber<<" "
			           <<user[j].adress<<" "
					   <<user[j].moneyLeft<<" "
			           <<user[j].status<<endl;
	        }
	        out_file4.close();
	        ofstream out_file10("item.txt",ios::out);
	        for(int j=0;j<itemNumber;j++)
	        {
		        out_file10<<item[j].ID<<" "
				<<item[j].name<<" "
				<<item[j].price<<" "
		        <<item[j].time<<" "
				<<item[j].num<<" "
				<<item[j].sellerID<<" "
		        <<item[j].status<<" "
				<<item[j].desciption<<endl;
	        }
	        out_file10.close();
	        ofstream out_file16("bill.txt",ios::out);
	        for(int j=0;j<=billNumber;j++)
	        {
		        out_file16<<bill[j].billID<<" "
				<<bill[j].itemID<<" "
				<<bill[j].onePrice<<" "
		        <<bill[j].num<<" "
				<<bill[j].dealTime<<" "
				<<bill[j].buyerID<<" "
		        <<bill[j].sellerID<<endl;
	        }
	        out_file16.close(); 
		    break;
		}
		else if(buyNum>item[q].num)
		{
			cout<<endl<<"购买失败！商品数量不足！"<<endl;
			break;
	    }
	    else if(user[userNumberNow].moneyLeft<buyNum*item[q].price)
	    {
	    	cout<<endl<<"您的余额不足！请前往个人信息中心充值！"<<endl;
	    	break;
		}
		else count01++;
	}
	if(count01==itemNumber)
	{
		cout<<endl<<"没有找到您想要购买的商品！返回初始界面！"<<endl;
	}
	cout<<endl;
	system("pause"); 
	system("cls");
	return;
}
void buyer03(){
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	char searchName[21];
	cout<<"请输入商品名称：";
	SetColorAndBackground(4,0);
	cin>>searchName;
	SetColorAndBackground(7,0);
	int count00=0,count01=0;
	for(int i=0;i<itemNumber;i++){
		if(strcmp(searchName,item[i].name)==0&&item[i].num!=0&&strcmp(item[i].status,"销售中")==0)
		{
			if(count00==0)
			{
			    cout<<"*******************************************"
		            <<"*******************************************"<<endl; 
				cout<<std::left<<setw(10)<<"商品ID"
				    <<std::left<<setw(15)<<"名称"
					<<std::left<<setw(10)<<"价格"
					<<std::left<<setw(15)<<"上架时间"
					<<std::left<<setw(10)<<"卖家ID"
					<<std::left<<setw(40)<<"商品描述"<<endl; 
				cout<<std::left<<setw(10)<<item[i].ID
			    <<std::left<<setw(15)<<item[i].name
			    <<std::left<<setw(10)<<item[i].price
			    <<std::left<<setw(15)<<item[i].time
			    <<std::left<<setw(10)<<item[i].sellerID
				<<std::left<<setw(40)<<item[i].desciption<<endl;
			    count00++;
			}
			else
			{
			    cout<<std::left<<setw(10)<<item[i].ID
			    <<std::left<<setw(15)<<item[i].name
			    <<std::left<<setw(10)<<item[i].price
			    <<std::left<<setw(15)<<item[i].time
			    <<std::left<<setw(10)<<item[i].sellerID
				<<std::left<<setw(40)<<item[i].desciption<<endl;
			    count00++;
			}
		}
		else count01++;
	}
	if(count01==itemNumber)
	{
		cout<<endl<<"没有找到您想要的商品！返回初始界面！"<<endl<<endl;
	}
	else cout<<"*******************************************"
		<<"*******************************************"<<endl; 
	system("pause");
	system("cls");
	return; 
}
void buyer04(){
	int itemNumber=0,count00=0,count01=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	int billNumber=0;
	ifstream in_file6("bill.txt",ios::in);
	while(true)
	{
		in_file6>>bill[billNumber].billID
		>>bill[billNumber].itemID
		>>bill[billNumber].onePrice
		>>bill[billNumber].num
		>>bill[billNumber].dealTime
		>>bill[billNumber].buyerID
		>>bill[billNumber].sellerID;
		if(in_file6.fail())break;
		billNumber++;
	}
	in_file6.close();
	    for(int i=0;i<billNumber;i++)
	    {
	    	if(strcmp(bill[i].buyerID,user[userNumberNow].userID)==0)
	    	{
	    		count00++;
	    		if(count00==1)
	    		{
	    			cout<<"************************************"
					      <<"****************************************"<<endl;
	                cout<<std::left<<setw(10)<<"订单ID"
		                <<std::left<<setw(10)<<"商品ID"
			            <<std::left<<setw(10)<<"交易单价"
			            <<std::left<<setw(10)<<"数量"
			            <<std::left<<setw(15)<<"交易时间"
			            <<std::left<<setw(10)<<"卖家ID"<<endl;
				}
				 cout<<std::left<<setw(10)<<bill[i].billID
			        <<std::left<<setw(10)<<bill[i].itemID
	    	        <<std::left<<setw(10)<<bill[i].onePrice
				    <<std::left<<setw(10)<<bill[i].num
	    		    <<std::left<<setw(15)<<bill[i].dealTime
				    <<std::left<<setw(10)<<bill[i].sellerID<<endl;
			}
	    	else count01++;
	    }
	    if(count01==billNumber)
	    {
	    	cout<<endl<<"您尚且没有历史订单！"<<endl<<endl;
		}
	    else 
		cout<<"************************************"
			<<"****************************************"<<endl;
	system("pause");
	system("cls");
	return;
}
void buyer05(){
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	char searchID[5];
	cout<<"请输入您想要查看的商品ID：";
	SetColorAndBackground(4,0);
	cin>>searchID;
	SetColorAndBackground(7,0);
	int count01=0;
	for(int i=0;i<itemNumber;i++){
		if(strcmp(searchID,item[i].ID)==0)
		{
			cout<<"*******************************"<<endl;
			cout<<"商品ID："<<item[i].ID<<endl 
		    <<"商品名称："<<item[i].name<<endl
		    <<"商品价格："<<item[i].price<<endl
		    <<"上架时间："<<item[i].time<<endl			    
			<<"商品描述："<<item[i].desciption<<endl
			<<"商品卖家："<<item[i].sellerID<<endl; 
			cout<<"*******************************"<<endl;
			break;
		}
		else count01++;
	}
	if(count01==itemNumber)
	{
		cout<<"没有找到您想要的商品！返回初始界面！"<<endl;
	}
	system("pause");
	system("cls");
	return;
}
void seller(){
	int operate6;
	while(true){
	    cout<<"========================================================================================="<<endl;
	    cout<<"1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面"<<endl;
	    cout<<"========================================================================================="<<endl; 
	    cout<<endl;
	    cout<<"请输入操作：";
	    SetColorAndBackground(4,0);
	    cin>>operate6;
	    SetColorAndBackground(7,0);
	    switch(operate6)
	    {
		    case 1:seller01();break;
		    case 2:seller02();break;
		    case 3:seller03();break;
		    case 4:seller04();break;
		    case 5:seller05();break;
		    case 6:
			    cout<<endl<<"即将返回用户主界面！"<<endl<<endl;
			    system("pause");
			    system("cls");
			    return;
	    }
	}
}
void seller01(){
	std::time_t t=std::time(0);
    std::tm* now=std::localtime(&t);
    int y=(now->tm_year+1900),m=(now->tm_mon+1),d=now->tm_mday;
    char ctime[20];
	if(d<=9&&m<=9)sprintf(ctime,"%d-0%d-0%d",y,m,d);
	if(d<=9&&m>9)sprintf(ctime,"%d-%d-0%d",y,m,d);
	if(d>9&&m<=9)sprintf(ctime,"%d-0%d-%d",y,m,d);
	if(d>9&&m>9)sprintf(ctime,"%d-%d-%d",y,m,d);
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID
		       >>user[userNumber].userName
		       >>user[userNumber].userCode
			   >>user[userNumber].phoneNumber
			   >>user[userNumber].adress
			   >>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	cout<<"请输入商品名称：";
	SetColorAndBackground(4,0);
	cin>>item[itemNumber].name;
	SetColorAndBackground(7,0);
	cout<<"请输入商品价格：";
	SetColorAndBackground(4,0);
	cin>>item[itemNumber].price;
	SetColorAndBackground(7,0);
	cout<<"请输入商品数量：";
	SetColorAndBackground(4,0);
	cin>>item[itemNumber].num;
	SetColorAndBackground(7,0);
	cout<<"请输入商品描述：";
	SetColorAndBackground(4,0);
	cin>>item[itemNumber].desciption;
	SetColorAndBackground(7,0);
	strcpy(item[itemNumber].sellerID,user[userNumberNow].userID);
	strcpy(item[itemNumber].time,ctime);
	item[itemNumber].ID[0]='M';
	item[itemNumber].ID[1]='0'+(itemNumber+1)/100;
	item[itemNumber].ID[2]='0'+((itemNumber+1)/10)%10;
	item[itemNumber].ID[3]='0'+(itemNumber+1)%10;
	item[itemNumber].ID[4]='\0';
	strcpy(item[itemNumber].status,"销售中"); 
	cout<<endl<<"请确认发布的商品信息无误！"<<endl;
	cout<<"**************************************"<<endl;
	cout<<"商品名称："<<item[itemNumber].name<<endl;
	cout<<"商品价格："<<fixed<<setprecision(1)<<item[itemNumber].price<<endl;
	cout<<"商品数量："<<item[itemNumber].num<<endl;
	cout<<"商品描述："<<item[itemNumber].desciption<<endl; 
	cout<<"**************************************"<<endl;
	char yesorno='k';
	while(yesorno!='y'&&yesorno!='n'){
		cout<<"请选择(y/n)：";
		SetColorAndBackground(4,0);
		cin>>yesorno;
		SetColorAndBackground(7,0);
	} 
	if(yesorno=='y'){
		cout<<"发布商品成功！"<<endl;
	    ofstream out_file10("item.txt",ios::out);
	    for(int j=0;j<=itemNumber;j++)
	    {
	    	out_file10<<item[j].ID<<" "
			          <<item[j].name<<" "
					  <<item[j].price<<" "
	    	          <<item[j].time<<" "
					  <<item[j].num<<" "
					  <<item[j].sellerID<<" "
	    	          <<item[j].status<<" "
					  <<item[j].desciption<<endl;
	    }
	    out_file10.close();
    }
    else if(yesorno=='n')
    {
    	cout<<"已取消发布！"<<endl;
	}
	system("pause");
	system("cls");
	return; 
}
void seller02(){
    int userNumber=0,count00=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID
		       >>user[userNumber].userName
		       >>user[userNumber].userCode
			   >>user[userNumber].phoneNumber
			   >>user[userNumber].adress
			   >>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	for(int i=0;i<itemNumber;i++)
	{
		if(strcmp(item[i].sellerID,user[userNumberNow].userID)==0&&strcmp(item[i].status,"销售中")==0){
			count00++;
			if(count00==1){
				cout<<endl<<"由您发布的商品如下："<<endl<<endl;
	            cout<<"************************************************************"<<endl;
	            cout<<std::left<<setw(10)<<"商品ID"
	            <<std::left<<setw(15)<<"名称"
		        <<std::left<<setw(10)<<"价格"
	            <<std::left<<setw(15)<<"上架时间"
	            <<std::left<<setw(10)<<"商品描述"<<endl; 
			} 
		cout<<std::left<<setw(10)<<item[i].ID
		    <<std::left<<setw(15)<<item[i].name
		    <<std::left<<setw(10)<<fixed<<setprecision(1)<<item[i].price
			<<std::left<<setw(15)<<item[i].time
			<<std::left<<setw(10)<<item[i].desciption<<endl;
		}
	}
	if(count00!=0)cout<<"************************************************************"<<endl;
	else cout<<endl<<"您尚未发布商品！"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	return;
}
void seller03(){
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID
		       >>user[userNumber].userName
		       >>user[userNumber].userCode
			   >>user[userNumber].phoneNumber
			   >>user[userNumber].adress
			   >>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	int itemNumber=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	cout<<"请输入被修改的商品ID：";
	char changeID[5];
	SetColorAndBackground(4,0);
	cin>>changeID;
	SetColorAndBackground(7,0);
	int i;
	for(i=0;i<itemNumber;i++)
	{
		if(strcmp(item[i].ID,changeID)==0&&strcmp(item[i].sellerID,user[userNumberNow].userID)==0)break; 
	}
	if(i==itemNumber){
		cout<<endl<<"没有找到相关商品，返回主菜单！"<<endl<<endl; 
		system("pause");
		system("cls");
		return;
	}
	 cout<<"请输入被修改商品的属性(1.价格 2.描述)：";
		int changeoperate=0;
		while(changeoperate!=1&&changeoperate!=2)
		{
			SetColorAndBackground(4,0);
		    cin>>changeoperate;
		    SetColorAndBackground(7,0);
		    if(changeoperate==1)
		    {
		    	cout<<"请输入被修改商品的价格：";
		    	SetColorAndBackground(4,0);
		    	cin>>item[i].price;
		    	SetColorAndBackground(7,0);
		    }
		    else if(changeoperate==2)
		    {
			    cout<<"请输入被修改商品的描述：";
			    SetColorAndBackground(4,0);
			    cin>>item[i].desciption;
			    SetColorAndBackground(7,0);
		    }
		}
		cout<<endl<<"请确认修改的商品信息无误！"<<endl;
		cout<<"*********************************"<<endl;
		cout<<"商品ID："<<item[i].ID<<endl;
		cout<<"商品名称："<<item[i].name<<endl;
	    cout<<"商品价格："<<fixed<<setprecision(1)<<item[i].price<<endl;
		cout<<"商品描述："<<item[i].desciption<<endl;
		cout<<"*********************************"<<endl<<endl;
		char yesorno='k';
	    while(yesorno!='y'&&yesorno!='n'){
		    cout<<"请选择(y/n)：";
		    SetColorAndBackground(4,0);
		    cin>>yesorno;
		    SetColorAndBackground(7,0);
	    } 
		if(yesorno=='y'){
			cout<<endl<<"修改成功！"<<endl<<endl;
			ofstream out_file10("item.txt",ios::out);
	        for(int j=0;j<itemNumber;j++)
	        {
	        	out_file10<<item[j].ID<<" "
				          <<item[j].name<<" "
						  <<item[j].price<<" "
	        	          <<item[j].time<<" "
						  <<item[j].num<<" "
						  <<item[j].sellerID<<" "
	        	          <<item[j].status<<" "
						  <<item[j].desciption<<endl;
	        }
	        out_file10.close();
		} 
		else if(yesorno=='n'){
			cout<<endl<<"已取消修改！"<<endl<<endl;
		}
		system("pause");
		system("cls");
		return;
}
void seller04(){
	int itemNumber=0;
	ifstream in_file11("item.txt",ios::in);
	while(true)
	{
		in_file11>>item[itemNumber].ID
		       >>item[itemNumber].name
		       >>item[itemNumber].price
			   >>item[itemNumber].time
			   >>item[itemNumber].num
			   >>item[itemNumber].sellerID
			   >>item[itemNumber].status
			   >>item[itemNumber].desciption;
		if(in_file11.fail())break;
		itemNumber++;
	}
	in_file11.close();
	cout<<"请输入要下架的商品ID：";
	char quitID[5];
	SetColorAndBackground(4,0);
	cin>>quitID;
	SetColorAndBackground(7,0);
	int i;
	for(i=0;i<itemNumber;i++)
	{
		if(strcmp(item[i].ID,quitID)==0)break; 
	}
	cout<<"确认要下架该商品吗？"<<endl;
	cout<<"*****************************************************************************************************"<<endl;
	cout<<std::left<<setw(10)<<"商品ID"
	    <<std::left<<setw(15)<<"名称"
	    <<std::left<<setw(10)<<"价格"
	    <<std::left<<setw(15)<<"上架时间"
	    <<std::left<<setw(10)<<"数量"
		<<std::left<<setw(40)<<"商品描述"<<endl;
	cout<<std::left<<setw(10)<<item[i].ID
	    <<std::left<<setw(15)<<item[i].name
		<<std::left<<setw(10)<<item[i].price
		<<std::left<<setw(15)<<item[i].time
		<<std::left<<setw(10)<<item[i].num
		<<std::left<<setw(40)<<item[i].desciption<<endl; 
	cout<<"*****************************************************************************************************"<<endl;
	char yesorno='k';
	while(yesorno!='y'&&yesorno!='n'){
		cout<<"请选择(y/n)：";
		SetColorAndBackground(4,0);
		cin>>yesorno;
		SetColorAndBackground(7,0);
	} 
	if(yesorno=='y')
	{
		cout<<"下架成功"<<endl; 
		strcpy(item[i].status,"已下架"); 
		ofstream out_file10("item.txt",ios::out);
	    for(int j=0;j<itemNumber;j++)
	    {
	        out_file10<<item[j].ID<<" "
			          <<item[j].name<<" "
					  <<item[j].price<<" "
	        	      <<item[j].time<<" "
					  <<item[j].num<<" "
					  <<item[j].sellerID<<" "
	        	      <<item[j].status<<" "
					  <<item[j].desciption<<endl;
	    }
	    out_file10.close();
	}
	else if(yesorno=='n')
	{
		cout<<"已取消下架！"<<endl;
	 } 
	system("pause");
	system("cls");
	return;
}
void seller05(){
	int itemNumber=0,count00=0,count01=0;
	ifstream in_file7("item.txt",ios::in);
	while(true)
	{
		in_file7>>item[itemNumber].ID
		>>item[itemNumber].name
		>>item[itemNumber].price
		>>item[itemNumber].time
		>>item[itemNumber].num
		>>item[itemNumber].sellerID
		>>item[itemNumber].status
		>>item[itemNumber].desciption;
		if(in_file7.fail())break;
		itemNumber++;
	}
	in_file7.close();
	int billNumber=0;
	ifstream in_file6("bill.txt",ios::in);
	while(true)
	{
		in_file6>>bill[billNumber].billID
		>>bill[billNumber].itemID
		>>bill[billNumber].onePrice
		>>bill[billNumber].num
		>>bill[billNumber].dealTime
		>>bill[billNumber].buyerID
		>>bill[billNumber].sellerID;
		if(in_file6.fail())break;
		billNumber++;
	}
	in_file6.close();
	    for(int i=0;i<billNumber;i++)
	    {
	    	if(strcmp(bill[i].sellerID,user[userNumberNow].userID)==0)
	    	{
	    		count00++;
	    		if(count00==1)
	    		{
	    			cout<<"************************************"
					      <<"****************************************"<<endl;
	                cout<<std::left<<setw(10)<<"订单ID"
		                <<std::left<<setw(10)<<"商品ID"
			            <<std::left<<setw(10)<<"交易单价"
			            <<std::left<<setw(10)<<"数量"
			            <<std::left<<setw(15)<<"交易时间"
			            <<std::left<<setw(10)<<"买家ID"<<endl;
				}
				 cout<<std::left<<setw(10)<<bill[i].billID
			        <<std::left<<setw(10)<<bill[i].itemID
	    	        <<std::left<<setw(10)<<bill[i].onePrice
				    <<std::left<<setw(10)<<bill[i].num
	    		    <<std::left<<setw(15)<<bill[i].dealTime
				    <<std::left<<setw(10)<<bill[i].buyerID<<endl;
			}
	    	else count01++;
	    }
	    if(count01==billNumber)
	    {
	    	cout<<endl<<"您尚且没有历史订单！"<<endl<<endl;
		}
	    else 
		cout<<"************************************"
			<<"****************************************"<<endl;
	system("pause");
	system("cls");
	return;
}
void selfInformationManagement(){
	while(true)
	{
	    cout<<"============================================="<<endl;
	    cout<<"1.查看信息 2.修改信息 3.充值 4.返回用户主界面"<<endl;
	    cout<<"============================================="<<endl; 
	    cout<<endl;
	    cout<<"请输入操作："; 
	    int operate6;
	    SetColorAndBackground(4,0);
	    cin>>operate6;
	    SetColorAndBackground(7,0);
	    switch (operate6)
	    {
	    	case 1:Info01();break;
    		case 2:Info02();break;
    		case 3:Info03();break;
    		case 4:
    			cout<<endl<<"即将返回用户主界面！"<<endl<<endl;
    			system("pause");
    			system("cls");
    			return;
    			break;
    	}
	}
}
void Info01()
{
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID
		       >>user[userNumber].userName
		       >>user[userNumber].userCode
			   >>user[userNumber].phoneNumber
			   >>user[userNumber].adress
			   >>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	cout<<"**********************************"<<endl;
	cout<<"用户名："<<user[userNumberNow].userName<<endl;
	cout<<"联系方式："<<user[userNumberNow].phoneNumber<<endl;
	cout<<"地址："<<user[userNumberNow].adress<<endl;
	cout<<"钱包余额："<<fixed<<setprecision(1)<<user[userNumberNow].moneyLeft<<endl;
	cout<<"**********************************"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	return;
}
void Info02() 
{
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID
		       >>user[userNumber].userName
		       >>user[userNumber].userCode
			   >>user[userNumber].phoneNumber
			   >>user[userNumber].adress
			   >>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	while(true)
	{
	
	    cout<<"请选择修改的属性(1.用户名 2.联系方式 3.地址)：";
	    int changeOperate02;
	    SetColorAndBackground(4,0);
	    cin>>changeOperate02;
	    SetColorAndBackground(7,0);
	    if(changeOperate02==1)
	    {
	    	loop:cout<<"请选择修改后的用户名：";
	    	char changeUserName[20]; 
	    	SetColorAndBackground(4,0);
	    	cin>>changeUserName;
	    	SetColorAndBackground(7,0);
	    	if(strcmp(changeUserName,user[userNumberNow].userName)==0)
			    {
				    cout<<endl<<"修改失败！新的用户名与原来的用户名重复！"<<endl<<endl;
				    system("pause");
				    system("cls");
				    goto loop;
				}
			else
			{
				int count03=0;
				for(int i=0;i<userNumber;i++)
				{
					if(strcmp(changeUserName,user[i].userName)==0)
					{
						cout<<endl<<"修改失败！该用户名已被占用！"<<endl<<endl;
						system("pause");
				        system("cls");
						goto loop; 
					}
					else count03++;
				}
				if(count03==userNumber)
				{
					cout<<endl<<"修改成功！"<<endl<<endl;
					strcpy(user[userNumberNow].userName,changeUserName);
				    ofstream out_file8("user.txt",ios::out);
	                for(int i=0;i<userNumber;i++){
		                out_file8<<user[i].userID<<" "<<user[i].userName<<" "
		                        <<user[i].userCode<<" "<<user[i].phoneNumber<<" "
			                    <<user[i].adress<<" "<<user[i].moneyLeft<<" "
			                    <<user[i].status<<endl;
	                }
	                out_file8.close();
					system("pause");
					system("cls");
					return;
				}
				else continue;
			}
	    }
	    else if(changeOperate02==2)
	    {
	    	loop1:cout<<"请输入修改后的联系方式：";
	    	char changePhoneNumber[12]; 
	    	SetColorAndBackground(4,0);
	    	cin>changePhoneNumber;
	    	SetColorAndBackground(7,0);
	    	if(strcmp(changePhoneNumber,user[userNumberNow].phoneNumber)==0)
			    {
				    cout<<endl<<"修改失败！新的联系方式与原来的联系方式重复！"<<endl<<endl;
				    system("pause");
				    system("cls");
				    goto loop1;
				}
			else
			{
				cout<<endl<<"修改成功！"<<endl<<endl;
				strcpy(user[userNumberNow].phoneNumber,changePhoneNumber);
				ofstream out_file8("user.txt",ios::out);
	            for(int i=0;i<userNumber;i++){
		            out_file8<<user[i].userID<<" "<<user[i].userName<<" "
		                    <<user[i].userCode<<" "<<user[i].phoneNumber<<" "
			                <<user[i].adress<<" "<<user[i].moneyLeft<<" "
			                <<user[i].status<<endl;
	            }
	            out_file8.close();
	            system("pause");
	            system("cls");
	            return;
			}
		}
		else if(changeOperate02==3)
		{
			loop2:cout<<"请输入修改后的地址：";
	    	char changeAddress[81]; 
	    	SetColorAndBackground(4,0);
	    	cin>changeAddress;
	    	SetColorAndBackground(7,0);
	    	if(strcmp(changeAddress,user[userNumberNow].adress)==0)
			    {
				    cout<<endl<<"修改失败！新的地址与原来的地址重复！"<<endl<<endl;
				    system("pause");
				    system("cls");
				    goto loop2;
				}
			else
			{
				cout<<endl<<"修改成功！"<<endl<<endl;
				strcpy(user[userNumberNow].adress ,changeAddress);
				ofstream out_file9("user.txt",ios::out);
	            for(int i=0;i<userNumber;i++){
		            out_file9<<user[i].userID<<" "
					        <<user[i].userName<<" "
		                    <<user[i].userCode<<" "
							<<user[i].phoneNumber<<" "
			                <<user[i].adress<<" "
							<<user[i].moneyLeft<<" "
			                <<user[i].status<<endl;
	            }
	            out_file9.close();
	            system("pause");
	            system("cls");
	            return;
			}
		}
    }
}
void Info03()
{
	std::time_t t=std::time(0);
    std::tm* now=std::localtime(&t);
    int y=(now->tm_year+1900),m=(now->tm_mon+1),d=now->tm_mday;
    char ctime[20];
	if(d<=9&&m<=9)sprintf(ctime,"%d-0%d-0%d",y,m,d);
	if(d<=9&&m>9)sprintf(ctime,"%d-%d-0%d",y,m,d);
	if(d>9&&m<=9)sprintf(ctime,"%d-0%d-%d",y,m,d);
	if(d>9&&m>9)sprintf(ctime,"%d-%d-%d",y,m,d);
	int userNumber=0;
	ifstream in_file4("user.txt",ios::in);
	while(true)
	{
		in_file4>>user[userNumber].userID
		       >>user[userNumber].userName
		       >>user[userNumber].userCode
			   >>user[userNumber].phoneNumber
			   >>user[userNumber].adress
			   >>user[userNumber].moneyLeft
			   >>user[userNumber].status;
		if(in_file4.fail())break;
		userNumber++;
	}
	in_file4.close();
	int moneyNumber=0;
	ifstream in_file7("moneyin.txt",ios::in);
	while(true)
	{
		in_file7>>moneyPutIn[moneyNumber].moneyIn
		>>moneyPutIn[moneyNumber].time
		>>moneyPutIn[moneyNumber].userID;
		if(in_file7.fail())break;
		moneyNumber++;
	}
	in_file7.close();
	cout<<"请输入充值金额：";
	double moneyIn;
	SetColorAndBackground(4,0);
	cin>>moneyIn; 
	SetColorAndBackground(7,0);
	cout<<endl<<"充值成功！"<<endl; 
	user[userNumberNow].moneyLeft+=moneyIn;
	moneyPutIn[moneyNumber].moneyIn=moneyIn;
	strcpy(moneyPutIn[moneyNumber].time,ctime);
	strcpy(moneyPutIn[moneyNumber].userID,user[userNumberNow].userID);
	ofstream out_file4("user.txt",ios::out);
	for(int i=0;i<userNumber;i++){
		out_file4<<user[i].userID<<" "
		       <<user[i].userName<<" "
		       <<user[i].userCode<<" "
			   <<user[i].phoneNumber<<" "
			   <<user[i].adress<<" "
			   <<user[i].moneyLeft<<" "
			   <<user[i].status<<endl;
	}
	out_file4.close();
	ofstream out_file17("moneyin.txt",ios::out);
	for(int i=0;i<=moneyNumber;i++){
		out_file17<<moneyPutIn[i].moneyIn<<" "
		        <<moneyPutIn[i].time<<" "
		        <<moneyPutIn[i].userID<<endl;
	}
	out_file17.close();
	cout<<endl<<"您的充值记录如下："<<endl;	 
	cout<<"**********************************"<<endl;
	cout<<std::left<<setw(20)<<"充值金额"<<std::left<<setw(20)<<"充值时间"<<endl;
	for(int i=0;i<=moneyNumber;i++)
	{
		if(strcmp(user[userNumberNow].userID,moneyPutIn[i].userID)==0)
		{
			cout<<std::left<<setw(20)<<fixed<<setprecision(1)<<moneyPutIn[i].moneyIn
			    <<std::left<<setw(20)<<moneyPutIn[i].time<<endl;
		}
	}
	cout<<"**********************************"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	return;
}
 
