int refresh_vision_memories( int x_seq, int y_seq)
{

    Rect ExclueMem(Vec2D(x_seq,y_seq),Vec2D(10,30));


    if(window_focus_id==W_SEQUENCIEL && mouse_x>x_seq && mouse_x<x_seq+450 && mouse_y> y_seq and mouse_y<y_seq+hauteur_globale_sequenciel ) // affichage survol des cases souris
    {
        Rect DelayOver (Vec2D (x_seq, y_seq ), Vec2D ( 40,20));
        DelayOver.SetRoundness(7.5);
        Rect InOutOver (Vec2D (x_seq, y_seq ), Vec2D ( 60,20));
        InOutOver.SetRoundness(7.5);
        Rect MemOver (Vec2D (x_seq, y_seq), Vec2D ( 60,20));
        MemOver.SetRoundness(7.5);
        Rect LinkOver (Vec2D (x_seq, y_seq ), Vec2D ( 35,20));
        LinkOver.SetRoundness(7.5);
        Rect bangOver (Vec2D (x_seq, y_seq), Vec2D ( 40,20));
        bangOver.SetRoundness(7.5);
        Rect Gpl1Over (Vec2D (x_seq, y_seq), Vec2D ( 30,20));
        Gpl1Over.SetRoundness(7.5);
        Rect TextOver (Vec2D (x_seq, y_seq), Vec2D ( 160,15));
        TextOver.SetRoundness(5);



        if(mouse_y>y_seq+80 && mouse_y< y_seq+100)
        {
            if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
            {
                LinkOver.MoveTo (Vec2D (x_seq+180,y_seq+80));
                LinkOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
            {
                bangOver.MoveTo (Vec2D (x_seq+225, y_seq+80));
                bangOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
            {
                Gpl1Over.MoveTo (Vec2D (x_seq+275, y_seq+80));
                Gpl1Over.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
            {
                if(mouse_y> y_seq+80 && mouse_y < y_seq+95)
                {
                    TextOver.MoveTo (Vec2D (x_seq+310, y_seq+80));
                }
                else
                {
                    TextOver.MoveTo(Vec2D (x_seq+310, y_seq+95));
                }
                TextOver.DrawOutline(CouleurLigne);
            }
        }



        else if(mouse_y>y_seq+110 && mouse_y<y_seq+140)
        {
            if(mouse_x> x_seq+10 && mouse_x<x_seq+50)//DELAYS
            {
                DelayOver.MoveTo (Vec2D (x_seq+10, y_seq+115 ));
                DelayOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+50 && mouse_x<x_seq+110)//IN OUT
            {
                InOutOver.MoveTo(Vec2D (x_seq+50, y_seq+115 ));
                InOutOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
            {
                MemOver.MoveTo (Vec2D (x_seq+110, y_seq+115 ));
                MemOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
            {
                LinkOver.MoveTo (Vec2D (x_seq+180, y_seq+115 ));
                LinkOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
            {
                bangOver.MoveTo (Vec2D (x_seq+225, y_seq+115 ));
                bangOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
            {
                Gpl1Over.MoveTo (Vec2D (x_seq+275, y_seq+115 ));
                Gpl1Over.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
            {
                if(mouse_y> y_seq+110 && mouse_y < y_seq+125)
                {
                    TextOver.MoveTo (Vec2D (x_seq+310, y_seq+110));
                }
                else
                {
                    TextOver.MoveTo(Vec2D (x_seq+310, y_seq+125));
                }
                TextOver.DrawOutline(CouleurLigne);
            }
        }



        else if(mouse_y>y_seq+140 && mouse_y<y_seq+170)
        {
            if(mouse_x> x_seq+10 && mouse_x<x_seq+50)//DELAYS
            {
                DelayOver.MoveTo (Vec2D (x_seq+10, y_seq+145 ));
                DelayOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+50 && mouse_x<x_seq+110)//IN OUT
            {
                InOutOver.MoveTo  (Vec2D (x_seq+50, y_seq+145));
                InOutOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
            {
                MemOver.MoveTo  (Vec2D (x_seq+110, y_seq+145));
                MemOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
            {
                LinkOver.MoveTo  (Vec2D (x_seq+180, y_seq+145 ));
                LinkOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
            {
                bangOver.MoveTo  (Vec2D (x_seq+225, y_seq+145 ));
                bangOver.DrawOutline(CouleurLigne);
            }
            else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
            {
                Gpl1Over.MoveTo  (Vec2D (x_seq+275, y_seq+145 ));
                Gpl1Over.DrawOutline(CouleurLigne);
            }
            else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
            {
                if(mouse_y> y_seq+140 && mouse_y < y_seq+155)
                {
                    TextOver.MoveTo  (Vec2D (x_seq+310, y_seq+140));
                }
                else
                {
                    TextOver.MoveTo(Vec2D (x_seq+310, y_seq+155));
                }
                TextOver.DrawOutline(CouleurLigne);
            }
        }




        for(int i=0; i<nbre_memoires_visualisables_en_preset; i++)
        {
            if(mouse_y>y_seq+145+(35*i)  && mouse_y< y_seq+175+(35*i))
            {

                if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
                {
                    MemOver.MoveTo (Vec2D (x_seq+110,y_seq+145+(35*i)));
                    MemOver.DrawOutline(CouleurLigne);
                }
                else if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
                {
                    LinkOver.MoveTo (Vec2D (x_seq+180,y_seq+145+(35*i)));
                    LinkOver.DrawOutline(CouleurLigne);
                }
                else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
                {
                    bangOver.MoveTo (Vec2D (x_seq+225, y_seq+145+(35*i) ));
                    bangOver.DrawOutline(CouleurLigne);
                }
                else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
                {
                    Gpl1Over.MoveTo (Vec2D (x_seq+275, y_seq+145+(35*i) ));
                    Gpl1Over.DrawOutline(CouleurLigne);
                }
                else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
                {
                    if(mouse_y> y_seq+140+(35*i) && mouse_y < y_seq+155+(35*i) )
                    {
                        TextOver.MoveTo (Vec2D (x_seq+310, y_seq+140+(35*i)));
                    }
                    else
                    {
                        TextOver.MoveTo(Vec2D (x_seq+310, y_seq+155+(35*i)));
                    }
                    TextOver.DrawOutline(CouleurLigne);
                }

            }
        }

    }







    /*if(index_is_saving==0 && init_done==1 && index_writing_curve==0 && index_quit==0)
    {

    ExclueMem.MoveTo(Vec2D(x_seq+170,y_seq+140));
    ExclueMem.Draw(CouleurYellow.WithAlpha(alpha_blinker*(MemoiresExclues[position_preset])));
    }*/

    if (MemoiresExistantes[mem_before_one]==1)
    {
        ExclueMem.MoveTo(Vec2D(x_seq+170,y_seq+80));
        ExclueMem.Draw(CouleurYellow.WithAlpha(alpha_blinker*(MemoiresExclues[mem_before_one])));

        neuro.Print(string_mem_before_one,  x_seq+115, y_seq+100);
        if(Banger_Memoire[mem_before_one]!=0)//dout
        {
            petitchiffre.Print(ol::ToString(Banger_Memoire[mem_before_one]),x_seq+235,y_seq+100);
        }
        if(set_from_seq_gridplayer1_next_step[mem_before_one]!=-1)
        {
            petitchiffre.Print(ol::ToString(set_from_seq_gridplayer1_next_step[mem_before_one]+1),x_seq+280,y_seq+100);
        }
        if(Times_Memoires[position_onstage][0]>0.0)
        {
            petitpetitchiffre.Print(string_time_memonstage[0], x_seq+20,y_seq+90);
        }
        if(Times_Memoires[position_onstage][2]>0.0)//dIn
        {

            petitpetitchiffrerouge.Print(string_time_memonstage[2], x_seq+20,y_seq+100);
        }
        petitpetitchiffre.Print(string_time_memonstage[3], x_seq+70, y_seq+90);
        petitpetitchiffrerouge.Print(string_time_memonstage[1], x_seq+70, y_seq+100);
        petitpetitchiffre.Print(descriptif_memoires[mem_before_one], x_seq+320, y_seq+90);
        petitpetitchiffre.Print(annotation_memoires[mem_before_one], x_seq+320, y_seq+105);
        if(Links_Memoires[mem_before_one]==1)
        {
            Line(Vec2D(x_seq+190,y_seq+85),Vec2D(x_seq+200,y_seq+85)).Draw(CouleurLigne);
            Line(Vec2D(x_seq+200,y_seq+85),Vec2D(x_seq+200,y_seq+100)).Draw(CouleurLigne);
            Line(Vec2D(x_seq+200,y_seq+100),Vec2D(x_seq+195,y_seq+95)).Draw(CouleurLigne);
            Line(Vec2D(x_seq+200,y_seq+100),Vec2D(x_seq+205,y_seq+95)).Draw(CouleurLigne);
        }
    }

    if (MemoiresExistantes[position_onstage]==1)
    {
        neuro.Print(string_mem_onstage,  x_seq+115, y_seq+100+ 30);

        ExclueMem.MoveTo(Vec2D(x_seq+170,y_seq+110));
        ExclueMem.Draw(CouleurYellow.WithAlpha(alpha_blinker*(MemoiresExclues[position_onstage])));

        petitpetitchiffre.Print(descriptif_memoires[position_onstage], x_seq+320, y_seq+120);
        petitpetitchiffre.Print(annotation_memoires[position_onstage], x_seq+320, y_seq+135);
        if(Banger_Memoire[position_onstage]!=0)
        {
            petitchiffre.Print(ol::ToString(Banger_Memoire[position_onstage]),x_seq+235,y_seq+130);
        }
        if(set_from_seq_gridplayer1_next_step[position_onstage]!=-1)
        {
            petitchiffre.Print(ol::ToString(set_from_seq_gridplayer1_next_step[position_onstage]+1),x_seq+280,y_seq+130);
        }
        if(Links_Memoires[position_onstage]==1)
        {
            Line(Vec2D(x_seq+190,y_seq+115+5),Vec2D(x_seq+200,y_seq+120)).Draw(CouleurLigne);
            Line(Vec2D(x_seq+200,y_seq+115+5),Vec2D(x_seq+200,y_seq+135)).Draw(CouleurLigne);
            Line(Vec2D(x_seq+200,y_seq+130+5),Vec2D(x_seq+195,y_seq+130)).Draw(CouleurLigne);
            Line(Vec2D(x_seq+200,y_seq+130+5),Vec2D(x_seq+205,y_seq+130)).Draw(CouleurLigne);
        }
    }
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





    int index_nbre_mem_visues=0;
    bool turn=0;
    for(int memsearch=position_preset+1; memsearch<10000; memsearch++)
    {
        if(memsearch>=9999 && turn==0)
        {
            memsearch=0;
            turn=1;
        }
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

            if(index_nbre_mem_visues>=nbre_memoires_visualisables_en_preset)
            {
                break;
            }
        }
    }


    return(0);
}
