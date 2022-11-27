int LoadWhiteCatColorProfil()
{
    if (config_color_style_is==0)//defaut
    {
        CouleurFond=CouleurFondDefaut;
        CouleurLigne=CouleurLigneDefaut;
        CouleurFader=CouleurFaderDefaut;
        CouleurPatch=CouleurPatchDefaut;
        CouleurSurvol=CouleurSurvolDefaut;
        CouleurLevel=CouleurLevelDefaut;
        CouleurSelection=CouleurSelectionDefaut;
        CouleurNiveau=CouleurNiveauDefaut;
        CouleurConfig=CouleurConfigDefaut;
        CouleurBleuProcedure=CouleurBleuProcedureDefaut;
        CouleurBlind=CouleurBlindDefaut;
        CouleurLock=CouleurLockDefaut;
    }
    else if(config_color_style_is==1)//gris classique
    {
        CouleurFond=CouleurGrisClair;
        CouleurLigne=CouleurNoir;
        CouleurFader=CouleurGrisAnthracite;
        CouleurPatch=CouleurNoir;
        CouleurSurvol=CouleurGrisMoyen;
        CouleurLevel=CouleurNoir;
        CouleurSelection=CouleurBlanc;
        CouleurNiveau=CouleurNoir;
        CouleurConfig=CouleurGrisAnthracite;
        CouleurBleuProcedure=CouleurNoir;
        CouleurBlind=Rgba::RED;
        CouleurLock=CouleurBlanc;
        petitchiffre.SetColor(Rgba::BLACK);
        petitpetitchiffre.SetColor(Rgba::BLACK);
        petitchiffrenoir.SetColor(Rgba::WHITE);
        circuitlevel.SetColor(Rgba::WHITE);
        circuitfaderlevel.SetColor(CouleurGrisAnthracite);
    }

    else if(config_color_style_is==2)//bleut�
    {
        CouleurFond=CouleurBleu1;
        CouleurLigne=CouleurBlanc;
        CouleurFader=CouleurBleu6;
        CouleurPatch=CouleurNoir;
        CouleurSurvol=CouleurBleu6;
        CouleurLevel=CouleurBleu4;
        CouleurSelection=CouleurBlanc;
        CouleurNiveau=CouleurBlanc;
        CouleurConfig=CouleurBleu4;
        CouleurBleuProcedure=CouleurBleu2;
        CouleurBlind=Rgba::RED;
        CouleurLock=CouleurBleu8;
    }

    else if(config_color_style_is==3)//dicrete
    {
        CouleurFond=Discrete1;
        CouleurLigne=Discrete2;
        CouleurFader=Discrete3;
        CouleurPatch=Discrete4;
        CouleurSurvol=Discrete5;
        CouleurLevel=Discrete6;
        CouleurSelection=Discrete7;
        CouleurNiveau=Discrete8;
        CouleurConfig=Discrete9;
        CouleurBleuProcedure=Discrete10;
        CouleurBlind=Discrete11;
        CouleurLock=Discrete12;
    }


    else if(config_color_style_is==4)//dmatrix
    {
        CouleurFond=Matrix1;
        CouleurLigne=Matrix2;
        CouleurFader=Matrix3;
        CouleurPatch=Matrix4;
        CouleurSurvol=Matrix5;
        CouleurLevel=Matrix6;
        CouleurSelection=Matrix7;
        CouleurNiveau=Matrix8;
        CouleurConfig=Matrix9;
        CouleurBleuProcedure=Matrix10;
        CouleurBlind=Matrix11;
        CouleurLock=Matrix12;
    }

    else if(config_color_style_is==5)//user
    {
        CouleurFond=CouleurUser1;
        CouleurLigne=CouleurUser2;
        CouleurFader=CouleurUser3;
        CouleurPatch=CouleurUser4;
        CouleurSurvol=CouleurUser5;
        CouleurLevel=CouleurUser6;
        CouleurSelection=CouleurUser7;
        CouleurNiveau=CouleurUser8;
        CouleurConfig=CouleurUser9;
        CouleurBleuProcedure=CouleurUser10;
        CouleurBlind=CouleurUser11;
        CouleurLock=CouleurUser12;
    }
    doom.SetColor( CouleurLigne );
    doomblanc.SetColor( CouleurLigne );
    petitdoomblanc.SetColor( CouleurLigne );
    neuro.SetColor( CouleurLigne );
    neuromoyen.SetColor( CouleurLigne );
    petitchiffre.SetColor( CouleurLigne );
    petitpetitchiffre.SetColor( CouleurLigne );
    neuroTitle.SetColor( CouleurLigne );
    doomrouge.SetColor( CouleurBlind );
    petitpetitchiffrerouge.SetColor( CouleurBlind );
    petitchiffrerouge.SetColor( CouleurBlind );
    circuitblindlevel.SetColor( CouleurBlind );
    circuitlevel.SetColor( CouleurLevel );
    petitchiffrenoir.SetColor( CouleurFond );
    petitdoomInspekt.SetColor( CouleurFader );
    circuitfaderlevel.SetColor( CouleurFader );
    return(0);
}
