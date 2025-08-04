package org.example.arglasses.utils;

import org.example.IArGlasses;
import org.example.cool.santa.NotifySanta;


import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;

import static org.example.arglasses.utils.ConstUtils.SANTA_HAS_A_NEW_GIFT_STR;

public class RealSanta extends NotifySanta {
    protected static final BlockingDeque<IArGlasses> santasGiftBag_ = new LinkedBlockingDeque<>();

    public RealSanta(String name) {
        super("Real santa" + " " + name);
    }
    public IArGlasses getFirstFromSantasBage() {
        return santasGiftBag_.peek();
    }

    public void addToSantasBag(IArGlasses gift) {
        try {
            int addingGift = 1;
            assert (gift != null);
            santasGiftBag_.add(gift);
        } catch (NullGiftException e) {

            throw new NullGiftException("Can not add null gift's to santa's bag");
        }
    }
    public  void santaHasAnewGift() {
        String santasPrint = String.format(SANTA_HAS_A_NEW_GIFT_STR, this.notifyName_, santasGiftBag_.size());
        System.out.println(santasPrint);
    }
}
