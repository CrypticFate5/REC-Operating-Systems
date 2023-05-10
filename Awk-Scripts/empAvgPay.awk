BEGIN{print "EMPLOYEE DETAILS"}{
    if($2>6000&&$3>4){
        print $1,"\t\t",$2*$3
        pay=pay+$2*$3
        count=count+1
    }
}

END{
    {
        print "No. of Employee= ", count
        print "Total Pay= ",pay
        print "Average Pay= ",pay/count
    }
}
