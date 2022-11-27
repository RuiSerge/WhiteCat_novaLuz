int print_ch_from_plot( int ch)
{

char gellist[72];
char gely[24];

for(int c=0;c<4;c++)
{
for (int s=1;s<=nbre_symbols_on_plot[c];s++)
{
if(symbol_channel_is[c][s]==ch)//report des symboles correspondant au circuit
{
strcpy(gellist,"");
strcpy(gely,"");
for(int g=0;g<3;g++)//3 slots de gelat par symbol
{
if( gelat[c][s][g]!=0)//si une gelat non zero
{


switch(gelat_family[c][s][g])
{
case 0:
sprintf(gely," Lee %d", gelat[c][s][g]);
break;
case 1:
sprintf(gely," Rosco %d", gelat[c][s][g]);
break;
case 2:
sprintf(gely," GamC. %d", gelat[c][s][g]);
break;
case 3:
sprintf(gely," Apollo %d", gelat[c][s][g]);
break;
default:
strcpy(gely,"");
break;
}
strcat(gellist,gely);
strcpy(gely,"");
}
}
sprintf(header_export,"%s %s \n",symbol_nickname[ ( symbol_type[c][s] ) ],gellist);
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
strcpy(gellist,"");
strcpy(header_export,"");
for(int no=0;no<4;no++)
{
if(strcmp(symbol_note[c][s][no],"")!=0)
{
sprintf(header_export,"Note %d:  %s",no+1,symbol_note[c][s][no]);
draw_info(page, 130, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
verification_fin_de_page();
strcpy(header_export,"");
}
}
}
}
}
 return(0);
}
