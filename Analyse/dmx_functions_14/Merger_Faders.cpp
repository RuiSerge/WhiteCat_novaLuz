int Merger_Faders()
{

 //merging des valeurs des faders en HTP
 int tmp_val=0;
 for (int h=0;h<513;h++)
 {
 bufferFaders[h]=0;
 channel_is_touched_by_fader_fx[h]=0;
 for(int cif=0;cif<core_user_define_nb_faders;cif++)
 {
 switch(fader_mode_with_buffers[cif])
 {
 case 0://HTP normal
 switch(fader_fx_route[cif])
 {
 case 0:
       bufferFaders[h]=Tmax(bufferFaders[h],FaderDoDmx[cif][h]);
 break;
 case 1:
      if(FaderDoDmx[cif][h]>0)
      {
      bufferSequenciel[h]=Tmax(bufferSequenciel[h],FaderDoDmx[cif][h]);
      channel_is_touched_by_fader_fx[h]=1;
      channel_is_touched_by_fader_number[h]=cif;
      channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
      }
 break;
 default: break;
 }
 break;
 case 1://Exclude rendering
 // rien ne se passe, ne sont pas reportés dans le buffer fader
 break;
 case 2://substract
  switch(fader_fx_route[cif])
 {
 case 0:
 tmp_val=bufferFaders[h]-FaderDoDmx[cif][h];
 if(tmp_val<0){tmp_val=0;}
 bufferFaders[h]=tmp_val;
 break;
 case 1:
 if(FaderDoDmx[cif][h]>0)
    {
       tmp_val=bufferSequenciel[h]-FaderDoDmx[cif][h];
       if(tmp_val<0){tmp_val=0;}
       bufferSequenciel[h]=tmp_val;
       channel_is_touched_by_fader_fx[h]=1;
       channel_is_touched_by_fader_number[h]=cif;
       channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
    }
 break;
 default: break;
 }
 break;
 case 3://add
 switch(fader_fx_route[cif])
 {
 case 0:
 if(FaderDoDmx[cif][h]>0)
 {
 tmp_val=bufferFaders[h]+FaderDoDmx[cif][h];
 if(tmp_val>255){tmp_val=255;}
 bufferFaders[h]=tmp_val;
 channel_is_touched_by_fader_fx[h]=1;
 channel_is_touched_by_fader_number[h]=cif;
 channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 break;
 case 1:
 if(FaderDoDmx[cif][h]>0)
 {
 tmp_val=bufferSequenciel[h]+FaderDoDmx[cif][h];
 if(tmp_val>255){tmp_val=255;}
 bufferSequenciel[h]=tmp_val;
 channel_is_touched_by_fader_fx[h]=1;
 channel_is_touched_by_fader_number[h]=cif;
 channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 break;
 default: break;
 }
 break;
 case 4: //screen
  switch(fader_fx_route[cif])
 {
 case 0:
 tmp_val=(int)((FaderDoDmx[cif][h]+bufferFaders[h])/2);
 if(tmp_val>255){tmp_val=255;}
 else if(tmp_val<0){tmp_val=0;}
 if(FaderDoDmx[cif][h]>0)
 {
 bufferFaders[h]=tmp_val;
 channel_is_touched_by_fader_fx[h]=1;
 channel_is_touched_by_fader_number[h]=cif;
 channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 break;
 case 1:
 tmp_val=(int)((FaderDoDmx[cif][h]+bufferSequenciel[h])/2);
 if(tmp_val>255){tmp_val=255;}
 else if(tmp_val<0){tmp_val=0;}
 if(FaderDoDmx[cif][h]>0)
 {
 bufferSequenciel[h]=tmp_val;
 channel_is_touched_by_fader_fx[h]=1;
 channel_is_touched_by_fader_number[h]=cif;
 channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 break;
 default: break;
 }
 break;
 case 5://exclusion
  switch(fader_fx_route[cif])
 {
 case 0:
 if(FaderDoDmx[cif][h]>0)
 {
 if(FaderDoDmx[cif][h]<bufferFaders[h])
 {
  tmp_val=bufferFaders[h]-FaderDoDmx[cif][h];
  if(tmp_val<0){tmp_val=0;}
  bufferFaders[h]=tmp_val;
  channel_is_touched_by_fader_fx[h]=1;
  channel_is_touched_by_fader_number[h]=cif;
  channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 else
 {
  tmp_val=FaderDoDmx[cif][h]-bufferFaders[h];
  if(tmp_val<0){tmp_val=0;}
  bufferFaders[h]=tmp_val;
  channel_is_touched_by_fader_fx[h]=1;
  channel_is_touched_by_fader_number[h]=cif;
  channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 }
 break;
 case 1:
 if(FaderDoDmx[cif][h]>0)
 {
 if(FaderDoDmx[cif][h]<bufferSequenciel[h])
 {
  tmp_val=bufferSequenciel[h]-FaderDoDmx[cif][h];
  if(tmp_val<0){tmp_val=0;}
  bufferSequenciel[h]=tmp_val;
  channel_is_touched_by_fader_fx[h]=1;
  channel_is_touched_by_fader_number[h]=cif;
  channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 else
 {
  tmp_val=FaderDoDmx[cif][h]-bufferSequenciel[h];
  if(tmp_val<0){tmp_val=0;}
  bufferSequenciel[h]=tmp_val;
  channel_is_touched_by_fader_fx[h]=1;
  channel_is_touched_by_fader_number[h]=cif;
  channel_is_touched_by_fader_type_fx[h]=fader_mode_with_buffers[cif];
 }
 }
 break;
 default: break;
}
 break;
 default:
 break;
 }
 }
 }



 return(0);
}
