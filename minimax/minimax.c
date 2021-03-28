int ex[3][3];
int level=0;   //0==>O    1==>X


int complete()
{
    int zz=0;
    for (int i =0 ; i<3 ; i++)
        for (int j=0;j<3 ; j++)
        {
            if(ex[i][j] ==0)
                zz=1;
        }
    return !zz;
}

 int whoWin()
{
    int winn[8];
    for(int i=0;i<8;i++)
      winn[i]=0;
    for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
       {
           winn[i]+=ex[i][j];
           winn[i+3]+=ex[j][i];
           if(i==j)
              winn[6]+=ex[i][j];  
           if(i+j==2)
              winn[7]+=ex[i][j];
       }
    for(int i=0;i<8;i++)
         if(winn[i]==3)
            return 1;  //X win
         else if(winn[i]==-3)
            return -1;  //O win
        else
            return 0; //draw
      
}

int predict(int level)   // level:    0==>O    1==>X
{
    int m =0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            ex[i][j]=game[i][j];
        }


    int w=whoWin();
    if(w==-1 || w==1)
        return w;
    
    if(complete())
        return 0;

    
    
    if (!complete())
    {
        if(level==0)
        {
            m=999;
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                {
                    if(ex[i][j]==0)
                    {
                        ex[i][j]=-1;
                        int tmp=predict(!level);
                        if(tmp<m)
                            m=tmp;
                        ex[i][j]=0;
                    }
                }
            return m;
        }

        if(level==1)
        {
            m=-999;
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                {
                    if(ex[i][j]==0)
                    {
                        ex[i][j]=1;
                        int tmp=predict(!level);
                        if(tmp>m)
                            m=tmp;
                        ex[i][j]=0;
                    }
                } 
            return m;          
        }
    }
    
}