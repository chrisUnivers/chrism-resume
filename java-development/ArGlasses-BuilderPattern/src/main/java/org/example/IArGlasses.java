package org.example;

public interface IArGlasses {
    public void setIOProcessor(IIOProcessor ioProcessor);
    public IIOProcessor getIOProcessor();
    public void setGlassesCondition(String glassesCondition);
    public String getGlassesCondition();
}