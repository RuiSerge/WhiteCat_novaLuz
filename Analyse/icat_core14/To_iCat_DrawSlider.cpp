int To_iCat_DrawSlider(int id, int x1,int y1, int affectation, int valeur_sl)
{

int draw_largeur=0; int draw_hauteur=0;
sprintf(StrOrderToiCat,"model slider%d image http://www.le-chat-noir-numerique.fr/iCat/slider.jpg",id);
nbrbytessendediCat=sendto(sockiCat,StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

switch ( iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model slider%d scale %.1f %d 0",id,0.125*(ratio_iCat_slider[iCatPageis][id]),(ratio_iCat_slider[iCatPageis][id]));//0.125=1/16 * largeur 8
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
draw_largeur=iCatSlidersizeX; draw_hauteur=iCatSlidersizeY;
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model slider%d rotate 0 90 0",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat,"model slider%d scale %d %.1f 0",id,(ratio_iCat_slider[iCatPageis][id]),0.125*(ratio_iCat_slider[iCatPageis][id]));//0.125=1/16 * largeur 8
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
draw_largeur=iCatSlidersizeY; draw_hauteur=iCatSlidersizeX;
break;
default: break;
}

sprintf(StrOrderToiCat,"model slider%d position %d %d 0",id, (x1*2)+((draw_largeur*ratio_iCat_slider[iCatPageis][id])/2), (y1*2)+((draw_hauteur*ratio_iCat_slider[iCatPageis][id])/2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

float col_fader_r=0.9, col_fader_g=0.5, col_fader_b=0.0;
int value=0;
switch(affectation)
{
case 1://faders
if(valeur_sl>=0 && valeur_sl<=48)
{
switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

if(FaderLocked[valeur_sl-1]==0)
{
  switch(DockTypeIs[valeur_sl-1][(dock_used_by_fader_is[valeur_sl-1])])
  {
               case 6://audio vol
               col_fader_r=0.0, col_fader_g=0.0, col_fader_b=0.6;
               break;
               case 7://audio pan
               col_fader_r=0.0, col_fader_g=0.0, col_fader_b=0.6;
               break;
               case 8://audio pitch
               col_fader_r=0.0, col_fader_g=0.0, col_fader_b=0.6;
               break;
               case 11://fx
               col_fader_r=0.0, col_fader_g=0.8, col_fader_b=0.0;
               break;
               case 12://grid
               col_fader_r=1.0, col_fader_g=0.0, col_fader_b=0.0;
               break;
               case 13://fx group
               col_fader_r=0.8, col_fader_g=0.8, col_fader_b=0.0;
               break;
               case 14://mover
               col_fader_r=0.5, col_fader_g=0.0, col_fader_b=0.7;
               break;
               case 15://draw
               col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
               break;
               case 16://echo
               col_fader_r=0.2, col_fader_g=0.6, col_fader_b=1.0;
               break;
               default://faders oranges
               col_fader_r=0.9, col_fader_g=0.5, col_fader_b=0.0;
               break;
  }
}
else
{//locké
  col_fader_r=0.0, col_fader_g=0.4, col_fader_b=0.2;
}


sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id, col_fader_r, col_fader_g, col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d text %d",id, valeur_sl);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
if(dmx_view==0){
if(is_dock_for_lfo_selected[valeur_sl-1][dock_used_by_fader_is[valeur_sl-1]]==1)
{
sprintf(StrOrderToiCat, "model tlev%d text %d *",id, (int)((float)(Fader[valeur_sl-1])/2.55));
}
else
{
sprintf(StrOrderToiCat, "model tlev%d text %d",id, (int)((float)(Fader[valeur_sl-1])/2.55));
}
}
else {
if(is_dock_for_lfo_selected[valeur_sl-1][dock_used_by_fader_is[valeur_sl-1]]==1)
{
sprintf(StrOrderToiCat, "model tlev%d text %d *",id, Fader[valeur_sl]);
}
else
{
sprintf(StrOrderToiCat, "model tlev%d text %d",id, Fader[valeur_sl]);
}
}
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tdes%d text %s",id,DockName[valeur_sl-1][dock_used_by_fader_is[valeur_sl-1]] );
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tdes%d position %d %d 0",id, (x1*2)-5, (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tdes%d rotate -90 0 0 1",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tdes%d font %s",id,iphone_fonts[5]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tdes%d fontsize 15",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


}
break;

case 2://speed fader
if(valeur_sl>=0 && valeur_sl<=48)
{
switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.9, col_fader_g=0.5, col_fader_b=0.0;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id, col_fader_r, col_fader_g, col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d text S.%d",id, valeur_sl);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 16",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d text %d",id, lfo_speed[valeur_sl-1]-64);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
}
break;

case 3://sequenciel /1: stage /2: preset /3: accelero
switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
switch(iCat_affectation_slider_value_is[iCatPageis][id])
{
case 0:
sprintf(StrOrderToiCat, "model t%d text St",id);
break;
case 1:
sprintf(StrOrderToiCat, "model t%d text Pst",id);
break;
case 2:
sprintf(StrOrderToiCat, "model t%d text Sp",id);
break;
default: break;
}
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

break;

case 4://grand master

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.7, col_fader_g=0.0, col_fader_b=0.0;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d text GM",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(10*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;

case 5://level wheel

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=0.7, col_fader_b=0.7;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d text LvA",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(10*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
if(dmx_view==0){
        sprintf(StrOrderToiCat, "model tlev%d text %d",id, (int)((float)(absolute_level_wheel)/2.55)); }
        else {sprintf(StrOrderToiCat, "model tlev%d text %d",id, absolute_level_wheel); }
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;

case 6://mover params


switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.5, col_fader_g=0.0, col_fader_b=0.7;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d text MoV%d",id, id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tl%d position %d %d 0",id, (x1*2)-(10*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


switch(tracker_16b_edit)
{
case 0:
 value= mover_params[valeur_sl-1][0];
break;
case 1:
 value= mover_params[valeur_sl-1][1];
break;
default: break;
}
sprintf(StrOrderToiCat, "model tlev%d text %d",id,value);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

break;

case 7: //DRAW PRESSURE

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d text P%d",id, iCat_affectation_slider_value_is[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d text %d",id,(int)(draw_level_to_do[(iCat_affectation_slider_value_is[iCatPageis][id]-1)]*127));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 8: //DRAW ANGLE

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d text D%d",id, iCat_affectation_slider_value_is[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d text %d",id,(int)(draw_damper_decay_factor[(iCat_affectation_slider_value_is[iCatPageis][id]-1)]*127));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 9: //DRAW Ghost

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d text G%d",id, iCat_affectation_slider_value_is[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d text %d",id,(int)(draw_ghost_to_do[(iCat_affectation_slider_value_is[iCatPageis][id]-1)]*127));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;


case 10: //DRAW PRESSURE SELECTED

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d text P%d",id, draw_preset_selected+1);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d text %d",id,(int)(draw_level_to_do[draw_preset_selected]*127));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 11: //DRAW ANGLE SELECTED

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d text D%d",id, draw_preset_selected+1);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d text %d",id,(int)(draw_damper_decay_factor[draw_preset_selected]*127));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 12: //DRAW Ghost

switch (iCat_orientation_slider[iCatPageis][id])
{
case 0://vertical
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]),
(x1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]),(y1*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1://horizontal
sprintf(StrOrderToiCat,"model level%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),(x1*2),(y1*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
sprintf(StrOrderToiCat,"model level%d width 100",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
col_fader_r=0.0, col_fader_g=1.0, col_fader_b=0.9;
sprintf(StrOrderToiCat,"model level%d color %.1f %.1f %.1f",id,col_fader_r,col_fader_g,col_fader_b);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model t%d text G%d",id, draw_preset_selected+1);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d position %d %d 0",id, (x1*2)-(5*ratio_iCat_slider[iCatPageis][id]), (y1*2)-5);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d font %s",id,iphone_fonts[6]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model t%d fontsize 20",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model tlev%d text %d",id,(int)(draw_ghost_to_do[draw_preset_selected]*127));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+(10*ratio_iCat_slider[iCatPageis][id]), (y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d font %s",id,iphone_fonts[0]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model tlev%d fontsize 12",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;


default:
break;
}

if( iCat_orientation_slider[iCatPageis][id]==1)
{
  sprintf(StrOrderToiCat, "model t%d position %d %d 0",id,(x1*2)+10+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]), (y1*2)+(5*ratio_iCat_slider[iCatPageis][id]));
  nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
  sprintf(StrOrderToiCat, "model tlev%d position %d %d 0",id,(x1*2)+10+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][id]), (y1*2)+(15*ratio_iCat_slider[iCatPageis][id]));
  nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
  sprintf(StrOrderToiCat, "model tdes%d rotate 0 0 0 1",id);
  nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
  sprintf(StrOrderToiCat, "model tdes%d position %d %d 0",id,(x1*2), (y1*2));
  nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

}




return(0);
}
