int calculs_etats_faders_et_contenus()
{
 calculation_on_faders_done=0;
for (int f=0;f<core_user_define_nb_faders;f++)
 {
if(FaderLocked[f]==1 && LockFader_is_FullLevel[f]==1)//masterisation au lock des autres faders
{
locklevel=Fader[f];
DoLock(f,Fader[f]);//remasterisation des niveaux
}
if(FaderIsFlash[f]==1 && FaderIsFlashBefore[f]==0)
{
LevelFaderBeforeFlash[f]=Fader[f];
fader_set_level(f,255);
FaderIsFlashBefore[f]= FaderIsFlash[f];
}
else if (FaderIsFlash[f]==0 && FaderIsFlashBefore[f]==1)
{
fader_set_level(f,LevelFaderBeforeFlash[f]);
FaderIsFlashBefore[f]= FaderIsFlash[f];
}

 for (int d=0;d<core_user_define_nb_docks;d++)
 {
        if (DockIsSelected[f][d]==1)
        {
        switch(DockTypeIs[f][d])
        {
         //artnet
          case 2:
          for (int pp=0;pp<513;pp++)
              {
             FaderDockContains[f][d][pp]=(int)ArtNet_16xUniverse_Receiving[pp][(DockNetIs[f][d])];
              }
          break;
          //DMX IN
         case 3:
          for (int ppin=0;ppin<512;ppin++)//etait 513 aout 2016
             {
             FaderDockContains[f][d][ppin]=(int)dmxIN[ppin+1];
             }
          break;
           //VIDEO TRACKING
         case 4:
          for (int ppin=0;ppin<513;ppin++)//était 514 aout 2016
             {
             FaderDockContains[f][d][ppin]=(int)buffer_tracker[ppin];
           }
           break;
            // MEMOIRES
          case 5:
             for (int ppin=0;ppin<513;ppin++)//était 514 aout 2016
             {
             FaderDockContains[f][d][ppin]=Memoires[(DockHasMem[f][d])][ppin];
             }
          break;
          case 6://report et controle des fadersAudio
          Control_Audio_thruth_faders(f,d,0);
          break;
          case 7://report et controle des fadersAudio
          Control_Audio_thruth_faders(f,d,1);
          break;
          case 8://report et controle des fadersAudio
          Control_Audio_thruth_faders(f,d,2);
          break;

          case 10://direct channeling remoting
          switch (index_fader_is_manipulated[f])
          {
          case 0:
          beforeloop_for_directch[f]=Fader[f];

          Fader[f]=bufferSequenciel[(FaderDirectChan[f][d])];


          if(Fader[f]==255){midi_levels[f]=127;} else { midi_levels[f]=(int)Fader[f]/2;}
          if( beforeloop_for_directch[f]!=Fader[f])
          {
          index_send_midi_out[f]=1;
          }
          break;
          case 1:
          bufferSaisie[(FaderDirectChan[f][d])]=(255- curve_report[(FaderCurves[f])][(Fader[f])]);//pour etre actif: buffer saisi
          index_fader_is_manipulated[f]=0;
          break;
          default: break;
          }
          break;

          case 11://chasers
           for (int ppin=1;ppin<513;ppin++)
             {
             FaderDockContains[f][d][ppin]=MergerBufferChasers[(ChaserAffectedToDck[f][d])][ppin];
             }
          break;
          case 12://grid
           for (int ppin=1;ppin<513;ppin++)
           {
             if(ppin<grider_begin_channel_is-1)
             {
              FaderDockContains[f][d][ppin]=0;//nettoyage à cause de l adressage   si chgt adresse faut nettoyer le buffer
              }
             if(ppin+grider_begin_channel_is-1<513)//eviter débordement hors des 513 circuits
             {
             FaderDockContains[f][d][ppin+grider_begin_channel_is-1]=buffer_gridder[(faders_dock_grid_affectation[f][d])][ppin-1];
             }
           }
          break;
          case 13://fgroup

          for (int ppin=1;ppin<513;ppin++)
              {FaderDockContains[f][d][ppin]=0;}

          for(int fg=0;fg<48;fg++)
          {
          if(fgroup[f][d][fg]==1)
          {
               for (int ppin=1;ppin<513;ppin++)
              {
              FaderDockContains[f][d][ppin]=Tmax(FaderDockContains[f][d][ppin],FaderDoDmx[fg][ppin]);
              }
          }
          }
          break;

          case 14://mover
           for (int ppin=1;ppin<513;ppin++)
           {
              FaderDockContains[f][d][ppin]=buffer_moving_head[ppin];
           }
          break;
          case 15://draw
        //  if(drawing_bitmap==0)
       //   {
          //calcul normal
           for (int ppin=1;ppin<513;ppin++)
           {
            FaderDockContains[f][d][ppin]=0;
           for(int p=0;p<500;p++)
           {
           if(draw_preset_channel_routing[(DrawAffectedToDck[f][d])][p]==ppin)
              {
              FaderDockContains[f][d][ppin]=int (255 * draw_preset_levels[(DrawAffectedToDck[f][d])][p] );
              }
           }
           }
         //  }
          break;
          case 16://echo
            for (int ppin=1;ppin<513;ppin++)
           {
            FaderDockContains[f][d][ppin]=int (255.0 * echo_levels[(echo_affected_to_dock[f][d])][0][ppin-1] );
           }
          break;
          case 17://Wave
            for (int ppin=1;ppin<513;ppin++)
           {
            FaderDockContains[f][d][ppin]= buffer_wave[ppin];
           }
          break;
          default:
          break;
          }

 //data normal

        for (int j=1;j<514;j++)
       {
        FaderDoDmx[f][j]=(int)(((float)(FaderDockContains[f][d][j])/255)  * (255- curve_report[(FaderCurves[f])][(Fader[f])]) );
      //avant curve:  FaderDoDmx[f][j]=(int)(((float)(FaderDockContains[f][d][j])/255)  * Fader[f]);
       }
 }
 }
 }
 calculation_on_faders_done=1;
 return(0);
}
