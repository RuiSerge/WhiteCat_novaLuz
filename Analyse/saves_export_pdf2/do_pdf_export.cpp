int do_pdf_export()
{
index_is_saving=1;
int comptch=0;
cmptline_pdf=0;

sprintf(rep,"%s\\import_export\\pdf\\",mondirectory);
chdir(rep);



    strcpy (fname, importfile_name);

    pdf = HPDF_New (error_handler, NULL);
    if (!pdf) {
        sprintf (string_Last_Order,"error: cannot create PdfDoc object\n");
        return 1;
    }

    if (setjmp(env)) {
        HPDF_Free (pdf);
        return 1;
    }


    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);


/* Add a new page object. */
num_page_pdf=1;
page= HPDF_AddPage (pdf);
height = HPDF_Page_GetHeight (page);
width = HPDF_Page_GetWidth (page);

/* Print the lines of the page. */
    HPDF_Page_SetLineWidth (page, 1);
    HPDF_Page_Rectangle (page, 0, 0, width , height );
    HPDF_Page_Stroke (page);

/* Print the title of the page */
    def_font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize (page, def_font, 13);
    tw = HPDF_Page_TextWidth (page, page_title);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 50, height - 30, page_title);
    HPDF_Page_EndText (page);

debut_lignes=(height -30);

/* header logiciel */
    HPDF_Page_BeginText (page);
    HPDF_Page_SetFontAndSize (page, def_font, 10);
    sprintf(header_export,"Export PDF from WHITECAT Lighting Board. %s",versionis);
    HPDF_Page_TextOut (page, 50, debut_lignes - 20,header_export);
    HPDF_Page_EndText (page);
    HPDF_Page_BeginText (page);
    HPDF_Page_SetFontAndSize (page, def_font, 10);
    sprintf(header_export,"http://www.le-chat-noir-numerique.fr");
    HPDF_Page_TextOut (page, 50, debut_lignes - 30,header_export);
    HPDF_Page_EndText (page);



    sprintf(header_export,"page %d", num_page_pdf);
    draw_numpage(page,width/2,20,header_export);
    position_ligne1= 50;

if(specify_who_to_save_PDF[0]==1)
{
draw_section (page, 100,debut_lignes -70 , "Memories", 1.0,0.0,0.0);

for(int m=0;m<10000;m++)
{
if(MemoiresExistantes[m]==1)
{
comptch=0;
sprintf(header_export,"Mem %d.%d", (m/10),(m%10));
if(MemoiresExclues[m]==1){strcat(header_export, " >>>>> [ MEMORY IS EXCLUDED from CueList ]");}
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

sprintf(header_export,"%s %s", descriptif_memoires[m], annotation_memoires[m]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
cmptline_pdf++;
 ////0=DIN  1=IN 2=DOUT 3=OUT
sprintf(header_export,"Stage: d:%.1f  OUT: %.1f  | Memory: d:%.1f  IN: %.1f", Times_Memoires[m][2], Times_Memoires[m][3],Times_Memoires[m][0],Times_Memoires[m][1]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean pour la boucle
if(Links_Memoires[m]==1)
{
strcpy(header_export,"Link to next Mem ");
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
draw_fleche_link( page, 70, debut_lignes -(position_ligne1 +(cmptline_pdf*12))+10);
cmptline_pdf++;
}
strcpy(header_export,"");//clean pour la boucle
if(Banger_Memoire[m]!=0)
{
sprintf(header_export,"Banger %d     - %s",Banger_Memoire[m],bangers_name[(Banger_Memoire[m])-1]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
}
strcpy(header_export,"");//clean pour la boucle
for(int c=1;c<513;c++)
{
if(Memoires[m][c]>0)
{
if(comptch==0){cmptline_pdf++; strcpy(header_export,"");}//retour ligne après 10 circuits
sprintf(little_header,"%d=%d   ",c,(int)((float)(Memoires[m][c])/2.55));
strcat(header_export,little_header);
comptch++;
if(comptch>10)
{
comptch=0;
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
}
}
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);//fin de la recherche
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");//clean pour la boucle
}
strcpy(header_export,"");//clean pour la boucle
}

cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}



if(specify_who_to_save_PDF[1]==1)
{

draw_section (page, 100,debut_lignes -70 , "Channel Views", 0.0,0.0,0.7);

for(int v=0;v<16;v++)
{
if(channel_number_in_View[v]>0)
{
cmptline_pdf++;
cmptline_pdf++;

verification_fin_de_page();

sprintf(header_export,"Channel View %d [%d]: %s", v+1,channel_number_in_View[v],channel_view_Name[v]);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");
for(int chm=0;chm<513;chm++)
{

if(check_presence_of_A_channel_in_A_view(v,chm)==1)
{

 if(comptch==0){cmptline_pdf++; strcpy(header_export,"");}//retour ligne après 10 circuits
 if(chm<100)  {sprintf(little_header,"%d  -  ",chm);}
 else {sprintf(little_header,"%d - ",chm);}
 strcat(header_export,little_header);
 comptch++;
 if(comptch>18)
 {
 comptch=0;
 draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
 cmptline_pdf++;
 verification_fin_de_page();
 }

}

}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);//fin de la recherche
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");//clean pour la boucle
comptch=0;
}
strcpy(header_export,"");

}



cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}



if(specify_who_to_save_PDF[2]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Channels: Plot + List ", 0.5,0.0,1.0);

for(int cp=1;cp<513;cp++)
{
if(check_channel_is_patched(cp)==1)
{
sprintf(header_export,"Ch.%d : %s\n",cp,descriptif_projecteurs[cp]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
print_ch_from_plot(cp);
cmptline_pdf++;
verification_fin_de_page();
print_ch_macro(cp);
cmptline_pdf++;
verification_fin_de_page();
}
}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();


}

if(specify_who_to_save_PDF[3]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Patch per channels", 1.0,0.0,0.0);

int cmptdim=0;
strcpy(header_export,"");

bool someone_ISpatched=0;
for(int circ=1;circ<513;circ++)
{

sprintf(header_export,"Channel %d -> Dim.",circ);
    for (int cpatch=1; cpatch<513; cpatch++)
    {
    if(Patch[cpatch]==circ)
    {
    someone_ISpatched=1;
    sprintf(little_header," %d [%d] -",cpatch, curves[cpatch]+1);
    strcat(header_export,little_header);
    cmptdim++;
    if(cmptdim>7)
        {
        cmptdim=0;
        draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
        strcpy(header_export,"");
        cmptline_pdf++;
        verification_fin_de_page();
        }
    }
    }
if(someone_ISpatched==1)
{
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
cmptdim=0;
}
strcpy(header_export,"");
someone_ISpatched=0;
cmptdim=0;
}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}

if(specify_who_to_save_PDF[4]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Patch per dimmers", 1.0,0.0,0.0);

int cmptdim=0;
for (int cpatch=1; cpatch<513; cpatch++)
{
if(cmptdim==0){cmptline_pdf++; strcpy(header_export,"");}//retour ligne après 10 circuits
sprintf(little_header,"Dim.%d=Ch.%d [%d]    ",cpatch, Patch[cpatch], curves[cpatch]+1);
strcat(header_export,little_header);
cmptdim++;
if(cmptdim>4)
{
cmptdim=0;
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");
}
}

cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[5]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Banger", 1.0,0.0,0.0);

strcpy(header_export,"");
bool there_is_someone_in_banger=0;
char header_banger_action[64];
char header_banger_typ[64];
for(int f=0;f<127;f++)
{
for(int bgtest=0;bgtest<6;bgtest++)
{
if(bangers_type[f][bgtest]!=0){there_is_someone_in_banger=1;break;}
}
if(there_is_someone_in_banger==1)
{
sprintf(header_export,"Banger %d / %s",f+1, bangers_name[f]);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");//clean
for(int bg=0;bg<6;bg++)
{
switch(bangers_type[f][bg])
{
case 0:
     sprintf(header_banger_typ,"-");
     sprintf(header_banger_action,"-");
break;
case 1:
     sprintf(header_banger_typ,"Faders");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Lock");
     break;
     case 1:
     sprintf(header_banger_action,"Up");
     break;
     case 2:
     sprintf(header_banger_action,"Down");
     break;
     case 3:
     sprintf(header_banger_action,"Saw");
     break;
     case 4:
     sprintf(header_banger_action,"To Prev.Dock");
     break;
     case 5:
     sprintf(header_banger_action,"To Next Dock");
     break;
     case 6:
     sprintf(header_banger_action,"Up/Down loop");
     break;
     case 7:
     sprintf(header_banger_action,"Set Dock Looped");
     break;
     case 8:
     sprintf(header_banger_action,"Set All Looped");
     break;
     case 9:
     sprintf(header_banger_action,"Set Dock Is");
     break;
     case 10:
     sprintf(header_banger_action,"Set LFO at");
     break;
     case 11:
     sprintf(header_banger_action,"Set Fader at");
     break;
     case 12:
     sprintf(header_banger_action,"SetStopPos at");
     break;
     case 13:
     sprintf(header_banger_action,"StopPos ON/OFF");
     break;
     case 14:
     sprintf(header_banger_action,"Paste to Seq.");
     break;
     case 15:
     sprintf(header_banger_action,"Fader MidiOut");
     break;
     case 16:
     sprintf(header_banger_action,"ALL  : Faders at 0");
     break;
     case 17:
     sprintf(header_banger_action,"ALL  : Speed at 0");
     break;
     case 18:
     sprintf(header_banger_action,"ALL  : Lock at 0");
     break;
     case 19:
     sprintf(header_banger_action,"ALL  : LFO at 0");
     break;
     case 20:
     sprintf(header_banger_action,"ALL  : Loop at 0");
     break;
     case 21:
     sprintf(header_banger_action,"ALL  : All at 0");
     break;
     case 22:
     sprintf(header_banger_action,"ALL  : MidiOut at 0");
     break;
     case 23:
     sprintf(header_banger_action,"ALL : RECALL");
     break;
     case 24:
     sprintf(header_banger_action,"Lock Preset");
     break;
     break;
     case 25:
     sprintf(header_banger_action,"Fader: Set Curve");
     break;
     case 26:
     sprintf(header_banger_action,"Fader: LoadChaser");
     break;
     case 27:
     sprintf(header_banger_action,"Fader: PlayChaser");
     break;
     case 28:
     sprintf(header_banger_action,"Fader: SeekChaser");
     break;
     case 29:
     sprintf(header_banger_action,"Fader: LoopChaser");
     break;
     case 30:
     sprintf(header_banger_action,"Fader: Autol.Chaser");
     break;
     case 31:
     sprintf(header_banger_action,"Fader: Set DCH.");
     break;
     case 32:
     sprintf(header_banger_action,"Fader: SetCH Full");
     break;
     case 33:
     sprintf(header_banger_action,"Fader: SetCH 0");
     break;
     case 34:
     sprintf(header_banger_action,"Damper On/Off");
     break;
     case 35:
     sprintf(header_banger_action,"Damper SetDecay");
     break;
     case 36:
     sprintf(header_banger_action,"Damper SetDelta");
     break;
     case 37:
     sprintf(header_banger_action,"Damper Mode");
     break;
     default:
     break;
     }
break;
case 2:
     sprintf(header_banger_typ,"Send Midi");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Key-On V:127");
     break;
     case 1:
     sprintf(header_banger_action,"Key-On V:0");
     break;
     case 2:
     sprintf(header_banger_action,"Key-Off V:127");
     break;
     case 3:
     sprintf(header_banger_action,"Ctrl-Change V:127");
     break;
     case 4:
     sprintf(header_banger_action,"Ctrl-Change V:0");
     break;
     case 5:
     sprintf(header_banger_action,"Ctrl-Change Ch:0");
     break;
     case 6:
     sprintf(header_banger_action,"Ctrl-Change Ch:1");
     break;
     case 7:
     sprintf(header_banger_action,"Ctrl-Change Ch:2");
     break;
     case 8:
     sprintf(header_banger_action,"Ctrl-Change Ch:3");
     break;
     case 9:
     sprintf(header_banger_action,"Ctrl-Change Ch:4");
     break;
     case 10:
     sprintf(header_banger_action,"Ctrl-Change Ch:5");
     break;
     case 11:
     sprintf(header_banger_action,"Ctrl-Change Ch:6");
     break;
     case 12:
     sprintf(header_banger_action,"Ctrl-Change Ch:7");
     break;
     case 13:
     sprintf(header_banger_action,"Ctrl-Change Ch:8");
     break;
     case 14:
     sprintf(header_banger_action,"Ctrl-Change Ch:9");
     break;
     case 15:
     sprintf(header_banger_action,"Ctrl-Change Ch:10");
     break;
     case 16:
     sprintf(header_banger_action,"Ctrl-Change Ch:11");
     break;
     case 17:
     sprintf(header_banger_action,"Ctrl-Change Ch:12");
     break;
     case 18:
     sprintf(header_banger_action,"Ctrl-Change Ch:13");
     break;
     case 19:
     sprintf(header_banger_action,"Ctrl-Change Ch:14");
     break;
     case 20:
     sprintf(header_banger_action,"Ctrl-Change Ch:15");
     break;
     case 21:
     sprintf(header_banger_action,"Set Faders/Sp Out");
     break;
     case 22:
     sprintf(header_banger_action,"Set ChasersTr Out");
     break;
     case 23:
     sprintf(header_banger_action,"Re-emit ALL Out");
     break;
     case 24:
     sprintf(header_banger_action,"MidiClock ON");
     break;
     case 25:
     sprintf(header_banger_action,"MidiClock OFF");
     break;
     case 26:
     sprintf(header_banger_action,"MidiClock RATE");
     break;
     case 27:
     sprintf(header_banger_action,"Msg START");
     break;
     case 28:
     sprintf(header_banger_action,"Msg STOP");
     break;
     case 29:
     sprintf(header_banger_action,"Msg CONTINUE");
     break;
     default:
     break;
     }
break;
case 3:
     sprintf(header_banger_typ,"Windows");
     switch(bangers_action[f][bg])
     {
       case 1:
     sprintf(header_banger_action,"Sequences");
     break;
     case 2:
     sprintf(header_banger_action,"Fader space");
     break;
     case 3:
     sprintf(header_banger_action,"MiniFaders");
     break;
     case 4:
     sprintf(header_banger_action,"Banger");
     break;
     case 5:
     sprintf(header_banger_action,"Audio Players");
     break;
     case 6:
     sprintf(header_banger_action,"Time Window");
     break;
     case 7:
     sprintf(header_banger_action,"Plot Window");
     break;
     case 8:
     sprintf(header_banger_action,"List Window");
     break;
     case 9:
     sprintf(header_banger_action,"Trichromy");
     break;
     case 10:
     sprintf(header_banger_action,"Video-tracking");
     break;
     case 11:
     sprintf(header_banger_action,"Chasers Window");
     break;
     case 12:
     sprintf(header_banger_action,"GridPlayers");
     break;
     case 13:
     sprintf(header_banger_action,"Draw Window");
     break;
     case 14:
     sprintf(header_banger_action,"Echo Window");
     break;
     case 15:
     sprintf(header_banger_action,"Mover Window");
     break;
     case 16:
     sprintf(header_banger_action,"NumPad Window");
     break;
     case 17:
     sprintf(header_banger_action,"CFG MENU");
     break;
     case 18:
     sprintf(header_banger_action,"iCAT Builder");
     break;
     default:
     sprintf(header_banger_action,"-");
     break;
     }
break;
case 4:
     sprintf(header_banger_typ,"Alarm");
     sprintf(header_banger_action,string_alarm[index_banger_selected]);
break;
case 5:
     sprintf(header_banger_typ,"AudioPlayers");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Clear Player");
     break;
     case 1:
     sprintf(header_banger_action,"Load in Player");
     break;
     case 2:
     sprintf(header_banger_action,"SetPlay Player");
     break;
     case 3:
     sprintf(header_banger_action,"Load & Play");
     break;
     case 4:
     sprintf(header_banger_action,"SetLoop Player");
     break;
     case 5:
     sprintf(header_banger_action,"Seek Player");
     break;
     case 6:
     sprintf(header_banger_action,"SetVolume Player");
     break;
     case 7:
     sprintf(header_banger_action,"Set Cue Player");
     break;
     case 8:
     sprintf(header_banger_action,"Seek to CueIn Pl.");
     break;
     case 9:
     sprintf(header_banger_action,"SetPan Player");
     break;
     case 10:
     sprintf(header_banger_action,"SetPitch Player");
     break;
     case 11:
     sprintf(header_banger_action,"SetMidiOut Player");
     break;
     default:
     break;
     }
break;

case 6:
     sprintf(header_banger_typ,"Sequences");
     switch(bangers_action[f][bg])
     {
      case 0://stage jump
      sprintf(header_banger_action,"SetMem onStage");
      break;
      case 1://preset jump
      sprintf(header_banger_action,"SetMem onPreset");
      break;
      case 2://set Speed
      sprintf(header_banger_action,"SetSpeed at");
      break;
      case 3://Set Link
      sprintf(header_banger_action,"SetLink On");
      break;
      case 4://Set Banger
      sprintf(header_banger_action,"SetBanger On");
      break;
      case 5://refresh
      sprintf(header_banger_action,"Reload Stage");
      break;
      case 6://refresh
      sprintf(header_banger_action,"Reload Preset");
      break;
      case 7://refresh
      sprintf(header_banger_action,"GO");
      break;
      case 8://set Blind
      sprintf(header_banger_action,"Set Blind");
      break;
      default:
      break;
     }

break;

case 7:
     sprintf(header_banger_typ,"Chasers");
     switch(bangers_action[f][bg])
     {
      case 0://call num chaser
      sprintf(header_banger_action,"Ch.Sel. Is");
      break;
      case 1://play chaser
      sprintf(header_banger_action,"Play");
      break;
      case 2://seek chaser
      sprintf(header_banger_action,"Seek");
      break;
      case 3://loop chaser
      sprintf(header_banger_action,"Loop");
      break;
      case 4://way chaser
      sprintf(header_banger_action,"Way");
      break;
      case 5://aller retour chaser
      sprintf(header_banger_action,"Aller-Retour");
      break;
      case 6://timemode
      sprintf(header_banger_action,"Time Mode");
      break;
      case 7://slaviness
      sprintf(header_banger_action,"Slave");
      break;
      case 8://Beg P
      sprintf(header_banger_action,"Set Beg Point");
      break;
      case 9://End P
      sprintf(header_banger_action,"Set End Point");
      break;
      case 10://Position
      sprintf(header_banger_action,"Set Position");
      break;
      case 11://toggle track
      sprintf(header_banger_action,"Toggle Track");
      break;
      case 12://ALL ON OFF
      sprintf(header_banger_action,"ALL ON");
      break;
      case 13://INV ON OFF
      sprintf(header_banger_action,"ON INV");
      break;
      case 14://ALL OFF
      sprintf(header_banger_action,"ALL OFF");
      break;
      case 15://call preset
      sprintf(header_banger_action,"ON Preset");
      break;
      case 16://level track
      sprintf(header_banger_action,"Ch.Sel. Level Track");
      break;
      default:
      break;
      }
break;
case 8:
     sprintf(header_banger_typ,"MiniFaders");
     switch(bangers_action[f][bg])
     {
      case 0:
      sprintf(header_banger_action,"Select Num.");
      break;
      case 1:
      sprintf(header_banger_action,"Select All");
      break;
      case 2:
      sprintf(header_banger_action,"Sel. Flash");
      break;
      case 3:
      sprintf(header_banger_action,"Sel. Tog.Lock");
      break;
      case 4:
      sprintf(header_banger_action,"Sel. Tog.Loop");
      break;
      case 5:
      sprintf(header_banger_action,"Sel. Tog.Up");
      break;
      case 6:
      sprintf(header_banger_action,"Sel. Tog.Down");
      break;
      case 7:
      sprintf(header_banger_action,"Sel. Tog.Saw");
      break;
      case 8:
      sprintf(header_banger_action,"Sel. Tog. AllLoop");
      break;
      case 9:
      sprintf(header_banger_action,"Sel. AllAt");
      break;
      case 10:
      sprintf(header_banger_action,"Sel. Tog.StopPos.");
      break;
      case 11:
      sprintf(header_banger_action,"Sel. ToPrev");
      break;
      case 12:
      sprintf(header_banger_action,"Sel. ToNext");
      break;
      case 13:
      sprintf(header_banger_action,"Sel. Tog.Up/Down");
      break;
      case 14:
      sprintf(header_banger_action,"Sel. Dock -");
      break;
      case 15:
      sprintf(header_banger_action,"Sel. Dock +");
      break;
      case 16:
      sprintf(header_banger_action,"Sel. PlayChaser");
      break;
      case 17:
      sprintf(header_banger_action,"Minifader Preset");
      break;
      default:
      break;
      }
break;
case 9:
     sprintf(header_banger_typ,"iCat");
     switch(bangers_action[f][bg])
     {
      case 0:
      sprintf(header_banger_action,"Select Page Num");
      break;
      case 1:
      sprintf(header_banger_action,"Select Page -");
      break;
      case 2:
      sprintf(header_banger_action,"Select Page +");
      break;
      case 3:
      sprintf(header_banger_action,"Refresh Page");
      break;
      case 4:
      sprintf(header_banger_action,"Toggle Orientation");
      break;
      default:
      break;
      }
break;
case 10: //chrono
    sprintf(header_banger_typ,"Chrono");
     switch(bangers_action[f][bg])
     {
      case 0:
      sprintf(header_banger_action,"Clear Chrono");
      break;
      case 1:
      sprintf(header_banger_action,"Play Chrono");
      break;
      case 2:
      sprintf(header_banger_action,"Set Chrono Page");
      break;
      default:
      break;
      }
break;
case 11://set channel
    sprintf(header_banger_typ,"SetChannel");
     switch(bangers_action[f][bg])
     {
      case 0:
      sprintf(header_banger_action,"/100 Set At");
      break;
      case 1:
      sprintf(header_banger_action,"/100 Set +");
      break;
      case 2:
      sprintf(header_banger_action,"/100 Set -");
      break;
      case 3:
      sprintf(header_banger_action,"/255 Set At");
      break;
      case 4:
      sprintf(header_banger_action,"/255 Set +");
      break;
      case 5:
      sprintf(header_banger_action,"/255 Set -");
      break;
      case 6:
      sprintf(header_banger_action,"Macro ON");
      break;
      case 7:
      sprintf(header_banger_action,"Macro OFF");
      break;
           case 8:
      sprintf(header_banger_action,"FromTo Macro1 ON");
      break;
      case 9:
      sprintf(header_banger_action,"FromTo Macro2 ON");
      break;
      case 10:
      sprintf(header_banger_action,"FromTo Macro3 ON");
      break;
      case 11:
      sprintf(header_banger_action,"FromTo Macro4 ON");
      break;
      case 12:
      sprintf(header_banger_action,"FromTo Macro1 OFF");
      break;
      case 13:
      sprintf(header_banger_action,"FromTo Macro2 OFF");
      break;
      case 14:
      sprintf(header_banger_action,"FromTo Macro3 OFF");
      break;
      case 15:
      sprintf(header_banger_action,"FromTo Macro4 OFF");
      break;
      default:
      break;
      }
break;

case 12://set banger
     sprintf(header_banger_typ,"SetBanger");
     switch(bangers_action[f][bg])
     {
      case 0:
      sprintf(header_banger_action,"On/Off");
      break;
      case 1:
      sprintf(header_banger_action,"RollBack");
      break;
      case 2:
      sprintf(header_banger_action,"Loop ON");
      break;
      case 3:
      sprintf(header_banger_action,"Loop OFF");
      break;
      default:
      break;
      }

break;


case 13://midi mute
     sprintf(header_banger_typ,"MidiMute");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"[GLOBAL]");
     break;
     case 1:
     sprintf(header_banger_action,"GrandMaster");
     break;
     case 2:
     sprintf(header_banger_action,"Fader");
     break;
     case 3:
     sprintf(header_banger_action,"LFO");
     break;
     case 4:
     sprintf(header_banger_action,"Sequences");
     break;
     case 5:
     sprintf(header_banger_action,"Trichromy");
     break;
     case 6:
     sprintf(header_banger_action,"VideoTracking");
     break;
     case 7:
     sprintf(header_banger_action,"Audio Level");
     break;
     case 8:
     sprintf(header_banger_action,"Audio Pan");
     break;
     case 9:
     sprintf(header_banger_action,"Audio Pitch");
     break;

     default:
     break;
     }
case 14://Grid
sprintf(header_banger_typ,"GridPlayer");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"1-Load&Play");
     break;
     case 1:
     sprintf(header_banger_action,"2-Load&Play");
     break;
     case 2:
     sprintf(header_banger_action,"3-Load&Play");
     break;
     case 3:
     sprintf(header_banger_action,"4-Load&Play"); //grid step
     break;
     case 4:
     sprintf(header_banger_action,"1-Stop&Load");    //grid step
     break;
     case 5:
     sprintf(header_banger_action,"2-Stop&Load");
     break;
     case 6:
     sprintf(header_banger_action,"3-Stop&Load");
     break;
     case 7:
     sprintf(header_banger_action,"4-Stop&Load");
     break;
     case 8:
     sprintf(header_banger_action,"Play/Pause");   //Player ON/OFF
     break;
     case 9:
     sprintf(header_banger_action,"Seek");     //bang
     break;
     case 10:
     sprintf(header_banger_action,"Autostop");
     break;
     case 11:
     sprintf(header_banger_action,"Macro Goto");
     break;
     case 12:
     sprintf(header_banger_action,"Macro Seek");
     break;
     case 13:
     sprintf(header_banger_action,"Macro StopPlay");
     break;
     case 14:
     sprintf(header_banger_action,"Set Seek");     //player seek
     break;
     case 15:
     sprintf(header_banger_action,"Set Accel."); //player 0-127
     break;
     case 16:
     sprintf(header_banger_action,"Set Slave"); //player ON/OFF
     break;
     case 17:
     sprintf(header_banger_action,"SnapFader"); //player ON/OFF
     break;
     case 18:
     sprintf(header_banger_action,"Next Step"); //GPL STP
     break;
     case 19:
     sprintf(header_banger_action,"Previous Step"); //GPL Stp
     break;
     case 20:
     sprintf(header_banger_action,"Goto=SeekStep"); //Goto position take seek step reference
     break;
     case 21:
     sprintf(header_banger_action,"Def.as SeekSt."); //Actual step is define as seekstep
     break;
     case 22:
     sprintf(header_banger_action,"Clear SeekSteps!"); //clear all seek steps
     break;
     case 23:
     sprintf(header_banger_action,"Clear Grid in GPL !!!"); //clear all grid
     break;
     default:
     break;
     }
break;
case 15://Hardware
sprintf(header_banger_typ,"Hardware");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Arduino ON/Off");
     break;
     case 1:
     sprintf(header_banger_action,"Arduino Baudrate");
     break;
     case 2:
     sprintf(header_banger_action,"Analog input ON");
     break;
     default:
     break;
     }
break;
case 16://emulate KBD
sprintf(header_banger_typ,"Emulate Kbd");
 switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Kbd A");
     break;
     case 1:
     sprintf(header_banger_action,"Kbd B");
     break;
     case 2:
     sprintf(header_banger_action,"Kbd C");
     break;
     case 3:
     sprintf(header_banger_action,"Kbd D");
     break;
      case 4:
     sprintf(header_banger_action,"Kbd E");
     break;
      case 5:
     sprintf(header_banger_action,"Kbd F");
     break;
      case 6:
     sprintf(header_banger_action,"Kbd G");
     break;
      case 7:
     sprintf(header_banger_action,"Kbd H");
     break;
      case 8:
     sprintf(header_banger_action,"Kbd I");
     break;
      case 9:
     sprintf(header_banger_action,"Kbd J");
     break;
      case 10:
     sprintf(header_banger_action,"Kbd K");
     break;
      case 11:
     sprintf(header_banger_action,"Kbd L");
     break;
      case 12:
     sprintf(header_banger_action,"Kbd M");
     break;
      case 13:
     sprintf(header_banger_action,"Kbd N");
     break;
      case 14:
     sprintf(header_banger_action,"Kbd O");
     break;
      case 15:
     sprintf(header_banger_action,"Kbd P");
     break;
      case 16:
     sprintf(header_banger_action,"Kbd Q");
     break;
      case 17:
     sprintf(header_banger_action,"Kbd R");
     break;
      case 18:
     sprintf(header_banger_action,"Kbd S");
     break;
      case 19:
     sprintf(header_banger_action,"Kbd T");
     break;
      case 20:
     sprintf(header_banger_action,"Kbd U");
     break;
      case 21:
     sprintf(header_banger_action,"Kbd V");
     break;
      case 22:
     sprintf(header_banger_action,"Kbd W");
     break;
      case 23:
     sprintf(header_banger_action,"Kbd X");
     break;
      case 24:
     sprintf(header_banger_action,"Kbd Y");
     break;
      case 25:
     sprintf(header_banger_action,"Kbd Z");
     break;

     case 26:
     sprintf(header_banger_action,"Kbd SPACE");
     break;

     case 27:
     sprintf(header_banger_action,"Kbd DOT");
     break;

      case 28:
     sprintf(header_banger_action,"Kbd 0");
     break;
      case 29:
     sprintf(header_banger_action,"Kbd 1");
     break;
      case 30:
     sprintf(header_banger_action,"Kbd 2");
     break;
      case 31:
     sprintf(header_banger_action,"Kbd 3");
     break;
      case 32:
     sprintf(header_banger_action,"Kbd 4");
     break;
      case 33:
     sprintf(header_banger_action,"Kbd 5");
     break;
      case 34:
     sprintf(header_banger_action,"Kbd 6");
     break;
      case 35:
     sprintf(header_banger_action,"Kbd 7");
     break;
      case 36:
     sprintf(header_banger_action,"Kbd 8");
     break;
      case 37:
     sprintf(header_banger_action,"Kbd 9");
     break;

      case 38:
     sprintf(header_banger_action,"Kbd SHIFT");
     break;
      case 39:
     sprintf(header_banger_action,"Kbd CTRL");
     break;
      case 40:
     sprintf(header_banger_action,"Kbd ESC");
     break;
      case 41:
     sprintf(header_banger_action,"Kbd F1");
     break;
      case 42:
     sprintf(header_banger_action,"Kbd F2");
     break;
      case 43:
     sprintf(header_banger_action,"Kbd F3");
     break;
      case 44:
     sprintf(header_banger_action,"Kbd F4");
     break;
     case 45:
     sprintf(header_banger_action,"Kbd F5");
     break;
     case 46:
     sprintf(header_banger_action,"Kbd F6");
     break;
     case 47:
     sprintf(header_banger_action,"Kbd F7");
     break;
     case 48:
     sprintf(header_banger_action,"Kbd F8");
     break;
     case 49:
     sprintf(header_banger_action,"Kbd F9");
     break;
     case 50:
     sprintf(header_banger_action,"Kbd F10");
     break;
     case 51:
     sprintf(header_banger_action,"Kbd F11");
     break;
     case 52:
     sprintf(header_banger_action,"Kbd F12");
     break;
     case 53:
     sprintf(header_banger_action,"Kbd ENTER");
     break;
     case 54:
     sprintf(header_banger_action,"Kbd Bcksp");
     break;
     case 55:
     sprintf(header_banger_action,"Kbd Tab");
     break;
     case 56:
     sprintf(header_banger_action,"Kbd PLUS");
     break;
     case 57:
     sprintf(header_banger_action,"Kbd MINUS");
     break;
     case 58:
     sprintf(header_banger_action,"Kbd Arrow LEFT");
     break;
     case 59:
     sprintf(header_banger_action,"Kbd Arrow RIGHT");
     break;
     case 60:
     sprintf(header_banger_action,"Kbd Arrow UP");
     break;
     case 61:
     sprintf(header_banger_action,"Kbd Arrow DOWN");
     break;
     case 62:
     sprintf(header_banger_action,"Kbd Arrow DEL");
     break;
     default:
     break;
     }
break;
case 17:
sprintf(header_banger_typ,"Draw");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Select Matrix");
     break;
     case 1:
     sprintf(header_banger_action,"Set Brush");
     break;
     case 2:
     sprintf(header_banger_action,"Set DrawMode");
     break;
     case 3:
     sprintf(header_banger_action,"Set Pressure");
     break;
     case 4:
     sprintf(header_banger_action,"Set Damper");
     break;
     case 5:
     sprintf(header_banger_action,"Set Ghost");
     break;
     case 6:
     sprintf(header_banger_action,"Set GPL");
     break;
     case 7:
     sprintf(header_banger_action,"Set Offset");
     break;
     case 8:
     sprintf(header_banger_action,"Clear Drawing");
     break;
     case 9:
     sprintf(header_banger_action,"Snap Fader");
     break;
     case 10:
     sprintf(header_banger_action,"Snap GridPl.");
     break;
     default:
     sprintf(header_banger_action,"-");
     break;
     }
break;
case 18:
sprintf(header_banger_typ,"Echo");
     switch(bangers_action[f][bg])
     {
     case 0:
     sprintf(header_banger_action,"Select Echo");
     break;
     case 1:
     sprintf(header_banger_action,"S.Set Fader");
     break;
     case 2:
     sprintf(header_banger_action,"S.ChanMode ");
     break;
     case 3:
     sprintf(header_banger_action,"S.SetChan /255");
     break;
     case 4:
     sprintf(header_banger_action,"S.SetChan /100");
     break;
     case 5:
     sprintf(header_banger_action,"S.Echo Mode");
     break;
     case 6:
     sprintf(header_banger_action,"S.SnapFader");
     break;
     case 7:
     sprintf(header_banger_action,"S.Bounce !");
     break;
     case 8:
     sprintf(header_banger_action,"S. S-K-B !");
     break;
     case 9:
     sprintf(header_banger_action,"S.BackFader");
     break;
     case 10:
     sprintf(header_banger_action,"S.SetGravity");
     break;
     case 11:
     sprintf(header_banger_action,"S.SetMass");
     break;
     case 12:
     sprintf(header_banger_action,"S.SetEnergy");
     break;
     case 13:
     sprintf(header_banger_action,"S.SetChanPos");
     break;
     case 14:
     sprintf(header_banger_action,"E.EchoMode");
     break;
     case 15:
     sprintf(header_banger_action,"E.SetFader");
     break;
     case 16:
     sprintf(header_banger_action,"E.SnapFader");
     break;
     case 17:
     sprintf(header_banger_action,"E.Bounce !");
     break;
     case 18:
     sprintf(header_banger_action,"E. S-K-B !");
     break;
     case 19:
     sprintf(header_banger_action,"E.BackFader");
     break;
     case 20:
     sprintf(header_banger_action,"E.ChanMode");
     break;
     case 21:
     sprintf(header_banger_action,"E.SetGravity");
     break;
     case 22:
     sprintf(header_banger_action,"E.SetMass");
     break;
     case 23:
     sprintf(header_banger_action,"E.SetEnergy");
     break;
     case 24:
     sprintf(header_banger_action,"E.SetChanPos");
     break;
     case 25:
     sprintf(header_banger_action,"E.ClearEcho");
     break;
     default:
     sprintf(header_banger_action,"-");
     break;
     }
break;


default:
break;
}
if(bangers_type[f][bg]!=0)//si il y a un type d evenement dedans
{
sprintf(header_export,"Event %d : %s",bg+1,header_banger_typ);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
draw_info(page, 220, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_banger_action);
sprintf(header_export,"Val 1: %d",bangers_params[f][bg][0]);
draw_info(page, 320, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
sprintf(header_export,"Val 2: %d",bangers_params[f][bg][1]);
draw_info(page, 400, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
sprintf(header_export,"delay: %.1f",bangers_delay[f][bg]);
draw_info(page, 500, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
}
verification_fin_de_page();
}
}
there_is_someone_in_banger=0;//pour check des autres bangers
strcpy(header_export,"");
strcpy(header_banger_action,"");
strcpy(header_banger_typ,"");
}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[6]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Audio folder", 0.0, 0.0,1.0);


sprintf(header_export,"Content of /audio/%s",audio_folder);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for(int u=1;u<127;u++)
{
if(strcmp(list_audio_files[u],"")!=0)
{
 sprintf(header_export,"-%d : %s",u,list_audio_files[u]);


 if(audiofile_cue_in_out_pos[u][0]!=0 || audiofile_cue_in_out_pos[u][1]!=0)
 {
 sprintf(little_header,"  |  CueIn: %.1f CueOut: %.1f",(((float)audiofile_cue_in_out_pos[u][0])/44100),(((float)audiofile_cue_in_out_pos[u][1])/44100));
 strcat(header_export,little_header);
 }
 draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
 cmptline_pdf++;
verification_fin_de_page();
}
}

cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[7]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Faders", 1.0,0.6,0.0);

bool there_is_someone_in_fader=0;
for(int f=0;f<48;f++)
{
there_is_someone_in_fader=0;
for(int d=0;d<6;d++)
{
if(DockTypeIs[f][d]!=9)
{there_is_someone_in_fader=1;break;}
}
if(there_is_someone_in_fader==1)
{
sprintf(header_export,"FADER %d ",f+1);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");//clean
sprintf(header_export,"Curve [%d] ",FaderCurves[f]+1);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"LFO: Speed: %d  Mode: ",lfo_speed[f]);

int dc= 127*Fader_dampered[f].getdecay();
int ddt=127*Fader_dampered[f].getdt();
int md=Fader_dampered[f].getdampermode();
switch(fader_damper_is_on[f])
{
case 0:
sprintf(header_export,"Damper OFF/ D:%d D:%d Mode:%d",  dc,ddt,md);
break;
case 1:
sprintf(header_export,"Damper ON/ D:%d D:%d Mode:%d",  dc,ddt,md);
break;
default: break;
}
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

if(lfo_mode_is[f]!=0)
{
switch(lfo_mode_is[f])
{
case 1:
strcat(header_export," up ");
break;
case 2:
strcat(header_export," down ");
break;
default: break;
}
}
else if(lfo_cycle_is_on[f]==1)
{
strcat(header_export," saw ");
}
else
{
strcat(header_export," - ");
}
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Cycling docks : ");
if(lfo_do_next_step[f][0]==1)
{
strcat(header_export," to Previous dock");
}
else if(lfo_do_next_step[f][1]==1)
{
strcat(header_export," to Next dock");
}
if(lfo_cycle_steps[f]==1)
{
strcat(header_export," | Cycling Previous-Next");
}
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
if(LevelStopPos[f]!=0)
{
sprintf(header_export,"Stop position:  %d  ",(int)(((float)LevelStopPos[f])/2.55));
switch(ActionnateStopOn[f])
{
case 1:
strcat(header_export,"is ON");
break;
default: break;
}
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

}


if(autolaunch[f]==1)
{
 sprintf(header_export,"Autolaunch ON  ");
 draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
 cmptline_pdf++;
}



for(int piu=0;piu<6;piu++)
{
if(DockIsSelected[f][piu]==1)
{
sprintf(header_export,"Dock selected: %d",piu+1);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
break;
}
}
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");//clean
cmptline_pdf++;
for(int d=0;d<6;d++)
{
if(DockTypeIs[f][d]!=9)//dock pas vide
{

comptch=0;
sprintf(header_export,"Dock %d: ", d+1);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
sprintf(header_export,"- %s",DockName[f][d]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"dIn:%.1f  IN: %.1f  | dOUT:%.1f  OUT: %.1f", time_per_dock[f][d][0],time_per_dock[f][d][1],time_per_dock[f][d][2],time_per_dock[f][d][3]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
if(is_dock_for_lfo_selected[f][d]==1)
{
strcpy(header_export,"Dock Loop ON");
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
}
strcpy(header_export,"");//clean
cmptline_pdf++;

switch(DockTypeIs[f][d])
{
case 0://channels
for(int c=1;c<513;c++)
{
if(FaderDockContains[f][d][c]>0)
{
if(comptch==0)
{
cmptline_pdf++;
strcpy(header_export,"");
}//retour ligne après 10 circuits

sprintf(little_header,"%d=%d   ",c,(int)((float)(FaderDockContains[f][d][c])/2.55));
strcat(header_export,little_header);
comptch++;
if(comptch>10)
{
comptch=0;
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
verification_fin_de_page();
}
}
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
break;

case 1://trichro
for (int fo=0;fo<8;fo++)
{
if(colorpreset_linked_to_dock[fo][0]==f)
{
if(colorpreset_linked_to_dock[fo][1]==d)
{
sprintf(header_export,"Trichromy preset %d \n",fo+1);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
}
}
}
break;

case 2://art net
strcpy(header_export,"");//clean
sprintf(header_export,"Art-Net Sub 0, Universe %d ",DockNetIs[f][d]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 3://dmx in
strcpy(header_export,"");//clean
cmptline_pdf++;
strcpy(header_export,"Dmx-IN ");
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 4://video
strcpy(header_export,"");//clean
cmptline_pdf++;
strcpy(header_export,"Video-tracking ");
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;


case 5://mems
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Memory: %d.%d ",DockHasMem[f][d]/10,DockHasMem[f][d]%10);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

strcpy(header_export,"");//clean
break;

case 6://audio volume
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Audio Volume Player %d  ",DockHasAudioVolume[f][d]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

strcpy(header_export,"");//clean
break;

case 7://audio pan
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Audio Pan Player %d  ",DockHasAudioPan[f][d]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 8://audio pitch
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Audio Pitch Player %d  ",DockHasAudioPitch[f][d]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

strcpy(header_export,"");//clean
break;
 break;*/

case 10://direct chan
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Direct Channel : %d",FaderDirectChan[f][d]);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 11://fx
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Chaser : %d",ChaserAffectedToDck[f][d]+1);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 12://grid
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"GridPlayer : %d",faders_dock_grid_affectation[f][d]+1);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 13://fgroup
strcpy(header_export,"");//clean
cmptline_pdf++;
strcpy(header_export,"Fgroup containing faders:");
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
for(int ifo=0;ifo<48;ifo++)
{
if(fgroup[f][d][ifo]==1){strcat(header_export," %d -");}
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
break;

case 14://mover
strcpy(header_export,"");//clean
cmptline_pdf++;
strcpy(header_export,"Mover");
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;

case 15: //Draw
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Draw %d",(DrawAffectedToDck[f][d]+1));
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;
case 16: //echo
strcpy(header_export,"");//clean
cmptline_pdf++;
sprintf(header_export,"Echo %d",(echo_affected_to_dock[f][d]+1));
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
strcpy(header_export,"");//clean
break;
default:
break;
} //fin du switch case dock
cmptline_pdf++; //separateur de dock
}
}
}
}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[8]==1)
{
sprintf(header_export,"page %d", num_page_pdf);
draw_numpage(page,width/2,20,header_export);
page=HPDF_AddPage(pdf);cmptline_pdf=0;
num_page_pdf++;
draw_section (page, 100,debut_lignes -70 , "Chasers",0.0,0.5,0.0);

bool there_is_someone_in_chaser=0;
for(int i=0;i<128;i++)
{
there_is_someone_in_chaser=0;
for(int tr=0;tr<24;tr++)
{
for(int c=1;c<513;c++)
{
 if(TrackContains[i][tr][c]!=0){there_is_someone_in_chaser=1; break;}
}
}
if(there_is_someone_in_chaser==1)
{
sprintf(header_export,"page %d", num_page_pdf);
draw_numpage(page,width/2,20,header_export);
page=HPDF_AddPage(pdf);cmptline_pdf=0;
num_page_pdf++;
draw_pdf_chaser(i, page);
}
}

sprintf(header_export,"page %d", num_page_pdf);
draw_numpage(page,width/2,20,header_export);
page=HPDF_AddPage(pdf);cmptline_pdf=0;
num_page_pdf++;
HPDF_Page_SetRGBStroke (page, 0.0, 0.5, 0.5);//couleur ligne
HPDF_Page_BeginText (page);
HPDF_Page_SetFontAndSize (page, def_font, 10);
HPDF_Page_EndText (page);
strcpy(header_export,"");

}


if(specify_who_to_save_PDF[9]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Trichromy",0.5,0.6,0.0);

bool there_is_someone_in_color_preset=0;
for (int t=0;t<8;t++)
{
there_is_someone_in_color_preset=0;
for(int col=0;col<4;col++)
{
for(int circ=1;circ<513;circ++)
{
if(dock_color_channels[t][col][circ]!=0)
{
there_is_someone_in_color_preset=1;break;
}
}
}
if(there_is_someone_in_color_preset==1)
{
switch(dock_color_type[t])
{
case 0:
sprintf(header_export,"Color Preset %d in Trichromy Mode",t+1);
break;
case 1:
sprintf(header_export,"Color Preset %d in Quadrichromy Mode",t+1);
break;
default: break;
}
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
switch(dock_color_type[t])
{
case 0:
sprintf(header_export,"Actual Color is: R=%d G=%d B=%d",picker_trichro[t][0],picker_trichro[t][1],picker_trichro[t][2]);
break;
case 1:
sprintf(header_export,"Actual Color is: R=%d G=%d B=%d Y=%d",picker_trichro[t][0],picker_trichro[t][1],picker_trichro[t][2],picker_trichro[t][3]);
break;
default: break;
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

for(int col=0;col<4;col++)
{
comptch=0;

switch (col)
{
case 0:
sprintf(header_export,"RED: ");
break;
case 1:
sprintf(header_export,"GREEN: ");
break;
case 2:
sprintf(header_export,"BLUE: ");
break;
case 3:
sprintf(header_export,"YELLOW: ");
break;
default: break;
}

for(int circ=1;circ<513;circ++)
{
if(dock_color_channels[t][col][circ]!=0)
{
sprintf(little_header,"%d   - ",circ);
strcat(header_export,little_header);
comptch++;
if(comptch>12)
{
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
comptch=0;
strcpy(little_header,"");
strcpy(header_export,"");
}
}
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
}
}
cmptline_pdf++;
verification_fin_de_page();

}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[10]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "Tracking Video",0.6,0.6,0.0);

sprintf(header_export,"Settings:");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Camera Video Size: %d x %d      - FPS: %d",video_size_x,video_size_y,fps_video_rate);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Image mode:");
if (flip_image==1) {strcat(header_export,"Flip ON / ");} else  {strcat(header_export,"Flip OFF / ");}
if (threshold_on==1) {sprintf(little_header,"Threshold ON : %d / ",threshold_level);} else  {sprintf(little_header,"Threshold OFF / ");}
strcat(header_export,little_header);
if (erode_mode==1) {sprintf(little_header,"Erode ON : %d / ",erode_level);} else  {sprintf(little_header,"Erode OFF / ");}
strcat(header_export,little_header);
if (blur_on==1) {strcat(header_export,"Blur ON / ");} else  {strcat(header_export,"Blur OFF / ");}
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

sprintf(header_export,"Background suppression: ");
if(ocv_calcul_mode==0){sprintf(little_header,"SNAP ON , div factor: %d ",div_facteur);}
else {sprintf(little_header,"SNAP OFF ( normal threshold capture)");}
strcat(header_export,little_header);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Decay position: %d",index_decay_tracker);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

cmptline_pdf++;
verification_fin_de_page();
bool there_is_a_roi_preset_affected=0;


bool test_there_is_a_channel=0;

for(int trk=0;trk<6;trk++)
{
sprintf(header_export,"Video Preset %d:",trk);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
for (int pr=0;pr<12;pr++)
{
there_is_a_roi_preset_affected=0;
for (int prp=0;prp<12;prp++)
{
for(int circ=1;circ<512;circ++)
{
if(tracking_contents[trk][prp][circ]!=0)
{
 there_is_a_roi_preset_affected=1; break;
}
}
}

if(there_is_a_roi_preset_affected==1)
{
test_there_is_a_channel=0;
sprintf(header_export,"Roi %d :  X: %d Y: %d  - Size X: %d Size Y: %d ",pr+1,tracking_coordonates[trk][pr][0],tracking_coordonates[trk][pr][1],tracking_coordonates[trk][pr][2],tracking_coordonates[trk][pr][3]);
draw_info(page, 120, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
sprintf(header_export,"Chan: ");
cmptline_pdf++;
cmptline_pdf++;
for(int circ=1;circ<512;circ++)
{
if(tracking_contents[trk][pr][circ]!=0)
{
test_there_is_a_channel=1;
sprintf(little_header,"%d   - ",circ);
strcat(header_export,little_header);
comptch++;
if(comptch>12)
{
draw_info(page, 120, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
comptch=0;
strcpy(little_header,"");
strcpy(header_export,"");
}
}
}
if(test_there_is_a_channel==1)
{
draw_info(page, 120, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
cmptline_pdf++;
}

verification_fin_de_page();
}
}
}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[11]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "GRIDPLAYERS",0.2,0.9,0.0);


draw_pdf_grid_players_config();
verification_fin_de_page();
}
if(specify_who_to_save_PDF[12]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "MOVER",0.6,0.0,0.6);
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}
if(specify_who_to_save_PDF[13]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "ECHO",0.0,0.4,0.9);
draw_pdf_echo_config();
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();
}

if(specify_who_to_save_PDF[14]==1)
{
saut_de_page();
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "DRAW",0.0,0.9,0.8);
cmptline_pdf++;
cmptline_pdf++;
draw_pdf_draw_config();
verification_fin_de_page();
}




if(specify_who_to_save_PDF[21]==1)
{
draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "ARDUINO",0.0,0.8,0.8);


sprintf(header_export,"Settings:");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Device on COM: %d - BaudRate: %d - Request Rate: %d",arduino_com0,arduino_baud_rate0,ARDUINO_RATE);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Parameters: ");
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Last I/O: %d Last ANALOG: %d",arduino_max_digital,arduino_max_analog);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
cmptline_pdf++;

sprintf(header_export,"I/O affectation:");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;


for(int i=2;i<=arduino_max_digital;i++)
{
switch(arduino_digital_type[i])
{
case 0://desafected
sprintf(header_export,"%d: -",i);
break;
case 1://input
sprintf(header_export,"%d: Input",i);
break;
case 2://PUL UP
sprintf(header_export,"%d:Pull Up",i);
break;
case 3://output
sprintf(header_export,"%d:Output",i);
break;
case 4://pwm
sprintf(header_export,"%d:PWM",i);
break;
case 5://servo
sprintf(header_export,"%d:SERVO",i);
break;
case 6://HF out
sprintf(header_export,"%d:HF OUT",i);
break;
case 7://HF in
sprintf(header_export,"%d:HF IN",i);
break;
default:
break;
}

if(arduino_digital_type[i]==1)//si de la famille des inputs
{
switch(arduino_digital_function_input[i][0])
{
case 0://desafected
strcat(header_export,"-");
break;
case 1: //fader up
sprintf(little_header,"Fader %d UP", arduino_digital_function_input[i][1]);
break;
case 2://fader down
sprintf(little_header,"Fader: %d DOWN", arduino_digital_function_input[i][1]);
break;
case 3://Fader saw
sprintf(little_header,"Fader: %d SAW", arduino_digital_function_input[i][1]);
break;
case 4:
sprintf(little_header,"Fader: %d ToPREVDock", arduino_digital_function_input[i][1]);
break;
case 5:
sprintf(little_header,"Fader: %d ToNEXTDock", arduino_digital_function_input[i][1]);
break;
case 6:
sprintf(little_header,"Fader: %d Up/Down", arduino_digital_function_input[i][1]);
break;
case 7:
sprintf(little_header,"Fader: %d LOCK", arduino_digital_function_input[i][1]);
break;
case 8:
sprintf(little_header,"Fader: %d FLASH", arduino_digital_function_input[i][1]);
break;
case 9:
sprintf(little_header,"Fader: %d All at 0", arduino_digital_function_input[i][1]);
break;
case 10:
sprintf(little_header,"Fader: %d L/Unloop dock", arduino_digital_function_input[i][1]);
break;
case 11:
sprintf(little_header,"Fader: %d L/Unloop all", arduino_digital_function_input[i][1]);
break;
case 12:
sprintf(little_header,"Seq: GO");
break;
case 13:
sprintf(little_header,"Seq: GO BACK");
break;
case 14:
sprintf(little_header,"Seq: JUMP");
break;
case 15:
sprintf(little_header,"Seq: SHIFT-W");
break;
case 16:
sprintf(little_header,"Seq: SHIFT-X");
break;
case 17:
sprintf(little_header,"As Key-On CH0 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 18:
sprintf(little_header,"As Key-On CH1 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 19:
sprintf(little_header,"As Key-On CH2 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 20:
sprintf(little_header,"As Key-On CH3 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 21:
sprintf(little_header,"As Key-On CH4 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 22:
sprintf(little_header,"As Key-On CH5 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 23:
sprintf(little_header,"As Key-On CH6 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 24:
sprintf(little_header,"As Key-On CH7 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 25:
sprintf(little_header,"As Key-On CH8 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 26:
sprintf(little_header,"As Key-On CH9 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 27:
sprintf(little_header,"As Key-On CH10 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 28:
sprintf(little_header,"As Key-On CH11 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 29:
sprintf(little_header,"As Key-On CH12 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 30:
sprintf(little_header,"As Key-On CH13 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 31:
sprintf(little_header,"As Key-On CH14 Pitch %d", arduino_digital_function_input[i][1]);
break;
case 32:
sprintf(little_header,"As Key-On CH15 Pitch %d", arduino_digital_function_input[i][1]);
break;
default:
break;
}
strcat(header_export,little_header);
}


if(arduino_digital_type[i]==2)//si de la famille des Outputs
{
switch(arduino_digital_function_output[i][0])
{
case 0://desafected
sprintf(little_header,"-");
break;
case 1: //relié à un circuit
sprintf(little_header,"Channel %d >10", arduino_digital_function_output[i][1]);
break;
case 2://relié à un fader
sprintf(little_header,"Fader %d >10", arduino_digital_function_output[i][1]);
break;
default: break;
}
strcat(header_export,little_header);
}

if(arduino_digital_type[i]==3)//si de la famille pwm
{
switch(arduino_digital_function_output[i][0])
{
case 0://desafected
sprintf(little_header,"-");
break;
case 1: //relié à un circuit
sprintf(little_header,"Channel %d >10", arduino_digital_function_output[i][1]);
break;
case 2://relié à un fader
sprintf(little_header,"Fader %d >10", arduino_digital_function_output[i][1]);
break;
default: break;
}
strcat(header_export,little_header);
}


draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

verification_fin_de_page();
}

cmptline_pdf++;

sprintf(header_export,"Analog affectation:");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();


for(int i=0;i<=arduino_max_analog;i++)
{
strcpy(header_export,"");
switch(arduino_analog_function_input[i])
{
case 0://desafected
sprintf(little_header,"-");
break;
case 1: //faders  lvl
sprintf(little_header,"Fader %d Level",arduino_analog_attribution_input[i]+1);
break;
case 2://faders speeed
sprintf(little_header,"Fader %d Speed",arduino_analog_attribution_input[i]+1);
break;
case 3://master
sprintf(little_header,"Grand Master");
break;
case 4://seq scene et preset et vitesse
sprintf(little_header,"Sequence: %d",arduino_analog_attribution_input[i]+1);
break;
case 5://relié à Draw
sprintf(little_header,"Draw X1");
break;
case 6://relié à Draw
sprintf(little_header,"Draw X2");
break;
case 7://relié à Draw
sprintf(little_header,"Draw Y1");
break;
case 8://relié à Draw
sprintf(little_header,"Draw Y2");
break;
case 9://Midi CH0
sprintf(little_header,"As CC CH0 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 10://Midi CH1
sprintf(little_header,"As CC CH1 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 11://Midi CH2
sprintf(little_header,"As CC CH2 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 12://Midi CH3
sprintf(little_header,"As CC CH3 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 13://Midi CH4
sprintf(little_header,"As CC CH4 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 14://Midi CH5
sprintf(little_header,"As CC CH5 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 15://Midi CH6
sprintf(little_header,"As CC CH6 Picth %d",arduino_analog_attribution_input[i]);
break;
case 16://Midi CH7
sprintf(little_header,"As CC CH7 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 17://Midi CH8
sprintf(little_header,"As CC CH8 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 18://Midi CH9
sprintf(little_header,"As CC CH9 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 19://Midi CH10
sprintf(little_header,"As CC CH10 Picth %d",arduino_analog_attribution_input[i]);
break;
case 20://Midi CH11
sprintf(little_header,"As CC CH11 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 21://Midi CH12
sprintf(little_header,"As CC CH12 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 22://Midi CH13
sprintf(little_header,"As CC CH13 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 23://Midi CH14
sprintf(little_header,"As CC CH14 Pitch %d",arduino_analog_attribution_input[i]);
break;
case 24://Midi CH15
sprintf(little_header,"As CC CH15 Pitch %d",arduino_analog_attribution_input[i]);
break;
default:
break;
}

strcat(header_export,little_header);
draw_info(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

verification_fin_de_page();
}
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
}

if(specify_who_to_save_PDF[22]==1)
{
generate_list_midi_for_pdf();


draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "MIDI AFFECTATIONS",1.0,0.0,0.0);

sprintf(header_export,"GRAND MASTER");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

print_midi_command(615);

sprintf(header_export,"MOVE FADER SPACE");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

print_midi_command(767);
print_midi_command(1627);

for(int i=0;i<48;i++)
{
sprintf(header_export,"FADER %d",i+1);
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
print_midi_command(i);
print_midi_command(i+48);
print_midi_command(i+97);
print_midi_command(i+146);
print_midi_command(i+196);
print_midi_command(i+245);
print_midi_command(i+294);
print_midi_command(i+343);
print_midi_command(i+392);
print_midi_command(i+441);
print_midi_command(i+499);
print_midi_command(i+556);
print_midi_command(i+685);
print_midi_command(i+802);
print_midi_command(i+851);
print_midi_command(i+900);
print_midi_command(i+1115);
print_midi_command(i+1164);
print_midi_command(i+1213);
print_midi_command(i+1278);
print_midi_command(i+1543);
print_midi_command(i+1912);
print_midi_command(i+1960);
print_midi_command(i+2008);
print_midi_command(i+2056);

}

sprintf(header_export,"MINIFADERS");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
print_midi_command(145);
for(int i=0;i<28;i++)
{
if(i+774!=793)
{
print_midi_command(i+774);
}
}
verification_fin_de_page();
sprintf(header_export,"CUELIST");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
for(int i=0;i<6;i++)
{
print_midi_command(i+491);
}
for(int i=0;i<6;i++)
{
print_midi_command(i+768);
}
print_midi_command(1591);
print_midi_command(1645);

verification_fin_de_page();

sprintf(header_export,"ALL AT ZERO");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
for(int i=0;i<8;i++)
{
print_midi_command(i+548);
}
verification_fin_de_page();


sprintf(header_export,"LOCK PRESETS");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
for(int i=0;i<8;i++)
{
print_midi_command(i+605);
}
verification_fin_de_page();

sprintf(header_export,"AUDIO PLAYERS");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for(int i=0;i<48;i++)
{
print_midi_command(i+616);
}
for(int i=0;i<4;i++)
{
 print_midi_command(i+1800);
}
for(int i=0;i<4;i++)
{
 print_midi_command(i+1805);
}
for(int i=0;i<4;i++)
{
 print_midi_command(i+1809);
}
for(int i=0;i<4;i++)
{
 print_midi_command(i+1813);
}
for(int i=0;i<4;i++)
{
 print_midi_command(i+1817);
}
for(int i=0;i<4;i++)
{
 print_midi_command(i+1821);
}
verification_fin_de_page();

sprintf(header_export,"NUMPAD");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for(int i=0;i<21;i++)
{
print_midi_command(i+491);
}

print_midi_command(1825);
print_midi_command(1826);
print_midi_command(1827);
print_midi_command(1828);
verification_fin_de_page();

sprintf(header_export,"BANGER WINDOW");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for(int i=0;i<9;i++)
{
print_midi_command(i+734);
}

verification_fin_de_page();

sprintf(header_export,"BANGERS SOLOS");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for (int l=0;l<127;l++)
{
print_midi_command(l+1343);
}

verification_fin_de_page();

sprintf(header_export,"FUNCTIONS");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for(int i=0;i<6;i++)
{
print_midi_command(i+743);

}

for(int i=0;i<11;i++)
{print_midi_command(i+747);}

for(int i=0;i<14;i++)
{
print_midi_command(i+1329);
}

print_midi_command(757);
print_midi_command(1625);//send midi out faders
print_midi_command(1592);//fgroup
print_midi_command(1593);//hipass
print_midi_command(1626);//menus
print_midi_command(1277);//midi mute
print_midi_command(1594);//PLOT
print_midi_command(1659);//DRAW
print_midi_command(1662);//ECHO
print_midi_command(1829);//Bazookat
print_midi_command(1541);//exclude
print_midi_command(1542);//hipass
verification_fin_de_page();

sprintf(header_export,"MIDICLOCK");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

print_midi_command(1894);//Midi clock level
for(int i=0;i<16;i++)
{
print_midi_command(i+1895);
}
verification_fin_de_page();


sprintf(header_export,"TIME");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
for(int i=0;i<9;i++)
{
print_midi_command(i+758);
}
verification_fin_de_page();

sprintf(header_export,"TRICHROMY");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
print_midi_command(497);

for(int i=0;i<8;i++)
{
print_midi_command(i+949);
}
verification_fin_de_page();

sprintf(header_export,"TRACKING VIDEO");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
print_midi_command(498);
for(int i=0;i<17;i++)
{
print_midi_command(i+957);
}

sprintf(header_export,"CHASERS WINDOW");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
for (int yu=0;yu<141;yu++)
{
print_midi_command(yu+974);
}
verification_fin_de_page();

cmptline_pdf++;
sprintf(header_export,"ARDUINO ANALOG IN : ");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
for (int yu=0;yu<63;yu++)
{
print_midi_command(yu+1830);
}
verification_fin_de_page();

verification_fin_de_page();

sprintf(header_export,"Fantastick-iCat");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);


for (int yu=0;yu<12;yu++)
{
print_midi_command(yu+1265);
}
verification_fin_de_page();

sprintf(header_export,"DRAW WINDOW");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for (int yu=0;yu<14;yu++)
{
print_midi_command(yu+1646);
}
print_midi_command(1660);
print_midi_command(1661);
verification_fin_de_page();

sprintf(header_export,"ECHO WINDOW");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

for (int yu=0;yu<35;yu++)
{
print_midi_command(yu+1663);
}

cmptline_pdf++;
cmptline_pdf++;
cmptline_pdf++;
verification_fin_de_page();


}


if(specify_who_to_save_PDF[23]==1)
{
if(cmptline_pdf>20){saut_de_page();}//pour fenetre de tracage

draw_section (page, 100,debut_lignes -(position_ligne1 +(cmptline_pdf*12)), "FantaStick-iCat Interface Builder",0.0,0.6,0.8);
cmptline_pdf++;
cmptline_pdf++;

verification_fin_de_page();

sprintf(header_export,"iCAT-Fantastick parameters:");
draw_title(page, 50, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);

sprintf(header_export,"WhiteCat use adapter: %s", IP_fantastick);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"iOS device network adress is: %s", specified_fs_ip);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"UDP PORTS: Server (IN) : %d Client (OUT): %d",  serveurport_iCat, clientport_iCat);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Data sending iteration: %d",  nbre_d_envois_de_l_info);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
switch(surface_type)
{
case 0:
sprintf(header_export,"Working space: iPhone");
break;
case 1:
sprintf(header_export,"Working space: iPad");
break;
default:
break;
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;

for(int pr=0;pr<8;pr++)
{
draw_pdf_icat_preset(pr);
}



}




 // derniere page, marquage
sprintf(header_export,"page %d", num_page_pdf);
HPDF_Page_SetFontAndSize (page, def_font, 10);
draw_numpage(page,width/2,20,header_export);

HPDF_SaveToFile (pdf, fname);

/* clean up */
HPDF_Free (pdf);





sprintf(rep,"%s\\",mondirectory);
chdir (rep);
index_is_saving=0;
return(0);
}
