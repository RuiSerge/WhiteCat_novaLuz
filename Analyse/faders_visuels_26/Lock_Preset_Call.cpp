int Lock_Preset_Call(int xf,int yf)
{
    int calcul_visu=0;
    neuro.Print("Lock Presets",xf-15,yf-30);

    for (int cm=0; cm<2; cm++)
    {
        for (int ll=0; ll<4; ll++)
        {
            Rect LockBt(Vec2D(xf+(cm*55)-5,yf+(ll*55)),Vec2D(45,45));
            LockBt.SetRoundness(5);
            LockBt.SetLineWidth(epaisseur_ligne_fader);

            calcul_visu=cm+(2*ll);

            LockBt.Draw(CouleurLock.WithAlpha(lock_preset[calcul_visu]));
            LockBt.DrawOutline(CouleurLigne);

            if(window_focus_id==W_MINIFADERS && Midi_Faders_Affectation_Type!=0 && mouse_x>xf+(cm*55)-5 && mouse_x<xf+(cm*55)+40 && mouse_y>yf+(ll*55) && mouse_y<yf+(ll*55)+45)
            {
                LockBt.DrawOutline(CouleurBlind);
            }



            petitdoomblanc.Print(ol::ToString(calcul_visu+1),xf+(cm*55)+10,yf+(ll*55)+25);


            petitchiffre.Print(ol::ToString(master_lock_preset[calcul_visu]),xf+(cm*55)+20,yf+(ll*55)+40);

        }
    }

    return(0);
}
