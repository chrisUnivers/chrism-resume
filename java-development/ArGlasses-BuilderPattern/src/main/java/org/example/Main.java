package org.example;

import org.example.arglasses.utils.ProcessInput;
import org.example.arglasses.utils.ReadInputT;
import org.example.arglasses.utils.RealSanta;
import org.example.cool.santa.InspectGift;
import org.example.cool.santa.SantasCoo;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.BlockingDeque;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingDeque;

// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Thread readInputs = new Thread(new ReadInputT("builderAndCondition.txt"));
        readInputs.start();


        List<SantasCoo> santasCOOsList = new ArrayList<>();
        ExecutorService processInputsGetSantaReady = Executors.newFixedThreadPool(4);
        RealSanta pinkSanta = new RealSanta("Pink Santa");

        for (int i = 0; i < 2; i++) {
            processInputsGetSantaReady.submit(new ProcessInput());
        }
        for (int i = 0; i < 2; i++) {  // create and add COO's to santa's coo's list
            SantasCoo coo = new SantasCoo("(COO " + i + ")");
            coo.subscribe(pinkSanta::addToSantasBag, pinkSanta::santaHasAnewGift);
            santasCOOsList.add(coo);
        }
        for (int i = 0; i < 2; i++) {
            processInputsGetSantaReady.submit(new InspectGift(santasCOOsList.get(i)));
        }
        processInputsGetSantaReady.shutdown();
    }
}