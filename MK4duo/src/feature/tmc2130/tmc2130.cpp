/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (C) 2013 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * tmc2130.cpp
 *
 * Copyright (C) 2017 Alberto Cotronei @MagoKimbra
 */

#include "../../../base.h"

#if ENABLED(HAVE_TMC2130)

  #if ENABLED(AUTOMATIC_CURRENT_CONTROL)
    bool auto_current_control = 0;
  #endif

  void automatic_current_control(TMC2130Stepper &st, const char *axisID) {
    // Check otpw even if we don't use automatic control. Allows for flag inspection.
    const bool is_otpw = st.checkOT();

    // Report if a warning was triggered
    static bool previous_otpw = false;
    if (is_otpw && !previous_otpw) {
      char timestamp[10];
      duration_t elapsed = print_job_counter.duration();
      const bool has_days = (elapsed.value > 60*60*24L);
      (void)elapsed.toDigital(timestamp, has_days);
      SERIAL_TXT(timestamp);
      SERIAL_TXT(": ");
      SERIAL_TXT(axisID);
      SERIAL_EM(" driver overtemperature warning!");
    }
    previous_otpw = is_otpw;

    #if ENABLED(AUTOMATIC_CURRENT_CONTROL) && CURRENT_STEP > 0
      // Return if user has not enabled current control start with M906 S1.
      if (!auto_current_control) return;

      /**
       * Decrease current if is_otpw is true.
       * Bail out if driver is disabled.
       * Increase current if OTPW has not been triggered yet.
       */
      uint16_t current = st.getCurrent();
      if (is_otpw) {
        st.setCurrent(current - CURRENT_STEP, R_SENSE, HOLD_MULTIPLIER);
        #if ENABLED(REPORT_CURRENT_CHANGE)
          SERIAL_TXT(axisID);
          SERIAL_MV(" current decreased to ", st.getCurrent());
        #endif
      }

      else if (!st.isEnabled())
        return;

      else if (!is_otpw && !st.getOTPW()) {
        current += CURRENT_STEP;
        if (current <= AUTO_ADJUST_MAX) {
          st.setCurrent(current, R_SENSE, HOLD_MULTIPLIER);
          #if ENABLED(REPORT_CURRENT_CHANGE)
            SERIAL_TXT(axisID);
            SERIAL_MV(" current increased to ", st.getCurrent());
          #endif
        }
      }
      SERIAL_EOL();
    #endif
  }

  void tmc2130_checkOverTemp(void) {

    static millis_t next_cOT = 0;
    if (ELAPSED(millis(), next_cOT)) {
      next_cOT = millis() + 5000;
      #if ENABLED(X_IS_TMC2130)
        automatic_current_control(stepperX, "X");
      #endif
      #if ENABLED(Y_IS_TMC2130)
        automatic_current_control(stepperY, "Y");
      #endif
      #if ENABLED(Z_IS_TMC2130)
        automatic_current_control(stepperZ, "Z");
      #endif
      #if ENABLED(X2_IS_TMC2130)
        automatic_current_control(stepperX2, "X2");
      #endif
      #if ENABLED(Y2_IS_TMC2130)
        automatic_current_control(stepperY2, "Y2");
      #endif
      #if ENABLED(Z2_IS_TMC2130)
        automatic_current_control(stepperZ2, "Z2");
      #endif
      #if ENABLED(E0_IS_TMC2130)
        automatic_current_control(stepperE0, "E0");
      #endif
      #if ENABLED(E1_IS_TMC2130)
        automatic_current_control(stepperE1, "E1");
      #endif
      #if ENABLED(E2_IS_TMC2130)
        automatic_current_control(stepperE2, "E2");
      #endif
      #if ENABLED(E3_IS_TMC2130)
        automatic_current_control(stepperE3, "E3");
      #endif
      #if ENABLED(E4_IS_TMC2130)
        automatic_current_control(stepperE4, "E4");
      #endif
      #if ENABLED(E5_IS_TMC2130)
        automatic_current_control(stepperE5, "E5");
      #endif
    }
  }

  /**
   * TMC2130 specific sensorless homing using stallGuard2.
   * stallGuard2 only works when in spreadCycle mode.
   * spreadCycle and stealthChop are mutually exclusive.
   */
  #if ENABLED(SENSORLESS_HOMING)
    void tmc2130_sensorless_homing(TMC2130Stepper &st, bool enable/*=true*/) {
      #if ENABLED(STEALTHCHOP)
        if (enable) {
          st.coolstep_min_speed(1024UL * 1024UL - 1UL);
          st.stealthChop(0);
        }
        else {
          st.coolstep_min_speed(0);
          st.stealthChop(1);
        }
      #endif

      st.diag1_stall(enable ? 1 : 0);
    }
  #endif // SENSORLESS_HOMING

#endif // ENABLED(HAVE_TMC2130)