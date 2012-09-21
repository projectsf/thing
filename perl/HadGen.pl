#! c:\perl\bin

open OUTFILE, ">./output/HadMat.txt"  or die "Can't open output file\n";

TabGen(1);


## TabGen($SizeMatrix)

sub TabGen{
  my $in = shift(@_);
  my $SizeMatrix = ($in+1) * 2;
  my $SizeBar = $in+1;
  @HadMatrix = (
    [1,1],
    [1,-1]
  );

  for(my $iter=2;$iter<$SizeMatrix;$iter++){

  # create bar
  # create bar matrix 1/4 size of final matrix
    for(my $i=0;$i<$iter;$i++){
      for(my $j=0;$j<$iter;$j++){
          $HadMatrixBar[$i][$j] = ($HadMatrix[$i][$j] * -1);
      }
    }

    #make subroutine for this
    
    for($i=0;$i<(power(2,$iter));$i++){

      # create top half of matrix (all positives)
      for($j=0;$j<(power(2,$iter));$j++){
        $TempI = $i % $iter;
        $TempJ = $j % $iter;
        if(($i >= $iter) && ($j >= $iter)){
          $HadMatrix[$i][$j] = $HadMatrixBar[$TempI][$TempJ];
        }
        else{
          $HadMatrix[$i][$j] = $HadMatrix[$TempI][$TempJ];
        }
      }
    }
    

  }

  # should make subroutine for printing
  print "HadMatrix\n";
  $MaxIndex = power(2,($SizeMatrix-1));
  for($i=0;$i<$MaxIndex;$i++){
    if(!($i % 2)){
      print OUTFILE "\n";
    }
      
    for($j=0;$j<$MaxIndex;$j++){
      printf OUTFILE "%2d ",$HadMatrix[$i][$j];
    }
    print OUTFILE "\n";
    }
   
}

# power(Root,Pow)
# returns a base raised to a power pow
#
sub power{
  my $Root = shift(@_);
  my $Pow = shift(@_);
  $Temp=1;
  for(my $i=0;$i<$Pow;$i++){
    $Temp= $Root * $Temp;
  }
  return $Temp;
}
