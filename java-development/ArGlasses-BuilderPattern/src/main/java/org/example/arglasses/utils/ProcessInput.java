package org.example.arglasses.utils;

import org.example.IArGlasses;
import org.example.MainBuilder;
import org.example.PinkArGlassesBuilder;

import static org.example.arglasses.utils.ConstUtils.PINK_BUILD_AR_GLASSES_STR;
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
                switch (bldAndCond[0].equals(PINK_BUILD_AR_GLASSES_STR)  ? PINK_BUILD_AR_GLASSES_STR : "") {
                    case PINK_BUILD_AR_GLASSES_STR:
                        PinkArGlassesBuilder newPinks = new PinkArGlassesBuilder();
                        MainBuilder mainBuilder = new MainBuilder(newPinks);
                        IArGlasses pinks = mainBuilder.MakeGlasses();
                        pinks.setGlassesCondition(bldAndCond[1]);
                        santasCOOBag_.add(pinks);
                    default:
                        int noBuild = 0;
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
     }
}