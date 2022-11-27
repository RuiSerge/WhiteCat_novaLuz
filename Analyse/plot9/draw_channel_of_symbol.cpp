int draw_channel_of_symbol( int calc, int symb, int plotx, int ploty)
{



    Circle ChannelProp(Vec2D(plotx,ploty),12);
    switch( symbol_is_selected[calc][symb])
    {
    case 0:
        ChannelProp.Draw(CouleurPlotFill);
        break;
    case 1:
        ChannelProp.Draw(CouleurFader);
        break;
    default:
        break;
    }
    ChannelProp.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
    if(symbol_channel_is[calc][symb]<10)
    {
        petitchiffrenoir.Print(ol::ToString(symbol_channel_is[calc][symb] ), (int)(plotx-5),(int)(ploty+3));
    }
    else if(symbol_channel_is[calc][symb]>=10 && symbol_channel_is[calc][symb]<100)
    {
        petitchiffrenoir.Print(ol::ToString(symbol_channel_is[calc][symb] ), (int)(plotx-6),(int)(ploty+3));
    }
    else
    {
        petitchiffrenoir.Print(ol::ToString(symbol_channel_is[calc][symb] ), plotx-11,ploty+3);
    }

    return(0);
}
