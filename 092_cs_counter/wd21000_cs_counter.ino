/*
 WD21000 project CS# counter for digital analiser sync.
 Target board: Nucleo-64, F091RC
 Programming via Mass Storage
 Serial enabled
*/

#define pin_input  D5

#define cs3_input D2 // CS3# form HDD input
#define counter_output D4
#define count_led D7 // ouput

uint8_t last_input = 0;
uint32_t cs3_event_counter = 0;
uint16_t timer3CH1CounterValue;

uint32_t channel_1;
HardwareTimer *MyTim1;
volatile uint32_t LastCapture = 0, CurrentCapture;
uint8_t state = 0;
uint32_t isInputCapture = 0;
uint8_t inputCaptureWait = 0;
int32_t monitor_time = 0;
bool operation_stop = true;

void InputCapture_IT_callback(void)
{
  if(operation_stop) return;
  //
  CurrentCapture = MyTim1->getCaptureCompare(channel_1);
  int32_t delta = CurrentCapture - LastCapture;
  LastCapture = CurrentCapture;
  isInputCapture++;
  if(isInputCapture >= 9) {
    operation_stop = true;
    digitalWrite(counter_output, HIGH); // Включение светодиода
    digitalWrite(count_led, HIGH); // Включение светодиода
  }
}

void Rollover_IT_callback(void)
{
  state = 0;
}

void setup() {
  Serial.begin(115200);
  
  // Настройка вывода управления светодиодом (используется вывод микроконтроллер PA5)
  pinMode(counter_output, OUTPUT);
  pinMode(count_led, OUTPUT);
  // Настройка входа контроля состояния кнопки (используется вывод микроконтроллер PС13)
  pinMode(PC13, INPUT);

  // Automatically retrieve TIM instance and channel associated to pin
  // This is used to be compatible with all STM32 series automatically.
  TIM_TypeDef *Instance1 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(pin_input), PinMap_PWM);
  channel_1 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(pin_input), PinMap_PWM));
  // Instantiate HardwareTimer object. Thanks to 'new' instantiation, HardwareTimer is not destructed when setup() function is finished.
  MyTim1 = new HardwareTimer(Instance1);
  // stop the timer before configuring them
  MyTim1->pause();
  // Configure rising edge detection to measure frequency
  MyTim1->setMode(channel_1, TIMER_INPUT_CAPTURE_RISING, pin_input);
  // With a PrescalerFactor = 1, the minimum frequency value to measure is : TIM counter clock / CCR MAX
  //  = (SystemCoreClock) / 65535
  // Example on Nucleo_L476RG with systemClock at 80MHz, the minimum frequency is around 1,2 khz
  // To reduce minimum frequency, it is possible to increase prescaler. But this is at a cost of precision.
  // The maximum frequency depends on processing of the interruption and thus depend on board used
  // Example on Nucleo_L476RG with systemClock at 80MHz the interruption processing is around 4,5 
  // microseconds and thus Max frequency is around 220kHz
  uint32_t PrescalerFactor = 1;
  MyTim1->setPrescaleFactor(PrescalerFactor);
  MyTim1->setOverflow(0x10000); // Max Period value to have the largest possible time to detect rising edge and avoid timer rollover
  MyTim1->attachInterrupt(channel_1, InputCapture_IT_callback);
  MyTim1->attachInterrupt(Rollover_IT_callback);
  MyTim1->resume();
  //
  digitalWrite(count_led, LOW);
  digitalWrite(counter_output, LOW);
  //
  Serial.println("WD21000 CS# counter");
  Serial.println("Ver: 2022.03.22-2 ");
  Serial.println((String)"TIM Frequency = " + MyTim1->getTimerClkFreq());
  //
  operation_stop = false;
}

void loop()
{
  if(digitalRead(PC13) == LOW) {    // Проверка состояния кнопки  
    digitalWrite(counter_output, LOW);
    digitalWrite(count_led, LOW);
    isInputCapture = 0;
    operation_stop = false;
  }
}
