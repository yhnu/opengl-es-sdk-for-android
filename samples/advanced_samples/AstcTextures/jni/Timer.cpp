/* Copyright (c) 2014-2017, ARM Limited and Contributors
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge,
 * to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "Timer.h"

#include <sys/time.h>

namespace AstcTextures
{
    /* Please see header for specification. */
    Timer::Timer() :
        startTime(),
        currentTime(),
        lastIntervalTime(0.0f),
        frameCount(0),
        fpsTime(0.0f),
        fps(0.0f)
    {    
        startTime.tv_sec    = 0;
        startTime.tv_usec   = 0;
        currentTime.tv_sec  = 0;
        currentTime.tv_usec = 0;

        reset();
    }

    /* Please see header for specification. */
    void Timer::reset()
    {
        gettimeofday(&startTime, NULL);

        lastIntervalTime = 0.0f;
        frameCount       = 0;
        fpsTime          = 0.0f;
    }

    /* Please see header for specification. */
    float Timer::getTime()
    {
        gettimeofday(&currentTime, NULL);

        float seconds      = (currentTime.tv_sec - startTime.tv_sec);
        float milliseconds = (float (currentTime.tv_usec - startTime.tv_usec)) / 1000000.0f;

        return (seconds + milliseconds);
    }

    /* Please see header for specification. */
    bool Timer::isTimePassed(float seconds)
    {
        float time = getTime();

        if (time - lastTime > seconds)
        {
            lastTime = time;

            return true;
        }

        return false;
    }
}
