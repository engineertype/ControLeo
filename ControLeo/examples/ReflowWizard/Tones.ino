// Play the selected tone
// This is a synchronous (blocking) call.  The function doesn't return until the
// tone has been played.  This works fine for this application, but it could be
// done using a timer interrupt and a lot more (complicated) code.


// Play a tone
void playTones(int tune) {
  if (tune >= MAX_TUNES)
    return;
    
  lcd.setBuzzer(ON);
  switch(tune) {
    case TUNE_STARTUP:
      delay(200);
      break;
    case TUNE_TOP_BUTTON_PRESS:
      delay(20);
      break;
    case TUNE_BOTTOM_BUTTON_PRESS:
      delay(20);
      break;
    case TUNE_REFLOW_DONE:
      delay(3000);
      break;
    case TUNE_REMOVE_BOARDS:
      delay(1000);
      break;
  }
  lcd.setBuzzer(OFF);
}

