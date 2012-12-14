# clear all
clear all

# load last gasp results from file 
x = load ("/home/maroney/temp/last-gasp-results.csv");

# sort data structure via first column
sorted = sortrows(x,1);

#walk list
y = [unique(sorted(:,1)) zeros(size(unique(sorted(:,1))))];
outputIndex = 1;
for i = [ 1 : size(sorted(:,1)) ]

	# extract pass/fail result
	currentHoldup = sorted(i,1);
	currentResult = sorted(i,3);

	captured = find(y==currentHoldup);

	# if in y already than ignore
	if (length(captured) == 0)
		# are there more to come
		duplicates = find(sorted==currentHoldup);
		if (length(duplicates) > 1)
			y (outputIndex, 2) = mean(sorted(duplicates,3));
		else
			y (outputIndex, 2) = currentResult;
		endif
		outputIndex++;
	endif
end
