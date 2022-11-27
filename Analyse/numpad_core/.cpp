int do_logical_visual_numeric_pad (int x_num, int y_num)
{

level_wheel_core(x_num+10+260,y_num+35,rayon_wheel_level,angle_correction_wheel);
for (int loi=0;loi<3;loi++)
{
if(mouse_x>x_num+10+(70*loi) && mouse_x<x_num+70+(70*loi) && mouse_y>y_num+16 && mouse_y<y_num+76)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][671+loi])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad %d is Ch: %d Pitch: %d Typ: %s" , (1+loi),miditable[1][671+loi],miditable[2][671+loi],thetypinfo);
  attribute_midi_solo_affectation((671+loi),Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
if(loi==0){simulate_keypress(KEY_1<<8);}
else if(loi==1){simulate_keypress(KEY_2<<8);}
else if(loi==2){simulate_keypress(KEY_3<<8);}
mouse_released=1;
}
}
}

for (int loi=0;loi<3;loi++)
{
if(mouse_x>x_num+10+(70*loi) && mouse_x<x_num+70+(70*loi) && mouse_y>y_num+86 && mouse_y<y_num+146)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][674+loi])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad %d is Ch: %d Pitch: %d Typ: %s" , (4+loi),miditable[1][674+loi],miditable[2][674+loi],thetypinfo);
  attribute_midi_solo_affectation((674+loi),Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
if(loi==0){simulate_keypress(KEY_4<<8);}
else if(loi==1){simulate_keypress(KEY_5<<8);}
else if(loi==2){simulate_keypress(KEY_6<<8);}
mouse_released=1;
}
}
}

for (int loi=0;loi<3;loi++)
{
if(mouse_x>x_num+10+(70*loi) && mouse_x<x_num+70+(70*loi) && mouse_y>y_num+156 && mouse_y<y_num+216)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][677+loi])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad %d is Ch: %d Pitch: %d Typ: %s" , (7+loi),miditable[1][677+loi],miditable[2][677+loi],thetypinfo);
  attribute_midi_solo_affectation((677+loi),Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
if(loi==0){simulate_keypress(KEY_7<<8);}
else if(loi==1){simulate_keypress(KEY_8<<8);}
else if(loi==2){simulate_keypress(KEY_9<<8);}
mouse_released=1;
}
}
}

for (int loi=0;loi<3;loi++)
{
if(mouse_x>x_num+10+(70*loi) && mouse_x<x_num+70+(70*loi) && mouse_y>y_num+226 && mouse_y<y_num+296)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
if(loi==0)
{
switch(miditable[0][670])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
sprintf(string_last_midi_id,"NumPad 0 is Ch: %d Pitch: %d Typ: %s" ,miditable[1][670],miditable[2][670],thetypinfo);
attribute_midi_solo_affectation(670,Midi_Faders_Affectation_Mode);
}
else if(loi==1)
{
sprintf(string_last_midi_id,"NumPad DOT is Ch: %d Pitch: %d Typ: %s" , miditable[1][679+loi],miditable[2][679+loi],thetypinfo);
attribute_midi_solo_affectation((679+loi),Midi_Faders_Affectation_Mode);
}
else if(loi==2)
{
sprintf(string_last_midi_id,"NumPad ESC is Ch: %d Pitch: %d Typ: %s" , miditable[1][679+loi],miditable[2][679+loi],thetypinfo);
attribute_midi_solo_affectation((679+loi),Midi_Faders_Affectation_Mode);
}
mouse_released=1;
}
else
{
if(loi==0){simulate_keypress(KEY_0<<8);}
else if(loi==1){simulate_keypress(KEY_COMMA<<8);}
else if(loi==2){simulate_keypress(KEY_ESC<<8);}
mouse_released=1;
}
}
}

if(mouse_x>x_num+10+210 && mouse_x<x_num+10+210+100 && mouse_y>y_num+86 && mouse_y<y_num+146)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][668])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad UP is Ch: %d Pitch: %d Typ: %s" ,miditable[1][668],miditable[2][668],thetypinfo);
  attribute_midi_solo_affectation(668,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_UP<<8);
mouse_released=1;
}
}

if(mouse_x>x_num+10+210 && mouse_x<x_num+10+210+100 && mouse_y>y_num+156 && mouse_y<y_num+216)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][669])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad DOWN is Ch: %d Pitch: %d Typ: %s" , miditable[1][669],miditable[2][669],thetypinfo);
  attribute_midi_solo_affectation(669,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_DOWN<<8);
mouse_released=1;
}
}

if(mouse_x>x_num+10+210 && mouse_x<x_num+10+210+100 && mouse_y>y_num+226 && mouse_y<y_num+296)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][665])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad ENTER is Ch: %d Pitch: %d Typ: %s" , miditable[1][665],miditable[2][665],thetypinfo);
  attribute_midi_solo_affectation(665,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_ENTER<<8);
mouse_released=1;
}
}

if(mouse_x>x_num+10+320 && mouse_x<x_num+70+320 && mouse_y>y_num+86 && mouse_y<y_num+146)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][666])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad PLUS is Ch: %d Pitch: %d Typ: %s" , miditable[1][666],miditable[2][666],thetypinfo);
  attribute_midi_solo_affectation(666,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_PLUS_PAD<<8);
mouse_released=1;
}
}


if(mouse_x>x_num+10+320 && mouse_x<x_num+70+320 && mouse_y>y_num+156 && mouse_y<y_num+216)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][667])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad MINUS is Ch: %d Pitch: %d Typ: %s" , miditable[1][667],miditable[2][667],thetypinfo);
  attribute_midi_solo_affectation(667,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_MINUS_PAD<<8);
mouse_released=1;
}
}


if(mouse_x>x_num+330 && mouse_x<x_num+390 && mouse_y>y_num+230 && mouse_y<y_num+250)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][1827])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad AT FULL is Ch: %d Pitch: %d Typ: %s" , miditable[1][1827],miditable[2][1827],thetypinfo);
  attribute_midi_solo_affectation(1827,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_I<<8);
mouse_released=1;
}
}
if(mouse_x>x_num+330 && mouse_x<x_num+390 && mouse_y>y_num+265 && mouse_y<y_num+285)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][1828])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad AT ZERO is Ch: %d Pitch: %d Typ: %s" , miditable[1][1828],miditable[2][1828],thetypinfo);
  attribute_midi_solo_affectation(1828,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
simulate_keypress(KEY_O<<8);
mouse_released=1;
}
}
if(mouse_x>x_num+330 && mouse_x<x_num+385 && mouse_y>y_num+15 && mouse_y<y_num+35)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][1825])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad CHECK MINUS is Ch: %d Pitch: %d Typ: %s" , miditable[1][1825],miditable[2][1825],thetypinfo);
  attribute_midi_solo_affectation(1825,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
     index_false_control= 1;
     index_false_shift=0;
     simulate_keypress(KEY_LEFT<<8);

mouse_released=1;
}
}

if(mouse_x>x_num+330 && mouse_x<x_num+385 && mouse_y>y_num+45 && mouse_y<y_num+65)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
  switch(miditable[0][1826])
  {
  case 0: sprintf(thetypinfo,"Note");break;
  case 1: sprintf(thetypinfo,"Key On");break;
  case 2: sprintf(thetypinfo,"Key Off");break;
  case 4: sprintf(thetypinfo,"Ctrl Change");break;
  default: break;
  }
  sprintf(string_last_midi_id,"NumPad CHECK PLUS is Ch: %d Pitch: %d Typ: %s" , miditable[1][1826],miditable[2][1826],thetypinfo);
  attribute_midi_solo_affectation(1826,Midi_Faders_Affectation_Mode);
  mouse_released=1;
}
else
{
     index_false_control= 1;
     index_false_shift=0;
     simulate_keypress(KEY_RIGHT<<8);
mouse_released=1;
}
}


return(0);
}
