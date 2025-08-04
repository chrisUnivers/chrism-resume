package org.example.cool.santa;

import org.example.IArGlasses;

import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;

public class SantasCoo extends NotifySanta {
    public static final BlockingDeque<IArGlasses> santasCOOBag_ = new LinkedBlockingDeque<>();
    public SantasCoo(String name) {
        super("Santa's coo" + " " + name);
    }
}