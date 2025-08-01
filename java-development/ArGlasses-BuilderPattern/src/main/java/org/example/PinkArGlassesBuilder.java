package org.example;

public class PinkArGlassesBuilder implements IArGlassesBuilder{

    protected  ArGlasses arGlasses_;
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
        String pinkArGlassesStr = "A pink AR glasses build";

        return pinkArGlassesStr;
    }
}
