#pragma once

enum class CrawlDirection {
    Forward,
    Backward
};

CrawlDirection RandomDirection();
int StartPosition(CrawlDirection direction, int endPosition);
