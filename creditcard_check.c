#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Step 1: Prompt the user for input
    long card;
    do {
        {
            card = get_long("Card number: ");
        }
    //Step 2: Identify if the card is valid
    } while (card < 0); //Card number must be greater than 0
    
    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = ((card % 100)/10*2);
    card2 = ((card % 10000)/1000*2);
    card3 = ((card % 1000000)/100000*2);
    card4 = ((card % 100000000)/10000000*2);
    card5 = ((card % 10000000000)/1000000000*2);
    card6 = ((card % 1000000000000)/100000000000*2);
    card7 = ((card % 100000000000000)/10000000000000*2);
    card7 = ((card % 10000000000000000)/1000000000000000*2);
    
    // 2.1 Splitting the digits
    card1 = (card1 % 100/10) + (card1 % 10);
    card2 = (card2 % 100/10) + (card2 % 10);
    card3 = (card3 % 100/10) + (card3 % 10);
    card4 = (card4 % 100/10) + (card4 % 10);
    card5 = (card5 % 100/10) + (card5 % 10);
    card6 = (card6 % 100/10) + (card6 % 10);
    card7 = (card7 % 100/10) + (card7 % 10);
    card8 = (card8 % 100/10) + (card8 % 10);
    
    // 2.2 Summarizing all those digits together into "sum1"
    int sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;
    
    // 2.3 Now we need to find the digits that were not multiplied by 2, starting from the last digit
    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9 = (card % 10);
    card10 = ((card % 1000)/100);
    card11 = ((card % 100000)/10000);
    card12 = ((card % 10000000)/1000000);
    card13 = ((card % 1000000000)/100000000);
    card14 = ((card % 100000000000)/10000000000);
    card15 = ((card % 10000000000000)/1000000000000);
    card16 = ((card % 1000000000000000)/100000000000000);
    
    // 2.4 Now we sum int all together into sum2
    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;
    
    // 2.5 put both sums together and form sum3:
    int sum3 = sum1 + sum2;
    
    // 2.6 Now, check if the last digit in this sum is 0
    
    int length = 0;
    long visa = card;
    long amex = card;
    long mastercard = card;
    
    //Optional: include Diners Club, Discover, and
        //long dinersclub = card;
        //long discover = card;
        //long jcb = card;
    
    if ((sum3 % 10) != 0) // 2.7 sum3 % 10 how we determine the last digit
    {
        printf("%s\n", "INVALID!"); // 2.8 Alternative: printf("INVALID!\n");
        return 0; // 2.9 We want to stop the system from running here if it is invalid
    }
    //Step 3: If valid, identify the type of credit card used
        //3.1 In the next stzep we need to differentiate between VISA, AMEX, Mastercard, diners club, discover, and jcb
        // 3.2 we also need to know what the card length is!!
    while (card > 0)
    {
        card = card/10;
        length++;
    }
    // 3.3 Identify if the card is a VISA
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }
    // 3.4 Identify if the card is a mastercard
    while (amex >= 10000000000000) // 10^13
    {
        amex /= 10000000000000;
    }
    if (length == 15 && (amex == 34 || amex == 37))
        {
        printf("%s\n", "AMEX");
        return 0;;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
    //3.5 Identify if the card is a diners club
    while (dinersclub >= 100000000000000) //10 ^14
    {
        dinersclub /= 100000000000000;
    }
    if (length == 14 && dinersclub == 30)
    {
        printf("%s\n", "Diners Club");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
    //3.6 Identify if the card is a Discover card
    while (discover >= 10000000000000000) // 10^16
    {
        discover /= 10000000000000000;
    }
    if (length == 16 && discover == 60)
    {
        printf("%s\n", "DISCOVER");
        return 0;;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
    while (discover >= 10000000000000000) // 10^16
    {
        discover /= 10000000000000000;
    }
    if (length == 16 && amex == 60)
    {
        printf("%s\n", "DISCOVER");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
    while (jcb >= 10000000000000000) // 10^16
    {
        jcb /= 10000000000000000;
    }
    if (length == 16 && jcb == 35)
    {
        printf("%s\n", "JCB");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
}
