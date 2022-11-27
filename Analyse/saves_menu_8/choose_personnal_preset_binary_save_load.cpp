int choose_personnal_preset_binary_save_load(int xs,int ys)
{
    petitchiffre.Print("Personnal Presets:",xs-15,ys-15);
    for(int i=0; i<4; i++)
    {
        Rect Carre(Vec2D(xs+(20*i),ys),Vec2D(10,10));
        switch(i)
        {
        case 0:
            Carre.Draw(CouleurBlind);
            break;
        case 1:
            Carre.Draw(CouleurBleuProcedure);
            break;
        case 2:
            Carre.Draw(CouleurGreen);
            break;
        case 3:
            Carre.Draw(CouleurYellowFgroup);
            break;
        default:
            break;
        }
        Carre.DrawOutline(CouleurLigne.WithAlpha(0.5));

    }
    return(0);
}
