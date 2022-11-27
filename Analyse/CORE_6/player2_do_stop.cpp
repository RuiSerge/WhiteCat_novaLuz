int player2_do_stop()//fade out to avoid clipping in sound when stopping
{
float value_lecteur=(((float)player_niveauson[1])/127);
for(float i=value_lecteur*30; i>0.0;i--)
{
if(i>=0.0){player2->setVolume(i/30);}
}
player2->setVolume(0.0);
player2->stop();
for(float i=value_lecteur*30; i<1.0;i++)
{
if(i<1.0){player2->setVolume(i/30);}
}
player2->setVolume(value_lecteur);
return(0);
}
