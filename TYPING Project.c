#include<stdio.h>
#include<string.h>
#include<time.h> //for time measurement (time_t , difftime)
#include<windows.h> //for sleep()
#include<ctype.h> //for tolower()

int main()
{
    char sentence[ ]="people so home child help only have point at first those much program  first run here place off a how day a move find then state up world or say hello world ";
    char input [1000];
    time_t start , end;

    printf("type the following sentence : \n\n");
    printf("%s\n\n",sentence);
    printf("starting in :\n\n");

    for(int i=3 ; i>=1 ; i--){
        printf("%d...\n",i);
        fflush(stdout);
        //using fflush(stdout); forces it to print immediately even if theres a delay after it
        //without this line out countdown might appear all at once after they delay - which looks wrong
        // with it each number prints one by one in real time
        Sleep(1000);
        // sleep() make to wait 1 second before showing next  number
    }
    printf("Go!\n\n");

    time(&start);//time() function stores the current time (in second)
    fgets(input , sizeof(input) , stdin); //its like starting a stopwatch before typing begins
    time(&end); //it will stop the stopwatch

    double time_taken= difftime(end , start);
    //difftime() returns the difference (in seconds) between two time_t values
    //example: if typing started at 10:00:00 and ended at 10:00:10.
    // ~~> time_taken =10.0 seconds
    int len=strlen(sentence);
    int len2=strlen(input);
    //remove trailing newline from input
    if(input[len2-1]=='\n'){
        input[len2-1]='\0';
        len2--;
    }
    //remove trailling spaces
    while(len2>0 && input[len2-1]==' '){
        input[len2-1]='\0';
        len2--;
    }

    int correct =0 ;
    for(int i=0 ; i<len && input[i]!='\0' ; i++){
        if(tolower(input[i])==tolower(sentence[i]))
            correct++;
    }

    double accuracy =((double)correct/len)*100.0 ;
    //accuracy =(correct characters / total characters) * 100;
    double wpm = (len2/5.0) / (time_taken/60.0);
    // A word is  roughly 5 characters [ standard rule ]
    // wpm= (total character /5 ) / (time in minitues)

    printf("\n____RESULT____\n");
    printf("Time taken: %.2lf seconds\n", time_taken);
    printf("Typing speed: %.2lf words per minitues (WPM) \n",wpm);
    printf("Accuracy : %.2lf%%\n",accuracy);
    // there are two % after lf because in printf() the percent % symbol is special
    // it tells printf that something ( line%d %f %s ) should beformatted
    // if we put only one % it wil give error
    //to print a real percent sign on the screen we must use %% .

    return 0 ;
}

