int do_logical_grand_master(int GMX, int GMY, int larg)
{

if(mouse_x>GMX && mouse_x<GMX+larg && mouse_y>=GMY-20 && mouse_y<=GMY+275)
{


if((window_focus_id==0)&& mouse_button==1 && index_allow_grand_master==1)
{
set_mouse_range(GMX, GMY-20, GMX+larg, GMY+275);//pour pas deborder
niveauGMaster=((GMY+255)-mouse_y);
if(niveauGMaster>255){niveauGMaster=255;}
if(niveauGMaster<0){niveauGMaster=0;}
midi_levels[615]=(niveauGMaster/2);
if(midi_send_out[615]==1){ index_send_midi_out[615]=1;}

if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(615,Midi_Faders_Affectation_Mode);

 switch(miditable[0][615])
 {
  case 0:
  sprintf(thetypinfo,"Note");
  break;
  case 1:
  sprintf(thetypinfo,"Key On");
  break;
  case 2:
  sprintf(thetypinfo,"Key Off");
  break;
  case 4:
  sprintf(thetypinfo,"Ctrl Change");
  break;
  default: break;
}
  sprintf(string_last_midi_id,"MIDI GRAND MASTER:Ch: %d Pitch: %d Type: %s", miditable[1][615],miditable[2][615],thetypinfo);

mouse_released=1;
}
}
}

if(mouse_x>GMX+larg+30-10 && mouse_x<GMX+larg+30+10 && mouse_y>GMY+250-10 && mouse_y<GMY+250+10)
{
 if(mouse_button==1 && mouse_released==0)
 {
  if(midi_send_out[615]==0){midi_send_out[615]=1; }
  else if(midi_send_out[615]==1){midi_send_out[615]=0; }
  mouse_released=1;
  }
}

raccrochage_midi_logical_vertical_dmx(GMX,GMY,615,larg,255);


return(0);
}
