package org.example.cool.santa;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Flow;
import java.util.function.Consumer;
import org.example.IArGlasses;

import static org.example.arglasses.utils.ConstUtils.ADDING_TO_SANTAS_BAG_STR;
import static org.example.arglasses.utils.ConstUtils.AR_GLASSES_CONDITION_NEW;
public class NotifySanta implements Flow.Publisher<IArGlasses>, Flow.Subscriber<IArGlasses> {
    protected IArGlasses giftFromSanta_;
    protected String notifyName_;
    protected List<Flow.Subscriber<? super  IArGlasses>> santasCOOs_ = new ArrayList<>();

    public NotifySanta(String name) {
        this.notifyName_ = name;
    }

    @Override
    public void subscribe(Flow.Subscriber<? super  IArGlasses> subscriber) {

        santasCOOs_.add(subscriber);
    }

    public void subscribe(Consumer<? super  IArGlasses> onNext, Runnable onComplete) {
        santasCOOs_.add(new Flow.Subscriber<IArGlasses>() {
            @Override
            public void onSubscribe(Flow.Subscription subscription) {

            }

            @Override
            public void onNext(IArGlasses arglasses) {
                onNext.accept(arglasses);
            }

            @Override
            public void onError(Throwable throwable) {
                throwable.printStackTrace();
            }

            @Override
            public void onComplete() {
                onComplete.run();
            }
        });
    }

    private void updateSantasBag() {
        santasCOOs_.forEach(coo -> {
            coo.onNext(giftFromSanta_);
            String santasBagPrint = String.format(ADDING_TO_SANTAS_BAG_STR, this.notifyName_, giftFromSanta_.getGlassesCondition());
            System.out.println(santasBagPrint);
            coo.onComplete();
        });
    }

    @Override
    public void onNext(IArGlasses newglasses) {
        if (newglasses.getGlassesCondition().toLowerCase().equals(AR_GLASSES_CONDITION_NEW)) {
            giftFromSanta_ = newglasses;
            updateSantasBag();
        } else {
            System.out.println(this.notifyName_ + ": " + newglasses.getGlassesCondition() + "was not added to santa's bag");
        }
    }

    @Override
    public void onComplete() {
    }
    @Override
    public void onError(Throwable throwable) {
        throwable.printStackTrace();
    }
    @Override
    public void onSubscribe(Flow.Subscription subscription) {}
}
