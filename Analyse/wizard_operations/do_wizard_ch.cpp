int do_wizard_ch()
{
if(wizard_amplitude_is_global==1)
{
bool firstmem=0;
for(int m=0;m<10000;m++)
{
if(MemoiresExistantes[m]==1 && firstmem==0)
{
firstmem=1;
wizard_from_mem=m;
}
if(MemoiresExistantes[m]==1 && firstmem!=0)
{
wizard_to_mem=m;
}
}
}


switch(wizard_action) // 0 Set at level / 1 Add / 2 Reduce / 3 replace
{
case 0://Set at level
for(int m=wizard_from_mem;m<=wizard_to_mem;m++)
{
if(MemoiresExistantes[m]==1)
{
for(int co=1;co<512;co++)
{
if(wizard_buffer_in[co]==1)
{
switch(dmx_view)
{
case 0:
if(wizard_level_is>0)
{
Memoires[m][co]=(int)(((float)wizard_level_is)*2.55)+1;
}
else if(wizard_level_is==0)
{
Memoires[m][co]=0;
}
break;
case 1:
Memoires[m][co]=wizard_level_is;
break;
default: break;
}
}
}
}
}
break;
case 1://Add
for(int m=wizard_from_mem;m<=wizard_to_mem;m++)
{
if(MemoiresExistantes[m]==1)
{
for(int co=1;co<512;co++)
{
if(wizard_buffer_in[co]==1)
{
if(Memoires[m][co]>0)//on ne rajoute pas sur un circuit à 0%
{
switch(dmx_view)
{
case 0:
if(Memoires[m][co]+(int)((((float)wizard_level_is)*2.55)+1) <=255)
{
Memoires[m][co]+=(int)((((float)wizard_level_is)*2.55)+1);
}
else {Memoires[m][co]=255;}
break;
case 1:
if(Memoires[m][co]+wizard_level_is<=255)
{
Memoires[m][co]+=wizard_level_is;
}
else  {Memoires[m][co]=255;}
break;
default: break;
}
}
}
}
}
}
break;
case 2://Reduce
for(int m=wizard_from_mem;m<=wizard_to_mem;m++)
{
if(MemoiresExistantes[m]==1)
{
for(int co=1;co<512;co++)
{
if(wizard_buffer_in[co]==1)
{
if(Memoires[m][co]>0)//on ne retire pas sur un circuit à 0%
{
switch(dmx_view)
{
case 0:
if(Memoires[m][co]-(int)((((float)wizard_level_is)*2.55)+1)>=0)
{
Memoires[m][co]-=(int)((((float)wizard_level_is)*2.55)+1);
}
else {Memoires[m][co]=0;}
break;
case 1:
if(Memoires[m][co]-wizard_level_is>=0)
{
Memoires[m][co]-=wizard_level_is;
}
else {Memoires[m][co]=0;}
break;
default: break;
}
}
}
}
}
}
break;
case 3://Exchange Replace
unsigned char tmp_buff_wiz[514];
bool please_replace[514];

for(int m=wizard_from_mem;m<=wizard_to_mem;m++)
{
if(MemoiresExistantes[m]==1)
{
int index_replace=0;
for(int co=1;co<513;co++)
{
please_replace[co]=0;
tmp_buff_wiz[co]=0;

if(wizard_buffer_in[co]==1)
{
tmp_buff_wiz[co]=Memoires[m][co];
please_replace[co]=1;
Memoires[m][co]=0;
strcpy(descriptif_projecteurs[co],"");
}
}
int index_nbre_circuit=0;

for(int co=1;co<513;co++)
{
if(wizard_buffer_out[co]==1)
{
for(int p=index_replace;p<513;p++)
{
        if(number_inchannels==number_outchannels)
        {
                         if(please_replace[p]==1)
                         {
                         Memoires[m][co]=tmp_buff_wiz[p];
                         please_replace[p]=0;
                         break;
                         }
        }

        else if(number_inchannels<number_outchannels )
        {

                        if(please_replace[p]==1)
                        {
                        Memoires[m][co]=tmp_buff_wiz[p];
                        index_nbre_circuit++;
                        if(index_nbre_circuit<number_inchannels)
                        {
                        please_replace[p]=0;
                        break;
                        }
                        }
        }
}
}
}
}
}




break;
case 4:
bool swapIN[514];
bool swapOUT[514];
unsigned char tmp_buff_mem[514];
for(int m=wizard_from_mem;m<=wizard_to_mem;m++)
{
if(MemoiresExistantes[m]==1)
{
for(int co=1;co<513;co++)
{
tmp_buff_mem[co]=Memoires[m][co];
swapIN[co]=wizard_buffer_in[co];
swapOUT[co]=wizard_buffer_out[co];
}
for(int co=1;co<513;co++)
{
if(swapIN[co]==1)
{
for(int t=1;t<513;t++)
{
if(swapOUT[t]==1)
{
Memoires[m][co]=tmp_buff_mem[t];
swapOUT[t]=0;break;
}
}
}
}
for(int co=1;co<513;co++)
{
swapOUT[co]=wizard_buffer_out[co];
}
for(int co=1;co<513;co++)
{
if(swapOUT[co]==1)
{
for(int t=1;t<513;t++)
{
if(swapIN[t]==1)
{
Memoires[m][co]=tmp_buff_mem[t];
swapIN[t]=0;break;
}
}
}
}

}
}



break;
default: break;
}

refresh_stage();


 return(0);
}
