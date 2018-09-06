function [ x_out ] = laff_scale( alpha, x )
% laff_scale

[m_x, n_x] = size(x);

if ~isscalar(alpha) || ~isvector(x)
    x_out = 'FAILED'
    return
end

if ( m_x == 1 )
    for i=1:n_x
        x_out(1, i) = x(1, i) * alpha
    end
else
    for i=1:m_x
        x_out(i, 1) = x(i, 1) * alpha
    end
end

return
end
