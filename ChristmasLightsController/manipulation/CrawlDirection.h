#pragma once

enum class CrawlDirection {
    Forward,
    Backward
};

auto RandomDirection() -> CrawlDirection;
auto StartPosition(CrawlDirection direction, int endPosition) -> int;
