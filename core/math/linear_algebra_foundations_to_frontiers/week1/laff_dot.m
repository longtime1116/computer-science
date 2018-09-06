function [ alpha ] = laff_dot( x, y )
% laff_dot

[m_x, n_x] = size(x);
[m_y, n_y] = size(y);


if ~isvector(x) || ~isvector(y)
    alpha = 'FAILED'
    return
end

if max([m_x, n_x]) ~= max([m_y, n_y]) || min([m_x, n_x] ~= min(m_y, n_y))
    alpha = 'FAILED'
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

alpha = 0
for i=1:max(m_x, n_x)
    alpha = alpha + normalized_x(i) * normalized_y(i);
end

return
end
