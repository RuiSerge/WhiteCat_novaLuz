int do_core_config( int x_cfg_sc,int y_cfg_sc, int largeur_cfg_sc, int hauteur_cfg_sc)
{
petitchiffre.Print("Max Calculations:", x_cfg_sc+15, y_cfg_sc+40);
Line(Vec2D( x_cfg_sc+15, y_cfg_sc+50),Vec2D( x_cfg_sc+120, y_cfg_sc+50)).Draw(CouleurLigne);

int def_param=0;
int def_param_min=1;
int def_param_max=1;

for (int l=0;l<7;l++)
{
Rect Param(Vec2D(x_cfg_sc+120,y_cfg_sc+60+(l*30)),Vec2D(50,25));
Param.SetRoundness(7.5);
Param.Draw(CouleurFond.WithAlpha(0.5));
switch(l)
{
case 0:
petitchiffre.Print("Faders", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_faders), x_cfg_sc+135,y_cfg_sc+75+(l*30));
def_param_max=48;
def_param_min=1;
break;
case 1:
petitchiffre.Print("Docks", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_docks), x_cfg_sc+140,y_cfg_sc+75+(l*30));
def_param_max=6;
break;
case 2:
petitchiffre.Print("Chasers", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_chasers), x_cfg_sc+135,y_cfg_sc+75+(l*30));
def_param_max=128;
break;
case 3:
petitchiffre.Print("Tracks/Chasers", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_tracks_per_chasers), x_cfg_sc+135,y_cfg_sc+75+(l*30));
def_param_max=24;
break;
case 4:
petitchiffre.Print("Gridplayers", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_gridplayers), x_cfg_sc+140,y_cfg_sc+75+(l*30));
def_param_max=4;
break;
case 5:
petitchiffre.Print("Bangers", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_bangers), x_cfg_sc+135,y_cfg_sc+75+(l*30));
def_param_max=128;
break;
case 6:
petitchiffre.Print("Echo", x_cfg_sc+15,y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(core_user_define_nb_echo), x_cfg_sc+135,y_cfg_sc+75+(l*30));
def_param_max=24;
break;
default: break;
}
if(window_focus_id==920 && mouse_x>x_cfg_sc+120 && mouse_x<x_cfg_sc+120+50 && mouse_y>y_cfg_sc+60+(l*30) && mouse_y<y_cfg_sc+60+(l*30)+25)
{
Param.DrawOutline(CouleurLigne);
if(mouse_b&1 && mouse_released==0  &&  numeric_postext>0)
{
def_param=atoi(numeric);
if(def_param<=def_param_max && def_param>=def_param_min)
{
switch(l)
{
case 0:
core_user_define_nb_faders=def_param;
break;
case 1:
core_user_define_nb_docks=def_param;
for(int i=0;i<48;i++)//core adapt
{
for(int d=0;d<6;d++)
{
DockIsSelected[i][d]=0;
}

DockIsSelected[i][0]=1;
}
break;
case 2:
core_user_define_nb_chasers=def_param;
break;
case 3:
core_user_define_nb_tracks_per_chasers=def_param;
nbre_track_visualisables=core_user_define_nb_tracks_per_chasers;
if(nbre_track_visualisables>8){nbre_track_visualisables=8;}
break;
case 4:
core_user_define_nb_gridplayers=def_param;
break;
case 5:
core_user_define_nb_bangers=def_param;
break;
case 6:
core_user_define_nb_echo=def_param;
break;
default: break;
}
mouse_released=1;
reset_numeric_entry();
}
}
}
}

petitchiffre.Print("Do Calculations:", x_cfg_sc+200, y_cfg_sc+40);
Line(Vec2D( x_cfg_sc+200, y_cfg_sc+50),Vec2D( x_cfg_sc+305, y_cfg_sc+50)).Draw(CouleurLigne);
char tmp_state_core[8];
for (int l=0;l<9;l++)
{
Rect BParam(Vec2D(x_cfg_sc+300,y_cfg_sc+60+(l*25)),Vec2D(50,20));
BParam.SetRoundness(7.5);
BParam.Draw(CouleurFond.WithAlpha(0.5));
switch(core_do_calculations[l])
{
case 0:
sprintf(tmp_state_core,"/Off");
break;
case 1:
BParam.Draw(CouleurFader);
sprintf(tmp_state_core,"/On");
break;
default: break;
}
switch(l)
{
case 0:
petitchiffre.Print("Faders", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 1:
petitchiffre.Print("CueList", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 2:
petitchiffre.Print("Banger", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 3:
petitchiffre.Print("Trichromy", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 4:
petitchiffre.Print("VideoTracking", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 5:
petitchiffre.Print("Chasers", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 6:
petitchiffre.Print("Grid", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 7:
petitchiffre.Print("Ch. Macros", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
case 8:
petitchiffre.Print("Echo", x_cfg_sc+200,y_cfg_sc+75+(l*25));
break;
default:
break;
}
petitchiffre.Print(tmp_state_core,x_cfg_sc+310,y_cfg_sc+75+(l*25));
if(window_focus_id==920 && mouse_x>x_cfg_sc+305 && mouse_x<x_cfg_sc+305+50 && mouse_y>y_cfg_sc+60+(l*25) && mouse_y<y_cfg_sc+60+(l*25)+20
&& mouse_released==0)
{
core_do_calculations[l]=toggle(core_do_calculations[l]);
mouse_released=1;
}

}

petitchiffre.Print("FPS RATE:", x_cfg_sc+370, y_cfg_sc+40);
Line(Vec2D( x_cfg_sc+370, y_cfg_sc+50),Vec2D( x_cfg_sc+485, y_cfg_sc+50)).Draw(CouleurLigne);
for (int l=0;l<2;l++)
{
Rect BCParam(Vec2D(x_cfg_sc+470,y_cfg_sc+60+(l*30)),Vec2D(50,25));
BCParam.SetRoundness(7.5);
BCParam.Draw(CouleurFond.WithAlpha(0.5));
switch(l)
{
case 0:
petitchiffre.Print("DMX:", x_cfg_sc+370, y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(BPS_RATE), x_cfg_sc+485, y_cfg_sc+75+(l*30));
break;
case 1:
petitchiffre.Print("DMX IN:", x_cfg_sc+370, y_cfg_sc+75+(l*30));
petitchiffre.Print(ol::ToString(dmxINrate), x_cfg_sc+485, y_cfg_sc+75+(l*30));
break;
default:
break;
}
if(window_focus_id==920 && mouse_x>x_cfg_sc+470 && mouse_x<x_cfg_sc+470+50 && mouse_y>y_cfg_sc+60+(l*30) && mouse_y<y_cfg_sc+60+(l*30)+25)
{
BCParam.DrawOutline(CouleurLevel);
if(mouse_b&1 && mouse_released==0  &&  numeric_postext>0)
{
def_param=atoi(numeric);
switch(l)
{
case 0://BPS RATE
if(def_param>=10 && def_param<=250)
{
BPS_RATE=def_param;
ticker_rate = BPS_TO_TIMER(BPS_RATE);
install_int_ex(ticker , ticker_rate);
reset_numeric_entry();
}
break;
case 1://DMX IN RATE
if(def_param>=10 && def_param<=50)
{
dmxINrate=def_param;
ticker_dmxIn_rate = BPS_TO_TIMER(dmxINrate);
install_int_ex(ticker_dmxIn , ticker_dmxIn_rate);
reset_numeric_entry();
}
break;
default: break;
}
mouse_released=1;
}
}
}

 return(0);
}
