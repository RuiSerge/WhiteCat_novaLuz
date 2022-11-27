int print_time_reperes(int the_time_wheel_datatype)//affichage des chiffres sur le tableau de bord
{

    if(the_time_wheel_datatype==1 || the_time_wheel_datatype==0 )//SECONDES OR MINUTES
    {
        petitpetitchiffre.Print("0",xtime_window+246,ytime_window+149);
        petitpetitchiffre.Print("3",xtime_window+244,ytime_window+185);
        petitpetitchiffre.Print("5",xtime_window+231,ytime_window+205);
        petitpetitchiffre.Print("7",xtime_window+217,ytime_window+224);
        petitpetitchiffre.Print("10",xtime_window+196,ytime_window+233);
        petitpetitchiffre.Print("15",xtime_window+140,ytime_window+249);
        petitpetitchiffre.Print("20",xtime_window+103,ytime_window+236);
        petitpetitchiffre.Print("25",xtime_window+65,ytime_window+205);
        petitpetitchiffre.Print("30",xtime_window+46,ytime_window+159);
        petitpetitchiffre.Print("35",xtime_window+52,ytime_window+112);
        petitpetitchiffre.Print("40",xtime_window+82,ytime_window+69);
        petitpetitchiffre.Print("45",xtime_window+126,ytime_window+48);
        petitpetitchiffre.Print("50",xtime_window+166,ytime_window+55);
        petitpetitchiffre.Print("55",xtime_window+215,ytime_window+77);
        petitpetitchiffre.Print("59",xtime_window+241,ytime_window+118);
    }
    if(the_time_wheel_datatype==2)//dixiemes
    {
        petitpetitchiffre.Print("00",xtime_window+246,ytime_window+147);
        petitpetitchiffre.Print("10",xtime_window+228,ytime_window+208);
        petitpetitchiffre.Print("20",xtime_window+178,ytime_window+242);
        petitpetitchiffre.Print("30",xtime_window+119,ytime_window+242);
        petitpetitchiffre.Print("40",xtime_window+71,ytime_window+213);
        petitpetitchiffre.Print("50",xtime_window+47,ytime_window+160);
        petitpetitchiffre.Print("60",xtime_window+58,ytime_window+99);
        petitpetitchiffre.Print("70",xtime_window+97,ytime_window+59);
        petitpetitchiffre.Print("80",xtime_window+154,ytime_window+46);
        petitpetitchiffre.Print("90",xtime_window+210,ytime_window+69);
    }
    return(0);
}
