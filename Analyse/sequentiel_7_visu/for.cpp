for(int memsearch=position_preset+1; memsearch<10000;memsearch++)
{
if(memsearch>=9999 && turn==0){memsearch=0;turn=1;}
if(MemoiresExistantes[memsearch]==1 && index_nbre_mem_visues<nbre_memoires_visualisables_en_preset)
{
index_nbre_mem_visues++;

sprintf(string_next_mem,"%d.%d",memsearch/10, memsearch%10);
neuro.Print(string_next_mem,  x_seq+115, y_seq+160+(35*index_nbre_mem_visues));
petitpetitchiffre.Print(descriptif_memoires[memsearch], x_seq+320, y_seq+150+(35*index_nbre_mem_visues));
petitpetitchiffre.Print(annotation_memoires[memsearch], x_seq+320, y_seq+165+(35*index_nbre_mem_visues));

Line(Vec2D(x_seq+10, y_seq+100+70+(35*index_nbre_mem_visues)),Vec2D(x_seq+450, y_seq+170+(35*index_nbre_mem_visues))).Draw(CouleurLigne.WithAlpha(0.5));

ExclueMem.MoveTo(Vec2D(x_seq+170,y_seq+135+(35*index_nbre_mem_visues)));
ExclueMem.Draw(CouleurYellow.WithAlpha(alpha_blinker*(MemoiresExclues[memsearch])));


if(Times_Memoires[memsearch][2]>0.0)
{
petitpetitchiffre.Print(string_time_mem8after[index_nbre_mem_visues][2], x_seq+20, y_seq+150+(35*index_nbre_mem_visues));
}
if(Times_Memoires[memsearch][0]>0.0)//dout
{
petitpetitchiffrerouge.Print(string_time_mem8after[index_nbre_mem_visues][0], x_seq+20, y_seq+165+(35*index_nbre_mem_visues));
}
petitpetitchiffre.Print(string_time_mem8after[index_nbre_mem_visues][3], x_seq+70, y_seq+150+(35*index_nbre_mem_visues));
petitpetitchiffrerouge.Print(string_time_mem8after[index_nbre_mem_visues][1], x_seq+70, y_seq+165+(35*index_nbre_mem_visues));
if(Banger_Memoire[memsearch]!=0)
{
petitchiffre.Print(ol::ToString(Banger_Memoire[memsearch]),x_seq+235,y_seq+160+(35*index_nbre_mem_visues));
}
if(set_from_seq_gridplayer1_next_step[memsearch]!=-1)
{
petitchiffre.Print(ol::ToString(set_from_seq_gridplayer1_next_step[memsearch]+1),x_seq+280,y_seq+160+(35*index_nbre_mem_visues));
}

if(Links_Memoires[memsearch]==1)
{
Line(Vec2D(x_seq+190,y_seq+145+(35*index_nbre_mem_visues)),Vec2D(x_seq+200,y_seq+145+(35*index_nbre_mem_visues))).Draw(CouleurLigne);
Line(Vec2D(x_seq+200,y_seq+145+(35*index_nbre_mem_visues)),Vec2D(x_seq+200,y_seq+160+(35*index_nbre_mem_visues))).Draw(CouleurLigne);
Line(Vec2D(x_seq+200,y_seq+160+(35*index_nbre_mem_visues)),Vec2D(x_seq+195,y_seq+155+(35*index_nbre_mem_visues))).Draw(CouleurLigne);
Line(Vec2D(x_seq+200,y_seq+160+(35*index_nbre_mem_visues)),Vec2D(x_seq+205,y_seq+155+(35*index_nbre_mem_visues))).Draw(CouleurLigne);
}

if(index_nbre_mem_visues>=nbre_memoires_visualisables_en_preset){break;}
}
}
