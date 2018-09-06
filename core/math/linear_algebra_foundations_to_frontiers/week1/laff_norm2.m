function [ alpha ] = laff_norm2( x )
% laff_dot

[m_x, n_x] = size(x);


if ~isvector(x)
    alpha = 'FAILED'
    return
end

if ( m_x == 1 )
        normalized_x = x';
else
    normalized_x = x;
end

alpha = 0
for i=1:max(m_x, n_x)
    alpha = alpha + normalized_x(i)^2
end

alpha = sqrt(alpha)

return
end
