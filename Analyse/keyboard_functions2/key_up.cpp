int key_up()
{

    switch(index_do_hipass)
    {
    case 0://mode normal

        if(index_blind==0)
        {

            for (int tc=1; tc<513; tc++) //était 514 aout 2016
            {
                if (Selected_Channel[tc]==1)
                {


                    if(index_crossfading==0)
                    {

                        if(dmx_view==1)
                        {
                            if(bufferSaisie[tc]+default_step_level<=255)
                            {
                                bufferSaisie[tc]+=default_step_level;
                            }
                        }
                        else if(dmx_view==0)
                        {
                            if( (bufferSaisie[tc]+(unsigned char)(default_step_level*2.55))<=255)
                            {
                                bufferPourcentStepdefaultlevel[tc]=(int) (((float)(bufferSaisie[tc]) /2.55))+default_step_level;
                                bufferSaisie[tc]=1+(unsigned char)(bufferPourcentStepdefaultlevel[tc]*2.55);
                            }
                            else if(bufferSaisie[tc]==254)
                            {
                                bufferSaisie[tc]=255;
                            }
                        }

                    }

                    else//index crossfading =1
                    {
                        channel_level_mofification_while_crossfade[tc]+=1;
                    }

                }
            }

        }

        else if (index_blind==1)//blind
        {

            for (int tb=1; tb<513; tb++) //etait 514 aout 2016
            {
                if (Selected_Channel[tb]==1)
                {

                    if(dmx_view==1)
                    {
                        if(bufferBlind[tb]+default_step_level<=255)
                        {
                            bufferBlind[tb]+=default_step_level;
                        }
                    }

                    else if(dmx_view==0)
                    {
                        if((bufferBlind[tb]+(unsigned char)(default_step_level*2.55))<=255)
                        {
                            bufferPourcentStepdefaultlevel[tb]=(int) (((float)(bufferBlind[tb]) /2.55))+default_step_level;
                            bufferBlind[tb]=1+(unsigned char)(bufferPourcentStepdefaultlevel[tb]*2.55);
                        }
                        else if(bufferBlind[tb]==254)
                        {
                            bufferBlind[tb]=255;
                        }
                    }


                }
            }
        }

        break;

    case 1://mode de modification discret des faders
        for (int i=1; i<513; i++)
        {

            if(Selected_Channel[i]==1)
            {

                FaderManipulating=highest_level_comes_from_fader[i]-1;
                if(DockTypeIs[FaderManipulating][dock_used_by_fader_is[FaderManipulating]]==0)//pas les contenus dynamiques, juste les circuits enregistrés on the fly
                {
                    if(dmx_view==0)
                    {

                        if( (FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i]  +(unsigned char)(default_step_level*2.55))<=255)
                        {
                            bufferPourcentStepdefaultlevel[i]=(int) (((float)(FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i]  ) /2.55))+default_step_level;
                            FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i]  =1+(unsigned char)(bufferPourcentStepdefaultlevel[i]*2.55);
                        }
                        else if(FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i]  ==254)
                        {
                            FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i]  =255;
                        }
                    }
                    else if (dmx_view==1)
                    {
                        if(FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i] +default_step_level<=255)
                        {
                            FaderDockContains[FaderManipulating][dock_used_by_fader_is[FaderManipulating]][i] +=default_step_level;
                        }
                    }
                }

            }
        }

        break;
    default:
        break;
    }
    index_level_attribue=1;//pour déselection lors prochain circuit piqué

    return(0);
}
