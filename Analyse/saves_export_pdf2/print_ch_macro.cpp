int print_ch_macro( int cp)
{

for(int m=0; m<4;m++)
{
if(channel_macro_reaction[cp][m]!=0)
{
char titlemacro[8];
char titlemacro2[24];
char titlemacro3[8];
switch(channel_macro_reaction[cp][m])
{
case 0:
sprintf(titlemacro,"-");
break;
case 1:
sprintf(titlemacro,">=");
break;
case 2:
sprintf(titlemacro,">");
break;
case 3:
sprintf(titlemacro,"==");
break;
case 4:
sprintf(titlemacro,"!=");
break;
case 5:
sprintf(titlemacro,"<=");
break;
case 6:
sprintf(titlemacro,"<");
break;
case 7:
sprintf(titlemacro,"Follow");
break;
default:
break;
}
switch(channel_macro_action[cp][m])
{
case 0:
sprintf(titlemacro2,"-");
break;
case 1:
sprintf(titlemacro2,"Bang Banger");
break;
case 2:
sprintf(titlemacro2,"Load Audio");
break;
case 3:
sprintf(titlemacro2,"Play A.Pl");
break;
case 4:
sprintf(titlemacro2,"Stop A.Pl");
break;
case 5:
sprintf(titlemacro2,"Seek A.Pl");
break;
case 6:
sprintf(titlemacro2,"Loop ON A.Pl");
break;
case 7:
sprintf(titlemacro2,"Loop OFF A.Pl");
break;
case 8:
sprintf(titlemacro2,"Volume A.Pl");
break;
case 9:
sprintf(titlemacro2,"Pan A.Pl");
break;
case 10:
sprintf(titlemacro2,"Pitch A.Pl");
break;
case 11:
sprintf(titlemacro2, "Midi Ch15 CC");
break;
case 12:
sprintf(titlemacro2, "Midi Ch15 KOn");
break;
case 13:
sprintf(titlemacro2, "Midi Ch15 KOff");
break;
default:
break;
}
switch(macro_channel_on[cp][m])
{
case 0:
sprintf(titlemacro3,"Off");
break;
case 1:
sprintf(titlemacro3,"ON");
break;
default: break;
}
sprintf(header_export,"Macro %d: %s / %d / %s / %d / %s\n",m+1,titlemacro,channel_macro_val[cp][m][0],titlemacro2,channel_macro_val[cp][m][1],titlemacro3);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
}
verification_fin_de_page();
}

return(0);
}
