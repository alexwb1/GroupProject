
#include <string>

class Story{
    private:
        //Not sure if we need any private variables
    public:
      int getWeeklyValue(int totalMoney, int percent increase); //gets value to get random story of week
      void getWeeklyStory(int weeklyValue); //contains (options 1-5);
      void veryBadStory(); //(if weekLyValue = 1)
      void badStory();//(if weekLyValue = 2)
          void badstory1();
          void badstory2();
          void badstory3();
          void badstory4();
          void badstory5();
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
          void veryGoodStory1();
          void veryGoodStory2();
          void veryGoodStory3();
          void veryGoodStory4();
          void veryGoodStory5();
}

//BAD STORIES
void Story::badstory1(){
    cout << "You ought to take time to relax after such a hard day’s work. You decide to go to the nearest Olive Garden " << endl;
    cout << "with your true love and enjoy a fine dinner. When you are presented with the bill, you open your wallet " << endl;
    cout << "to find a single penny, but you aren’t worried for you have a debit card; however, it becomes absolutely obvious " << endl;
    cout << "that today’s work has went in vain as you and your true love learn that debit card has been declined." << endl;
    cout << endl;
}
void Story::badstory2(){
    cout << "You go home feeling unsure about the choices you've had made." << endl;
    cout << "You turn on the television and notice one of your assets being fudded" << endl;
    cout << "You watch in horror and disbelief as your assets plunge in value." << endl;
    cout << "You couldn't sleep that night knowing money has been lost." << endl;
    cout << endl;
}
void Story::badstory3(){
    cout << "You go home feeling confident that your assets will experience a moon today" << endl;
    cout << "You notice a black cat pass by you before coming home and start to feel unsure" << endl;
    cout << "Nervous and anxious, you turn on the daily stocks report and watch in absolute horror." << endl;
    cout << "Apparently a group of whales have dumped the assets in your portfolio!" << endl;
    cout << "You turn off the television in absolute denial and hope your portfolio will be untouched by this turn of events." << endl;
    cout << endl;
}
//NEUTRAL STORIES
void Story::neutralStory1(){
    cout << "In hindsight, you feel you've tried your best in the decisions you have made today." << endl;
    cout << "Surely you will make great gains with such precise planning and utilization of logic. Surely?" << endl;
    cout << "You decide to abstain from thinking about it any further as it makes you begin to doubt yourself" << endl;
    cout << "Although concerned, you were still able reassure yourself that you tried your best" << endl;
    cout << "and there was no wrong with your logic. You were able to to sleep easy with that in mind." << endl;
    cout << endl;
}
void Story::neutralStory2(){
    cout << "It is quite obvious that your recent losses have been quite rough. These exchanges can be quite unforgiving, but" << endl;
    cout << "in the long run, it is okay as every struggle is only temporary and can be ultimately overcomed." << endl;
    cout << "Afterall, atleast you can still afford to eat Ramen Noodles and watch cable television!" << endl;
    cout << "As the commercials on TV say \"Failure is just short for a postponed success! Never give up for that is what real failure is!\"" << endl;
    cout << "With such reassurance and motivation you tell yourself confidently, \"it can't possibly get any worse than this!\"" << endl;
    cout << endl;
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

//VERY GOOD STORIES
void Story::veryGoodStory1(){
    cout << "You tell yourself, \"it's great to be rich!\" as you ride your jet ski on nitro along the shores of Fiji." << endl;
    cout << "As you dry off on the beach beholding the awe inspiring sight of the beautiful sun set, you receive an anonymous phone call" << endl;
    cout << "\"Congraulations! You are officially a millionare and have been invited into the millionaire’s club!\"" << endl;
    cout << "Feeling like royalty, you then command your butler for more cavier. It simply cannot get any better than this! " << endl;
    cout << endl;
}

//Story at end of Game
void Story::endStory1(){
cout << "Congratulations!" << endl;
cout << "You have succeeded in making a large amount of profit." << endl;
cout << "As a result, you have decided to celebrate by buying a Lamborghini and a mansion on the water in Miami." << endl;
cout << "In addition, you invested the rest of your profits in a start-up that ended up exploding." << endl;
cout << "You are now a multi-millionaire and will live the rest of your life comfort." << endl;
}

void Story::endStory2(){
cout << "Although you did not become rich from the stock market, at least you made a decent amount of profit." << endl;
cout << "You decided to take your wife on vacation to Spain." << endl;
cout << "Additionally, your success in the market lead to increased confidence in the office, which resulted in a promotion." << endl;
cout << "Overall, you are happy with the results of your investments." << endl;
}

void Story::endStory3(){
cout << "You didn’t make any profit, but at least you didn’t loose any either." << endl;
cout << "You spent the last few months investing the majority of your time analyzing and investing in the stock market." << endl;
cout << "You got angry because you feel like you wasted your time, but your therapist advised you to start meditating." << endl;
cout << "You decided to might as well try at the market again, and hopefully make a profit the next time." << endl;
}

void Story::endStory4(){
cout << "Just like the majority of other novice investors, you ended up loosing a small amount of money." << endl;
cout << "Although you are angry that you don’t get to go on vacation any more, you are also thankful to not have lost your entire investment." << endl;
cout << "At the end of day, this experience was valuable to you, and you hope to use your new investing knowledge to make money in the future." << endl;

void Story::endStory5(){
cout << "You have very bad luck! You lost the majority of your investment." << endl;
cout << "When your wife found out you lost all the money, she decided to divorce you." << endl;
cout << "In addition, you lost your job due to recent depression." << endl;
cout << "Even though you lost everything that was important to you, at least you learned a valuable lesson… invest intelligently!" << endl;
