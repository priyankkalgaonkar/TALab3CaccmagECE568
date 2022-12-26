#include "mbed.h"
#include "FXOS8700Q.h"
    I2C i2c(PTE25, PTE24);
    FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);    // Configured for the FRDM-K64F with onboard sensors
    FXOS8700QMagnetometer mag(i2c, FXOS8700CQ_SLAVE_ADDR1);
    int main(void)
    {
        motion_data_units_t acc_data, mag_data;
        motion_data_counts_t acc_raw, mag_raw;
        float faX, faY, faZ, fmX, fmY, fmZ, tmp_float;
        int16_t raX, raY, raZ, rmX, rmY, rmZ, tmp_int;
        acc.enable();
        mag.enable();
        while (true) {
            // counts based results
            acc.getAxis(acc_raw);
            mag.getAxis(mag_raw);
            acc.getX(raX);
            acc.getY(raY);
            acc.getZ(raZ);
            mag.getX(rmX);
            mag.getY(rmY);
            mag.getZ(rmZ);
            // unit based results
            acc.getAxis(acc_data);
            mag.getAxis(mag_data);
            acc.getX(faX);
            acc.getY(faY);
            acc.getZ(faZ);
            mag.getX(fmX);
            mag.getY(fmY);
            mag.getZ(fmZ);
           printf("FXOSQ8700Q ACC: X=%1.4fY=%1.4fZ=%1.4f", acc.getX(faX),acc.getY(faY),acc.getZ(faZ));
           printf("  MAG: X=%4.1fY=%4.1fZ=%4.1f\r\n", mag.getX(fmX),mag.getY(fmY), mag.getZ(fmZ));
            wait_us(100000);
        }
    }