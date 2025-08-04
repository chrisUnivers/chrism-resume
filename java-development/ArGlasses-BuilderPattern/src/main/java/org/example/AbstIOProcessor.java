package org.example;

public class AbstIOProcessor implements IIOProcessor {

    protected String            arGlassesName_;
    protected UtilEnums.IOProcessorModels ioModel_;
    protected String            ioProcessorName_;

    protected  AbstIOProcessor() {
        ioModel_ = UtilEnums.IOProcessorModels.DEFAULT_NAME;
        arGlassesName_ = "None";
    }

    @Override
    public UtilEnums.IOProcessorModels getIOProcessorModel() {
        return this.ioModel_;
    }
    @Override
    public void setIOProcessorModel(UtilEnums.IOProcessorModels ioModel) {
        this.ioModel_ = ioModel;

    }
}