int feedback_banger(int xvis, int yvis)
{
    char over_banger_is[64];
    int banger_overoll=0;
    for (int nb=0; nb<8; nb++)
    {
        for (int lb=0; lb<16; lb++)
        {
            if((nb)+(lb*8)<core_user_define_nb_bangers)
            {
                Circle BangerFeedback(Vec2D(xvis+(nb*12)+30,yvis+(lb*12)+30),5);
                BangerFeedback.DrawOutline(CouleurLigne.WithAlpha(0.5));
                if(bang_is_sended[(nb)+(lb*8)]==0 && (((nb)+(lb*8))<127))//évenement pas encore fini dans son éxécution
                {
                    BangerFeedback.Draw(CouleurBlind.WithAlpha(alpha_blinker));
                }


                if(window_focus_id==W_BANGER &&  mouse_x>xvis+(nb*12)+25 && mouse_x<xvis+(nb*12)+35 && mouse_y>yvis+(lb*12)+25 && mouse_y<yvis+(lb*12)+35)
                {
                    banger_overoll=(nb)+(lb*8);
                    if(banger_overoll<127)
                    {
                        if( Midi_Faders_Affectation_Type!=0)//config midi
                        {
                            BangerFeedback.SetLineWidth(2.0);
                            BangerFeedback.DrawOutline(CouleurBlind);
                            char desc_midi_bg[24];
                            sprintf(desc_midi_bg,"Banger %d",banger_overoll+1);
                            show_type_midi(1343+banger_overoll,desc_midi_bg );
                        }
                        else
                        {
                            BangerFeedback.DrawOutline(CouleurLigne);
                        }

                    }
                }
            }
        }
    }

    for(int p=0; p<16; p++)
    {
        sprintf(over_banger_is,"%d",(p*8)+1);
        petitpetitchiffrerouge.Print(over_banger_is,xvis,(yvis+p*12)+35);
    }

    if(banger_overoll<127)
    {
        sprintf(over_banger_is,"BANGER %d",banger_overoll+1);
        petitpetitchiffre.Print(over_banger_is,xvis,yvis+10);

        sprintf(over_banger_is, bangers_name[banger_overoll]);
        petitpetitchiffre.Print(over_banger_is,xvis,yvis+20);
    }
    sprintf(over_banger_is,"Last bang sended: %d",last_banger_sended_manually+1);
    petitpetitchiffre.Print(over_banger_is,xvis,yvis+230);
    return(0);
}
