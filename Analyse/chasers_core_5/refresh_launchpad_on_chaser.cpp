int refresh_launchpad_on_chaser()
{
if( launchpad_chaser_mode==1)
{

for(int trk=0;trk<chaser_midi_rows ;trk++)
{


for(int pas=0;pas<8;pas++)
{
previous_color_on_chaser[trk][pas]=launchpad_color_defined[(1048+(trk*8)+pas)];
switch(chaser_step_operation[chaser_selected][position_affichage_track_num[chaser_selected]+trk][chaser_step_launchpad[chaser_selected]+pas])
{
case 0:
launchpad_color_defined[(1048+(trk*8)+pas)]=0;
break;
case 1:
launchpad_color_defined[(1048+(trk*8)+pas)]=lch_orange_fonce;
break;
case 2:
launchpad_color_defined[(1048+(trk*8)+pas)]=lch_green;
break;
case 3:
launchpad_color_defined[(1048+(trk*8)+pas)]=lch_red;
break;
default: break;
}
int correcteur=0;
switch(chaser_way[chaser_selected])
{
case 0:
correcteur=+1;
break;
case 1:
correcteur=-1;
break;
default: break;
}

if((chaser_step_launchpad[chaser_selected]+pas)==chaser_step_is[chaser_selected]+correcteur)
{launchpad_color_defined[(1048+pas)]=lch_yellow;}//curseur toujours sur première ligne

if(previous_color_on_chaser[trk][pas]!=launchpad_color_defined[(1048+(trk*8)+pas)])
{
midi_launchpad_state_before[(1048+(trk*8)+pas)]=0;
midi_launchpad_state[(1048+(trk*8)+pas)]=1;
}
}
}
}
 return(0);
}
