package org.example;

public class PinkArGlassesBuilder implements IArGlassesBuilder{

    @Override
    public void BuildIOProcessor() {

    }

    @Override
    public void Reset() {

    }
    @Override
    public IArGlasses MakeARGlasses() {
        return null;
    }
    @Override
    public String toString() {
        String pinkArGlassesBldr = "I'm a pink ar glasses build";

        return pinkArGlassesBldr;
    }
}
