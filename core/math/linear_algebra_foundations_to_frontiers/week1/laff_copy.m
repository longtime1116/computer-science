function [ y_out ] = laff_copy( x, y )
%LAFF_COPY Summary of this function goes here
%   Detailed explanation goes here

[m_x, n_x] = size(x);
[m_y, n_y] = size(y);

if (max([m_x, n_x]) ~= max([m_y, n_y]))
    y_out = 'FAILED'
    return
end

if ( m_x == 1 )
    if (m_y == 1)
        normalized_y = y';
    else
        normalized_y = y;
    end
        normalized_x = x';
else
    if (m_y == 1)
        normalized_y = y';
    else
        normalized_y = y;
    end
    normalized_x = x;
end

for i=1:max(m_x, n_x)
    normalized_y(i) = normalized_x(i);
end

if (m_y == 1)
    y_out = normalized_y';
else
    y_out = normalized_y;
end

return
end1
