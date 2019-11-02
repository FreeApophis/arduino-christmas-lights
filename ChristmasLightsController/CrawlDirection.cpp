#include "CrawlDirection.h"

#include "framework.h"

CrawlDirection RandomDirection()
{
    return random(2)
               ? CrawlDirection::Forward
               : CrawlDirection::Backward;
}

int StartPosition(CrawlDirection direction, int endPosition)
{
    return direction == CrawlDirection::Forward
               ? 0
               : endPosition;
}
