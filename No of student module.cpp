int checkNoInClass(){				//Prints total number of students in each class
system("CLS");
	int cl=0,i,found =0;
	Class obj;
	int cnt=0;
	fstream fl(FLBCLAS,ios::in|ios::binary);
	if(!fl){
		cout<<"No Records Found !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		found=1;
		cl++;			//Gets each record from file and stores count of each class [c-p cp]
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
	cout<<"\t\t-------------------\n";
	cout<<"\t\tTotal Number of Students:\t";
	printf("%d", cl);
	cout<<"\n\t\t-------------------\n";
	cout<<"";
	return found;
}