#include "CrawlDirection.h"

#include "framework.h"

auto RandomDirection() -> CrawlDirection
{
    return random(2)
               ? CrawlDirection::Forward
               : CrawlDirection::Backward;
}

auto StartPosition(const CrawlDirection direction, const int endPosition) -> int
{
    return direction == CrawlDirection::Forward
               ? 0
               : endPosition;
}
