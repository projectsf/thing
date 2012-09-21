##
open OUTFILE, ">./output/GCVect.txt" or die "Can't open output file\n";

$BitWidth = 18;
$NumVectors = 100;
$Root = 2;

$Max = power($Root,$BitWidth);

for($i=0;$i<$NumVectors;$i++){
  $GCodeXSt   = Int2Bin(int(rand $Max),$BitWidth);
  $GCodeYSt   = Int2Bin(int(rand $Max),$BitWidth);
  $GCodeMask1 = Int2Bin(int(rand $Max),$BitWidth);
  $GCodeMask2 = Int2Bin(int(rand $Max),$BitWidth);
  print OUTFILE "$GCodeXSt$GCodeYSt$GCodeMask1$GCodeMask2\n";
}
  
sub power{
  my $Root = shift(@_);
  my $Pow = shift(@_);
  $Temp=1;
  for(my $i=0;$i<$Pow;$i++){
    $Temp= $Root * $Temp;
  }
  return $Temp;
}

sub Int2Bin{
  my $Value    = shift(@_);
  my $BitWidth = shift(@_);
  #print "$Value,$BitWidth\n";
  my $BinString = ""; 
  for(my $i=$BitWidth-1;$i>=0;$i--){
    my $CurrMax = power(2,$i);
    if($Value >= $CurrMax){
      $BinString = $BinString . "1";
      $Value = $Value - power(2,$i);
    }
    else{
      $BinString = $BinString . "0";
    }
  }
  return $BinString;
  
}
   
  
  


