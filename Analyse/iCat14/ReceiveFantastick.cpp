int ReceiveFantastick()
{
if(fantastick_message[0]=='I' &&  fantastick_message[1] =='P')
{
 fantastick_message[bytesreceivediCat]='\0';
 sprintf(FS_IP,fantastick_message);
}


int fsid=0, fsx=0, fsy=0;

     if( fantastick_message[0]=='M' ||  fantastick_message[0]=='B' ||  fantastick_message[0]=='E'
     || fantastick_message[0]=='S'
     || fantastick_message[0]=='A' ||  fantastick_message[0]=='X')
     {
      fantastick_message[bytesreceivediCat]='\0';
      sprintf(FS_BUFFER,fantastick_message);
      switch( fantastick_message[0])
      {
      case 'A':
      sscanf(FS_BUFFER,"A %f %f %f",&fs_accelerometer[0],&fs_accelerometer[1],&fs_accelerometer[2]);
      break;

      case 'B':
      sscanf(FS_BUFFER,"B %d %d %d",&fsx, &fsy, &fsid);
      FS_touch_point_begin[0][fsid-1]=fsx;
      FS_touch_point_begin[1][fsid-1]=fsy;
      FS_touch_point_move[0][fsid-1]=fsx;
      FS_touch_point_move[1][fsid-1]=fsy;
      break;
      case 'M':
      sscanf(FS_BUFFER,"M %d %d %d",&fsx, &fsy, &fsid);
      FS_touch_point_move[0][fsid-1]=fsx;
      FS_touch_point_move[1][fsid-1]=fsy;
      break;
      case 'S':
      sscanf(FS_BUFFER,"S %d %d %d",&fsx, &fsy, &fsid);
      FS_touch_point_stationnary[0][fsid-1]=fsx;
      FS_touch_point_stationnary[1][fsid-1]=fsy;
      break;
      case 'E':
      sscanf(FS_BUFFER,"E %d %d %d",&fsx, &fsy, &fsid);
      FS_touch_point_end[0][fsid-1]=fsx;
      FS_touch_point_end[1][fsid-1]=fsy;
      for(int t=0;t<iCat_nbre_de_sliders[iCatPageis]+1;t++)
      {
      if(slider_is_controlled_by_point[iCatPageis][t]==fsid-1)
      {
      slider_is_touched[iCatPageis][t]=0;
      slider_is_controlled_by_point[iCatPageis][t]=0;
      //reset du touch
      FS_touch_point_begin[0][fsid-1]=-999;
      FS_touch_point_begin[1][fsid-1]=-999;
      FS_touch_point_move[0][fsid-1]=-999;
      FS_touch_point_move[1][fsid-1]=-999;
      }
      }
      break;
      case 'X':
      sscanf(FS_BUFFER,"X %d",&nbre_icat_points_detectes);
      if(nbre_icat_points_detectes==0)
      {
      for(int p=0;p<fs_max_points+1;p++)
      {
      FS_touch_point_begin[0][p]=-999;
      FS_touch_point_begin[1][p]=-999;
      FS_touch_point_move[0][p]=-999;
      FS_touch_point_move[1][p]=-999;
      FS_touch_point_end[0][p]=-999;
      FS_touch_point_end[1][p]=-999;
      }
      }

      before_nbre_icat_points_detectes=nbre_icat_points_detectes;
      break;
      default: break;
      }
     }


 return(0);
}
