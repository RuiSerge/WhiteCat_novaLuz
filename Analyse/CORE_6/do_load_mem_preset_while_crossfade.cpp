int do_load_mem_preset_while_crossfade(int mem_is)
{
    index_go=0;
    index_pause=0;
    index_go_back=0;
    for (int op=1; op<514; op++)
    {
        bufferSaisie[op]=bufferSequenciel[op];
    }
    niveauX1=255;
    niveauX2=0;
    crossfade_speed=64;
    position_preset=mem_is;
    refresh_mem_onpreset(mem_is);
    prepare_crossfade();
    floatX1=niveauX1;
    floatX2=niveauX2;
    index_go=1;
    refresh_integrated_gridplayer1();
    return(0);
}
