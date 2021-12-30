  #include <stdio.h>
  #define max 100

    int asciiToBinary(int input) {
        int result = 0, i = 1, remainder;

        /// convert ascii to binary format
        while (input > 0) {
                remainder = input % 2;
                result = result + (i * remainder);
                input = input / 2;
                i = i * 10;
        }
        return(result);
  }
    int main() {
        int i,r, binary[max], temp[max], dataRec[max],sizeofArr = 0, finalArray[max];
        char input[max];
        int finalArraySizeCounter=0;


       /*FILE*fp;
        fp = fopen("Drive path\txtFile.txt","r");
      fgets( input, 100, fp );//line input
      fclose (fp);*/

        printf("Enter only 5 characters: ");
        for( i = 0; i <5; i++){
            scanf("%c",&input[i]);
        }
        for(i=0;input[i] != '\0';i++){
            int ch = input[i];
                binary[i]=asciiToBinary(ch);

        }

        for(i=0;input[i] != '\0';i++){

            sizeofArr++;
        }

        for(int x = 0; x<sizeofArr;x++){
           for(i=6; i>=0; i--){
            r = binary[x]%10;
        binary[x] = binary[x]/10;
          temp[i] = r;
        }

        for(i=0;i<=6;i++){
        finalArray[finalArraySizeCounter]=temp[i];
        finalArraySizeCounter++;
        }


    }


    ///Finding redundent bit

   int dataword[100],j=0;


    int r1 = 0, r2 = 1,r4 = 3, r8 = 7,k; //redundent bit pos
    int d3 = 2, d5 = 4,d6 = 5, d7 = 6,d9 = 8, d10 = 9,d11 = 10; //data bit pos

    for(k =0; k < sizeofArr;k++){

        for(i=r1; i<=(r1+10);i++){
        if(i==r1 || i==r2 || i==r4 || i==r8){
            dataword[i]=0;

        }
          else{
            dataword[i]=finalArray[j];
            j++;
            }
        }





        dataword[r1] = dataword[d3]^dataword[d5]^dataword[d7]^dataword[d9]^dataword[d11];
        dataword[r2] = dataword[d3]^dataword[d6]^dataword[d7]^dataword[d10]^dataword[d11];
        dataword[r4] = dataword[d5]^dataword[d6]^dataword[d7];
        dataword[r8] = dataword[d9]^dataword[d10]^dataword[d11];



        r1+=11;
        r2+=11;
        r4+=11;
        r8+=11;

        d3+=11;
        d5+=11;
        d6+=11;
        d7+=11;
        d9+=11;
        d10+=11;
        d11+=11;

    }

    ///Print Data words
        printf("\nData words : \n");
        for(i=0;i<finalArraySizeCounter;i++){
            if(i%7==0){
                printf("  ");
            }
            printf("%d ",finalArray[i]);
        }

        ///Print Code Words
        printf("\n\nCode words : \n");
         for(i=0;i<=((10*sizeofArr)+(sizeofArr-1));i++){
            if(i%11==0){
                printf("  ");
            }
            printf("%d ",dataword[i]);

        }



    ///Error detect

    int errorPos = 0;
    int p1=0, p2=0, p4=0, p8=0;
    int bits;


    int dx1 = 0,dx2 = 1,dx3 = 2,dx4 = 3,dx5 = 4,dx6 = 5,dx7 = 6;
    int dx8 = 7,dx9 = 8,dx10 = 9,dx11 = 10;


    printf("\n\nHow many bits you have recieved: ");
    scanf("%d",&bits);

    printf("\n\nWhat  have you recieved enter bits one by one:\n");
    for(i=0; i < bits; i++){
      scanf("%d",&dataRec[i]);
    }

    for(k =0; k < sizeofArr;k++){

        p1 = dataRec[dx1]^dataRec[dx3]^dataRec[dx5]^dataRec[dx7]^dataRec[dx9]^dataRec[dx11];
        p2 = dataRec[dx2]^dataRec[dx3]^dataRec[dx6]^dataRec[dx7]^dataRec[dx10]^dataRec[dx11];
        p4 = dataRec[dx4]^dataRec[dx5]^dataRec[dx6]^dataRec[dx7];
        p8 = dataRec[dx8]^dataRec[dx9]^dataRec[dx10]^dataRec[dx11];


        if(p1==1 || p2==1 || p4==1 || p8==1){


            ///Error detection & corrections
            if(p1==1){
            errorPos += 1;
            }
            if(p2==1){
            errorPos += 2;
            }
            if(p4==1){
            errorPos += 4;
            }
            if(p8==1){
            errorPos += 8;
            }
            printf("\nError found at position %d",errorPos);

            if (dataRec[errorPos-1]==1){
                dataRec[errorPos-1]=0;
            }
            else{
                dataRec[errorPos-1]=1;
            }
            errorPos=((k+1)*11);
            printf("\n\nAfter Correction the bits are: \n");
            for(i=0; i <= ((10*sizeofArr)+(sizeofArr-1)); i++){
                if(i%11==0){
                printf(" ");
            }
                printf("%d ",dataRec[i]);
            }
        }
        else{
            printf("\n\nNo Error\n");
            errorPos+=11;
        }

    dx1+=11;
    dx2+=11;
    dx3+=11;
    dx4+=11;
    dx5+=11;
    dx6+=11;
    dx7+=11;
    dx8+=11;
    dx9+=11;
    dx10+=11;
    dx11+=11;
    }

        return 0;
  }

