if (MemoiresExistantes[position_preset]==1)
{
ExclueMem.MoveTo(Vec2D(x_seq+170,y_seq+140));
ExclueMem.Draw(CouleurYellow.WithAlpha(alpha_blinker*(MemoiresExclues[position_preset])));
neuro.Print(string_mem_preset,  x_seq+115, y_seq+160);
petitpetitchiffre.Print(descriptif_memoires[position_preset], x_seq+320, y_seq+150);
petitpetitchiffre.Print(annotation_memoires[position_preset], x_seq+320, y_seq+165);
petitpetitchiffre.Print(cross_din, x_seq+20, y_seq+160);
petitchiffre.Print(cross_in, x_seq+55, y_seq+160);
petitchiffre.Print(cross_out, x_seq+55, y_seq+130);
petitpetitchiffre.Print(cross_dout, x_seq+20, y_seq+130);
if(Banger_Memoire[position_preset]!=0)
{
petitchiffre.Print(ol::ToString(Banger_Memoire[position_preset]),x_seq+235,y_seq+160);
}
if(set_from_seq_gridplayer1_next_step[position_preset]!=-1)
{
petitchiffre.Print(ol::ToString(set_from_seq_gridplayer1_next_step[position_preset]+1),x_seq+280,y_seq+160);
}
if(Links_Memoires[position_preset]==1)
{
Line(Vec2D(x_seq+190,y_seq+150),Vec2D(x_seq+200,y_seq+150)).Draw(CouleurLigne);
Line(Vec2D(x_seq+200,y_seq+150),Vec2D(x_seq+200,y_seq+165)).Draw(CouleurLigne);
Line(Vec2D(x_seq+200,y_seq+165),Vec2D(x_seq+195,y_seq+160)).Draw(CouleurLigne);
Line(Vec2D(x_seq+200,y_seq+165),Vec2D(x_seq+205,y_seq+160)).Draw(CouleurLigne);
}
}
