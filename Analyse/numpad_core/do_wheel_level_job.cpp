int do_wheel_level_job(int levelwheelis)
{
unsigned char your_level_is;

switch(wheellevel_absolutemode)
    {
    case 0://relatif
        if(levelwheelis<64){ simulate_keypress(KEY_UP<<8);}
        else if(levelwheelis>64){ simulate_keypress(KEY_DOWN<<8);}
    break;
    case 1://absolute , on récupère de toute facon le niveau midi comme base
        your_level_is=(int)((((float)levelwheelis)/127)*255);
        switch(index_do_hipass)
        {
        case 0://mode normal
            for (int tc=1;tc<514;tc++)
            {
            if (Selected_Channel[tc]==1 && index_blind==0)
            {
            bufferSaisie[tc]=your_level_is;
            }
            else if (Selected_Channel[tc]==1 && index_blind==1)
            {
            bufferBlind[tc]=your_level_is;
            }
            }
        break;
        case 1://mode hipass faders
            for (int i=1;i<513;i++)
            {
            if(Selected_Channel[i]==1)
            {
            FaderManipulating=highest_level_comes_from_fader[i]-1;
            if(DockTypeIs[FaderManipulating][dock_used_by_fader_is[FaderManipulating]]==0)//pas les contenus dynamiques, juste les circuits enregistrés on the fly
            {
            FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i]  =your_level_is;
            }
            }
            }
        break;
        default: break;
        }
        absolute_level_wheel=your_level_is;
    break;
    default: break;
    }
return(0);
}
