function [ y_out ] = laff_axpy( alpha, x, y )
% laff_axpy

[m_x, n_x] = size(x);
[m_y, n_y] = size(y);


if ~isscalar(alpha) || ~isvector(x) || ~isvector(y)
    y_out = 'FAILED'
    return
end

if max([m_x, n_x]) ~= max([m_y, n_y]) || min([m_x, n_x] ~= min(m_y, n_y))
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
    normalized_y(i) = alpha * normalized_x(i) + normalized_y(i);
end

if (m_y == 1)
    y_out = normalized_y';
else
    y_out = normalized_y;
end

return
end
