
#include "DiamondApple.h"

void DiamondApple::setPosition(std::unique_ptr<ItemPosition> item_pos) const {
    itemPosition_ = std::move(item_pos.get());
}

// ItemPosition* DiamondApple::getPosition() {
// }