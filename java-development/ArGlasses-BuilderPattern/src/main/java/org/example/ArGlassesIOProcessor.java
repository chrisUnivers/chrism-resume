package org.example;


public class ArGlassesIOProcessor extends AbstIOProcessor{

    public ArGlassesIOProcessor() {
        this("No Name IO Processor", UtilEnums.IOProcessorModels.YELLOW, "Pink");
    }

    public ArGlassesIOProcessor(String ioProcessorName, UtilEnums.IOProcessorModels iomodel, String arglassesname) {
        ioModel_ = iomodel;
        arGlassesName_ = arglassesname;
        ioProcessorName_ = ioProcessorName;
    }
}