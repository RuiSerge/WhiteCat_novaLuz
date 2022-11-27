int To_iCat_DrawTrackingZone(int id, int x1,int y1, int xtrackertodraw, int ytrackertodraw)
{
int aire=0;


switch(iCat_trackzone_type_is[iCatPageis][id])
{
case 1://MOver

sprintf(StrOrderToiCat,"model trackzoneE%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/2),
(x1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]),(y1*2)+((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat,"model trackzoneE%d color 0.4, 0.4, 0.4",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model trackzoneF%d xyz %d %d 0 %d %d 0",id,
(x1*2)+((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/2), (y1*2),
(x1*2)+((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/2),(y1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat,"model trackzoneF%d color 0.4, 0.4, 0.4",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model trackPosition%d image http://www.le-chat-noir-numerique.fr/iCat/rond_banger_on.png",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat,"model trackPosition%d scale %.1f %.1f 0",id, 0.2*ratio_iCat_trackzone[iCatPageis][id], 0.2*ratio_iCat_trackzone[iCatPageis][id]);//0.25=128/32
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model trackPosition%d position %d %d 0",id,(x1*2)+xtrackertodraw, (y1*2)+ytrackertodraw);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
char string_mf_id[16];
sprintf(string_mf_id,"%d-%d",xtrackertodraw,ytrackertodraw);
sprintf(StrOrderToiCat,"model trackTextPos%d text %s",id,string_mf_id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model trackTextPos%d position %d %d 0",id,(x1*2), (y1*2)-(1*ratio_iCat_trackzone[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model trackTextPos%d font %s",id,iphone_fonts[5]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model trackTextPos%d fontsize %d",id, 10*ratio_iCat_trackzone[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;

case 2://draw"Draw Activ");
sprintf(StrOrderToiCat,"model DrawAera%dTitle text %s",id,"Draw Activ");
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model DrawAera%dTitle position %d %d 0",id,(x1*2), (y1*2)-(1*ratio_iCat_trackzone[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model DrawAera%dTitle font %s",id,iphone_fonts[5]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model DrawAera%dTitle fontsize %d",id, 8*ratio_iCat_trackzone[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);



for(int lign=0;lign<draw_preset_parameters[draw_preset_selected][1];lign++)
{
for(int col=0;col<draw_preset_parameters[draw_preset_selected][0];col++)
{
int coordonnee=col+(lign*draw_preset_parameters[draw_preset_selected][0]);
sprintf(StrOrderToiCat,"model DrawAera%dOffstet%d xyz %d %d -1 %d %d -1 %d %d -1 %d %d -1",
id,coordonnee,
(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *col),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *lign),

(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *col),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(lign+1)),

(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(col+1)),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(lign+1)),

(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(col+1)),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(lign)));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model DrawAera%dOffstet%d render triangle_fan",id,coordonnee);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model DrawAera%dOffstet%d color 0. %.1f %.1f",id,coordonnee,
draw_preset_levels[draw_preset_selected][coordonnee]*1.0,draw_preset_levels[draw_preset_selected][coordonnee]*0.8);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat,"model track%dNumCh%d text %d",id,coordonnee,draw_preset_channel_routing[draw_preset_selected][coordonnee]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model track%dNumCh%d position %d %d 0",id,coordonnee,
(x1*2)+(int)(( (float)(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *col),
(y1*2)+(7*ratio_iCat_trackzone[iCatPageis][id])+(int)(( (float)(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(lign)) );

nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model track%dNumCh%d font %s",id,coordonnee,iphone_fonts[5]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model track%dNumCh%d fontsize %d",id,coordonnee, 6*ratio_iCat_trackzone[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


}
}



sprintf(StrOrderToiCat,"model DrawAera%dCurseur xyz %d %d -0.5 %d %d -0.5 %d %d -0.5 %d %d -0.5",
id,
(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0])*draw_centre_x[draw_preset_selected] ),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1])*draw_centre_y[draw_preset_selected] ),

(x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected])),
(y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

(x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
(y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

(x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
(y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *draw_centre_y[draw_preset_selected]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat,"model DrawAera%dCurseur render triangle_strip",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat,"model DrawAera%dCurseur color 1.0 0. 0.",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);




break;
case 3://draw"Draw Matrix num");

aire=iCat_trackzone_affectation_is[iCatPageis][id]-1;
sprintf(StrOrderToiCat,"model DrawAera%dTitle text Draw Num %d",id,iCat_trackzone_affectation_is[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model DrawAera%dTitle position %d %d 0",id,(x1*2), (y1*2)-(1*ratio_iCat_trackzone[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model DrawAera%dTitle font %s",id,iphone_fonts[5]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model DrawAera%dTitle fontsize %d",id, 8*ratio_iCat_trackzone[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


for(int lign=0;lign<draw_preset_parameters[aire][1];lign++)
{
for(int col=0;col<draw_preset_parameters[aire][0];col++)
{
int coordonnee=col+(lign*draw_preset_parameters[aire][0]);
sprintf(StrOrderToiCat,"model DrawSelAera%dOffstet%d xyz %d %d -1 %d %d -1 %d %d -1 %d %d -1",
id,coordonnee,
(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][0]) *col),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][1]) *lign),

(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][0]) *col),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][1]) *(lign+1)),

(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][0]) *(col+1)),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][1]) *(lign+1)),

(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][0]) *(col+1)),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][1]) *(lign)));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model DrawSelAera%dOffstet%d render triangle_fan",id,coordonnee);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model DrawSelAera%dOffstet%d color 0. %.1f %.1f",id,coordonnee,
draw_preset_levels[aire][coordonnee]*1.0,draw_preset_levels[aire][coordonnee]*0.8);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat,"model track%dNumCh%d text %d",id,coordonnee,draw_preset_channel_routing[aire][coordonnee]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat, "model track%dNumCh%d position %d %d 0",id,coordonnee,
(x1*2)+(int)(( (float)(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][0]) *col),
(y1*2)+(7*ratio_iCat_trackzone[iCatPageis][id])+(int)(( (float)(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[aire][1]) *(lign)) );

nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model track%dNumCh%d font %s",id,coordonnee,iphone_fonts[5]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
sprintf(StrOrderToiCat, "model track%dNumCh%d fontsize %d",id,coordonnee, 6*ratio_iCat_trackzone[iCatPageis][id]);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


}
}



sprintf(StrOrderToiCat,"model DrawAera%dCurseur xyz %d %d -0.5 %d %d -0.5 %d %d -0.5 %d %d -0.5",
id,
(x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0])*draw_centre_x[draw_preset_selected] ),
(y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1])*draw_centre_y[draw_preset_selected] ),

(x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected])),
(y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

(x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
(y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

(x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
(y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id])/draw_preset_parameters[draw_preset_selected][1]) *draw_centre_y[draw_preset_selected]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat,"model DrawAera%dCurseur render triangle_strip",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


sprintf(StrOrderToiCat,"model DrawAera%dCurseur color 1.0 0. 0.",id);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);




break;
default:
break;
}


sprintf(StrOrderToiCat,"model trackzoneA%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2),
(x1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]),(y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model trackzoneB%d xyz %d %d 0 %d %d 0",id,
(x1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]), (y1*2),
(x1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]),(y1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model trackzoneC%d xyz %d %d 0 %d %d 0",id,
(x1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]), (y1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]),
(x1*2),(y1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

sprintf(StrOrderToiCat,"model trackzoneD%d xyz %d %d 0 %d %d 0",id,
(x1*2), (y1*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][id]),
(x1*2),(y1*2));
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


 return(0);
}
