void tree_example2()
{
	TFile *file = new TFile("myTree.root", "READ"); 	// open the file
	TTree *t_rd = (TTree *) file -> Get("tree");			// get tree from the file
	
	// Histograms
	TH2F *h_pxpy = new TH2F("h_pxpy", "py Vs px", 100, -2, 2, 100, -2, 2);
	TH1F *h_pt   = new TH1F("h_pt", "pt", 100, 0, 5);
	
	// variables
	double px, py, pt, random;
	
	// assign branches to the variable
	t_rd -> SetBranchAddress("px", &px);
	t_rd -> SetBranchAddress("py", &py);
	t_rd -> SetBranchAddress("pt", &pt);
	t_rd -> SetBranchAddress("random", &random);
	
	for (int Evnt = 0; Evnt < t_rd -> GetEntries(); Evnt++)
	{
		// Get entry for each event
		t_rd -> GetEntry(Evnt);
		
		// once tree gets an info, we can dump that into the histogram
		h_pxpy -> Fill(px, py);
		h_pt   -> Fill(pt);
	}
	
	// h_pxpy on the first canvas
	TCanvas *cnvs1 = new TCanvas();
	h_pxpy -> SetStats(0);
	h_pxpy -> Draw("colz");
	
	// h_pt on the second canvas
	TCanvas *cnvs2 = new TCanvas();
	h_pt -> SetStats(0);
	h_pt -> SetFillColor(kCyan);
	h_pt -> Draw();
}
