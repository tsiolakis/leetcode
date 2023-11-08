function [maxDist] = maxDistToClosest(seats)
    lastCoronaSeat = 1;
    maxDist = 0;
    for i = 1 : size(seats,2)
        if seats(i) == 1
            lastCoronaSeat = i;
            maxDist = i - 1;
            break
        end
    end
    for i = lastCoronaSeat : size(seats,2)
        if seats(i) == 1
            if floor((i - lastCoronaSeat)/2) > maxDist
                maxDist = floor((i - lastCoronaSeat)/2);
            end
            lastCoronaSeat = i;
        end
    end
    if (seats(end) == 0) && (size(seats,2) - lastCoronaSeat > maxDist)
        maxDist = size(seats,2) - lastCoronaSeat;
    end
end
