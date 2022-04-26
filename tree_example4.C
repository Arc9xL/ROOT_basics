void tree_example4()
{
	TFile *file = new TFile("myArray.root", "READ"); 		// Read root file
	TTree *t_rd = (TTree *) file -> Get("tree");				// get tree from the root files
	
	// Create variables
	double px[5], py[5], pt[5];
	
	// set branches
	t_rd -> SetBranchAddress("px", px);
	t_rd -> SetBranchAddress("py", py);
	t_rd -> SetBranchAddress("pt", pt);
	
	// histogram
	TH2F *h_pxpy = new TH2F("h_pxpy", "py vs px", 100, -10, 70, 100, -10, 70);
	TH1F *h_pt   = new TH1F("h_pt", "pt", 100, 0, 70);
	TH1F *h_1d   = new TH1F("h_1d", "pt[i]", 100, -10, 70);
	
	for (int Evnt = 0; Evnt < t_rd -> GetEntries(); Evnt++)
	{
		// Get event info from the tree
		t_rd -> GetEntry(Evnt);
		
		for (int i = 0; i < 5; i++)
		{
			h_pxpy -> Fill(px[i], py[i]);
			h_pt   -> Fill(pt[i]);
			
			// you can change the value of "i" and see its effect on h_1d graph
			if (i == 3){h_1d -> Fill(pt[i]);}
		}
	}
	
	TCanvas *cnvs1 = new TCanvas();
	h_pxpy -> SetStats(0);
	h_pxpy -> Draw("colz");
	
	TCanvas *cnvs2 = new TCanvas();
	h_pt -> SetStats(0);
	h_pt -> Draw();
	
	TCanvas *cnvs3 = new TCanvas();
	h_1d -> SetStats(0);
	h_1d -> Draw();
}
