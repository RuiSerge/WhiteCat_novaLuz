int menu_curve(int XCurv, int YCurv)
{
    Rect CurveSpace( Vec2D((XCurv),(YCurv)),Vec2D(315,600));
    CurveSpace.SetRoundness(15);
    CurveSpace.SetLineWidth(triple_epaisseur_ligne_fader);
    CurveSpace.Draw(CouleurFond);
    if(window_focus_id==W_PATCH)
    {
        CurveSpace.DrawOutline(CouleurFader);
    }
    else
    {
        CurveSpace.DrawOutline(CouleurLigne);
    }

    neuro.Print("CURVES",XCurv+210,YCurv+30);

    Rect CurveEditEnable( Vec2D((XCurv+30),(YCurv+10)),Vec2D(50,20));
    CurveEditEnable.SetRoundness(7.5);


    if(index_enable_curve_editing==1)
    {
        CurveEditEnable.Draw(CouleurFader);
    }
    CurveEditEnable.DrawOutline(CouleurLigne);
    petitchiffre.Print("edit",XCurv+40,YCurv+22);

    Rect CurveEditSpace( Vec2D((XCurv+30),(YCurv+50)),Vec2D(255,255));
    CurveEditSpace.SetRoundness(7.5);
    CurveEditSpace.Draw(CouleurFond);
    CurveEditSpace.DrawOutline(CouleurFond);

    for (int l=1; l<=25; l++)
    {
        Line( Vec2D( XCurv+30+(l*10), YCurv+50 ), Vec2D( XCurv+30+(l*10),YCurv+305)).Draw(CouleurLigne.WithAlpha(0.2));
        Line( Vec2D( XCurv+30, YCurv+50+(l*10) ), Vec2D( XCurv+285,YCurv+50+(l*10))).Draw(CouleurLigne.WithAlpha(0.2));
    }



    Rect CurveSplineRatio( Vec2D((XCurv+30),(YCurv+330)),Vec2D(255,25));
    CurveSplineRatio.SetRoundness(7.5);
    CurveSplineRatio.SetLineWidth(epaisseur_ligne_fader);
    Rect CurveSplineLevel( Vec2D((XCurv+30),(YCurv+330)),Vec2D(index_curve_spline_level,25));
    CurveSplineLevel.SetRoundness(7.5);
    CurveSplineLevel.SetLineWidth(epaisseur_ligne_fader);

    CurveSplineLevel.Draw(CouleurSurvol);
    CurveSplineRatio.DrawOutline(CouleurLigne);

    petitchiffre.Print(ol::ToString(index_curve_spline_level),XCurv+157,YCurv+340);
    petitchiffre.Print(ol::ToString(curve_spline_level),XCurv+157,YCurv+350);




    curve_spline_level=(((float)index_curve_spline_level)/127)-1;
    if( window_focus_id==W_PATCH && index_enable_curve_editing==1 && mouse_x>=XCurv+30 && mouse_x<=XCurv+285 && mouse_y>YCurv+330 && mouse_y<YCurv+355 && mouse_button==1)
    {
        index_curve_spline_level=mouse_x-(XCurv+30);
        the_curve_spline_level[curve_selected]=index_curve_spline_level;
        write_curve();
    }

    Rect Curve(Vec2D(XCurv,YCurv),Vec2D(60,20));
    Curve.SetRoundness(7.5);
    Curve.SetLineWidth(epaisseur_ligne_fader);

    for(int l=0; l<4; l++)
    {
        for (int curvenumber=0; curvenumber<4; curvenumber++)
        {
            Curve.MoveTo(Vec2D((XCurv+20+(curvenumber*70)),(YCurv+370+(30*l))));
            if(curve_selected==curvenumber+(l*4))
            {
                Curve.Draw(CouleurBlind);
            }
            petitchiffre.Print(ol::ToString(1+curvenumber+(l*4)),XCurv+50+(curvenumber*70),YCurv+385+(30*l));
            Curve.DrawOutline(CouleurLigne);
        }
    }


    SplineCurve();
    if(window_focus_id==W_PATCH && mouse_x>=(XCurv+30)&& mouse_x<=(XCurv+285) && mouse_y>=(YCurv+50) && mouse_y<=(YCurv+305))
    {
        if(dmx_view==1)
        {
            petitchiffrerouge.Print(ol::ToString((YCurv+305)-mouse_y),mouse_x-25,mouse_y-15);
            petitchiffre.Print(ol::ToString(mouse_x-(XCurv+30)),mouse_x+10,mouse_y-15);
        }
        else if( dmx_view==0)
        {
            petitchiffrerouge.Print(ol::ToString((int)(((YCurv+305)-mouse_y)/2.55)),mouse_x-25,mouse_y-15);
            petitchiffre.Print(ol::ToString((int)((mouse_x-(XCurv+30))/2.55)),mouse_x+10,mouse_y-15);
        }
    }
    petitchiffre.Print("Presets to curve :",XCurv+20,YCurv+500);
    Rect ActToCurve(Vec2D(XCurv,YCurv),Vec2D(60,20));
    ActToCurve.SetRoundness(7.5);
    ActToCurve.SetLineWidth(epaisseur_ligne_fader);
    for (int act=0; act<4; act++)
    {
        ActToCurve.MoveTo( Vec2D( (XCurv+20+(act*70)), (YCurv+510) ) );

        switch(act)
        {
        case 0:
            if (index_reset_curve==1)
            {
                ActToCurve.Draw(CouleurBlind);
            }
            petitchiffre.Print("linear",XCurv+30+(act*70),YCurv+525);
            break;
        case 1:
            if (index_square_curve==1)
            {
                ActToCurve.Draw(CouleurBlind);
            }
            petitchiffre.Print("square",XCurv+20+(act*70)+5,YCurv+525);
            break;
        case 2:
            if (index_preheat_curve==1)
            {
                ActToCurve.Draw(CouleurBlind);
            }
            petitchiffre.Print("preheat",XCurv+20+(act*70)+1,YCurv+525);
            break;
        case 3:
            if (index_fluo_curve==1)
            {
                ActToCurve.Draw(CouleurBlind);
            }
            petitchiffre.Print("fluo.",XCurv+20+(act*70)+15,YCurv+525);
            break;
        default:
            break;
        }
        ActToCurve.DrawOutline(CouleurLigne);
    }
    Rect AffectCurveTo( Vec2D(XCurv+65,(YCurv+560)),Vec2D(200,30));
    AffectCurveTo.SetRoundness(15);
    AffectCurveTo.SetLineWidth(epaisseur_ligne_fader);

    AffectCurveTo.DrawOutline(CouleurLigne);
    petitchiffre.Print("AFFECT CURVE TO",XCurv+90, YCurv+572);
    petitchiffre.Print("SELECTED DIMMERS",XCurv+90, YCurv+585);
    return(0);
}
