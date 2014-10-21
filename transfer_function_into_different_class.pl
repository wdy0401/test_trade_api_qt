while(<DATA>)
{
	my $oriline=$_;
	$oriline=~s/\;//;
	$oriline=~s/\s+$//;
	
	my @a=(split/\(|\)/);
	#print"$a[0]\t$a[1]\t$a[2]\n";
	my ($name)=($a[0]=~/(\S+$)/);
	my @par=(split/,/,$a[1]);
	for(@par)
	{
		s/const std::string & //;
		s/long//;
		s/double//;
		s/\s+//;
	}
	$p=$oriline;
	$p=~s/.*\(//;
	$p=~s/\).*//;
	
	
	# print "void tactic::$name($p)\n";
	# my $line=join"<<",@par;
	# print "\{\n";
	# print"\t";
	# print 'cout<<"function name"<<endl;';print"\n";
	# print"\t";
	# print "cout<<\"    \"<<\"$name\"<<endl;";print"\n";
	# print"\tcout <<$line<<endl;\n";
	# print "}\n";	
	
	print "void trans_event::$name($p)\n";
	print "\{\n";
	print"\t";
	my $line=join" , ",@par;
	print "ptc->$name($line);";print"\n";
	print "}\n";	
}







__DATA__
void order_send_ack(const std::string & orderid);
void order_change_size_ack(const std::string & orderid, long size);
void order_change_price_ack(const std::string & orderid, double price);
void order_fill(const std::string & orderid,long fillsize);
void order_change_size_rej(const std::string & orderid, long size);
void order_change_price_rej(const std::string & orderid, double price);
void order_change_size_done(const std::string & orderid, long size);
void order_change_price_done(const std::string & orderid, double price);