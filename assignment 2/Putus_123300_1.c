/*
 * CE161 Assignment 2
 * Liam Fleming    1202340
 * Edward Putus	   1203300
 *
 * main file template for activity 1 was used
 * in this assignment.
 */
//

/*
 * Header files giving access to addition ARM main board functionality
 */
#include <board/LED-lib.h> /* Provide access to LEDs */
#include <board/Button-lib.h> /* Provide access to buttons */
#include <board/SevenSegmentDisplay.h> /* Provide access to 7 segment display */

#define TENS		DISPLAY4
#define SECONDS		DISPLAY3
#define HUNDREDS	DISPLAY2
#define THOUSANDS	DISPLAY1

short Digit[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x67, 0x2D };

/*
 * Define the direction codes for the movement of the LEDs.
 */
#define LEFT  0
#define RIGHT 1

/*
 * Software routine to delay a number of milliseconds
 * All timings are approximate.
 */
void delay_ms(short ms)
{
	volatile short loop;

	while (ms-- > 0)
		for (loop = 0; loop < 2100; loop++);
}

/*
 * Main function - Program execution begins here!
 */

int main()
{


	/*
	 * Declare a variable to store the number of an LED.
	 */
	LEDnumber redLEDpos, redLEDpos2, LEDpos, LeftEnd, RightEnd;
	LEDcolour LEDlist[NUMOFLEDS];

	short redLeftRight, redLeftRight2;


	ConfigureLEDs();
	ConfigureButtons();
	Configure7SegmentDisplay();


	for (LEDpos = LED1; LEDpos <= LED8; LEDpos++)
		LEDlist[LEDpos] = OFF;



	redLEDpos = LED1;
	redLEDpos2=LED8;  // set this to LED7 to see the orange light

	/*
	 * Declares which side is variable 8 and 1.
	 *
	 */

	LeftEnd = LED8;
	RightEnd = LED1;

	/*
	 * Now set the direction of LED movement.
	 */
	redLeftRight = LEFT;
	redLeftRight2 = RIGHT;

	/*
	 * This loop moves the lit LED along the row of LEDs until it hits the end.
	 * It then bounces back towards the other end.
	 *
	 * This loops continues until the right side button is pressed.
	 */

	while(IsButtonReleased(BUTTON8))
	{

		/*
		 * When button 2 is pressed, preform the level2 function
		 * once finished, if button 6 is pressed, preform level2 again
		 * if button 7 is pressed, exit back to level1 interface.
		 */
		if (IsButtonPressed(BUTTON2))
		{
			level2();
			while (IsButtonReleased(BUTTON7))
					{
						if (IsButtonPressed(BUTTON6))
						{
							level2();
						}

					}

			Set7SegmentDisplayValue(TENS, Digit[0x7F]);
			Set7SegmentDisplayValue(SECONDS, Digit[0x7F]);
			Set7SegmentDisplayValue(HUNDREDS, Digit[0x7F]| Digit[0x7F]);
			Set7SegmentDisplayValue(THOUSANDS, Digit[0x7F]);
		}

		/*
		 * When button 3 is pressed, perform the level3 function
		 * once finished, if button 6 is pressed, perform level3 again
		 * if button 7 is pressed, exit back to level1 interface.
		 *
		 */
		if (IsButtonPressed(BUTTON3))
		{
			level3();
			while (IsButtonReleased(BUTTON7))
					{
						if (IsButtonPressed(BUTTON6))
						{
							level3();
						}

					}
		}
	/*
	 * Display all the LED values for a short period of time
	 */

	LEDlist[redLEDpos]= RED;
	LEDlist[redLEDpos2]= RED;
	SetAllLEDs(LEDlist);
	delay_ms(400);
	LEDlist[redLEDpos]= OFF;
	LEDlist[redLEDpos2]= OFF;
	SetAllLEDs(LEDlist);


		/*
		 * Has it reached the end yet? If so, change the direction of travel indicator.
		 */
		if (redLEDpos == LeftEnd)
			redLeftRight = RIGHT;

		if (redLEDpos == RightEnd)
			redLeftRight = LEFT;


		if (redLEDpos2 == LeftEnd)
			redLeftRight2 = RIGHT;


		if (redLEDpos2 == RightEnd)
			redLeftRight2 = LEFT;


		/*
		 * Now move the LED to its new position.
		 */
		 if (redLeftRight == LEFT)
			redLEDpos++;

		 else
			redLEDpos--;

		if (redLeftRight2 == LEFT)
			redLEDpos2++;

		else
			redLEDpos2--;


	}
	//DISPLAY the words OFF for 3 seconds
	Set7SegmentDisplayValue(TENS, 0x3F);
	Set7SegmentDisplayValue(SECONDS, 0x71);
	Set7SegmentDisplayValue(HUNDREDS, 0x71);
	Set7SegmentDisplayValue(THOUSANDS, Digit[0x7F]);
	delay_ms(3000);

	Set7SegmentDisplayValue(TENS, Digit[0x7F]);
	Set7SegmentDisplayValue(SECONDS, Digit[0x7F]);
	Set7SegmentDisplayValue(HUNDREDS, Digit[0x7F]| Digit[0x7F]);

	return 0;
}


/*
 * This code block performs the level2 part of the program,
 * Which consists of;
 * Red lights flashing on and off for 2 seconds
 * LED1 turns green, awaiting input from User
 * Button 1 reduces the seconds
 * Button 3 increases the seconds
 * Button 2 reduces the hundreds
 * Button 4 increases the hundreds
 * Button 5 starts the countdown
 * All LEDS are off
 * Once countdown is finished, Display ‘--.--‘
 * All LED's are orange for 3 seconds
* Press Button 6 to return to this block of code
* Press Button 7 to finish this block of code.
*
*/
void level2()
{
								/*
								 * Reset the display
								 */
								int tens = 6;
								int seconds = 0;
								int hundreds = 0;
								int thousands = 0;
								Set7SegmentDisplayValue(TENS, Digit[tens]);
								Set7SegmentDisplayValue(SECONDS, Digit[seconds] | 0x80);
								Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
								Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);


								SetAllLEDs(LEDsAllRed);
								delay_ms(500);
								SetAllLEDs(LEDsAllOff);
								delay_ms(500);
								SetAllLEDs(LEDsAllRed);
								delay_ms(500);
								SetAllLEDs(LEDsAllOff);
								delay_ms(500);

								int counter = 0;
								int x=300;

								SetLEDcolor(LED1, GREEN);

								while (IsButtonReleased(BUTTON7))
								{

									//Decrease seconds
									if (IsButtonPressed(BUTTON1))
									{
										delay_ms(x);
										counter = counter + 1;
										//If button is held, increments speed up.
										if (counter>4)
										{
											x=100;
										}

										if (IsButtonReleased(BUTTON1))
										{
											x=300;
											counter=0;
										}
										if (tens <= 6)
										{
											if (seconds == 0)
											{
												if (tens==0)
												{
													hundreds = 0;
													thousands = 0;
													Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
													Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
												}
												else
												{
													seconds = 9;
													tens = tens -1;
													Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
													Set7SegmentDisplayValue(TENS, Digit[tens]);
												}
											}
											else
											{
											seconds = seconds -1;
											Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
											}
										}
									}


						//Increase seconds
									if (IsButtonPressed(BUTTON3))
									{
										delay_ms(x);
										counter = counter + 1;

										//If button is held, increments speed up.
										if (counter>4)
										{
											x=100;
										}

										if (IsButtonReleased(BUTTON3))
											{
												x=300;
												counter=0;
											}
										if (tens <= 5)
										{
											if (seconds == 9)
											{
												seconds = 0;
												tens = tens + 1;
												if (tens == 6)
												{
													hundreds = 0;
													thousands = 0;
													Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
													Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
												}
												Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
												Set7SegmentDisplayValue(TENS, Digit[tens]);
											}
											else
											{
												seconds = seconds + 1;
												Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
											}
										}
									}

						//Reduce thousands
									if (IsButtonPressed(BUTTON2))
									{

										delay_ms(x);

										//If button is held, increments speed up.
										counter = counter + 1;
										if (counter>4)
										{
											x=100;
										}

										if (IsButtonReleased(BUTTON2))
										{
											x=300;
											counter=0;
										}
										if (thousands ==0)
										{
											if (hundreds==0)
											{
												if (seconds == 0)
												{
													if (tens == 0)
													{
													}
													else
													{
														tens = tens - 1;
														seconds = 9;
														hundreds = 9;
														thousands = 9;
														Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
														Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
														Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
														Set7SegmentDisplayValue(TENS, Digit[tens]);
													}
												}
												else
												{
													seconds = seconds - 1;
													hundreds = 9;
													thousands = 9;
													Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
													Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
													Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
												}
											}
											else
											{
												thousands = 9;
												hundreds = hundreds - 1;
												Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
												Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
											}
										}
										else
										{
											thousands = thousands - 1;
											Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);

										}
									}

						//increase thousands
									if (IsButtonPressed(BUTTON4))
									{
										delay_ms(x);
										counter = counter + 1;
										//If button is held, increments speed up.
										if (counter>4)
										{
											x=100;
										}

										if (IsButtonReleased(BUTTON4))
										{
											x=300;
											counter=0;
										}

										if (thousands == 9)
										{
											if (hundreds == 9)
											{
												if (seconds ==9)
												{
													if (tens == 6)
													{
														seconds = 0;
														hundreds = 0;
														thousands = 0;
														Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
														Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
														Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
														Set7SegmentDisplayValue(TENS, Digit[tens]);
													}
													else
													{
														tens = tens + 1;
														seconds = 0;
														hundreds = 0;
														thousands = 0;
														Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
														Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
														Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
														Set7SegmentDisplayValue(TENS, Digit[tens]);
													}
												}
												else
												{
													seconds = seconds + 1;
													hundreds = 0;
													thousands = 0;
													Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
													Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
													Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
												}

											}
											else
											{
												if (tens == 6)
												{
													seconds = 0;
													hundreds = 0;
													thousands = 0;
													Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
													Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
													Set7SegmentDisplayValue(SECONDS, Digit[seconds]| 0x80);
													Set7SegmentDisplayValue(TENS, Digit[tens]);
												}
												else
												{
												thousands = 0;
												hundreds = hundreds + 1;
												Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
												Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
												}
											}

										}
										else
										{
											if (tens != 6)
											{
											thousands = thousands + 1;
											Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
											}
										}
									}


									//Starts the countdown
									//DUE TO SLOW CLOCK SPEED, I thousands were set to zero to make sure seconds were accurate.
									if (IsButtonPressed(BUTTON5))
									{
										SetAllLEDs(LEDsAllOff);
										int Timer = 1;
										//This loop works by assigning a the value 1 or 0 to variable Timer, which represent
										//True or false respectively, once the counter turns to zero, Timer will be set to 0
										//ending the loop
										while (Timer == 1)
										{
											delay_ms(70);
											if (thousands == 0)
											{
												if (hundreds == 0)
												{
													if (seconds == 0)
													{
														if (tens == 0)
														{
															Timer = 0;
															SetAllLEDs(LEDsAllOrange);
															//clears the board
															Set7SegmentDisplayValue(TENS, Digit[0x7F]);
															Set7SegmentDisplayValue(SECONDS, Digit[0x7F] | 0x80);
															Set7SegmentDisplayValue(HUNDREDS, Digit[0x7F]);
															Set7SegmentDisplayValue(THOUSANDS, Digit[0x7F]);

															//Inputs '--.--'
															Set7SegmentDisplayValue(TENS, 0x40);
															Set7SegmentDisplayValue(SECONDS, 0x40 | 0x80);
															Set7SegmentDisplayValue(HUNDREDS, 0x40);
															Set7SegmentDisplayValue(THOUSANDS, 0x40);
															delay_ms(3000);
														}
														else
														{
														Set7SegmentDisplayValue(SECONDS, Digit[seconds] | 0x80);
														thousands = 0;
														hundreds = 9;
														seconds = 9;
														tens = tens - 1;
														Set7SegmentDisplayValue(TENS, Digit[tens]);
														Set7SegmentDisplayValue(SECONDS, Digit[seconds] | 0x80);
														Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
														Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
														}
													}
													else
													{
														Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
														thousands = 0;
														hundreds = 9;
														seconds = seconds - 1;
														Set7SegmentDisplayValue(SECONDS, Digit[seconds] | 0x80);
														Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
														Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
													}
												}
												else
												{
												Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
												thousands = 0;
												hundreds = hundreds - 1;
												Set7SegmentDisplayValue(HUNDREDS, Digit[hundreds]);
												Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
												}
											}
											else
											{
												thousands = thousands - 1;
												Set7SegmentDisplayValue(THOUSANDS, Digit[thousands]);
											}
										}

										SetAllLEDs(LEDsAllOff);

									}
								}
}


/*
 * This code block performs the level3 part of the program,
 * Which consists of;
 * Red lights flashing on and off 4 times
 * display shows '--.--'
 * Button 1 to choose decimal
 * Button 2 to choose hexidecimal
 * green lights flash 4 times when decision made
 * Buttons 1-6 to choose binary characters
 * Button 7 ends the bit selection.
 * outputs value
*
*/
void level3()
{
	//LEDS blink red 4 times
		SetAllLEDs(LEDsAllRed);
		delay_ms(200);
		SetAllLEDs(LEDsAllOff);
		delay_ms(200);
		SetAllLEDs(LEDsAllRed);
		delay_ms(200);
		SetAllLEDs(LEDsAllOff);
		delay_ms(200);
		SetAllLEDs(LEDsAllRed);
		delay_ms(200);
		SetAllLEDs(LEDsAllOff);
		delay_ms(200);
		SetAllLEDs(LEDsAllRed);
		delay_ms(200);
		SetAllLEDs(LEDsAllOff);
		delay_ms(200);


		int truefalse = 1;
		//Inputs '--.--'
		Set7SegmentDisplayValue(TENS, 0x40);
		Set7SegmentDisplayValue(SECONDS, 0x40 | 0x80);
		Set7SegmentDisplayValue(HUNDREDS, 0x40);
		Set7SegmentDisplayValue(THOUSANDS, 0x40);

		//This loop works by assigning 1 or 0 to a variable truefalse, which
		//will act as a boolean value, once the program has output a solution
		//it will change value, ending the function.
		while (truefalse == 1)
		{
						//Button 1 for decimal, Button 2 for hexidecimal.
						if (IsButtonPressed(BUTTON1))
						{
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);

							Set7SegmentDisplayValue(TENS, 0x40);
							Set7SegmentDisplayValue(SECONDS, 0x40 | 0x80);
							Set7SegmentDisplayValue(HUNDREDS, 0x40);
							Set7SegmentDisplayValue(THOUSANDS, 0x40);


							int but1 = 0;
							int but2 = 0;
							int but3 = 0;
							int but4 = 0;
							int but5 = 0;
							int but6 = 0;

							//Pressing buttons 1-6 will change it's value from 0-1;
							//Until button 7 is pressed
							while (IsButtonReleased(BUTTON7))
							{
								if (IsButtonPressed(BUTTON6))
								{
									if (but1 == 0)
										{
											but1 = 1;
										}
									else
									{
										but1 = 0;
									}
									delay_ms(300);
								}

								if (IsButtonPressed(BUTTON5))
								{
									if (but2 == 0)
										{
											but2 = 1;
										}
									else
									{
										but2 = 0;
									}
									delay_ms(300);
								}

								if (IsButtonPressed(BUTTON4))
								{
									if (but3 == 0)
										{
											but3 = 1;
										}
									else
									{
										but3 = 0;
									}
									delay_ms(300);
								}

								if (IsButtonPressed(BUTTON3))
								{
									if (but4 == 0)
										{
											but4 = 1;
										}
									else
									{
										but4 = 0;
									}
									delay_ms(300);
								}

								if (IsButtonPressed(BUTTON2))
								{
									if (but5 == 0)
										{
											but5 = 1;
										}
									else
									{
										but5 = 0;
									}
									delay_ms(300);
								}

								if (IsButtonPressed(BUTTON1))
								{
									if (but6 == 0)
										{
											but6 = 1;
										}
									else
									{
										but6 = 0;
									}
									delay_ms(300);
								}
							}

							int decimalnum = 0;
							decimalnum = (but1*32)+(but2*16)+(but3*8)+(but4*4)+(but5*2)+(but6*1);

							//Use two displays, "tens" and "seconds".
							//to find value for tens, integer division decimalnum by 10
							//to find value for "seconds" remainder division decimalnum by 10

							int ten = 0;
							int unit = 0;
							ten = decimalnum / 10;
							unit = decimalnum % 10;

							Set7SegmentDisplayValue(TENS, Digit[ten]);
							Set7SegmentDisplayValue(SECONDS, Digit[unit]);
							truefalse = 0;
						}


						if (IsButtonPressed(BUTTON2))
						{
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);
							SetAllLEDs(LEDsAllGreen);
							delay_ms(200);
							SetAllLEDs(LEDsAllOff);
							delay_ms(200);

							Set7SegmentDisplayValue(TENS, 0x40);
							Set7SegmentDisplayValue(SECONDS, 0x40 | 0x80);
							Set7SegmentDisplayValue(HUNDREDS, 0x40);
							Set7SegmentDisplayValue(THOUSANDS, 0x40);


							int but1 = 0;
							int but2 = 0;
							int but3 = 0;
							int but4 = 0;
							int but5 = 0;
							int but6 = 0;

							//Pressing buttons 1-6 will change it's value from 0-1;
							//Until button 7 is pressed
							while (IsButtonReleased(BUTTON7))
							{
								if (IsButtonPressed(BUTTON6))
								{
									if (but1 == 0)
									{
										but1 = 1;
									}
									else
									{
										but1 = 0;
									}
										delay_ms(300);
								 }

								if (IsButtonPressed(BUTTON5))
								{
									if (but2 == 0)
									{
										but2 = 1;
									}
									else
									{
										but2 = 0;
									}
										delay_ms(300);
								}

									if (IsButtonPressed(BUTTON4))
									{
										if (but3 == 0)
											{
												but3 = 1;
											}
										else
										{
											but3 = 0;
										}
										delay_ms(300);
									}

									if (IsButtonPressed(BUTTON3))
									{
										if (but4 == 0)
											{
												but4 = 1;
											}
										else
										{
											but4 = 0;
										}
										delay_ms(300);
									}

									if (IsButtonPressed(BUTTON2))
									{
										if (but5 == 0)
											{
												but5 = 1;
											}
										else
										{
											but5 = 0;
										}
										delay_ms(300);
									}

									if (IsButtonPressed(BUTTON1))
									{
										if (but6 == 0)
											{
												but6 = 1;
											}
										else
										{
											but6 = 0;
										}
										delay_ms(300);
									}
								}

									//An easy way to convert to hexidecimal
									// was to split it up into groups of 4, right to left
									// leaving two zeros always at the front
									// eg 0011 1001
									int hex1 = (but1*2)+(but2*1);
									int hex2 = (but3*8)+(but4*4)+(but5*2)+(but6*1);

									//if hex2 is greater than 9, it must
									//be converted into a character from A-F
									if (hex2 > 9)
									{
										if (hex2 == 10)
										{
											hex2 = 0x77;
										}
										if (hex2 == 11)
										{
											hex2 = 0x7C;
										}
										if (hex2 == 12)
										{
											hex2 = 0x39;
										}
										if (hex2 == 13)
										{
											hex2 = 0x5E;
										}
										if (hex2 == 14)
										{
											hex2 = 0x79;
										}
										if (hex2 == 15)
										{
											hex2 = 0x71;
										}
										Set7SegmentDisplayValue(TENS, Digit[hex1]);
										Set7SegmentDisplayValue(SECONDS, hex2);
										truefalse = 0;
									}
									else
									{
										Set7SegmentDisplayValue(TENS, Digit[hex1]);
										Set7SegmentDisplayValue(SECONDS, Digit[hex2]);
										truefalse = 0;
									}
						}
		}
}
