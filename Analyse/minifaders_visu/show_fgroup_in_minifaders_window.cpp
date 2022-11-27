int show_fgroup_in_minifaders_window(int xs, int ys, int fad, int dk)
{
    petitpetitchiffre.Print("Fgroup in f", xs+5,ys);
    petitpetitchiffre.Print(ol::ToString(over_minifader+1), xs+65,ys);
    Rect FgOn(Vec2D(xs,ys),Vec2D(10,10));

    for(int u=0; u<8; u++)
    {
        for (int i=0; i<6; i++)
        {
            if(DockTypeIs[fad][dk]==13)
            {
                FgOn.MoveTo(Vec2D(xs+3+(15*i),ys+13+(20*u)));
                FgOn.Draw(CouleurFader.WithAlpha(0.8*fgroup[fad][dk][(u*6)+i]));
            }

            minichiffre.Print(ol::ToString((u*6)+i+1),xs+5+(15*i),ys+20+(20*u));
        }
    }
    return(0);
}
