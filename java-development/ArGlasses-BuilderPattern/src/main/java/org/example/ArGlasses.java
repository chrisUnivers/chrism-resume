package org.example;

public class ArGlasses implements IArGlasses{
    String arGlassesCondition_;
    protected IIOProcessor arGlassesIOProcessor_;

    @Override
    public void setIOProcessor(IIOProcessor ioProcessor) {
        this.arGlassesIOProcessor_ = ioProcessor;
    }
    @Override
    public IIOProcessor getIOProcessor() {
        return this.arGlassesIOProcessor_;
    }
    public String getGlassesCondition() {
        return this.arGlassesCondition_;
    }
    @Override
    public void setGlassesCondition(String glassesCondition) {

        this.arGlassesCondition_ = glassesCondition;
    }
    @Override
    public String toString() {
        final String arGlassesStr = String.format("Your new glasses have the following Specs:%n%s", arGlassesIOProcessor_.toString());
        return arGlassesStr; // + more %s, so more output but currently only have a processor
    }
}

