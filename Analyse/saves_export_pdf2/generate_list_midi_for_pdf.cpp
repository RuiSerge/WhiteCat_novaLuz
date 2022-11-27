int generate_list_midi_for_pdf()
{

sprintf(list_midi_affect[615],"Grand Master level");

sprintf(list_midi_affect[767],"Move Fader space");
for(int i=0;i<48;i++)
{
sprintf(list_midi_affect[i],"Level");
sprintf(list_midi_affect[i+48],"Dock -");
sprintf(list_midi_affect[i+96],"Dock +");
sprintf(list_midi_affect[i+146],"Lock");
sprintf(list_midi_affect[i+196],"Lfo speed");
sprintf(list_midi_affect[i+245],"Up");
sprintf(list_midi_affect[i+294],"Down");
sprintf(list_midi_affect[i+343],"Saw");
sprintf(list_midi_affect[i+392],"Cycle Dock -");
sprintf(list_midi_affect[i+441],"CycleDock +");
sprintf(list_midi_affect[i+499],"Cycle Up and Down");
sprintf(list_midi_affect[i+556],"Midi Do Action");
sprintf(list_midi_affect[i+685],"Set Stop Pos");
sprintf(list_midi_affect[i+802],"Loop One");
sprintf(list_midi_affect[i+851],"Loop All");
sprintf(list_midi_affect[i+900],"Flash");
sprintf(list_midi_affect[i+1115],"Embeded Play");
sprintf(list_midi_affect[i+1164],"Embeded Seek");
sprintf(list_midi_affect[i+1213],"Embeded Loop/Autostop");
sprintf(list_midi_affect[i+1278],"Embeded Autolaunch");
sprintf(list_midi_affect[i+1543],"FX Mode");
sprintf(list_midi_affect[i+1912],"Damper On/off");
sprintf(list_midi_affect[i+1960],"Damper Decay");
sprintf(list_midi_affect[i+2008],"Damper Mode");
sprintf(list_midi_affect[i+2056],"Damper Delta");
}
sprintf(list_midi_affect[767],"Faders Handle Horizontal");
sprintf(list_midi_affect[1627],"Faders Handle Vertical");
sprintf(list_midi_affect[145],"Select All");
sprintf(list_midi_affect[774],"Selection -");
sprintf(list_midi_affect[775],"Selection +");
sprintf(list_midi_affect[776],"Select");
sprintf(list_midi_affect[777],"Unselect");
sprintf(list_midi_affect[778],"FLASH");
sprintf(list_midi_affect[779],"LOCK");
sprintf(list_midi_affect[780],"LOOP");
sprintf(list_midi_affect[781],"UP");
sprintf(list_midi_affect[782],"DOWN");
sprintf(list_midi_affect[783],"SAW");
sprintf(list_midi_affect[784],"ALL LOOP");
sprintf(list_midi_affect[785],"At Zero");
sprintf(list_midi_affect[786],"Set StopPos");
sprintf(list_midi_affect[787],"To PrevDock");
sprintf(list_midi_affect[788],"To NextDock");
sprintf(list_midi_affect[789],"UPDOWN");
sprintf(list_midi_affect[790],"Select Dock-");
sprintf(list_midi_affect[791],"Select Dock+");
sprintf(list_midi_affect[792],"-");

sprintf(list_midi_affect[793],"NOTHING FREE");
for(int o=0;o<8;o++)
{
sprintf(list_midi_affect[o+794],"MiniFader Preset %d",o);
}

sprintf(list_midi_affect[491],"Stage Fader");
sprintf(list_midi_affect[492],"Preset Fader");
sprintf(list_midi_affect[493],"Speed");
sprintf(list_midi_affect[494],"GO");
sprintf(list_midi_affect[495],"GO BACK");
sprintf(list_midi_affect[496],"DOUBLE GO");
sprintf(list_midi_affect[768],"Create New Mem");
sprintf(list_midi_affect[769],"Delete Mem");
sprintf(list_midi_affect[770],"Stage Minus");
sprintf(list_midi_affect[771],"Stage Plus");
sprintf(list_midi_affect[772],"Preset Minus");
sprintf(list_midi_affect[773],"Preset Plus");
sprintf(list_midi_affect[1591],"Autoreset Crossfade Speed");
sprintf(list_midi_affect[1645],"GOTO");
sprintf(list_midi_affect[548],"Faders");
sprintf(list_midi_affect[549],"Speed");
sprintf(list_midi_affect[550],"Lock");
sprintf(list_midi_affect[551],"Lfo");
sprintf(list_midi_affect[552],"Loop");
sprintf(list_midi_affect[553],"All");
sprintf(list_midi_affect[554],"Midiout");
sprintf(list_midi_affect[555],"Recall");
for(int o=0;o<8;o++)
{
sprintf(list_midi_affect[o+605],"Lock Preset %d",o);
}

for(int p=0;p<4;p++)
{
sprintf(list_midi_affect[616+p]," %d LEVEL",p+1);
sprintf(list_midi_affect[620+p]," %d Pan",p+1);
sprintf(list_midi_affect[624+p]," %d Pitch",p+1);
sprintf(list_midi_affect[628+p]," %d PLAY",p+1);
sprintf(list_midi_affect[632+p]," %d Seek To 0",p+1);
sprintf(list_midi_affect[636+p]," %d General Loop",p+1);
sprintf(list_midi_affect[640+p]," %d Backward",p+1);
sprintf(list_midi_affect[644+p]," %d Forward",p+1);
sprintf(list_midi_affect[648+p]," %d Set IN",p+1);
sprintf(list_midi_affect[652+p]," %d Set Out",p+1);
sprintf(list_midi_affect[656+p]," %d Cue On/Off",p+1);
sprintf(list_midi_affect[660+p]," %d Seek Cue",p+1);
sprintf(list_midi_affect[1800+p]," %d Autoload",p+1);
sprintf(list_midi_affect[1805+p]," %d Autostop",p+1);
sprintf(list_midi_affect[1809+p]," %d Loadfile num",p+1);
sprintf(list_midi_affect[1813+p]," %d Prev track",p+1);
sprintf(list_midi_affect[1817+p]," %d Next track",p+1);
sprintf(list_midi_affect[1821+p]," %d SeektoEnd",p+1);
}
sprintf(list_midi_affect[664],"Midi Level Wheel");
sprintf(list_midi_affect[665],"ENTER");
sprintf(list_midi_affect[666],"+");
sprintf(list_midi_affect[667],"-");
sprintf(list_midi_affect[668],"Up");
sprintf(list_midi_affect[669],"Down");
sprintf(list_midi_affect[670],"0");
sprintf(list_midi_affect[671],"1");
sprintf(list_midi_affect[672],"2");
sprintf(list_midi_affect[673],"3");
sprintf(list_midi_affect[674],"4");
sprintf(list_midi_affect[675],"5");
sprintf(list_midi_affect[676],"6");
sprintf(list_midi_affect[677],"7");
sprintf(list_midi_affect[678],"8");
sprintf(list_midi_affect[679],"9");
sprintf(list_midi_affect[680],"Point");
sprintf(list_midi_affect[681],"Esc");
sprintf(list_midi_affect[682],"All");
sprintf(list_midi_affect[683],"Inv");
sprintf(list_midi_affect[684],"To");
sprintf(list_midi_affect[1825],"Check minus");
sprintf(list_midi_affect[1826],"Check plus");
sprintf(list_midi_affect[1827],"AtFull");
sprintf(list_midi_affect[1828],"AtZero");
sprintf(list_midi_affect[734],"Bang it !");
for(int bc=0;bc<6;bc++)
{
sprintf(list_midi_affect[735+bc],"Bang %d", bc+1);
}
sprintf(list_midi_affect[741],"Banger Page -");
sprintf(list_midi_affect[742],"Banger Page +");
for (int l=0;l<127;l++)
{
sprintf(list_midi_affect[1343+l],"Banger N°%d",l+1);
}

sprintf(list_midi_affect[743],"DOCK F1");
sprintf(list_midi_affect[744],"MODIFY F2");
sprintf(list_midi_affect[745],"REPORT F3");
sprintf(list_midi_affect[746],"CLEAR F4");
sprintf(list_midi_affect[757],"QUIT");

sprintf(list_midi_affect[758],"Time Wheel");
sprintf(list_midi_affect[759],"Switch Time Type");
sprintf(list_midi_affect[760],"Delay IN");
sprintf(list_midi_affect[761],"IN");
sprintf(list_midi_affect[762],"Delay OUT");
sprintf(list_midi_affect[763],"OUT");
sprintf(list_midi_affect[764],"Affect Time");
sprintf(list_midi_affect[765],"Chrono");
sprintf(list_midi_affect[766],"Reset Chrono");

sprintf(list_midi_affect[497],"Thichromy Wheel");
for(int y=0;y<8;y++)
{sprintf(list_midi_affect[949+y],"Dock Color %d",y+1); }


sprintf(list_midi_affect[498],"Tracking Decay Wheel");
for(int y=0;y<12;y++)
{sprintf(list_midi_affect[957+y],"ROI %d",y+1); }
for(int y=0;y<5;y++)
{sprintf(list_midi_affect[969+y],"Video Preset %d",y+1); }

sprintf(list_midi_affect[974],"Select Chaser -");
sprintf(list_midi_affect[975],"Select Chaser +");
sprintf(list_midi_affect[976],"View track up");
sprintf(list_midi_affect[977],"View track down");
sprintf(list_midi_affect[978],"Chaser Play");
sprintf(list_midi_affect[979],"Chaser Seek");
sprintf(list_midi_affect[980],"Chaser Loop");
sprintf(list_midi_affect[981],"Forward way");
sprintf(list_midi_affect[982],"Backward way");
sprintf(list_midi_affect[983],"Aller-Retour");
sprintf(list_midi_affect[984],"ON: ALL");
sprintf(list_midi_affect[985],"ON: INV");
sprintf(list_midi_affect[986],"ON: ALL OFF");
sprintf(list_midi_affect[987],"ON: Preset 1");
sprintf(list_midi_affect[988],"ON: Preset 2");
sprintf(list_midi_affect[989],"ON: Preset 3");
sprintf(list_midi_affect[990],"ON: Preset 4");
sprintf(list_midi_affect[991],"Operator UP");
sprintf(list_midi_affect[992],"Operator STAY");
sprintf(list_midi_affect[993],"Operator DOWN");
sprintf(list_midi_affect[994],"TIME MODE (Std / Join)");
sprintf(list_midi_affect[995],"Begin Step");
sprintf(list_midi_affect[996],"End Step");
sprintf(list_midi_affect[997],"On Timeline Step Position");
for (int ot=0;ot<nbre_tracks_par_chaser;ot++)
{
sprintf(list_midi_affect[998+ot],"ON Track %d",ot+1);
sprintf(list_midi_affect[1024+ot],"LEVEL Track %d",ot+1);
}
for (int yc=0;yc<8;yc++)
{
for(int yl=0;yl<8;yl++)
{
sprintf(list_midi_affect[1048+yl+(yc*8)],"Grid L.%d, Pos %d",yc+1, yl+1);
}
}
sprintf(list_midi_affect[1112],"NOTHING FREE");
sprintf(list_midi_affect[1113],"Grid Pos -");
sprintf(list_midi_affect[1114],"Grid Pos +");

sprintf(list_midi_affect[1265],"iCat Page -");
sprintf(list_midi_affect[1266],"iCat Page +");
for(int yl=0;yl<8;yl++)
{
sprintf(list_midi_affect[1267+yl],"Call iCat Page %d",yl+1);
}
sprintf(list_midi_affect[1275],"iCat Page Orientation");
sprintf(list_midi_affect[1276],"iCat Page Refresh");
sprintf(list_midi_affect[1277],"MidiMute (Global)");


sprintf(list_midi_affect[747],"Call Name window");
sprintf(list_midi_affect[748],"Call Time window");
sprintf(list_midi_affect[749],"Call Trichro window");
sprintf(list_midi_affect[750],"Call Tracking video");
sprintf(list_midi_affect[751],"Call Cue List");
sprintf(list_midi_affect[752],"Call Faders Window");
sprintf(list_midi_affect[753],"Call Banger window");
sprintf(list_midi_affect[754],"Blind mode");
sprintf(list_midi_affect[755],"Call CFG MENU");
sprintf(list_midi_affect[756],"Call Audio window");

sprintf(list_midi_affect[1329],"Call Wizard window");
sprintf(list_midi_affect[1330],"Call Save window");
sprintf(list_midi_affect[1331],"Call Patch window");
sprintf(list_midi_affect[1332],"Call List window");
sprintf(list_midi_affect[1333],"Direct CH mode");
sprintf(list_midi_affect[1334],"View mode");
sprintf(list_midi_affect[1335],"Freeze mode");
sprintf(list_midi_affect[1336],"Call Minifaders window");
sprintf(list_midi_affect[1337],"Call Chaser window");
sprintf(list_midi_affect[1338],"Call Numeric pad");
sprintf(list_midi_affect[1339],"Call Mover window");
sprintf(list_midi_affect[1340],"Call Grider window");
sprintf(list_midi_affect[1341],"Call iCat builder");
sprintf(list_midi_affect[1342],"Call Help window");
sprintf(list_midi_affect[1594],"Call Plot window");
sprintf(list_midi_affect[1659],"Call Draw window");
sprintf(list_midi_affect[1662],"Call Echo window");
sprintf(list_midi_affect[1829],"Call Bazookat window");
sprintf(list_midi_affect[1541],"Exclude CH. from GM");
sprintf(list_midi_affect[1542],"Hipass Mode");

sprintf(list_midi_affect[1592],"Fgroup Mode");

sprintf(list_midi_affect[1593],"Send MidiOut Faders");


sprintf(list_midi_affect[1625],"Midi Affectation");

sprintf(list_midi_affect[1626],"Call Menus Widow");

for (int gl=0;gl<4;gl++)
{
sprintf(list_midi_affect[1472+gl],"On/Off View Gpl %d",gl+1);
sprintf(list_midi_affect[1476+gl],"Minus sel Gpl %d",gl+1);
sprintf(list_midi_affect[1480+gl],"Plus sel Gpl %d",gl+1);
sprintf(list_midi_affect[1484+gl],"Minus Step Gpl %d",gl+1);
sprintf(list_midi_affect[1488+gl],"Plus Step Gpl %d",gl+1);
sprintf(list_midi_affect[1492+gl],"Play Gpl %d",gl+1);
sprintf(list_midi_affect[1496+gl],"Seek Gpl %d",gl+1);
sprintf(list_midi_affect[1500+gl],"AutostopGpl %d",gl+1);
sprintf(list_midi_affect[1504+gl],"Slave Gpl %d",gl+1);
sprintf(list_midi_affect[1508+gl],"Speed Gpl %d",gl+1);
sprintf(list_midi_affect[1512+gl],"Goto ON Gpl %d",gl+1);
sprintf(list_midi_affect[1516+gl],"Count ON Gpl %d",gl+1);
sprintf(list_midi_affect[1520+gl],"SeekPos ON Gpl %d",gl+1);
sprintf(list_midi_affect[1524+gl],"StopPlay ON Gpl %d",gl+1);
sprintf(list_midi_affect[1528+gl],"GridCall Gpl %d",gl+1);
sprintf(list_midi_affect[1532+gl],"StepCallx7 Gpl %d",gl+1);
sprintf(list_midi_affect[1536+gl],"StepCall Gpl %d",gl+1);
}
sprintf(list_midi_affect[1540],"Slave Speed CueList Gpl1");


sprintf(list_midi_affect[1595],"Show Levels");
sprintf(list_midi_affect[1596],"Show Levels from faders");
sprintf(list_midi_affect[1597],"Plot UP list");
sprintf(list_midi_affect[1598],"Plot DOWN list");
sprintf(list_midi_affect[1599],"Plot CC list");
sprintf(list_midi_affect[1600],"Plot ADD list");
sprintf(list_midi_affect[1601],"Rotate selected");
sprintf(list_midi_affect[1602],"DUB selected");
sprintf(list_midi_affect[1603],"Delete selected");
sprintf(list_midi_affect[1604],"SentTo/Grp selected");
sprintf(list_midi_affect[1605],"Select Layer 1");
sprintf(list_midi_affect[1606],"Select Layer 2");
sprintf(list_midi_affect[1607],"Select Layer 3");
sprintf(list_midi_affect[1608],"Select Layer 4");
sprintf(list_midi_affect[1609],"Layer MODE");
sprintf(list_midi_affect[1610],"Relativ xy CH");
sprintf(list_midi_affect[1611],"Relativ xy Name");
sprintf(list_midi_affect[1612],"Relativ xy Gels");
sprintf(list_midi_affect[1613],"Relativ xy Dim");
sprintf(list_midi_affect[1614],"Relativ xy Notes");
for(int pr=0;pr<8;pr++)
{
sprintf(list_midi_affect[1615+pr],"Relativ Preset %d", pr+1);
}

sprintf(list_midi_affect[1624],"Channel Handle Bar");
sprintf(list_midi_affect[1644],"Classical CH View");
for(int pr=0;pr<16;pr++)
{
sprintf(list_midi_affect[1628+pr],"Channel View %d", pr+1);
}

sprintf(list_midi_affect[1658],"Brush Type");
for(int pr=0;pr<6;pr++)
{
sprintf(list_midi_affect[1646+pr],"Draw Matrix %d", pr+1);
}

sprintf(list_midi_affect[1652],"Draw Mode");
sprintf(list_midi_affect[1653],"Brush Pressure");
sprintf(list_midi_affect[1654],"Brush Angle");

sprintf(list_midi_affect[1655],"Ghost Level");
sprintf(list_midi_affect[1656],"Continuous GPL");

sprintf(list_midi_affect[1660],"Draw MidiX");
sprintf(list_midi_affect[1661],"Draw MidiY");

for(int pr=0;pr<24;pr++)
{
sprintf(list_midi_affect[1663+pr],"Echo Preset %d", pr+1);
}
sprintf(list_midi_affect[1686],"ECHO MODE");
sprintf(list_midi_affect[1687],"SNAP FADER");
sprintf(list_midi_affect[1688],"BOUNCE");
sprintf(list_midi_affect[1689],"SNAP KILL & BOUNCE");
sprintf(list_midi_affect[1690],"RECALL FADER");

sprintf(list_midi_affect[1691],"Previous Chan");
sprintf(list_midi_affect[1692],"Next Chan");
sprintf(list_midi_affect[1693],"Gravity");
sprintf(list_midi_affect[1694],"Mass");
sprintf(list_midi_affect[1695],"Energy");
sprintf(list_midi_affect[1696],"ChanMode");

for (int i=0;i<63;i++)
{
  sprintf(list_midi_affect[1830+i],"Arduino analog in %d ON/OFF",i);
}

sprintf(list_midi_affect[1894],"MidiClock Level");
for (int i=0;i<16;i++)
{
 sprintf(list_midi_affect[1895+i],"MidiClock Speed_%d", i+1);
}

return(0);
}
