int Receive_DMX_IN()
{
if(do_DMX_out[4]==1 ) //sunlite
{
Receive_sunlite_dmxIN();
}

else if (index_init_EnttecPROIN_ok==1 && do_DMX_out[4]==0)
{
resIn=Enttec_Pro_ReceiveData(SET_DMX_RX_MODE,dmxIN,513); //etait en 513
if(resIn<0)
            {
            sprintf(string_Last_Order,"DMX IN from ENTTEC PRO  FAILED");
            }
 }

return(0);
}
