int reset_indexes_conf()//menu setup cfg
{
    index_config_general=0;
    index_config_dmx=0;
    index_config_midi=0;
    index_config_network=0;
    index_setup_gfx=0;
    index_config_arduino=0;
    index_config_core=0;
    index_affect_dmxin=0;
    Midi_Faders_Affectation_Type=0;//pour ne pas affecter quoi que ce soit en midi
    Midi_Faders_Affectation_Mode=0;
    //do_affectation_on_midi_affect_itself=0;//pour affectation midi on itself
    return(0);
}
