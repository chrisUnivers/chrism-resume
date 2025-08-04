package org.example;

import static org.example.arglasses.utils.ConstUtils.*;

public class PinkArGlassesBuilder implements IArGlassesBuilder{

    protected  ArGlasses arGlasses_;

    public PinkArGlassesBuilder() {
        Reset();
    }

    @Override
    public void BuildIOProcessor() {
        ArGlassesIOProcessor io_processor = new ArGlassesIOProcessor(FAST_IO_PROCESSOR_INPUTS[0], FAST_IO_PROCESSOR_MODEL, FAST_IO_PROCESSOR_INPUTS[1]);
        arGlasses_.setIOProcessor(io_processor);
    }
    @Override
    public void Reset() {
        arGlasses_ = new ArGlasses();

    }
    @Override
    public IArGlasses MakeARGlasses() {
        return this.arGlasses_;
    }

    public void BuildGlassesFrames() {

    }

    @Override
    public String toString() {
        String pinkArGlassesStr = PINK_AR_GLASSES_BLDR_TOSTRING_STR;

        return pinkArGlassesStr;
    }
}
