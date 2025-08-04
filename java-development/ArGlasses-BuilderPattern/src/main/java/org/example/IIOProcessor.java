package org.example;

public interface IIOProcessor {
    public void setIOProcessorModel(UtilEnums.IOProcessorModels ioName);
    public UtilEnums.IOProcessorModels getIOProcessorModel();
}