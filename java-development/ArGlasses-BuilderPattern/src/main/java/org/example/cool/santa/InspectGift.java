package org.example.cool.santa;


import static org.example.cool.santa.SantasCoo.santasCOOBag_;
import org.example.IArGlasses;

public class InspectGift implements Runnable {

    protected SantasCoo thrdCOO_;
    protected IArGlasses toMake_;
    public InspectGift(SantasCoo santasCoo)  {
        this.thrdCOO_ = santasCoo;
    }
    @Override
    public void run() {
        try {
            while (true) {
                if (santasCOOBag_.isEmpty()) {
                    break;
                }

                toMake_ = santasCOOBag_.take();
                this.thrdCOO_.onNext(toMake_);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}