package org.example.cool.santa;


import org.example.IArGlasses;
import static org.example.cool.santa.SantasCoo.santasCOOBag_;

public class InspectGift implements Runnable {

    protected SantasCoo thrdCOO_;
    protected IArGlasses toMake_;
    public InspectGift(SantasCoo santasCoo) throws InterruptedException {
        this.thrdCOO_ = santasCoo;
        toMake_ = santasCOOBag_.take();
    }
    @Override
    public void run() {
        int running = 1;
        this.thrdCOO_.onNext(toMake_);
    }
}