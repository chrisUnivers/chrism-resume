#include "DiamondApple.h"

DiamondApple::DiamondApple() {

}

void DiamondApple::setPosition(std::unique_ptr<ItemPosition> item_pos) const {
    itemPosition_ = std::move(item_pos);
}

// ItemPosition* DiamondApple::getPosition() {
// }