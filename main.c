#include <stdint.h>
#include <stdio.h>

static volatile uint8_t ledState = 0U;
static volatile uint32_t timerCounter = 0U;

/* Simulated timer handler: toggle the LED state after 500 software ticks. */
static void TimerInterruptHandler(void)
{
    ++timerCounter;

    if (timerCounter >= 500U)
    {
        timerCounter = 0U;
        ledState = (uint8_t)!ledState;

        if (ledState != 0U)
        {
            puts("LED ON");
        }
        else
        {
            puts("LED OFF");
        }
    }
}

int main(void)
{
    while (1)
    {
        TimerInterruptHandler();

        /* A small busy loop spaces out the simulated ticks; it is not a
         * calibrated delay and its duration depends on the target CPU. */
        for (volatile uint32_t i = 0U; i < 10000U; ++i)
        {
            /* Intentionally empty. */
        }
    }

    return 0;
}
