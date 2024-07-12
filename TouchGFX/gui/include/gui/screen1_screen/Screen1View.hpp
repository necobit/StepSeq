#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
//    void updateStepNo(int newValue);
    void updateBPM(int newValue);
//    void updatemsec(int newValue);
    void stepHL1();
    void stepHL2();
    void stepHL3();
    void stepHL4();
    void stepHL5();
    void stepHL6();
    void stepHL7();
    void stepHL8();
    void stepHL9();
    void stepHL10();
    void stepHL11();
    void stepHL12();
    void stepHL13();
    void stepHL14();
    void stepHL15();
    void stepHL16();
    void stepHL1_2();
    void stepHL2_2();
    void stepHL3_2();
    void stepHL4_2();
    void stepHL5_2();
    void stepHL6_2();
    void stepHL7_2();
    void stepHL8_2();
    void stepHL9_2();
    void stepHL10_2();
    void stepHL11_2();
    void stepHL12_2();
    void stepHL13_2();
    void stepHL14_2();
    void stepHL15_2();
    void stepHL16_2();
    void stepHL1_3();
    void stepHL2_3();
    void stepHL3_3();
    void stepHL4_3();
    void stepHL5_3();
    void stepHL6_3();
    void stepHL7_3();
    void stepHL8_3();
    void stepHL9_3();
    void stepHL10_3();
    void stepHL11_3();
    void stepHL12_3();
    void stepHL13_3();
    void stepHL14_3();
    void stepHL15_3();
    void stepHL16_3();
    void stepHL1_4();
    void stepHL2_4();
    void stepHL3_4();
    void stepHL4_4();
    void stepHL5_4();
    void stepHL6_4();
    void stepHL7_4();
    void stepHL8_4();
    void stepHL9_4();
    void stepHL10_4();
    void stepHL11_4();
    void stepHL12_4();
    void stepHL13_4();
    void stepHL14_4();
    void stepHL15_4();
    void stepHL16_4();
    void tmpChange(int value);
    void allclear();
    void play_stop();

private:
    int step;
    int stpHL[4][16];
    int BPM = 120;
    int BPMtomsec = 60000 / BPM;
    int onTime = 30;
    int play = 0;
protected:
    int tickCounter;
};

#endif // SCREEN1VIEW_HPP
