#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32u5xx_hal.h"
#include "main.h"

// #include <gui_generated/screen1_screen/Screen1ViewBase.hpp>

#include <images/BitmapDatabase.hpp>

extern TIM_HandleTypeDef htim2;
int mscounter;

Screen1View::Screen1View() {
}

void Screen1View::setupScreen() {
	Screen1ViewBase::setupScreen();
	stepCircle1.setAlpha(50);
	stepCircle2.setAlpha(50);
	stepCircle3.setAlpha(50);
	stepCircle4.setAlpha(50);
	stepCircle5.setAlpha(50);
	stepCircle6.setAlpha(50);
	stepCircle7.setAlpha(50);
	stepCircle8.setAlpha(50);
	stepCircle9.setAlpha(50);
	stepCircle10.setAlpha(50);
	stepCircle11.setAlpha(50);
	stepCircle12.setAlpha(50);
	stepCircle13.setAlpha(50);
	stepCircle14.setAlpha(50);
	stepCircle15.setAlpha(50);
	stepCircle16.setAlpha(50);
	line1.setAlpha(30);
	line2.setAlpha(30);
	line3.setAlpha(30);
	line4.setAlpha(30);

}

void Screen1View::tearDownScreen() {
	Screen1ViewBase::tearDownScreen();
}

// 1/60secごとに自動的に呼び出される関数
void Screen1View::handleTickEvent() {
	if (play) {
		tickCounter++;
//	Screen1View::updatemsec(mscounter);
		if (mscounter >= onTime - 1) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); //上から１番目の列
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); //２番目の列
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET); //３番目の列
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET); //４番目の列
			line1.setAlpha(30);
			line2.setAlpha(30);
			line3.setAlpha(30);
			line4.setAlpha(30);
			line1.invalidate();
			line2.invalidate();
			line3.invalidate();
			line4.invalidate();
		}
		if (mscounter >= ((BPMtomsec - 1) / 4)) {
			mscounter = 0;
			step++;
			if (step > 15)
				step = 0;
			tickCounter = 0;

			if (step == 0) {
				stepCircle16.setAlpha(50);
				stepCircle16.invalidate();
				stepCircle1.setAlpha(255);
				stepCircle1.invalidate();
			}
			if (step == 1) {
				stepCircle1.setAlpha(50);
				stepCircle1.invalidate();
				stepCircle2.setAlpha(255);
				stepCircle2.invalidate();
			}
			if (step == 2) {
				stepCircle2.setAlpha(50);
				stepCircle2.invalidate();
				stepCircle3.setAlpha(255);
				stepCircle3.invalidate();
			}
			if (step == 3) {
				stepCircle3.setAlpha(50);
				stepCircle3.invalidate();
				stepCircle4.setAlpha(255);
				stepCircle4.invalidate();
			}
			if (step == 4) {
				stepCircle4.setAlpha(50);
				stepCircle4.invalidate();
				stepCircle5.setAlpha(255);
				stepCircle5.invalidate();
			}
			if (step == 5) {
				stepCircle5.setAlpha(50);
				stepCircle5.invalidate();
				stepCircle6.setAlpha(255);
				stepCircle6.invalidate();
			}
			if (step == 6) {
				stepCircle6.setAlpha(50);
				stepCircle6.invalidate();
				stepCircle7.setAlpha(255);
				stepCircle7.invalidate();
			}
			if (step == 7) {
				stepCircle7.setAlpha(50);
				stepCircle7.invalidate();
				stepCircle8.setAlpha(255);
				stepCircle8.invalidate();
			}
			if (step == 8) {
				stepCircle8.setAlpha(50);
				stepCircle8.invalidate();
				stepCircle9.setAlpha(255);
				stepCircle9.invalidate();
			}
			if (step == 9) {
				stepCircle9.setAlpha(50);
				stepCircle9.invalidate();
				stepCircle10.setAlpha(255);
				stepCircle10.invalidate();
			}
			if (step == 10) {
				stepCircle10.setAlpha(50);
				stepCircle10.invalidate();
				stepCircle11.setAlpha(255);
				stepCircle11.invalidate();
			}
			if (step == 11) {
				stepCircle11.setAlpha(50);
				stepCircle11.invalidate();
				stepCircle12.setAlpha(255);
				stepCircle12.invalidate();
			}
			if (step == 12) {
				stepCircle12.setAlpha(50);
				stepCircle12.invalidate();
				stepCircle13.setAlpha(255);
				stepCircle13.invalidate();
			}
			if (step == 13) {
				stepCircle13.setAlpha(50);
				stepCircle13.invalidate();
				stepCircle14.setAlpha(255);
				stepCircle14.invalidate();
			}
			if (step == 14) {
				stepCircle14.setAlpha(50);
				stepCircle14.invalidate();
				stepCircle15.setAlpha(255);
				stepCircle15.invalidate();
			}
			if (step == 15) {
				stepCircle15.setAlpha(50);
				stepCircle15.invalidate();
				stepCircle16.setAlpha(255);
				stepCircle16.invalidate();
			}

			//        frameCountStepC1Interval = 0;

//		Screen1View::updateStepNo (step);

			if (stpHL[0][step]) { //一番上の列
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
				line1.setAlpha(255);
				line1.invalidate();

			}
			if (stpHL[1][step]) { //２番目の列
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
				line2.setAlpha(255);
				line2.invalidate();
			}
			if (stpHL[2][step]) { //３番目の列
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
				line3.setAlpha(255);
				line3.invalidate();
			}
			if (stpHL[3][step]) { //４番目の列
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
				line4.setAlpha(255);
				line4.invalidate();
			}
		}
	}
}

void Screen1View::updateBPM(int newValue) {
//	touchgfx::Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", 0);
	touchgfx::Unicode::snprintf(dispBPMBuffer, DISPBPM_SIZE, "%d", newValue);
	dispBPM.invalidate();
}

//void Screen1View::updateStepNo(int newValue) {
////	touchgfx::Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", 0);
//	touchgfx::Unicode::snprintf(stepNOBuffer, STEPNO_SIZE, "%d", newValue);
//	stepNO.invalidate();
//}

//void Screen1View::updatemsec(int newValue) {
////	touchgfx::Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", 0);
//	touchgfx::Unicode::snprintf(dispmsBuffer, DISPMS_SIZE, "%d", newValue);
//	dispms.invalidate();
//}

void Screen1View::tmpChange(int value) {
	BPM = value;
	Screen1View::updateBPM (BPM);
	BPMtomsec = 60000 / BPM;
}

void Screen1View::stepHL1() {
	stpHL[0][0] = !stpHL[0][0];
}

void Screen1View::stepHL2() {
	stpHL[0][1] = !stpHL[0][1];
}

void Screen1View::stepHL3() {
	stpHL[0][2] = !stpHL[0][2];
}

void Screen1View::stepHL4() {
	stpHL[0][3] = !stpHL[0][3];
}

void Screen1View::stepHL5() {
	stpHL[0][4] = !stpHL[0][4];
}

void Screen1View::stepHL6() {
	stpHL[0][5] = !stpHL[0][5];
}

void Screen1View::stepHL7() {
	stpHL[0][6] = !stpHL[0][6];
}

void Screen1View::stepHL8() {
	stpHL[0][7] = !stpHL[0][7];
}
void Screen1View::stepHL9() {
	stpHL[0][8] = !stpHL[0][8];
}

void Screen1View::stepHL10() {
	stpHL[0][9] = !stpHL[0][9];
}

void Screen1View::stepHL11() {
	stpHL[0][10] = !stpHL[0][10];
}

void Screen1View::stepHL12() {
	stpHL[0][11] = !stpHL[0][11];
}

void Screen1View::stepHL13() {
	stpHL[0][12] = !stpHL[0][12];
}

void Screen1View::stepHL14() {
	stpHL[0][13] = !stpHL[0][13];
}

void Screen1View::stepHL15() {
	stpHL[0][14] = !stpHL[0][14];
}

void Screen1View::stepHL16() {
	stpHL[0][15] = !stpHL[0][15];
}

void Screen1View::stepHL1_2() {
	stpHL[1][0] = !stpHL[1][0];
}

void Screen1View::stepHL2_2() {
	stpHL[1][1] = !stpHL[1][1];
}

void Screen1View::stepHL3_2() {
	stpHL[1][2] = !stpHL[1][2];
}

void Screen1View::stepHL4_2() {
	stpHL[1][3] = !stpHL[1][3];
}

void Screen1View::stepHL5_2() {
	stpHL[1][4] = !stpHL[1][4];
}

void Screen1View::stepHL6_2() {
	stpHL[1][5] = !stpHL[1][5];
}

void Screen1View::stepHL7_2() {
	stpHL[1][6] = !stpHL[1][6];
}

void Screen1View::stepHL8_2() {
	stpHL[1][7] = !stpHL[1][7];
}
void Screen1View::stepHL9_2() {
	stpHL[1][8] = !stpHL[1][8];
}

void Screen1View::stepHL10_2() {
	stpHL[1][9] = !stpHL[1][9];
}

void Screen1View::stepHL11_2() {
	stpHL[1][10] = !stpHL[1][10];
}

void Screen1View::stepHL12_2() {
	stpHL[1][11] = !stpHL[1][11];
}

void Screen1View::stepHL13_2() {
	stpHL[1][12] = !stpHL[1][12];
}

void Screen1View::stepHL14_2() {
	stpHL[1][13] = !stpHL[1][13];
}

void Screen1View::stepHL15_2() {
	stpHL[1][14] = !stpHL[1][14];
}

void Screen1View::stepHL16_2() {
	stpHL[1][15] = !stpHL[1][15];
}

void Screen1View::stepHL1_3() {
	stpHL[2][0] = !stpHL[2][0];
}

void Screen1View::stepHL2_3() {
	stpHL[2][1] = !stpHL[2][1];
}

void Screen1View::stepHL3_3() {
	stpHL[2][2] = !stpHL[2][2];
}

void Screen1View::stepHL4_3() {
	stpHL[2][3] = !stpHL[2][3];
}

void Screen1View::stepHL5_3() {
	stpHL[2][4] = !stpHL[2][4];
}

void Screen1View::stepHL6_3() {
	stpHL[2][5] = !stpHL[2][5];
}

void Screen1View::stepHL7_3() {
	stpHL[2][6] = !stpHL[2][6];
}

void Screen1View::stepHL8_3() {
	stpHL[2][7] = !stpHL[2][7];
}
void Screen1View::stepHL9_3() {
	stpHL[2][8] = !stpHL[2][8];
}

void Screen1View::stepHL10_3() {
	stpHL[2][9] = !stpHL[2][9];
}

void Screen1View::stepHL11_3() {
	stpHL[2][10] = !stpHL[2][10];
}

void Screen1View::stepHL12_3() {
	stpHL[2][11] = !stpHL[2][11];
}

void Screen1View::stepHL13_3() {
	stpHL[2][12] = !stpHL[2][12];
}

void Screen1View::stepHL14_3() {
	stpHL[2][13] = !stpHL[2][13];
}

void Screen1View::stepHL15_3() {
	stpHL[2][14] = !stpHL[2][14];
}

void Screen1View::stepHL16_3() {
	stpHL[2][15] = !stpHL[2][15];
}

void Screen1View::stepHL1_4() {
	stpHL[3][0] = !stpHL[3][0];
}

void Screen1View::stepHL2_4() {
	stpHL[3][1] = !stpHL[3][1];
}

void Screen1View::stepHL3_4() {
	stpHL[3][2] = !stpHL[3][2];
}

void Screen1View::stepHL4_4() {
	stpHL[3][3] = !stpHL[3][3];
}

void Screen1View::stepHL5_4() {
	stpHL[3][4] = !stpHL[3][4];
}

void Screen1View::stepHL6_4() {
	stpHL[3][5] = !stpHL[3][5];
}

void Screen1View::stepHL7_4() {
	stpHL[3][6] = !stpHL[3][6];
}

void Screen1View::stepHL8_4() {
	stpHL[3][7] = !stpHL[3][7];
}
void Screen1View::stepHL9_4() {
	stpHL[3][8] = !stpHL[3][8];
}

void Screen1View::stepHL10_4() {
	stpHL[3][9] = !stpHL[3][9];
}

void Screen1View::stepHL11_4() {
	stpHL[3][10] = !stpHL[3][10];
}

void Screen1View::stepHL12_4() {
	stpHL[3][11] = !stpHL[3][11];
}

void Screen1View::stepHL13_4() {
	stpHL[3][12] = !stpHL[3][12];
}

void Screen1View::stepHL14_4() {
	stpHL[3][13] = !stpHL[3][13];
}

void Screen1View::stepHL15_4() {
	stpHL[3][14] = !stpHL[3][14];
}

void Screen1View::stepHL16_4() {
	stpHL[3][15] = !stpHL[3][15];
}

void Screen1View::allclear() {
    StepButton1.setXY(97, 215);
    StepButton1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
	StepButton1.invalidate();

    StepButton2.setXY(135, 215);
    StepButton2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton2.invalidate();

    StepButton3.setXY(173, 215);
    StepButton3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton3.invalidate();

    StepButton4.setXY(211, 215);
    StepButton4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton4.invalidate();

    StepButton5.setXY(249, 215);
    StepButton5.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton5.invalidate();

    StepButton6.setXY(287, 215);
    StepButton6.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton6.invalidate();

    StepButton7.setXY(325, 215);
    StepButton7.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton7.invalidate();

    StepButton8.setXY(363, 215);
    StepButton8.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton8.invalidate();

    StepButton9.setXY(401, 215);
    StepButton9.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton9.invalidate();

    StepButton10.setXY(439, 215);
    StepButton10.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton10.invalidate();

    StepButton11.setXY(477, 215);
    StepButton11.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton11.invalidate();

    StepButton12.setXY(515, 215);
    StepButton12.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton12.invalidate();

    StepButton13.setXY(553, 215);
    StepButton13.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton13.invalidate();

    StepButton14.setXY(591, 215);
    StepButton14.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton14.invalidate();

    StepButton15.setXY(629, 215);
    StepButton15.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton15.invalidate();

    StepButton16.setXY(667, 215);
    StepButton16.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton16.invalidate();

    StepButton1_2.setXY(97, 271);
    StepButton1_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton1_2.invalidate();

    StepButton2_2.setXY(135, 271);
    StepButton2_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton2_2.invalidate();

    StepButton3_2.setXY(173, 271);
    StepButton3_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton3_2.invalidate();

    StepButton4_2.setXY(211, 271);
    StepButton4_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton4_2.invalidate();

    StepButton5_2.setXY(249, 271);
    StepButton5_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton5_2.invalidate();

    StepButton6_2.setXY(287, 271);
    StepButton6_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton6_2.invalidate();

    StepButton7_2.setXY(325, 271);
    StepButton7_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton7_2.invalidate();

    StepButton8_2.setXY(363, 271);
    StepButton8_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton8_2.invalidate();

    StepButton9_2.setXY(401, 271);
    StepButton9_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton9_2.invalidate();

    StepButton10_2.setXY(439, 271);
    StepButton10_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton10_2.invalidate();

    StepButton11_2.setXY(477, 271);
    StepButton11_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton11_2.invalidate();

    StepButton12_2.setXY(515, 271);
    StepButton12_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton12_2.invalidate();

    StepButton13_2.setXY(553, 271);
    StepButton13_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton13_2.invalidate();

    StepButton14_2.setXY(591, 271);
    StepButton14_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton14_2.invalidate();

    StepButton15_2.setXY(629, 271);
    StepButton15_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton15_2.invalidate();

    StepButton16_2.setXY(667, 271);
    StepButton16_2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton16_2.invalidate();

    StepButton1_3.setXY(97, 328);
    StepButton1_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton1_3.invalidate();

    StepButton2_3.setXY(135, 328);
    StepButton2_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton2_3.invalidate();

    StepButton3_3.setXY(173, 328);
    StepButton3_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton3_3.invalidate();

    StepButton4_3.setXY(211, 328);
    StepButton4_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton4_3.invalidate();

    StepButton5_3.setXY(249, 328);
    StepButton5_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton5_3.invalidate();

    StepButton6_3.setXY(287, 328);
    StepButton6_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton6_3.invalidate();

    StepButton7_3.setXY(325, 328);
    StepButton7_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton7_3.invalidate();

    StepButton8_3.setXY(363, 328);
    StepButton8_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton8_3.invalidate();

    StepButton9_3.setXY(401, 328);
    StepButton9_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton9_3.invalidate();

    StepButton10_3.setXY(439, 328);
    StepButton10_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton10_3.invalidate();

    StepButton11_3.setXY(477, 328);
    StepButton11_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton11_3.invalidate();

    StepButton12_3.setXY(515, 328);
    StepButton12_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton12_3.invalidate();

    StepButton13_3.setXY(553, 328);
    StepButton13_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton13_3.invalidate();

    StepButton14_3.setXY(591, 328);
    StepButton14_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton14_3.invalidate();

    StepButton15_3.setXY(629, 328);
    StepButton15_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton15_3.invalidate();

    StepButton16_3.setXY(667, 328);
    StepButton16_3.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton16_3.invalidate();

    StepButton1_4.setXY(97, 385);
    StepButton1_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton1_4.invalidate();

    StepButton2_4.setXY(135, 385);
    StepButton2_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton2_4.invalidate();

    StepButton3_4.setXY(173, 385);
    StepButton3_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton3_4.invalidate();

    StepButton4_4.setXY(211, 385);
    StepButton4_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton4_4.invalidate();

    StepButton5_4.setXY(249, 385);
    StepButton5_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton5_4.invalidate();

    StepButton6_4.setXY(287, 385);
    StepButton6_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton6_4.invalidate();

    StepButton7_4.setXY(325, 385);
    StepButton7_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton7_4.invalidate();

    StepButton8_4.setXY(363, 385);
    StepButton8_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton8_4.invalidate();

    StepButton9_4.setXY(401, 385);
    StepButton9_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton9_4.invalidate();

    StepButton10_4.setXY(439, 385);
    StepButton10_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton10_4.invalidate();

    StepButton11_4.setXY(477, 385);
    StepButton11_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton11_4.invalidate();

    StepButton12_4.setXY(515, 385);
    StepButton12_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton12_4.invalidate();

    StepButton13_4.setXY(553, 385);
    StepButton13_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton13_4.invalidate();

    StepButton14_4.setXY(591, 385);
    StepButton14_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton14_4.invalidate();

    StepButton15_4.setXY(629, 385);
    StepButton15_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton15_4.invalidate();

    StepButton16_4.setXY(667, 385);
    StepButton16_4.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID));
    StepButton16_4.invalidate();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 16; j++) {
			stpHL[i][j] = 0;
		}
	}
}

void Screen1View::play_stop() {
	play = !play;
	step = 0;
		stepCircle1.setAlpha(50);
		stepCircle1.invalidate();
		stepCircle2.setAlpha(50);
		stepCircle2.invalidate();
		stepCircle3.setAlpha(50);
		stepCircle3.invalidate();
		stepCircle4.setAlpha(50);
		stepCircle4.invalidate();
		stepCircle5.setAlpha(50);
		stepCircle5.invalidate();
		stepCircle6.setAlpha(50);
		stepCircle6.invalidate();
		stepCircle7.setAlpha(50);
		stepCircle7.invalidate();
		stepCircle8.setAlpha(50);
		stepCircle8.invalidate();
		stepCircle9.setAlpha(50);
		stepCircle9.invalidate();
		stepCircle10.setAlpha(50);
		stepCircle10.invalidate();
		stepCircle11.setAlpha(50);
		stepCircle11.invalidate();
		stepCircle12.setAlpha(50);
		stepCircle12.invalidate();
		stepCircle13.setAlpha(50);
		stepCircle13.invalidate();
		stepCircle14.setAlpha(50);
		stepCircle14.invalidate();
		stepCircle15.setAlpha(50);
		stepCircle15.invalidate();
		stepCircle16.setAlpha(50);
		stepCircle16.invalidate();

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); //上から１番目の列
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); //２番目の列
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET); //３番目の列
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET); //４番目の列
		line1.setAlpha(30);
		line2.setAlpha(30);
		line3.setAlpha(30);
		line4.setAlpha(30);
		line1.invalidate();
		line2.invalidate();
		line3.invalidate();
		line4.invalidate();

}
