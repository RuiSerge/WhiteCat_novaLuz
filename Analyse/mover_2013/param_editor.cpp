int param_editor(int xt, int yt)
{
    neuromoyen.Print("Move Params", xt, yt-10);

    char string_para[5][16];
    sprintf(string_para[0],"X");
    sprintf(string_para[1],"Y");
    sprintf(string_para[2],"Iris");
    sprintf(string_para[3],"Focus");
    sprintf(string_para[4],"Zoom");
    for(int dv=0; dv<5; dv++)
    {
        Rect ParamN(Vec2D( xt+60,yt+5+(dv*15)),Vec2D(30,12));
        Rect LevelFrame(Vec2D(xt+180,yt+5+(dv*15)),Vec2D(255,10));
        LevelFrame.SetRoundness(5);
        if(window_focus_id==W_MOVER && index_do_dock==1 && mouse_x>xt+60 && mouse_x<xt+60+30 && mouse_y>yt+5+(dv*15) && mouse_y<yt+5+(dv*15)+10  && mouse_button==1 && mouse_released==0)
        {
            ParamN.Draw(CouleurBlind);

            int adress_to_attribute=atoi(numeric);
            if(adress_to_attribute>0 && adress_to_attribute<513)
            {

                mover_params_adresses[dv]=adress_to_attribute;
                switch(dv)
                {
                case 0:
                    xadress=adress_to_attribute;
                    break;
                case 1:
                    yadress=adress_to_attribute;
                    break;
                case 2:
                    irisadress=adress_to_attribute;
                    break;
                case 3:
                    focusadress=adress_to_attribute;
                    break;
                case 4:
                    zoomadress=adress_to_attribute;
                    break;
                default:
                    break;
                }
                reset_mover_buffer();
                reset_numeric_entry();
                numeric_postext=0;
                mouse_released=1;
            }

        }


        minichiffre.Print(string_para[dv], xt, yt+15+(dv*15));
        int v_tmp=0;
        switch(dv)
        {
        case 0:
            minichiffre.Print(ol::ToString(xadress), xt+65,yt+15+(dv*15));
            if(tracker_16b_edit==0)
            {
                v_tmp=mover_params[0][0];
            }
            else
            {
                v_tmp=mover_params[0][1];
            }

            break;
        case 1:
            minichiffre.Print(ol::ToString(yadress), xt+65,yt+15+(dv*15));
            if(tracker_16b_edit==0)
            {
                v_tmp=mover_params[1][0];
            }
            else
            {
                v_tmp=mover_params[1][1];
            }
            break;
        case 2:
            minichiffre.Print(ol::ToString(irisadress), xt+65,yt+15+(dv*15));
            if(tracker_16b_edit==0)
            {
                v_tmp=mover_params[2][0];
            }
            else
            {
                v_tmp=mover_params[2][1];
            }
            break;
        case 3:
            minichiffre.Print(ol::ToString(focusadress), xt+65, yt+15+(dv*15));
            if(tracker_16b_edit==0)
            {
                v_tmp=mover_params[3][0];
            }
            else
            {
                v_tmp=mover_params[3][1];
            }
            break;
        case 4:
            minichiffre.Print(ol::ToString(zoomadress), xt+65, yt+15+(dv*15));

            if(tracker_16b_edit==0)
            {
                v_tmp=mover_params[4][0];
            }
            else
            {
                v_tmp=mover_params[4][1];
            }
            break;
        default:
            break;
        }
        ParamN.DrawOutline(CouleurLigne);
        Rect Level(Vec2D(xt+180,yt+5+(dv*15)),Vec2D(v_tmp,10));
        Level.SetRoundness(5);
        Level.Draw(CouleurFader.WithAlpha(0.7));
        LevelFrame.DrawOutline(CouleurLigne.WithAlpha(0.3));

        sprintf(string_param_mover_is,"%d %d", mover_params[dv][0], mover_params[dv][1]);
        minichiffre.Print(string_param_mover_is,xt+110,  yt+15+(dv*15));


        if(window_focus_id==W_MOVER && mouse_x> xt+180-10 && mouse_x< xt+180+255+10 && mouse_y>=yt+5+(dv*15) && mouse_y<yt+5+(dv*15)+10 && mouse_button==1)
        {
            set_mouse_range(xt+180-10,yt+5+(dv*15), xt+180+255+10, yt+5+(dv*15)+10);//liberation du curseur souris
            int valeur=mouse_x-(xt+180-10);
            valeur=constrain_data_to_dmx_range(valeur);
            switch(dv)
            {
            case 0:
                if(tracker_16b_edit==0)
                {
                    mover_params[0][0]=valeur;
                }
                else //fine
                {
                    mover_params[0][1]=valeur;
                }
                break;

            case 1:
                if(tracker_16b_edit==0)
                {
                    mover_params[1][0]=valeur;
                }
                else //fine
                {
                    mover_params[1][1]=valeur;
                }
                break;

            case 2:
                if(tracker_16b_edit==0)
                {
                    mover_params[2][0]=valeur;
                }
                else //fine
                {
                    mover_params[2][1]=valeur;
                }
                break;

            case 3:
                if(tracker_16b_edit==0)
                {
                    mover_params[3][0]=valeur;
                }
                else //fine
                {
                    mover_params[3][1]=valeur;
                }
                break;

            case 4:
                if(tracker_16b_edit==0)
                {
                    mover_params[4][0]=valeur;
                }
                else //fine
                {
                    mover_params[4][1]=valeur;
                }
                break;
            default:
                break;
            }
        }
        if(dv>=2)
        {
            Rect AllowCopyParams(Vec2D(xt+445,yt+5+(dv*15)),Vec2D(10,10));
            AllowCopyParams.Draw(CouleurFader.WithAlpha(param_selected[dv]));
            AllowCopyParams.DrawOutline(CouleurLigne.WithAlpha(0.3));
            if(window_focus_id==W_MOVER && mouse_x>xt+445 && mouse_x<xt+445+10 && mouse_y>yt+5+(dv*15) && mouse_y<yt+5+(dv*15)+10 && mouse_button==1 && mouse_released==0)
            {
                param_selected[dv]=toggle(param_selected[dv]);
                mouse_released=1;
            }
        }

    }


    Rect ShiftIris(Vec2D(xt+5,yt+130),Vec2D(100,20));
    ShiftIris.SetRoundness(4);
    ShiftIris.Draw(CouleurFader.WithAlpha(index_copy_params));
    ShiftIris.DrawOutline(Rgba::WHITE);
    petitchiffre.Print("Set To Bank",xt+15, yt+143);


    if(window_focus_id==W_MOVER && mouse_x>xt+5 && mouse_x<xt+5+100 && mouse_y>yt+130 && mouse_y<yt+130+20)
    {
        if(mouse_button==1  && index_mouse_is_tracking==0 && mouse_released==0 )
        {
            index_copy_params=toggle(index_copy_params);
            mouse_released=1;
        }
    }





    return(0);
}
