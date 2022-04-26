void tree_example3()
{
	TFile *file = new TFile("myArray.root", "RECREATE");
	TTree *tree = new TTree("tree", "tree");
	TRandom r;
	
	// variables
	double px[5], py[5], pt[5];
	
	// variables in tree
	tree -> Branch("px", px, "px[5]/D");
	tree -> Branch("py", py, "py[5]/D");
	tree -> Branch("pt", pt, "pt[5]/D");
	
	// variables to initialize after each array loop
	double x, y;
	
	for (int Evnt = 0; Evnt < 100000; Evnt++)
	{
		for (int i = 0; i < 5; i++)
		{
			r.Rannor(x, y);
			px[i] = x + i* 10;
			py[i] = y + i* 10;
			pt[i] = sqrt(px[i]* px[i] + py[i]* py[i]);
		}
		tree -> Fill();
	}
	
	file -> Write();
	file -> Close();
}
