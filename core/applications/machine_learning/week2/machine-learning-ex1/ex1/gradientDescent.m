function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);
tmp_theta = zeros(size(theta));

for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %


    for j = 1:length(theta)
      tmp_theta(j) = theta(j) - calcDiff(X, y, theta, alpha, j);
    end

    theta = tmp_theta;
    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);

    if (iter != 1 && J_history(iter - 1) < J_history(iter))
      break;
    end
end

end

function diff = calcDiff(X, y, theta, alpha, theta_index)
diff = 0;
m = length(y);
for i=1:m
  diff = diff + ([X(i, :)] * theta - y(i)) * X(i, theta_index);
end
diff = alpha * diff / m;
end
