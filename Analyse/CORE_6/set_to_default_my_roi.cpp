int set_to_default_my_roi(int dkprpreset, int dkpr)
{
    if(dkpr<6)
    {
        tracking_coordonates[dkprpreset][dkpr][0]=25+(40*dkpr);//x
        tracking_coordonates[dkprpreset][dkpr][1]=100;//y
        tracking_coordonates[dkprpreset][dkpr][2]=25;//largeur
        tracking_coordonates[dkprpreset][dkpr][3]=25;//hauteur
    }
    else if(dkpr>=6)
    {
        tracking_coordonates[dkprpreset][dkpr][0]=25+(40*(dkpr-6));//x
        tracking_coordonates[dkprpreset][dkpr][1]=150;//y
        tracking_coordonates[dkprpreset][dkpr][2]=25;//largeur
        tracking_coordonates[dkprpreset][dkpr][3]=25;//hauteur
    }

    for(int affe=1; affe<512; affe++)//�tait 513 aout 2016
    {
        tracking_contents[dkprpreset][dkpr][affe]=0;
    }
    return(0);
}
