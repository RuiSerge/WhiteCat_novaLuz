int Box_mem_to_mem(int xb, int yb)
{


Rect Allmem(Vec2D((xb+270),(yb+170)), Vec2D( 50,20));
Allmem.SetRoundness(7.5);
Allmem.SetLineWidth(triple_epaisseur_ligne_fader);
Allmem.Draw(CouleurFond.WithAlpha(0.5));
petitchiffre.Print("On ALL the memories",xb+325,yb+180);

Rect Frommem(Vec2D((xb+270),(yb+205)), Vec2D( 50,20));
Frommem.SetRoundness(7.5);
Frommem.SetLineWidth(triple_epaisseur_ligne_fader);
Frommem.Draw(CouleurFond.WithAlpha(0.5));
petitchiffre.Print("From memory",xb+325,yb+220);
petitchiffre.Print("To memory",xb+325,yb+255);


switch(wizard_amplitude_is_global)
{
case 0:
Frommem.Draw(CouleurFader);
break;
case 1:
Allmem.Draw(CouleurFader);
break;
default: break;
}

if(window_focus_id==W_WIZARD && mouse_x>xb+270 && mouse_x<xb+320 )
{
if(mouse_y>yb+170 && mouse_y<yb+190)//wizard global
{
if(mouse_button==1 && mouse_released==0)
{
wizard_amplitude_is_global=1;
bool firstmem=0;
for(int m=0;m<10000;m++)
{
if(MemoiresExistantes[m]==1 && firstmem==0)
{
firstmem=1;
wizard_from_mem=m;
}
if(MemoiresExistantes[m]==1 && firstmem!=0)
{
wizard_to_mem=m;
}
}
wizard_calcul_nbre_de_mem();
mouse_released=0;
}
}
if(mouse_y>yb+205 && mouse_y<yb+225 && window_focus_id==921)//wizard mem to mem
{
if(mouse_button==1 && mouse_released==0)
{
wizard_amplitude_is_global=0;
wizard_calcul_nbre_de_mem();
mouse_released=0;
}
}
}

char mem_wiz_tmp[7];

Rect wiz_fromMem(Vec2D(xb+410,yb+200), Vec2D( 60,30));
wiz_fromMem.SetRoundness(7.5);
wiz_fromMem.Draw(CouleurFond.WithAlpha(0.5));

sprintf(mem_wiz_tmp,"%d.%d",wizard_from_mem/10,wizard_from_mem%10);
petitchiffre.Print(mem_wiz_tmp,xb+425,yb+220);

Rect wiz_toMem(Vec2D(xb+410,yb+235), Vec2D( 60,30));
wiz_toMem.SetRoundness(7.5);
wiz_toMem.Draw(CouleurFond.WithAlpha(0.5));

sprintf(mem_wiz_tmp,"%d.%d",wizard_to_mem/10,wizard_to_mem%10);
petitchiffre.Print(mem_wiz_tmp,xb+425,yb+255);


if(wizard_amplitude_is_global==0)
{
if(window_focus_id==W_WIZARD && mouse_x>xb+410 && mouse_x<xb+470 )
{
if( mouse_y>yb+200 && mouse_y<yb+230)
{
wiz_fromMem.DrawOutline(CouleurLigne);

if(mouse_button==1 && mouse_released==0)
{
int tempentry=(int)(10*atof(numeric));
reset_numeric_entry();
if(tempentry>=0.0 && tempentry<10000)
{
wizard_from_mem=tempentry;
wizard_calcul_nbre_de_mem();
}
else {sprintf(string_Last_Order,">>Wrong entry : a Mem is from 0.0 to 999.9!");}
mouse_released=1;
}
}
if( mouse_y>yb+235 && mouse_y<yb+265 && window_focus_id==921)
{
wiz_toMem.DrawOutline(CouleurLigne);

if(mouse_button==1 && mouse_released==0)
{
int tempentry=(int)(10*atof(numeric));
reset_numeric_entry();
if(tempentry>=0.0 && tempentry<10000)
{
wizard_to_mem=tempentry;
wizard_calcul_nbre_de_mem();
}
else {sprintf(string_Last_Order,">>Wrong entry : a Mem is from 0.0 to 999.9!");}
mouse_released=1;
}
}
}
}
 return(0);
}
