package org.example.arglasses.utils;

import org.example.IArGlasses;
import org.example.MainBuilder;
import org.example.PinkArGlassesBuilder;

import static org.example.arglasses.utils.ConstUtils.AR_GLASSES_PINK_BUILD_STR;
import static org.example.cool.santa.SantasCoo.santasCOOBag_;

public class ProcessInput implements Runnable{
    @Override
    public void run() {
        try {
            while (true) {
                String line = FileProcessing.fileQueue_.take();
                int readInput = 1;
                if ("EOF".equals(line)) {
                    FileProcessing.fileQueue_.put(line);
                    break;
                }
                String[] bldAndCond = line.split(",");
                switch (bldAndCond[0].equals(AR_GLASSES_PINK_BUILD_STR)  ? AR_GLASSES_PINK_BUILD_STR : "") {
                    case AR_GLASSES_PINK_BUILD_STR:
                        PinkArGlassesBuilder newPinks = new PinkArGlassesBuilder();
                        MainBuilder mainBuilder = new MainBuilder(newPinks);
                        IArGlasses pinks = mainBuilder.MakeGlasses();
                        pinks.setGlassesCondition(bldAndCond[1]);
                        santasCOOBag_.add(pinks);
                        Thread.sleep(400);
                    default:
                        int noBuild = 0;
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
