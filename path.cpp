//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "path.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//int square[50][50];
//int **w;                //cost
int w[50][50];
int n;
int a[50][50];   //distance
int ssad[50][50];
int distance[50];
int trans[50][50];
short int found[2510];
String froms[50];
int from[50];
int last[50];
int wall;
int fromno=0;
String path="";
//String di[30]="";
String pth="";
int source;
int dij[50][50];
int mindis[50][50];
int minp[50];
int renew[50][50];
TColor GridColor[50][50];

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1 -> Memo1->Lines->Clear();   //開始先清空
//	GridColor = new TColor* [StringGrid5->ColCount];
//
//	 for (int i=0; i<StringGrid5->ColCount; i++)
//	 GridColor[i] = new TColor[StringGrid5->RowCount];

	 


}
//---------------------------------------------------------------------------
void printstringgrid(int n)
{
	Form1->StringGrid1->RowCount = n+1; // why n+1?
	Form1->StringGrid1->ColCount = n+1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			Form1->StringGrid1->Cells[j+1][i+1] = w[i][j];

	}
	for(int a=1;a<=n;a++)
	{
		 Form1->StringGrid1->Cells[a][0] = a-1;
		 Form1->StringGrid1->Cells[0][a] = a-1;
	}
}
void printssad(int n)
{
	Form1->StringGrid3->RowCount = n+1; // why n+1?
	Form1->StringGrid3->ColCount = n+1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			Form1->StringGrid3->Cells[j+1][i+1] = ssad[i][j];

	}
	for(int a=1;a<=n;a++)
	{
		 Form1->StringGrid3->Cells[a][0] = a-1;
		 Form1->StringGrid3->Cells[0][a] = a-1;
	}
}

void printdij(int n)
{
	Form1->StringGrid5->RowCount = n+1; // why n+1?
	Form1->StringGrid5->ColCount = n+2;
     dij[source][source]=0;

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			Form1->StringGrid5->Cells[j+1][i+1] = dij[i][j];

	}
	for(int a=1;a<=n;a++)
	{
		 Form1->StringGrid5->Cells[a][0] = a-1;
		 Form1->StringGrid5->Cells[0][a] = a-1;
	}
	for(int i=0;i<n ;i++)
	{
		Form1->StringGrid5->Cells[n+1][i+1]=minp[i];
		//Form1->StringGrid5->Cells[i][n+1]=1;
	}
	Form1->StringGrid5->Cells[n+1][0] = "from";

	//設定顏色的初始值
	 for (int i=0; i<=n; i++)
		for (int k=0; k<=n; k++)
			if (mindis[i][k])
				GridColor[i+1][k+1] = static_cast<TColor>(RGB(250, 245, 135));
			else if (renew[i][k])
			 {
                GridColor[i+1][k+1] = static_cast<TColor>(RGB(100, 25, 55));
			 }
			else
				GridColor[i+1][k+1] = clWhite;
	  for (int i=0; i<=n+1; i++)
	  {
			GridColor[0][i]= clWhite;
			GridColor[i][0]= clWhite;
			GridColor[i][n+2]= clWhite;
      }
	  GridColor[0][0]= clWhite;
	 //StringGrid5->DefaultDrawing= false;
   // StringGrid5->Refresh();

}

void printtrans(int n)
{
	Form1->StringGrid4->RowCount = n+1; // why n+1?
	Form1->StringGrid4->ColCount = n+1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			Form1->StringGrid4->Cells[j+1][i+1] = trans[i][j];

	}
	for(int a=1;a<=n;a++)
	{
		 Form1->StringGrid4->Cells[a][0] = a-1;
		 Form1->StringGrid4->Cells[0][a] = a-1;
	}
}
int choose(int t)              //選出尚未連接的點中可連接起來且擁有最小距離的頂點
{
	int min = wall+1;
	int minpos = -1;
	for(int i=0;i<n;i++)
	{	if(distance[i]<min && !found[i])
		{
			min = distance[i];
			minpos =i;
			//ShowMessage(minpos);
		}
		//dij[t][i]= distance[i];

	}
	return minpos;

}
 

void shortestpat(int v)
{


	for(int i=0; i<n;i++ )
	{
		found[i]= FALSE;
		distance[i]= w[v][i];
		minp[i]=i;

	}
	found[v]= TRUE;

	for(int a=0;a<50;a++)
	{
		froms[a]="";
	}
	for(int a=0;a<n;a++)
	{
		froms[a]=IntToStr(a);
		last[a]=a;
	}
	for(int i=0;i<n;i++)
	{

		int u=choose(i);
		mindis[i][u]=distance[u];

	   //	ShowMessage(mindis[i][u]);
		for(int d=0;d<n ;d++)
			dij[d][i]=distance[d];


		found[u]=TRUE;

		//int a=0;
	   // int firsttime=0;
		for(int a=0;a<n;a++)
		{

			distance[v]=0;

			if(!found[a])
			{
				if(distance[u]+w[u][a]<distance[a])   //原本從起點到u的最短距離加上u到a的總距 比直接從起點到a的距離小
				{

					distance[a] = distance[u]+w[u][a];
					renew[i+1][a] = distance [a];
					minp[a]=u;

					froms[a]= froms[u]+"--["+IntToStr(w[u][a])+"]"+"->"+ froms[a];
						//froms[i]=  "i="+IntToStr(i) +":"+froms[i]+">";
						//froms[i]=  "i="+IntToStr(i) +";";
					   // ShowMessage(i);
					//if(firsttime==0)
					if(froms[u]==w[source][u])
						last[a]=u;
					else
                        last[a]=last[u];
				   //	firsttime=1;
				}
				else
				{
					//froms[a]=  "--{"+IntToStr(distance[u])+"}"+ froms[a];

				}

			}


//			 if(a==n)
//				froms[a]=  "--{"+IntToStr(distance[u])+"}"+froms[a];
		}





	}
}

void shortestpaths(int v)
{


	for(int i=0; i<n;i++ )
	{
		found[i]= FALSE;
		distance[i]= w[v][i];
		from[i]=v;

	}
	int temp=1;


	found[v]= TRUE;

	distance[v]=0;
	while(temp==1)
	{	pth="";
		//int node;
		fromno=0;
		path="";
		for(int i=0;i<n-2;i++)
		{
			int u=choose(i);

			found[u]=TRUE;

			for(int a=0;a<n;a++)
			{

				//歸零擺進來的話每做下一個終點之前的紀錄就會被洗掉
				if(!found[a])
					if(distance[u]+w[u][a]<distance[a])   //原本從起點到u的最短距離加上u到a的總距 比直接從起點到a的距離小
					{
						distance[a] = distance[u]+w[u][a];
						from[a]=u;

					}
			}
		}
		temp=0;
		for(int i=0; i<n;i++ )
		{

		   if(	found[i]== FALSE)
				temp=1;
		}

	}


}

void printallpair(int n)
{
	//ShowMessage(n);
	Form1->StringGrid2->RowCount = n+1; // why n+1?
	Form1->StringGrid2->ColCount = n+1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			Form1->StringGrid2->Cells[j+1][i+1] = a[i][j];

	}
	for(int i=1;i<=n;i++)
	{
		 Form1->StringGrid2->Cells[i][0] = i-1;
		 Form1->StringGrid2->Cells[0][i] = i-1;
	}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	n = StrToInt(Edit1->Text);
//	if(w!=NULL)
//	{
//		for(int a=0;a<n;a++)
//			delete w[a];
//		delete w;
//	}
//	w = new int*[n];
//	for(int a=0;a<n;a++)
//		w[a]= new int [n];
	int range = StrToInt(Edit2->Text);
	int rangemax = StrToInt(Edit3->Text);
	wall = StrToInt(Edit4->Text);
    int i,j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			w[i][j]=rand() % range + 1;
			if (w[i][j]> rangemax)
				 w[i][j]= wall;
		}
		w[i][i]=wall;



	}
	printstringgrid(n);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//	if(w)
//	{
//		for(int a=0;a<n;a++)
//			delete w[a];
//		delete w;
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{


	for(int i=0;i<n;i++)
		for(int j=0; j<n;j++)
		{
			a[i][j]=w[i][j];
			a[i][i]= 0;
		}
	for(int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for(int j=0; j<n ;j++)
			{
				//a[i][j]=min{a[i][j],a[i][k]+a[k][j]};
				if(a[i][j] >  a[i][k]+a[k][j])
					a[i][j] = a[i][k]+a[k][j];
			}
//	for(int i=0;i<n;i++)
//		for(int j=0; j<n;j++)
//			Memo1->Lines->Add(a[i][j]);
	//

	printallpair(n);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

    Form1 -> Memo1->Lines->Clear();
	source = StrToInt(Edit5->Text);
	String dis="";

	for(int i=0;i<50;i++)
	{
		for(int a=0;a<50;a++)
		{
			mindis[i][a]=NULL;
			renew[i][a]=NULL;
            minp[i]= i;
		}
	}
//	//int node;
//	fromno=0;
	path="";

	shortestpat(source);

	for(int a=0;a<n;a++)
	{
		if(a!=source)
		{
			dis = dis +  distance[a] + " ";
			Memo1->Lines->Add("the shortest distance from " + IntToStr(source)+ " to "+IntToStr(a)+" is "+IntToStr(distance[a]));

			//if(a==n)
			//Memo1->Lines->Add(IntToStr(source)+"->["+w[source][last[a]]+"]"+"->"+froms[a]);

			Memo1->Lines->Add(IntToStr(source)+"->["+w[source][last[a]]+"]"+"->"+froms[a]);
		}
	   //	Memo1->Lines->Add(IntToStr(source)+" "+IntToStr(last[a]));


	}
	//Memo1->Lines->Add(dis);
   // Memo1->Lines->Add(path);


     printdij(n);
	for(int i=0; i<n;i++ )   //print all start
	{
		//String dis="";
		//if()
		shortestpaths(i);
//		mindis[i]=distance[i+1];
		for(int a=0;a<n;a++)
		{


			dij[i][a] = distance[a];
			if(w[i][a] == wall )
				dij[i][a] = wall;
//			if(distance[a]<mindis[i]&&distance[a]!=0)
//				mindis[i] = distance[a];

			ssad[i][a] = distance[a];

		}
//		if(mindis[i]==wall || mindis[i]==0)
//			mindis[i]=-1;



		//Memo1->Lines->Add(dis);


	}



	printssad(n);
	//StringGrid5->Refresh();

   //	if(w[source])

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{


	for(int i=0;i<n;i++)
		for(int j=0; j<n;j++)
		{
            trans[i][j]=0;
			a[i][j]=w[i][j];
			a[i][i]= 0;
		}
	for(int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for(int j=0; j<n ;j++)
			{
				//a[i][j]=min{a[i][j],a[i][k]+a[k][j]};
				if(a[i][j] >  a[i][k]+a[k][j])
					a[i][j] = a[i][k]+a[k][j];
			}
	//執行一次allpairj完

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			trans[i][j]=1;
			//if(w[i][j] == wall || w[i][j] == 0 )  //相鄰矩陣
			if(a[i][j] == wall)     //directed
				trans[i][j]=0;
		}
	}
   //	printdij("");
	printtrans(n);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid5DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{


	String text = StringGrid5->Cells[ACol][ARow];
	StringGrid5->Canvas->Brush->Color = GridColor[ACol][ARow];

     /*
	for(int s=0; s< ACol; s++)
	{
		String text1 = StringGrid5->Cells[s][ARow];
		for(int i=0;i<n ;i++)
		{
			//ShowMessage(mindis[s][i]);
			if (text1 == mindis[s][i])
			{  	StringGrid5->Canvas->Brush->Color = static_cast<TColor>(RGB(250, 245, 135));
				//StringGrid5->Canvas->Font->Color = clBlue;
			}
			else
				StringGrid5->Canvas->Brush->Color = clWhite;
		}

	 }     */
	 StringGrid5->Canvas->FillRect(Rect);
	StringGrid5->Canvas->TextRect(Rect, Rect.Left+3, Rect.Top+5, text);


//
//	StringGrid5->Canvas->Brush->Color = clWhite;
//
//	StringGrid5->Canvas->Font->Color = clBlue;
//
//	StringGrid5->Canvas->FillRect(Rect);
//
//	AnsiString text = StringGrid5->Cells[ACol][ARow];
//
//	StringGrid5->Canvas->TextRect(Rect, Rect.Left+8, Rect.Top+8, text);
}
//---------------------------------------------------------------------------


