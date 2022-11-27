int Save_Arduino_Config()//pas en user mais dans un spectacle
{
    FILE *fpp;
    if((fpp=fopen("arduino.txt","w")))//etait wb
    {
        fprintf(fpp,"#arguments:COM PORT / BAUDRATE / REQUEST RATE / MAX IO / MAX ANALOG /\n");
        fprintf(fpp, "%d / %d / %d / %d / %d /\n",  arduino_com0, arduino_baud_rate0, ARDUINO_RATE, arduino_max_digital, arduino_max_analog );
        fclose(fpp);
        sprintf(string_save_load_report[idf],"Saved arduino.txt");
    }
    if( !fpp )
    {
        sprintf(string_save_load_report[idf],"!arduino.txt");
    }


    return(0);
}
