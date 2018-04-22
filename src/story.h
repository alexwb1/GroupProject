
#include <string>

class Story{
    private:
        //Not sure if we need any private variables
    public:
      int getWeeklyValue(int totalMoney, int percent increase); //gets value to get random story of week
      void getWeeklyStory(int weeklyValue); //contains (options 1-5);
      void veryBadStory(); //(if weekLyValue = 1)
      void badStory();//(if weekLyValue = 2)

      void neutralStory();//(if weekLyValue = 3) selects 1 of 5 neutral stories
          void neutralStory1();
          void neutralStory2();
          void neutralStory3();
          void neutralStory4();
          void neutralStory5();
      void goodStory();//(if weekLyValue = 4)
          void goodStory1();
          void goodStory2();
          void goodStory3();
          void goodStory4();
          void goodStory5();
      void veryGoodStory();//(if weekLyValue = 5)
}

//NEUTRAL STORIES
void Story::neutralStory1(){
    cout << "In hindsight, you feel you've tried your best in the decisions you have made today." << endl;
    cout << "Surely you will make great gains with such precise planning and utilization of logic. Surely?" << endl;
    cout << "You decide to abstain from thinking about it any further as it makes you begin to doubt yourself" << endl;
    cout << "Although concerned, you were still able reassure yourself that you tried your best" << endl;
    cout << "and there was no wrong with your logic. You were able to to sleep easy with that in mind." << endl;
    cout << end
}

//GOOD STORIES
void Story::goodStory1(){
    cout << "Today was a good day. Absolutely nothing could make it go wrong." << endl;
    cout << "You go home knowing that the universe is on your side. Atleast for the time being." << endl;
    cout << "Due to your excitement, you were unable to sleep. Anxious and impatient, you check your portfolio on your phone." << endl;
    cout << "You are then greeted with flashes of bright green and an euphoria like no other encompases you." << endl;
    cout << endl;
}
void Story::goodStory2(){
    cout << "You go home feeling good about the choices you've had made." << endl;
    cout << "You turn on the television and watch the daily stocks report." << endl;
    cout << "It seems things are going your way today!" << endl;
    cout << "You were able to sleep easy that night knowing you have made gains." << endl;
    cout << endl;
}
