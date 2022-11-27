int MoveCloseBox(int xmv,int ymv, int idwindow)
{

    Circle CloseBox(Vec2D(xmv,ymv),15);
    Circle MoveBox(Vec2D(xmv+40,ymv),15);
    if(window_focus_id==idwindow)
    {
        if(mouse_y>ymv-15 && mouse_y<ymv+15)
        {
            if(mouse_x>xmv-15 && mouse_x<xmv+15)
            {
                CloseBox.Draw(CouleurSurvol);
            }
            else if(mouse_x>xmv+40-15 && mouse_x<xmv+40+15)
            {
                MoveBox.Draw(CouleurSurvol);
                if((mouse_button==1 && mouse_released==0)|| mouse_released==1)
                {
                    MoveBox.Draw(CouleurFader);
                }

            }
        }
    }
    //close draw
    Line (Vec2D(xmv-5,ymv-5),Vec2D(xmv+5,ymv+5)).Draw(CouleurLigne);
    Line (Vec2D(xmv+5,ymv-5),Vec2D(xmv-5,ymv+5)).Draw(CouleurLigne);
    //move draw
    petitchiffre.Print("M",xmv+40-5,ymv+3);
    CloseBox.DrawOutline(CouleurLigne);
    MoveBox.DrawOutline(CouleurLigne);
    return(0);
}
