void tree_example1()
{
	TFile *file = new TFile("myTree.root", "RECREATE");		// class for creating a root file
	TTree *tree = new TTree("tree", "simple tree");				// class for making a tree
	TRandom r;																						// class for random numbers
	
	// data we want to fill in the tree
	double px, py, pt;
	double random;
	
	// Make Branches
	tree -> Branch("px",     &px,     "px/D");
	tree -> Branch("py",     &py,     "py/D");
	tree -> Branch("pt",     &pt,     "pt/D");
	tree -> Branch("random", &random, "random/D");
	
	for (int Event = 0; Event < 100000; Event++)
	{
		r.Rannor(px, py);													// assign random number to px and py
		pt = sqrt(px*px + py*py);
		random = r.Rndm();												// assign random number to "random"
	
		tree -> Fill();														// Fill data after one event
	}
	
	file -> Write();
	file -> Close();
}
