
#include <string>

class Story{
    private:
        //Not sure if we need any private variables
        string name; //Is the player's name
    public:
      Story(string name);
      int getWeeklyValue(int totalMoney, int percent increase); //gets value to get random story of week
      void getWeeklyStory(int weeklyValue); //contains (options 1-5);
      void veryBadStory(); //(if weekLyValue = 1)
          void veryBadStory1();
          void veryBadStory2();
          void veryBadStory3();
          void veryBadStory4();
          void veryBadStory5();
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
//Story constructor
Story::Story(string name){
  this->name = name;
}

//VERY BAD
void Story::veryBadStory1(){
    std::cout << "You feel uneasy about the decisions you have made. There are many signs that you have picked up" << std::endl;
    std::cout << "that your portfolio is going to suffer some detrimental losts. You decide to avoid the thought." << std::endl;
    std::cout << "You close your eyes to relax, but see a demonic entity appear in the abyss!" << std::endl;
    std::cout << "An omen of something terrible to occurs to you!" << std::endl;


}
void Story::veryBadStory2(){
  std::cout << "You tell yourself, \""<< name << ", it really sucks to be poor!\" as you eat cheap sushi for dinner." << std::endl;
  std::cout << "Your assets will eventually improve, right? The doubt of that thought makes you uncomfortable." << std::endl;
  std::cout << "You attempt to reassure yourself by watching the daily stocks on television, but without success" << estd::endl;
  std::cout << "Unfortunately, this miserable existence called life will continue to be miserable. When will it ever end?" << std::endl;
  std::cout << std::endl;
}
void Story::veryBadStory3(){
  std::cout << "You ought to take time to relax after such a hard day’s work. You decide to go to the nearest Olive Garden " << std::endl;
  std::cout << "with your true love and enjoy a fine dinner. When you are presented with the bill, you open your wallet " << std::endl;
  std::cout << "to find a single penny, but you aren’t worried for you have a debit card; however, it becomes absolutely obvious " << std::endl;
  std::cout << "that today’s work has went in vain as you and your true love learn that debit card has been declined." << std::endl;
  std::cout << std::endl;
}
void Story::veryBadStory4(){
    std::cout << "It is quite obvious that your recent losts have been quite rough. These exchanges can be quite unforgiving, but" << std::endl;
    std::cout << "in the long run, it is okay as every struggle is only temporary and can be ultimately overcomed." << std::endl;
    std::cout << "Afterall, atleast you can still afford to eat Ramen Noodles and watch cable television!" << std::endl;
    std::cout << "As the commercials on TV say \"Failure is just short for a postponed success! Never give up for that is what real failure is!\"" << std::endl;
    std::cout << "With such reassurance and motivation you tell yourself confidently, \"it can't possibly get any worse than this!\"" << std::endl;
    std::cout << std::endl;
}
void Story::veryBadStory5(){
    std::cout << "You have become so poor that you can't even afford to pay attention to your assets anymore." << std::endl;
    std::cout << "There is only one thing that matters and its food. You try credit with every vending machine but ultimately fail." << std::endl;
    std::cout << "Your credit card has basically been deactivated at this point. You give up and go home hungry." << std::endl;
    std::cout << "You are unable to sleep, hungry and afraid of what will remain of your assets tomorrow." << std::endl;
    std::cout << "You finally muster up the courage to check your portfolio on your phone. You are greeted with a flash of bright" << std::endl;
    std::cout << "red before tossing your phone out the window in disbelief. Absolutely broken and unable to sleep, you silently sit" << std::endl;
    std::cout << "until you notice a cockroach eating a crum right beside you...     dinner." << std::endl;
    std::cout << std::endl;
}
//BAD STORIES
void Story::badstory1(){
  cout << "In hindsight, you feel you've tried your best in the decisions you have made today." << endl;
  cout << "Surely you will make great gains with such precise planning and utilization of logic. Surely?" << endl;
  cout << "Suddenly, you come to a terrifying realization that you have actually done the opposite of what you had set out to do!" << endl;
  cout << "You had confused the word pump with dump! You undergo a panic attack in your bedroom, and black out from the stress." << endl;

}
void Story::badstory2(){
    std::cout << "You go home feeling unsure about the choices you've had made." << std::endl;
    std::cout << "You turn on the television and notice one of your assets being fudded" << std::endl;
    std::cout << "You watch in horror and disbelief as your assets plunge in value." << std::endl;
    std::cout << "You couldn't sleep that night knowing money has been lost." << std::endl;
    std::cout << std::endl;std::
}
void Story::badstory3(){
    std::cout << "You go home feeling confident that your assets will experience a moon today" << std::endl;
    std::cout << "You notice a black cat pass by you before coming home and start to feel unsure" << std::endl;
    std::cout << "Nervous and anxious, you turn on the daily stocks report and watch in absolute horror." << std::endl;
    std::cout << "Apparently a group of whales have dumped the assets in your portfolio!" << std::endl;
    std::cout << "You turn off the television in absolute denial and hope your portfolio will be untouched by this turn of events." << std::endl;
    std::cout << std::endl;
}
void Story::badStory4(){
    std::cout << "Today was a good day. Absolutely nothing could make it go wrong." << std::endl;
    std::cout << "You go home knowing that the universe is on your side. Atleast for the time being." << std::endl;
    std::cout << "Due to your excitement, you were unable to sleep. Anxious and impatient, you check your portfolio on your phone." << std::endl;
    std::cout << "You are then greeted with flashes of bright red and your heart sinks. You quickly turn off your phone in disbelief." << std::endl;
    std::cout << "Coming into terms with reality, you were unable to sleep knowing you have made some losts." << std::endl;
    std::cout << std::endl;
}
void Story::badStory5(){
  cout << "Sometimes its worth taking risks if the rewards are high enough. Afterall," << endl;
  cout << "all rich people have taken risks to get to where they are!" << endl;
  cout << "However such thinking doesn't feel reassuring right now. You feel like an absolute beta male tonight" << endl;
  cout << "You go to mid town to forget your troubles. Unfortunately you get knocked out and thrown in some allyway. " << endl;
  cout << "A sign that things are not currently in your favor!" << endl;
  cout << endl;
}


//NEUTRAL STORIES
void Story::neutralStory1(){
    std::cout << "In hindsight, you feel you've tried your best in the decisions you have made today." << std::endl;
    std::cout << "Surely you will make great gains with such precise planning and utilization of logic. Surely?" << std::endl;
    std::cout << "You decide to abstain from thinking about it any further as it makes you begin to doubt yourself" << std::endl;
    std::cout << "Although concerned, you were still able reassure yourself that you tried your best" << std::endl;
    std::cout << "and there was no wrong with your logic. You were able to to sleep easy with that in mind." << std::endl;
    std::cout << std::endl;
}
void Story::neutralStory2(){
    std::cout << "You feel quite pleased with how your portfolio is turning out; however," << std::endl;
    std::cout << "you are slightly worried that something may go wrong; terribly wrong." << std::endl;
    std::cout << "You quickly check your portfolio on your phone and feel reassured!" << std::endl;
    std::cout << "Your assets are in decent shape, but you now recognize you are not invincible." << std::endl;
    std::cout << std::endl;
}
void Story::neutralStory3(){
    std::cout << "Sometimes its worth taking risks if the rewards are high enough. Afterall," << std::endl;
    std::cout << "all rich people have taken risks to get to where they are!" << std::endl;
    std::cout << "It shouldn't be any differnt with you! You feel like an absolute alpha male tonight" << std::endl;
    std::cout << "You go to mid town and have the time of your life. You get absolutely wasted! " << std::endl;
    std::cout << std::endl;
}
void Story::neutralStory4(){
    std::cout << "Unsure of how your assets will fair you decide it be best to abstain from thinking about it" << std::endl;
    std::cout << "Such stress will only jinx your portfolio! You decide to go party in midtown to distract yourself" << std::endl;
    std::cout << "You end up having a blast and get wasted. You have essentially rid yourself of anything remotely" << std::endl;
    std::cout << "to do with your fiancial situation. It probably be for the best." << std::endl;
    std::cout << std::endl;
}
void Story::neutralStory5(){
    std::cout << "You've tried to make the right decisions but the future seems uncertain" << std::endl;
    std::cout << "It could go wrong or it can go right; however, if it goes wrong" << std::endl;
    std::cout << "it will be possible to recover from such damages. It keeps your mind" << std::endl;
    std::cout << "calm knowing that you can withstand the potential losts." << std::endl;
    std::cout << std::endl;
}

//GOOD STORIES
void Story::goodStory1(){
    std::cout << "Today was a good day. Absolutely nothing could make it go wrong." << std::endl;
    std::cout << "You go home knowing that the universe is on your side. Atleast for the time being." << std::endl;
    std::cout << "Due to your excitement, you were unable to sleep. Anxious and impatient, you check your portfolio on your phone." << std::endl;
    std::cout << "You are then greeted with flashes of bright green and an euphoria like no other encompases you." << std::endl;
    std::cout << std::endl;
}
void Story::goodStory2(){
    std::cout << "You go home feeling good about the choices you've had made." << std::endl;
    std::cout << "You turn on the television and watch the daily stocks report." << std::endl;
    std::cout << "It seems things are going your way today!" << std::endl;
    std::cout << "You were able to sleep easy that night knowing you have made gains." << std::endl;
    std::cout << std::endl;
}std::
void Story::goodStory3(){
    std::cout << "You go home feeling like a champion. Your portfolio is going up!" << std::endl;
    std::cout << "You go on a date with your true love to the Olive Garden" << std::endl;
    std::cout << "Everything went as desired. When you recieve the bill you open your wallet" << std::endl;
    std::cout << "to find plenty of cash. You tip the waitress good and go home satisfied." << std::endl;
    std::cout << std::endl;
}
void Story::goodStory4(){
    std::cout << "You go home unsure of the decisions you have made that day." << std::endl;
    std::cout << "You have many concerns of how your assets will fair in the future." << std::endl;
    std::cout << "You decide to watch the daily stocks report in attempts to reassure yourself." << std::endl;
    std::cout << "Fortunately, your assets have only increased and will only continue to increase as expected." << std::endl;
    std::cout << std::endl;
}
void Story::goodStory5(){
    std::cout << "You feel quite satisfied with the decisions that you have made." << std::endl;
    std::cout << "You feel that things could only go right for your current portfolio." << std::endl;
    std::cout << "You decide to go to mid town to celebrate what seems to be assured gains" << std::endl;
    std::cout << "Everyone adores your presence." << std::endl;
    std::cout << std::endl;
}
//VERY GOOD STORIES
void Story::veryGoodStory1(){
    std::cout << "You tell yourself, \"it's great to be rich!\" as you ride your jet ski on nitro along the shores of Fiji." << std::endl;
    std::cout << "As you dry off on the beach beholding the awe inspiring sight of the beautiful sun set, you receive an anonymous phone call" << endl;
    std::cout << "\"Congraulations! You are officially a millionare and have been invited into the millionaire’s club!\"" << std::endl;
    std::cout << "Feeling like royalty, you then command your butler for more cavier. It simply cannot get any better than this! " << std::endl;
    std::cout << std::endl;
}

//Story at end of Game
void Story::endStory1(){
std::cout << "Congratulations " << name << "!"<< std::endl;
std::cout << "You have succeeded in making a large amount of profit." << std::endl;
std::cout << "As a result, you have decided to celebrate by buying a Lamborghini and a mansion on the water in Miami." << std::endl;
std::cout << "In addition, you invested the rest of your profits in a start-up that ended up exploding." << std::endl;
std::cout << "You are now a multi-millionaire and will live the rest of your life comfort." << std::endl;
}

void Story::endStory2(){
std::cout << "Although you did not become rich from the stock market, at least you made a decent amount of profit." << std::endl;
std::cout << "You decided to take your wife on vacation to Spain." << std::endl;
std::cout << "Additionally, your success in the market lead to increased confidence in the office, which resulted in a promotion." << std::endl;
std::cout << "Overall, you are happy with the results of your investments." << std::endl;
}

void Story::endStory3(){
std::cout << "You didn’t make any profit, but at least you didn’t loose any either." << std::endl;
std::cout << "You spent the last few months investing the majority of your time analyzing and investing in the stock market." << std::endl;
std::cout << "You got angry because you feel like you wasted your time, but your therapist advised you to start meditating." << std::endl;
std::cout << "You decided to might as well try at the market again, and hopefully make a profit the next time." << std::endl;
}

void Story::endStory4(){
std::cout << "Just like the majority of other novice investors, you ended up loosing a small amount of money." << std::endl;
std::cout << "Although you are angry that you don’t get to go on vacation any more, you are also thankful to not have lost your entire investment." << std::endl;
std::cout << "At the end of day, this experience was valuable to you, and you hope to use your new investing knowledge to make money in the future." << std::endl;
}
void Story::endStory5(){
std::cout << "You have very bad luck! You lost the majority of your investment." << std::endl;
std::cout << "When your wife found out you lost all the money, she decided to divorce you." << std::endl;
std::cout << "In addition, you lost your job due to recent depression." << std::endl;
std::cout << "Even though you lost everything that was important to you, at least you learned a valuable lesson… invest intelligently!" << std::endl;
}
