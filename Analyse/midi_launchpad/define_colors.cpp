int define_colors()
{
for(int g=0;g<3072;g++)
{
launchpad_color_defined[g]=8;
launchpad_is_a_cycling_effect[g]=0;
}

for(int i=0;i<48;i++)
{
 launchpad_color_defined[i+146]=lch_green;//lock
 launchpad_color_defined[i+245]=lch_orange;//UP
 launchpad_color_defined[i+294]=lch_orange;//DOWN
 launchpad_color_defined[i+343]=lch_orange;//SAW
 launchpad_is_a_cycling_effect[i+245]=1;
 launchpad_is_a_cycling_effect[i+294]=1;
 launchpad_is_a_cycling_effect[i+343]=1;
 launchpad_color_defined[i+392]=lch_ambre;//PREVDOCK
 launchpad_color_defined[i+441]=lch_ambre;//NEXTDOCK
 launchpad_color_defined[i+499]=lch_ambre;//UPDOWNDOCK
 launchpad_color_defined[i+685]=lch_red;//STOPPOS
 launchpad_color_defined[i+802]=lch_orange_fonce;//Loop One
 launchpad_color_defined[i+851]=lch_orange_fonce;//Loop All
 launchpad_color_defined[i+900]=lch_orange;//FLASH
 launchpad_color_defined[1115+i]=lch_orange;//Play Chaser
 launchpad_color_defined[1164+i]=lch_orange;//Seek Chaser
 launchpad_color_defined[1213+i]=lch_orange;//loop Chaser
}

for(int pl=0;pl<4;pl++)
{
launchpad_color_defined[628+pl]=lch_red; //play
launchpad_color_defined[636+pl]=lch_orange; //general loop
launchpad_color_defined[656+pl]=lch_red; //cueloop
}
launchpad_color_defined[734]=lch_red;

for(int i=0;i<15;i++)
{
launchpad_color_defined[743+i]=lch_orange;
}
launchpad_color_defined[754]=lch_red;//blind

for(int p=0;p<4;p++)//time
{
launchpad_color_defined[760+p]=lch_orange_fonce;
}

for(int co=0;co<8;co++)//dock color
{
launchpad_color_defined[949+co]=lch_orange_fonce;
}
for(int o=0;o<12;o++)//tracking space
{
launchpad_color_defined[957+o]=lch_orange_fonce;
}


for(int op=0;op<5;op++)//tracking dock
{
launchpad_color_defined[969+op]=lch_yellow;
}

for(int op=0;op<8;op++)//tracking dock
{
launchpad_color_defined[794+op]=lch_orange;
}


launchpad_color_defined[978]=lch_orange;//Play
launchpad_color_defined[980]=lch_orange;//loop
launchpad_color_defined[981]=lch_orange;//Forward
launchpad_color_defined[982]=lch_orange;//backward
launchpad_color_defined[983]=lch_orange;//aller retour
launchpad_color_defined[991]=lch_orange;//Up Op
launchpad_color_defined[992]=lch_green;//Stay Op
launchpad_color_defined[993]=lch_red;//Down Op
launchpad_color_defined[994]=lch_orange;//Tjoin STd Mode

for(int yo=0;yo<24;yo++)
{
launchpad_color_defined[998+yo]=lch_green;    //on off des tracks
}

for(int yo=0;yo<8;yo++)
{
launchpad_color_defined[1267+yo]=lch_orange_fonce;    //on iCat preset
}

launchpad_color_defined[1277]=lch_red;    //midi mute general

for(int io=0;io<25;io++)
{
launchpad_color_defined[io+1329]=lch_orange;
}
launchpad_color_defined[1333]=lch_orange_fonce; //direct CH
launchpad_color_defined[1334]=lch_orange_fonce; //view
launchpad_color_defined[754]=lch_red;//blind

for(int io=0;io<4;io++)
{
launchpad_color_defined[io+1472]=lch_red;//on off affichage players
launchpad_color_defined[io+1492]=lch_orange;//play player
launchpad_color_defined[io+1500]=lch_red;//autostop mode
launchpad_color_defined[io+1504]=lch_orange_fonce;//slave
launchpad_color_defined[io+1512]=lch_red;//macro goto
launchpad_color_defined[io+1516]=lch_red;//macro count
launchpad_color_defined[io+1520]=lch_red;//macro seek pos
launchpad_color_defined[io+1524]=lch_red;//stopplay macro
}
launchpad_color_defined[1540]=lch_orange;//on off asservissement sequenciel gpl1

launchpad_color_defined[1591]=lch_red;//on off reset accelerometre on crossfade done

 return(0);
}
