#! /usr/local/bin/perl


$SearchString = "set_scan_style multiplexed_flip_flop";
$ReplaceString = "set_scan_style clocked_scan";

$FileList = system("ls *.con");


foreach $File ($FileList){


  open INFILE, ("$File");
  open TEMPFILE, (">$File.tmp");


  while(<INFILE>){
    
    if(/$SearchString/){
      s/$SearchString/$ReplaceString/;
    }

    #print TEMPFILE $_;
    print $_;
  }

  close(INFILE);
  close(TEMPFILE);

  #system ("mv $File.tmp $File");
}
