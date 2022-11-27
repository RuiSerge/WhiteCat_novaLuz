int arduino_close(int device)
{
if(device==0)
{
 serial0.Close();
 sprintf(string_Arduino_status,">> Closed Arduino on PORT %d >> OK !",arduino_com0);
}

return(0);
}
